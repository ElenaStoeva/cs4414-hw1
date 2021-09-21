#include "TrafficLight.hpp"

// state 0 -> red
// state 1 -> green
// state 2 -> yellow
TrafficLight::TrafficLight(string streetName, int state, int lengthGreen)
{
  this->streetName = streetName;
  this->state = state; //remove state argument, initiallize to 0
  this->lengthGreen = lengthGreen;
  this->lengthYellow = 10;
  this->remainingTime = 0;
}

int TrafficLight::getState()
{
  return state;
}

void TrafficLight::switchColor()
{
  state = (state + 1) % 3;
  if (state == 1)
  {
    remainingTime = lengthGreen;
  }
  if (state == 2)
  {
    remainingTime = lengthYellow;
  }
}

void TrafficLight::updateRemainingTime()
{
  remainingTime = min(0, remainingTime - 1);
}
