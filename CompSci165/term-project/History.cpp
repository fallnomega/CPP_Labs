// Term Project: History.cpp
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
  cout << "Term Project:  History.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";
  
  //setting up default link list
  course *head = 0; //empty linked list
    
  /////////////////////////////////
  //prompt user to pull from file//
  /////////////////////////////////
  cout << "Pull courses from courses.dat ? [y/n]> ";
  char finAnswer=course::getYesNo();
  if(finAnswer=='n') cout << "Manual entry then\n\n";
  else
  {
    head=head->restoreList();
  }//else
  course::header();
  head->coutClass();

  ////////
  //MENU//  
  ////////
  while(true)
  {
    int choice = course::menu();
    ///////
    //add//
    ///////

    if(choice==1)
    {
      while(true)
      {
        head=head->AddClass();
        //want to add more prompt
        course::header();
        head->coutClass();
        cout << "\n\nContinue adding more course?(y/n):";
        char aanswer=course::getYesNo();
        if(aanswer=='n')
        {
          cout << "Moving along then" << endl;
          break;
        }//if
      }//while
    }//if choice 1 add
    
    //////////
    //delete//
    //////////

    if(choice==2)
    {
      course temp;
      head=head->deleteNode(head, temp); // call 

    }//if choice 2 delete

    ////////
    //list//
    ////////

    if(choice==3)
    {
      course::header();
      head->coutClass();
    }//if choice 3 list 

    ////////
    //sort//
    ////////

    if(choice==4)
    {
      ////////////////////////
      //sorting various ways//
      ////////////////////////
      cout << "\n\nSort by [1 - 4]:\n[1] Unit\n[2] Grade\n[3] Description\n[4] Term\n";
      int schoice;
      cin >> schoice;
      cin.ignore(1000,10);

      //sort by units
      if(schoice==1)
      {
        cout <<"\n\n////////////////////\n//Sorting by Units//\n////////////////////\n\n";
        course::header();
        head = head->sortByUnit();
        head->coutClass();
        cout << "\nEnter to continue\n";
        cin.get();
      }//sort by units

      //sort by grades
      if(schoice==2)
      {
        cout <<"\n\n/////////////////////\n//Sorting by Grades//\n/////////////////////\n\n";
        course::header();
        head = head->sortByGrade();
        head->coutClass();
        cout << "\nPress Enter to continue\n";
        cin.get();  
      }//sort by grades

      //sort by description
      if(schoice==3)
      {
        cout <<"\n\n///////////////////////\n//Sort by Description//\n///////////////////////\n\n";
        course::header();
        head = head->sortByDescription();
        head->coutClass();
        cout << "\nPress Enter to continue\n";
        cin.get();  
      }//sort by description

      //sort by term
      if(schoice==4)
      {
        cout << "\n\n////////////////\n//Sort by Term//\n////////////////\n\n";
        course::header();
        head = head->sortByTerm();
        head->coutClass();
        cout << "\nPress Enter to continue\n";
        cin.get();
      }//sort by term
    }//if choice 4 sort

    ////////
    //quit//
    ////////

    if(choice==5)
    {
          ///////////////////////////////////////////////////////
          //save to courses.dat file section before exit prompt//
          ///////////////////////////////////////////////////////
    
          cout << "Save new entries to courses.dat? [y/n]? > ";
          char foutAnswer=course::getYesNo();;
          if(foutAnswer=='n') cout << "Ending Class Application without Saving" << endl;
          else
          {
            cout << "Saving to courses.dat\n" << endl;
            head->saveList();
          }
      cout << "Have a nice day!\n";
      break;
    }//if choice 5 quit

  }//while
  /////////////////////////////////  
  //remove all nodes from listing//
  /////////////////////////////////

  head->clearList();
  cout << endl;
}//main
