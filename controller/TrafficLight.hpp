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
  string streetName;  // name of the street of this traffic light
  int state;          // state representing the current color (0 - red, 1 - green, 2 - yellow)
  int lengthGreen;    // length of the green cycle
  int nextSwitchTime; // next time to switch light IF this traffic light is green or yellow or it's red and it's its turn to switch to green
};
