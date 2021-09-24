#pragma once
#include <vector>
#include <string>
#include "TrafficLight.hpp"
using namespace std;

class TrafficController
{
public:
  TrafficController(vector<string>, string, int, string);
  int startSimulation();
  int update(int);
  vector<string> getCSV();
  vector<string> getKML();
  void printAllLights(); // I used this method for debugging

private:
  int numberOfStreets;                // number of streets in this intersection
  int k;                              // integer that we use to determine green cycle length for traffic lights in this intersection
  string cnn;                         // cnn of this intersection
  vector<string> streets;             // names of streets in this intersection (empty street names omitted)
  vector<TrafficLight> trafficLights; // traffic light objects in this intersection
  TrafficLight createTrafficLight(string, int, int, int);
  string coordinates;       // Coordinates in the form "Point(x, y)"
  string stateToColor(int); // Converts numerical state to a word for the corresponding color
  int yellowCycle;          // Lenght of yellow cycle (same for all traffic lights)
};