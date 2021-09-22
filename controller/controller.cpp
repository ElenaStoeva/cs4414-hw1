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
      string tmp1 = tmp;
      getline(str_strm, tmp, delim);
      words.push_back(tmp1 + tmp);
    }
  }
  return words;
}

int main()
{
  int counter = -1;
  int t = 3;
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
      // cout << tbc << endl;

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
        cout << street1 << ", " << street2 << ", " << street3 << ", " << street4 << endl;
        TrafficController t = TrafficController(streets, cnn, k, -1);
        trafficControllers.push_back(t);
        k = k + streets.size();
      }
    }
  }
  else
  {
    cout << "Can't open file" << endl;
  }

  // Start simulation
  counter = 0;
  for (vector<TrafficController>::iterator it = trafficControllers.begin(); it != trafficControllers.end(); ++it)
  {
    TrafficController trafficController = *it;
    trafficController.startSimulation();
  }

  while (counter < t)
  {
    for (vector<TrafficController>::iterator it = trafficControllers.begin(); it != trafficControllers.end(); ++it)
    {
      TrafficController trafficController = *it;
      // update counter and all traffic lights
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
    TrafficController trafficController = *it;
    vector<string> trafficControllerCSV = trafficController.getCSV();
    for (vector<string>::iterator it_csv = trafficControllerCSV.begin(); it_csv != trafficControllerCSV.end(); ++it)
    {
      string line = *it_csv;
      if (csvOutput.is_open())
      {
        csvOutput << line << endl;
      }
      else
      {
        cout << "Didn't expect this" << endl;
      }
    }
  }
  csvOutput.close();

  // Output kml file

  return 0;
}
