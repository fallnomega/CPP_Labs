// Lab 6a: Time.h
// Programmer: Jason Hillin
// Editor(s) used: VS 2010 Express
// Compiler(s) used: VS 2010 Express
//

#ifndef TIME_H
#define TIME_H

class Time
{
public:
  Time(int=0,int=0,int=0);//default constructor

  //set functions( the Time & return types enaable cascading)
  Time &setTime (int, int,int); //set Time
  Time &setHour(int);//set hour
  Time &setMinute(int);//set minute
  Time &setSecond(int);//set second

  //get functions(normally declared const)
  int getHour() const; //return hour
  int getMinute() const;//return minute
  int getSecond() const;//return second

  //print functions
  void printUniversal() const; //print Universal time
  void printStandard() const; //print Standard time
private:
  int hour;//0-23 (24 hour clock format)
  int minute;//0-59
  int second;//0-59
}; //end class Time

#endif
