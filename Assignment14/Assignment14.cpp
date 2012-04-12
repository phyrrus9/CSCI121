#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;
class Car{  int yearModel;  string make;  int speed;  public:  car(int *, string);  int getmodel(void);  char * getmake(void);  int getspeed(void);
  void accelerate(void);
  void brake(void);
};
Car::car(int _, string __)
{
  yearModel = _;
  make = __;
  speed = 0;
}
int Car::getmodel(void)
{
  return yearModel;
}
string Car::getmake(void)
{
  return make;
}
int Car::getspeed(void)
{
  return speed;
}
void Car::accelerate(void)
{
  speed += 5;
}
void Car::brake(void)
{
  speed -= 5;
}
int main()
{
  Car * rlyfastcar; //create a really fast car
  int i; //for the sake of using the same variable
  for (i=0;i<5;i++) //loop 5 times
  {
    rlyfastcar->accelerate();
    //cout << rlyfastcar->getspeed() << endl;
  }
  for (i=0;i<5;i++) //loop 5 times
  {
    rlyfastcar->brake();
    //cout << rlyfastcar->getspeed() << endl;
  }
  return 0;
}