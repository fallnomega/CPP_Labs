// Lab 8a: pPrimer.cpp
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


int main ()
{
  cout << "Lab 8a: pPrimer.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";
  
  // declare and initialize garbage times.
  tod theTime[] ={{}, {}, {}, {}, {}};

  //print out the memory garbage tod's in main
  //along with int i object before it begins
  //its for loop cycle
  int i;
  cout << "Int i in memory is located at: " << &i <<
    "\n\nMemory locations for Time of Day\n--------------------------------\n";
  for(i=0;i<5;i++)
    {
      cout << "Time of Day[" << i  << "] is " << &theTime[i]
        <<"\ntheTime[" << i <<"].hour is located at " << &theTime[i].hour
        <<"\ntheTime[" << i <<"].minute is located at " << &theTime[i].minute
        <<"\ntheTime[" << i <<"].second is located at " << &theTime[i].second
        <<"\ntheTime[" << i <<"].descr is located at " << &theTime[i].descr << endl << endl << endl;
    }//for
  
  //tod size output
  cout << "Size of tod = " << sizeof(tod) << 
    "\nSize of tod pointers = " << sizeof(tod*) << endl;
}//main