#include "TrafficController.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

TrafficController::TrafficController(vector<string> streets, string cnn, int k, string coordinates)
{
  this->streets = streets;
  this->cnn = cnn;
  this->k = k;
  this->intersection = streets.size();
  vector<TrafficLight> trafficLights;
  for (int i = 0; i < intersection; i++)
  {
    int state = 0;
    int lengthGreen;
    if ((k + i) % 25 == 0)
    {
      lengthGreen = 90;
    }
    else if ((k + i) % 25 < 15)
    {
      lengthGreen = 60;
    }
    else
    {
      lengthGreen = 30;
    }
    TrafficLight t = createTrafficLight(streets.at(i), state, lengthGreen, 0);
    trafficLights.push_back(t);
  }
  this->trafficLights = trafficLights;
  coordinates.erase(0, 7);
  coordinates.erase(coordinates.length() - 1, 1);
  int length = coordinates.length();
  for (int i = 0; i < length; i++)
  {
    if (coordinates[i] == ' ')
    {
      coordinates[i] = ',';
    }
  }
  this->coordinates = coordinates;
}

TrafficLight TrafficController::createTrafficLight(string streetName, int state, int lengthGreen, int nextSwitchTime)
{
  TrafficLight t = TrafficLight(streetName, state, lengthGreen, nextSwitchTime);
  return t;
}

int TrafficController::startSimulation()
{
  trafficLights.at(0).switchColor();
  int greenCycle = trafficLights.at(0).getGreenCycle();
  trafficLights.at(0).setNextSwitchTime(greenCycle);
  trafficLights.at(1).setNextSwitchTime(greenCycle + 10);
  return greenCycle;
}

int TrafficController::update(int currentTime)
{
  int nextEventTime = INT_MAX;
  int nextGreenTrafficLightIndex;
  int nextGreenTime;
  bool someoneSwitchedToGreen = false;
  for (int i = 0; i < intersection; i++)
  {
    if (trafficLights.at(i).getNextSwitchTime() == currentTime)
    {
      trafficLights.at(i).switchColor();
      if (trafficLights.at(i).getState() == 1)
      {
        int nextSwitchTime = currentTime + trafficLights.at(i).getGreenCycle();
        nextEventTime = min(nextEventTime, nextSwitchTime);
        trafficLights.at(i).setNextSwitchTime(nextSwitchTime);
        nextGreenTrafficLightIndex = (i + 1) % intersection;
        nextGreenTime = nextSwitchTime + 10;
        someoneSwitchedToGreen = true;
      }
      else if (trafficLights.at(i).getState() == 2)
      {
        int nextSwitchTime = currentTime + 10;
        nextEventTime = min(nextEventTime, nextSwitchTime);
        trafficLights.at(i).setNextSwitchTime(nextSwitchTime);
      }
    }
  }
  if (someoneSwitchedToGreen)
  {
    trafficLights.at(nextGreenTrafficLightIndex).setNextSwitchTime(nextGreenTime);
  }
  return nextEventTime;
}

vector<string> TrafficController::getCSV()
{
  vector<string> csv;
  for (int i = 0; i < intersection; i++)
  {
    string street = trafficLights.at(i).getStreetName();
    string color;
    if (trafficLights.at(i).getState() == 0)
    {
      color = "Red";
    }
    else if (trafficLights.at(i).getState() == 1)
    {
      color = "Green";
    }
    else
    {
      color = "Yellow";
    }
    string row = cnn + "," + street + "," + color;
    csv.push_back(row);
  }
  return csv;
}

vector<string> TrafficController::getKML()
{
  vector<string> kml;
  kml.push_back("<Placemark>");
  kml.push_back("<name>" + cnn + "</name>");
  string description = streets.at(0);
  string icon = "i" + to_string(intersection) + stateToColor(trafficLights.at(0).getState());
  for (int i = 1; i < intersection; i++)
  {
    description = description + " and " + streets.at(i);
    icon = icon + stateToColor(trafficLights.at(i).getState());
  }
  kml.push_back("<description>" + description + "</description>");
  kml.push_back("<styleUrl>#" + icon + "</styleUrl>");
  kml.push_back("<Point>");
  kml.push_back("<coordinates>" + coordinates + "</coordinates>");
  kml.push_back("</Point>");
  kml.push_back("</Placemark>");
  return kml;
}

void TrafficController::printAllLights()
{
  for (int i = 0; i < intersection; i++)
  {
    cout << trafficLights.at(i).getStreetName() << ":       " << trafficLights.at(i).getState() << ", Next switch time:"
         << trafficLights.at(i).getNextSwitchTime() << endl;
  }
}

string TrafficController::stateToColor(int s)
{
  if (s == 0)
  {
    return "r";
  }
  else if (s == 1)
  {
    return "g";
  }
  else
  {
    return "y";
  }
}
