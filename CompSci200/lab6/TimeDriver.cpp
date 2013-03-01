// Lab 6a: TimeDriver.cpp
// Programmer: Jason Hillin
// Editor(s) used: VS 2010 Express
// Compiler(s) used: VS 2010 Express
//

#include "Time.h"
#include "Time.h"//test ifndef
#include <iostream>
using std::cout;
using std::endl;

int main()
{
  cout << "Programmer: Jason Hillin\nLab 6a: TimeDriver.cpp"
    << "\nDescription: Time Driver to test class Time\n\n";
  //original copy run through all functions in class
  cout << "Original chrono Time object" << endl;
  const Time chrono(07,27,37);
  chrono.printStandard();
  chrono.printUniversal();


  //copy of chrono using assignment upon declaration 
  cout << "\nCopy of chrono using assignment upon declaration: " << endl;
  const Time copyChrono = chrono;
  chrono.printStandard();
  chrono.printUniversal();

  //copy of flash using assignment after declaration
  cout << "\nCopy of chrono using assignment after declaration: " << endl;
  Time copyCopyChrono;
  copyCopyChrono = chrono;
  copyCopyChrono.printStandard();
  copyCopyChrono.printUniversal();
  
  cout << "\nTesting setTime with a copy of chrono to change time to 10:13:05\n";
  copyCopyChrono.setTime(10,13,5);
  copyCopyChrono.printStandard();
  copyCopyChrono.printUniversal();

  cout << "\nUsing erroneous hour, minute, and second for setters to update copy of chrono: " << endl;
  copyCopyChrono.setHour(26);
  copyCopyChrono.setMinute(99);
  copyCopyChrono.setSecond(87);
  copyCopyChrono.printStandard();
  copyCopyChrono.printUniversal();

  //test time getters (minus print getters)
  cout << "\nTest Time segment getters (minus print getters) using copy of chrono" << endl;
  cout << copyChrono.getHour() << " - hour, " << copyChrono.getMinute() << " - minute, "
    << copyChrono.getSecond() << " - second";

  cout << endl;
}