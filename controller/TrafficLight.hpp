#include <string>
using namespace std;

class TrafficLight
{
public:
  TrafficLight(string, int, int);
  int getState();
  void switchColor();
  int getRemainingTime();
  void updateRemainingTime();
  string getStreetName();

private:
  string streetName;
  int state;
  int lengthGreen;
  int lengthYellow;
  int remainingTime;
};
