#include "Event.hpp"

Event::Event(int time, TrafficController *t)
{
  this->time = time;
  this->trafficController = t;
}

TrafficController *Event::getTrafficController()
{
  return trafficController;
}

void Event::changeNextOccurence(int nextTime)
{
  time = nextTime;
}