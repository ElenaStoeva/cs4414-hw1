#pragma once
#include "TrafficController.hpp"

class Event
{
public:
  Event(int, TrafficController *);
  TrafficController *getTrafficController();
  void changeNextOccurence(int);
  int time;

private:
  TrafficController *trafficController;
};