// Lab 16: History.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express and X-Code
// Compiler(s) used: MS Visual C++ 2010 Express and g++

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

#include <cstring>
#include <cstdlib>
#include <cctype>

#include "course.h"

/////////
//class//
/////////



////////
//main//
////////
int main()
{
  cout << "Lab 16:  History.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";
   
  //setting up default link list
  course *head = 0; //empty linked list
    
  /////////////////////////////////
  //prompt user to pull from file//
  /////////////////////////////////
  cout << "Pull courses from courses.dat ? [y/n]> ";
  char finAnswer;
  cin >> finAnswer;
  cin.ignore(1000,10);
  if(finAnswer=='n') cout << "Manual entry then\n\n";
  else
  {
    head=head->restoreList();
  }
    
  /////////////
  //insertion//
  /////////////
  course::header();
  head->coutClass();
  
  //prompt to enter new courses
  cout << "\n\nWould you like to add to the listing [y/n]?> ";
  char answer;
  cin >> answer;
  cin.ignore(1000,10);
  if(answer=='n')
  {
    cout <<"\n\nMoving along then!" << endl;
  }//if
  else
  {
    while(true)
    {
      head=head->AddClass();
      //want to add more prompt
      course::header();
      head->coutClass();
      cout << "\n\nContinue adding more course?(y/n):";
      char aanswer;
      cin >> aanswer;
      cin.ignore(1000,10);
      if(aanswer=='n')
      {
        ////////////////////////////////////////////////
        //save to courses.dat file section before sort//
        ////////////////////////////////////////////////
    
        cout << "Save new entries to courses.dat? [y/n]? > ";
        char foutAnswer;
        cin >> foutAnswer;
        cin.ignore(1000,10);
        if(foutAnswer=='n') cout << "Ending Class Additions without Saving" << endl;
        else
        {
          cout << "Saving to courses.dat\n" << endl;
          head->saveList();
        }
        cout << "Moving along then" << endl;
        break;
      }//if
    }//while
  }//else
      
  ////////////////////////
  //sorting various ways//
  ////////////////////////
  cout << "\nTime for some CRAZY SORTING!\n\n";
  cout << "The course listing unsorted\n";
  course::header();
  head->coutClass();
  cout << "\n\nPress Enter to continue to the sorting shenanigans\n";
  cin.get();
  cout <<"\n\nSort by Units\n--------\n";
  course::header();
  head = head->sortByUnit();
  head->coutClass();
  cout << "\nEnter to continue\n";
  cin.get();
  cout <<"\n\nSort by Grades\n---------\n";
  course::header();
  head = head->sortByGrade();
  head->coutClass();
  cout << "\nPress Enter to continue\n";
  cin.get();  
  cout <<"\n\nSort by Description\n\n--------------\n";
  course::header();
  head = head->sortByDescription();
  head->coutClass();
  cout << "\nPress Enter to continue\n";
  cin.get();  
  cout << "\n\nSort by Term\n-------\n";
  course::header();
  head = head->sortByTerm();
  head->coutClass();
  cout << "\nPress Enter to continue\n";
  cin.get();
    
  //remove all nodes from listing
  head->clearList();
  cout << endl;
}//main
