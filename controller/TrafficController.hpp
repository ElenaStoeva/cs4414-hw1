#include <vector>
#include <string>
#include "TrafficLight.hpp"
using namespace std;

class TrafficController
{
public:
  TrafficController(vector<string>, string, int, string);
  void startSimulation();
  void update();
  vector<string> getCSV();
  vector<string> getKML();
  void printAllLights();

private:
  int intersection;                   // number of streets in this intersection
  int k;                              // integer that we use to determine green cycle length for traffic lights in this intersection
  string cnn;                         // cnn of this intersection
  vector<string> streets;             // names of streets in this intersection (empty street names omitted)
  vector<TrafficLight> trafficLights; // traffic light objects in this intersection
  TrafficLight createTrafficLight(string, int, int);
  string coordinates;
  string stateToColor(int);
};