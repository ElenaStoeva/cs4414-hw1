#include "TrafficLight.hpp"

// state 0 -> red
// state 1 -> green
// state 2 -> yellow
TrafficLight::TrafficLight(string streetName, int state, int lengthGreen, int nextSwitchTime)
{
  this->streetName = streetName;
  this->state = state; //remove state argument, initiallize to 0
  this->lengthGreen = lengthGreen;
  this->lengthYellow = 10;
  this->nextSwitchTime = nextSwitchTime;
}

int TrafficLight::getState()
{
  return state;
}

string TrafficLight::getStreetName()
{
  return streetName;
}

void TrafficLight::switchColor()
{
  state = (state + 1) % 3;
}

int TrafficLight::getGreenCycle()
{
  return lengthGreen;
}

int TrafficLight::getNextSwitchTime()
{
  return nextSwitchTime;
}

void TrafficLight::setNextSwitchTime(int nextT)
{
  nextSwitchTime = nextT;
}