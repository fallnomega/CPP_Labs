// Lab 11: History.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express
// Compiler(s) used: MS Visual C++ 2010 Express

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;


//class
class course
{
public:
  char nCourse[11];
  char term[7];
  int units;
  char grade;
  course *next;
};

//function
void coutClass(course* a);
int main()
{
  cout << "Lab 11 -  History.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";
  
  //setting up default link list
  course *head = 0; //empty linked list

  //give the blank listing
  cout << "Course Listing\n--------------\n";
  cout << "     Courses" << setw(15) <<"      Term" << setw(10) << "Units" <<setw(10) << "Grade\n"
    << "----------------------------------------------\n";  
  for(course* p=head;p;p=p->next) coutClass(p); 

  //prompt to enter new courses
  cout << "Would you like to add courses to the list? (y/n): ";
  char answer;
  cin >> answer;
  cin.ignore(1000,10);

  if(answer=='n')
  {
   cout << "Printing list before exiting program.\n\n"
     << "     Courses" << setw(15) <<"      Term" << setw(10) << "Units" <<setw(10) << "Grade\n"
     << "----------------------------------------------\n";  
   for(course* p=head;p;p=p->next) coutClass(p); 
   cout << endl;
  }//if
  else
  {
    while(true)
    {
      //get new entry
      cout << "Please enter new course name, term, units, and grade "
        << "with a space between them.\nExample: compsc-110 fa2009 4 a\n";
      course* newCourse = new course;
      cin >> newCourse->nCourse;
      cin >> newCourse->term;
      cin >> newCourse->units;
      cin >> newCourse->grade;
      newCourse->next = head;
      head = newCourse;

      //show new node on the current list
      cout << "\n\nNew Course Listing\n------------------\n"
		<< "     Courses" << setw(15) <<"      Term" << setw(10) << "Units" <<setw(10) << "Grade\n"
        << "----------------------------------------------\n";  
      for(course* p=head;p;p=p->next) coutClass(p); 

      //want to add more prompt
      cout << "\n\nContinue adding more course?(y/n):";
      char aanswer;
      cin >> aanswer;
      cin.ignore(1000,10);
      if(aanswer=='n')
      {
        cout << "Printing list before exiting program.\n\n"
          <<"     Courses" << setw(15) <<"Term" << setw(10) 
          << "Units" <<setw(10) << "Grade\n"
          << "----------------------------------------------\n"; 
        for(course* p=head;p;p=p->next) coutClass(p); 
        cout << endl;
        break;
      }//if
    }//while
  }//else


  //remove all nodes from listing
  while(head)
  {
    course* next = head->next;
    delete head;
    head=next;
  }//while
  
  cout << endl;
}//main

//functions
void coutClass(course* a)
{
  cout <<   setw(15) << a->nCourse <<setw(7) << " "<< a->term 
    << setw(6) <<  a->units <<  setw(8) << a->grade << endl;
}

