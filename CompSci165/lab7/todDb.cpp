// Lab 7b: todDb.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express
// Compiler(s) used: MS Visual C++ 2010 Express

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;


#include <cctype>
using std::toupper;

//struct definition
struct tod
{
  int hour; // the hour, 0-23
  int minutes; //the minute, 0 -59
  int seconds; // the second, 0 - 59
  char descr[32]; // the description of the time of day
};

//function prototypes
void coutTod(const tod& t); //print out the 5 times

//main body
int main ()
{
  cout << "Lab 7b: todDb.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";
    
  //prompt user to use db or predefined times.
  tod theTime[]= {{00,0,0}, {00,0,0}, {00,0,0}, {00,0,0}, {00,0,0}};
  cout << "Would you like to read the time from \"todDb.dat\" (Y/N)?";
  char dbAnswer;
  cin >> dbAnswer;
  dbAnswer=toupper(dbAnswer);

  if(dbAnswer=='Y')
  {
    //Initialize and declare the time of noon, midnight, lunch time,
    //supper time, and bed time from todDb.dat
    ifstream fin;
    fin.open("todDb.dat",ios::in|ios::binary);
    for(int i=0;i<5;i++)
    {
      fin.read((char*)&theTime[i], sizeof(tod));
    }//for
    fin.close();
  }//if dbAnswer==Y

  //print out the 5 times using coutTod function
  cout << "The times are set to:\n";
  for(int i=0;i<5;i++)
    {
      coutTod(theTime[i]);
    }
  cout << endl << endl;
  
  //prompt user on whether or not to make changes 
  //to the data
  while(1)
  {
    //reminder of what the times are set to
    cout << "***********************************\n"
      << "***********************************\n"
      << "The current entries 0-4 are set to:" << endl;
    for(int i=0;i<5;i++)
    {
      cout << i << " =";
      coutTod(theTime[i]);
    }//for
    cout << "***********************************\n"
      << "***********************************\n\n\n";
    
    //prompt for change
    char answer;
    cout << "Would you like to make changes to any of the times? (Y/N): ";
    cin >> answer;
    answer = toupper(answer);
    cout << answer  << endl;
    
    //break if answer = N
    if(answer=='N') break;
    else
    {
      //User chooses the entry to modify
      cout << "Which entry would you like to change ? (0 - 4): ";
      int entry;
      cin >> entry;
      if(entry>4) continue;
      cout << "\n\n";

      //User modifies the entry selected.
      cout << "For entry " << entry << " please "
        <<"specify the time you want to implement "
        << "by doing HOUR MINUTES SECONDS\nEnter the time now:"
        << endl;
      cin >> theTime[entry].hour >> theTime[entry].minutes >> theTime[entry].seconds;
      cin.ignore(1000,10);
      cout << "The label to give the new time entry ? : ";
      cin.getline(theTime[entry].descr, 32);
    }//else
  }//while

  //Confirm that User wants to write
  //the changes to todDb.dat and execute
  //writing to todDb.dat
  cout << "Write changes to \"todDb.dat\" ? (Y/N)";
  char answer;
  cin >> answer;
  answer = toupper(answer);
  if(answer=='Y')
  {
    ofstream fout;
    fout.open("todDb.dat",ios::out|ios::binary);
    for(int i=0;i<5;i++)
    {
      fout.write((char*)&theTime[i], sizeof(tod));
    }//for
    fout.close();
  }//if
  else cout << "Not applying changes as requested, thanks for stopping by.\n\n";

  //post finished listings and exit program
  cout << "Final Results: \n";
  for(int i=0;i<5;i++)
  {
    cout << i << " =";
    coutTod(theTime[i]);
  }
  
  cout << "\n\nExiting program!" << endl;
}//main

//functions
//when called, prints the time
void coutTod(const tod& t)
{
  cout << t.descr << " is " << t.hour << ':';
  if(t.minutes< 10) cout << '0';
    cout << t.minutes << ':';
  if(t.seconds < 10) cout << '0';
    cout << t.seconds << endl;
}