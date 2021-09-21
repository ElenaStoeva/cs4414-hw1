#include <vector>
#include <string>
#include "TrafficLight.hpp"
using namespace std;

class TrafficController
{
public:
  TrafficController(vector<string>, string, int, int);
  void startSimulation();
  void update();

private:
  int intersection;
  int k;
  int counter;
  string cnn;
  vector<string> streets;
  vector<TrafficLight> trafficLights;
  TrafficLight createTrafficLight(string, int, int);
};