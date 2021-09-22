#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "TrafficController.hpp"
using namespace std;

vector<string> parseCSVLine(string line)
{
  stringstream str_strm(line);
  string tmp;
  vector<string> words;
  char delim = ',';

  while (getline(str_strm, tmp, delim))
  {
    size_t found = tmp.find("\"");
    if (found == string::npos)
      words.push_back(tmp);
    else
    {
      // FIX THIS!!!
      string cellWithCommas = tmp;
      getline(str_strm, tmp, delim);
      while (tmp.find("\"") == string::npos)
      {
        cellWithCommas = cellWithCommas + "," + tmp;
        getline(str_strm, tmp, delim);
      }
      cellWithCommas = cellWithCommas + "," + tmp;
      words.push_back(cellWithCommas);
    }
  }
  return words;
}

int main(int argc, char **argv)
{
  int t;
  if (argc != 2)
  {
    std::cout << "Incorrect number of arguements" << std::endl;
    return 0;
  }
  else
  {
    string arg = string(argv[1]);
    arg.erase(0, 3);
    t = stoi(arg);
    if (t < 0)
    {
      cout << "The input time must be a non-negative integer." << endl;
    }
  }

  int counter = -1;
  vector<TrafficController> trafficControllers;
  string line;
  ifstream f;

  f.open("Traffic_Signals_SF.csv");

  if (f.is_open())
  {
    getline(f, line);
    int k = 0;
    while (getline(f, line))
    {
      vector<string> row = parseCSVLine(line);
      string cnn = row.at(0);
      string street1 = row.at(3);
      string street2 = row.at(4);
      string street3 = row.at(6);
      string street4 = row.at(8);
      string tbc = row.at(12);
      string coordinates = row.at(34);
      if (tbc == "GPS")
      {
        vector<string> streets;
        if (street1 != "")
        {
          streets.push_back(street1);
        }
        if (street2 != "")
        {
          streets.push_back(street2);
        }
        if (street3 != "")
        {
          streets.push_back(street3);
        }
        if (street4 != "")
        {
          streets.push_back(street4);
        }
        TrafficController t = TrafficController(streets, cnn, k, coordinates);
        trafficControllers.push_back(t);
        k = k + streets.size() - 1;
      }
    }
    f.close();
  }
  else
  {
    cout << "Can't open file" << endl;
  }

  // Start simulation
  counter = 0;
  for (vector<TrafficController>::iterator it = trafficControllers.begin(); it != trafficControllers.end(); ++it)
  {
    (*it).startSimulation();
    // (*it).printAllLights();
  }

  // Update traffic lights
  while (counter < t)
  {
    for (vector<TrafficController>::iterator it = trafficControllers.begin(); it != trafficControllers.end(); ++it)
    {
      (*it).update();
    }
    counter = counter + 1;
  }

  // Output csv file
  ofstream csvOutput;
  csvOutput.open("myfile.csv");
  if (csvOutput.is_open())
  {
    csvOutput << "CNN,STREET,COLOR" << endl;
  }
  else
  {
    cout << "Didn't expect this" << endl;
  }

  for (vector<TrafficController>::iterator it = trafficControllers.begin(); it != trafficControllers.end(); ++it)
  {
    vector<string> trafficControllerCSV = (*it).getCSV();
    for (vector<string>::iterator it_csv = trafficControllerCSV.begin(); it_csv != trafficControllerCSV.end(); ++it_csv)
    {
      string line = *it_csv;
      csvOutput << line << endl;
    }
  }
  csvOutput.close();

  // Output kml file
  ofstream kmlOutput;
  kmlOutput.open("myfile.kml");

  // headers
  if (kmlOutput.is_open())
  {
    kmlOutput << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    kmlOutput << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
    kmlOutput << "<Document>" << endl;
  }
  else
  {
    cout << "Didn't expect this" << endl;
  }

  char letters[3] = {'r', 'g', 'y'};

  // add icon styles
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      string id = "i2";
      id.push_back(letters[i]);
      id.push_back(letters[j]);
      kmlOutput << "<Style id=\"" + id + "\">" << endl;
      kmlOutput << "<IconStyle id=\"" + id + "\">" << endl;
      kmlOutput << "<Icon>" << endl;
      kmlOutput << "<href>files/" + id + ".png</href>" << endl;
      kmlOutput << "<scale>1.0</scale>" << endl;
      kmlOutput << "</Icon>" << endl;
      kmlOutput << "</IconStyle>" << endl;
      kmlOutput << "</Style>" << endl;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        string id = "i3";
        id.push_back(letters[i]);
        id.push_back(letters[j]);
        id.push_back(letters[k]);
        kmlOutput << "<Style id=\"" + id + "\">" << endl;
        kmlOutput << "<IconStyle id=\"" + id + "\">" << endl;
        kmlOutput << "<Icon>" << endl;
        kmlOutput << "<href>files/" + id + ".png</href>" << endl;
        kmlOutput << "<scale>1.0</scale>" << endl;
        kmlOutput << "</Icon>" << endl;
        kmlOutput << "</IconStyle>" << endl;
        kmlOutput << "</Style>" << endl;
      }
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        for (int l = 0; l < 3; l++)
        {
          string id = "i4";
          id.push_back(letters[i]);
          id.push_back(letters[j]);
          id.push_back(letters[k]);
          id.push_back(letters[l]);
          kmlOutput << "<Style id=\"" + id + "\">" << endl;
          kmlOutput << "<IconStyle id=\"" + id + "\">" << endl;
          kmlOutput << "<Icon>" << endl;
          kmlOutput << "<href>files/" + id + ".png</href>" << endl;
          kmlOutput << "<scale>1.0</scale>" << endl;
          kmlOutput << "</Icon>" << endl;
          kmlOutput << "</IconStyle>" << endl;
          kmlOutput << "</Style>" << endl;
        }
      }
    }
  }

  // add pushpins
  for (vector<TrafficController>::iterator it = trafficControllers.begin(); it != trafficControllers.end(); ++it)
  {
    vector<string> trafficControllerKML = (*it).getKML();
    for (vector<string>::iterator it_kml = trafficControllerKML.begin(); it_kml != trafficControllerKML.end(); ++it_kml)
    {
      string line = *it_kml;
      kmlOutput << line << endl;
    }
  }

  // footers
  kmlOutput << "</Document>" << endl;
  kmlOutput << "</kml>" << endl;

  kmlOutput.close();

  return 0;
}
