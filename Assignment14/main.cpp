/* Assignment 14 by Ethan Laur due Wednesday 18, 2012
 * This program will create a new instance of a car,
 * and increase its speed 5 times.  The class (though
 * commented out) has the ability for faster and slower
 * cars, just in case you wanted to race... */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;
class Car
{
private: //just for the sake of making sure we did this
    int yearModel;
    string make;
    int speed;
    //int acceleration; //the rate at which the car accelerates
    //int brakespeed; //the speed at which the car slows down
    //int position; //sample position in a race
public:
    Car(int, string);
    //Car(int,int,int,string); //year,acceleration,brakespeed,make
    int getmodel(void);
    //int getposition(void); //for the racecar version
    string getmake(void);
    int getspeed(void);
    void accelerate(void);
    void brake(void);
};
Car::Car(int _, string __)
{
    yearModel = _;
    make = __;
    speed = 0;
    cout << "New car created: " << yearModel << " " << make << endl;
}
/*Car::Car(int _,int __,int ___, string ____) //for the racecar version
{
    yearModel = _;
    acceleration = __;
    brakespeed = ___
    make = ____;
    speed = 0;
    cout << "New car created: " << yearModel << " " << make << endl;
}*/
int Car::getmodel(void)
{
    return yearModel;
}
/*int Car::getposition(void) //returns the position for the racecars
{
    return position;
}*/
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
    //speed += acceleration; //for the racecar version
}
void Car::brake(void)
{
    speed -= 5;
    //speed -= brakespeed; //for the racecar version
}
int main()
{
    cout << "What is the make of your car? ";
    string make;
    cin >> make;
    cout << "What is the model year? ";
    int model;
    cin >> model;
    Car * rlyfastcar = new Car(model,make); //create a really fast car
    int i; //for the sake of using the same variable
    cout << rlyfastcar->getspeed() << endl;
    for (i=0;i<5;i++) //loop 5 times
    {
        rlyfastcar->accelerate();
        cout << rlyfastcar->getspeed() << endl;
    }
    for (i=0;i<5;i++) //loop 5 times
    {
        rlyfastcar->brake();
        cout << rlyfastcar->getspeed() << endl;
    }
    delete rlyfastcar; //make the car go boom boom
    return 0;
}
