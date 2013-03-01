// Lab 6: todA.cpp
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
void coutTod(int, const tod[]); //n = number of items in the array
long diffTod(const tod&, const tod&);// difference between two times
int isAfter(const tod&, const tod&); //true if 1st is after 2nd
int isBefore(const tod&, const tod&);// true if 1st is before 2nd

//main body
int main ()
{
  cout << "Lab 6: todA.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";
  
  
  // declare and initialize the time of noon, midnight, lunch time, supper time, and bed time.
  tod theTime[] ={{12,0,0,"Noon"}, {00,0,0,"Midnight"}, {12,30,00,"Lunch Time"}, {17,15,30, "Supper Time"}, {22,45,17,"Bed Time"}};

  //print out the 5 times using coutTod function
  cout << "The times are set to:\n";
  coutTod(5, theTime);
  cout << endl << endl;
   
  //3 differences of time called using function(diffTod)
  //and results printed
  cout << "Measuring the time difference in seconds between two times:\n";
  //first
  cout << "The difference between " << theTime[0].descr;
    cout << " and " << theTime[3].descr << " in seconds is ";
    cout << diffTod(theTime[0], theTime[3]) << endl;
  //second
  cout << "The difference between " << theTime[1].descr;
    cout << " and " << theTime[4].descr << " in seconds is ";
    cout << diffTod(theTime[1], theTime[4]) << endl;
  //third
  cout << "The difference between " << theTime[3].descr;
    cout << " and " << theTime[2].descr << " in seconds is ";
    cout << diffTod(theTime[3], theTime[2]) << endl;
  cout << endl << endl;

  //3 before or after statements called using
  //isBefore or isAfter functions and then  printed
  cout << "Comparing whether the time is before or after another time:\n";
  //first
  if(isBefore(theTime[0], theTime[3]))
    cout << theTime[0].descr << " is before " << theTime[3].descr << endl;
  else
    cout << theTime[0].descr << " is not before " << theTime[3].descr << endl;
  //second
  if(isAfter(theTime[4], theTime[1]))
    cout << theTime[4].descr << " is after " << theTime[1].descr << endl;
  else
    cout << theTime[4].descr << " is not after " << theTime[1].descr << endl;
  //third
  if(isBefore(theTime[2], theTime[1]))
    cout << theTime[2].descr << " is before " << theTime[1].descr << endl;
  else
    cout << theTime[2].descr << " is not before " << theTime[1].descr << endl;
  cout << endl;
}//main

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

//puts a call to coutTod(const tod& t)
void coutTod(int n, const tod t[])//n = number of items in the array
{
  //print the time using coutTod(const tod& t)
  for(int i=0;i<n;i++)
  {
    coutTod(t[i]);
  } //for
}

// difference between two times
long diffTod(const tod& t1, const tod& t2)
{
  long dif =  (((long)(t1.hour - t2.hour) *3600L)
    + ((long)(t1.minute - t2.minute) * 60L)
    + (long)(t1.second - t2.second));
  return dif;
}

//compares if time 1 is after time 2
int isAfter(const tod& t1, const tod& t2) //true if 1st is after 2nd
{
  int result = diffTod(t1, t2);
  if (result>0) return 1;
  else return 0;
}

//compares if time 1 is before time 2
int isBefore(const tod& t1, const tod& t2) // true if 1st is before 2nd
{
  int result = diffTod(t1, t2);
  if (result<0) return 1;
  else return 0;
}