#include "TrafficController.hpp"
#include <iostream>
using namespace std;

TrafficController::TrafficController(vector<string> streets, string cnn, int k, int counter)
{
  this->streets = streets;
  this->cnn = cnn;
  this->k = k;
  this->intersection = streets.size();
  this->counter = counter;
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
    TrafficLight t = createTrafficLight(streets.at(0), state, lengthGreen);
    trafficLights.push_back(t);
  }
  this->trafficLights = trafficLights;
}

TrafficLight TrafficController::createTrafficLight(string streetName, int state, int lengthGreen)
{
  TrafficLight t = TrafficLight(streetName, state, lengthGreen);
  return t;
}

void TrafficController::startSimulation()
{
  counter = 0;
  TrafficLight firstTrafficLight = trafficLights.at(0);
  firstTrafficLight.switchColor();
}

void TrafficController::update()
{
  counter = counter + 1;
  int greenTrafficLightIndex;
  for (int i = 0; i < intersection; i++)
  {
    TrafficLight trafficLight = trafficLights.at(i);
    if (trafficLight.getState() == 1)
    {
      greenTrafficLightIndex = i;
    }
    trafficLight.updateRemainingTime();
    if (trafficLight.getRemainingTime() == 0 && trafficLight.getState() != 0)
    {
      trafficLight.switchColor();
    }
  }
  // Switch next traffic light to green
  int nextGreenTrafficLightIndex = (greenTrafficLightIndex + 1) % intersection;
  TrafficLight nextGreenTrafficLight = trafficLights.at(nextGreenTrafficLightIndex);
  nextGreenTrafficLight.switchColor();
}