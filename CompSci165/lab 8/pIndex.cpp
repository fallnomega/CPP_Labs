// Lab 8c: pIndex.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express
// Compiler(s) used: MS Visual C++ 2010 Express

#include <iostream>
using std::cout;
using std::endl;

//struct definition
struct tod
{
  int hour; // the hour, 0-23
  int minute; //the minute, 0 -59
  int second; // the second, 0 - 59
  char descr[32]; // the description of the time of day
};

//function prototypes
void coutTod(const tod& t); //print out the 5 times

int main ()
{
  cout << "Lab 8c: pIndex.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";

  // declare and initialize the time of noon, midnight, lunch time, supper time, and bed time.
  tod theTime[] ={{12,0,0,"Noon"}, {00,0,0,"Midnight"}, {12,30,00,"Lunch Time"}, {17,15,30, "Supper Time"}, {22,45,17,"Bed Time"}};

  //original order of times
  cout << "Original Time\n-------------\n";
  for(int i=0;i<5;i++) coutTod(theTime[i]);
  cout << endl << endl;
  
  //chronological index going from earliest to least:
  //midnight, noon,lunch time, supper time, and bed time
  tod* tIndex[5]= {&theTime[1],&theTime[0],&theTime[2],&theTime[3],&theTime[4]};
  cout << "Chronological Order\n-------------------\n";
  for(int i=0;i<5;i++) coutTod(*tIndex[i]);
  cout << endl << endl;

  //alphabetical index going:
  //bed time,lunch time, midnight, noon, and  supper time
  tod* aIndex[5]= {&theTime[4],&theTime[2],&theTime[1],&theTime[0],&theTime[3]};
  cout << "Alphabetical Order\n-------------------\n";
  for(int i=0;i<5;i++) coutTod(*aIndex[i]);
  cout << endl << endl;
}

//functions

//when called, prints the time
void coutTod(const tod& t)
{
  cout << t.descr << " is " << t.hour << ':';
    if(t.minute< 10) cout << '0';
      cout << t.minute << ':';
    if(t.second < 10) cout << '0';
      cout << t.second << endl;
}