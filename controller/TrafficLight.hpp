#pragma once
#include <string>
using namespace std;

class TrafficLight
{
public:
  TrafficLight(string, int, int, int);
  int getState();
  void switchColor();
  int getGreenCycle();
  string getStreetName();
  int getNextSwitchTime();
  void setNextSwitchTime(int);

private:
  string streetName;
  int state;
  int lengthGreen;
  int lengthYellow;
  int nextSwitchTime;
};
