// Lab 3
// Programmer: Jason Hillin
// Editor(s) used: Xcode & MS Visual C++ 2010 Express
// Compiler(s) used: g++

#include <iostream>
using std::cout;
using std::endl;

//function prototype(s)
int avg(int, int);
double avg(double, double);

int main()
{
cout << "Lab 3: Avg.cpp\n";
cout << "Programmer: Jason Hillin\n\n";
//averageing ints
cout << "*Integer averages*\n";
cout << "The average of 4 and 6 is " << avg(4,6) << endl;
cout << "The average of 15 and 45 is " << avg(15,45) << endl;
cout << "The average of 350 and 612 is " << avg(350,612) << endl;

//averaging floats
cout << "\n*Float averages*\n";
cout << "The average of 10.5 and 12.5 is " << avg(20.0, 27.7) << endl;
cout << "The average of 10.5 and 12.5 is " << avg(49.2, 110.5) << endl;
cout << "The average of 10.5 and 12.5 is " << avg(1119.8, 15019.7) << endl;
}

//return average of two integers
int avg (int a,int b) //"a" and "b" are the two numbers to be averaged
{
  return (a+b)/2; //return the average of "a" and "b"
}
//return average of two floats
double avg (double a,double b) //"a" and "b" are the two numbers to be averaged
{
  return (a+b)/2.0; //return the average of "a" and "b"
}