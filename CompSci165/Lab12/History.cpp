// Lab 12: History.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express
// Compiler(s) used: MS Visual C++ 2010 Express

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstring>
#include <cstdlib>


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
void coutClass(course* a); //print class
void clearList(course* head);//delete list
course* insert(course*, course*); // insertion 
int courseCmp(const course*, const course*); //compare course
int myStricmp(const char* dst, const char* src); //semester compare
int myStrnicmp(const char* dst, const char* src, int count);//tie breaker


////////
//main//
////////
int main()
{
  cout << "Lab 12:  History.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";
  
  //setting up default link list
  course *head = 0; //empty linked list

  /////////////
  //insertion//
  /////////////
  cout << "\n\nCourse Listing\n-----------------------------------------------\n"
    << "     Courses" << setw(15) <<"      Term" << setw(10) << "Units" <<setw(10) << "Grade\n"
    << "-----------------------------------------------\n";  
  for(course* p=head;p;p=p->next) coutClass(p); 

  //prompt to enter new courses
  cout << "\n\nWould you like to add to the listing [y/n]?> ";
  char answer;
  cin >> answer;
  cin.ignore(1000,10);
  if(answer=='n')
  {
   cout <<"\n\nGood bye!" << endl;
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
      head =insert(newCourse,head);//call
    
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
        cout << "\n\nCourse Listing\n-----------------------------------------------\n"
          << "     Courses" << setw(15) <<"      Term" << setw(10) << "Units" <<setw(10) << "Grade\n"
          << "-----------------------------------------------\n";  
        for(course* p=head;p;p=p->next) coutClass(p); 
        cout << "Bye" << endl;
        break;
      }//if
    }//while
  }//else

  //remove all nodes from listing
  clearList(head);
  cout << endl;
}//main


/////////////
//functions//
/////////////
void coutClass(course* a) //print course listings
{
  cout <<   setw(15) << a->nCourse <<setw(7) << " "<< a->term 
    << setw(6) <<  a->units <<  setw(8) << a->grade << endl;
}

void clearList(course* head)//clear list
{
    while(head)
  {
    course* next = head->next;
    delete head;
    head=next;
  }//while
}
course* insert(course* t, course* h) //insertion method 
{ 
  course* p, *prev; 
  for (p=h, prev=0; p; prev=p, p=p->next)
    if (courseCmp(t, p) < 0) // if "t" precedes "p"... 
      break; // "t" goes between "prev" and "p"
  t->next = p; // "t" inserted before "p" 
  if (prev) // "t" inserted after "prev" 
    prev->next = t; 
  else // "t" added to front of list 
    h = t; 
  return h; 
}
// COMPARE function for above
int courseCmp(const course* a, const course* b) // header 
{ 
  //validate the length
  if((strlen(a->term) !=6) || (strlen(b->term) !=6)) // .. in cstring
    return myStricmp(a->nCourse, b->nCourse);
  if(myStricmp(a->term, b->term)==0) 
  return myStricmp(a->nCourse, b->nCourse);

  //handle ties here
  if(myStricmp(a->term, b->term)==0)
    return myStricmp(a->nCourse,b->nCourse);

  //compare the years
  int yearA = atoi(a->term + 2); //atoi is found ...
  int yearB = atoi(b->term+2);//..in cstlib
  if(yearA<yearB)
    return -1; //termA comes first
  if(yearA>yearB)
    return 1; //termB comes first

  //compare semesters in case of same year
  if(myStrnicmp(a->term, "SP", 2) == 0)
    return -1; //termA comes first
  if(myStrnicmp(a->term,"SU",2) == 0)
    return myStrnicmp(b->term,"SP",2) ? -1: 1;
  return 1;
}

int myStricmp(const char* dst, const char* src)
{
  int f, l;
  do
  {
    if (((f = (unsigned char)(*(dst++))) >= 'A') && (f <= 'Z')) f -= 'A' - 'a';
    if (((l = (unsigned char)(*(src++))) >= 'A') && (l <= 'Z')) l -= 'A' - 'a';
  } while (f && (f == l));
  return(f - l);
}

int myStrnicmp(const char* dst, const char* src, int count)
{
  int f, l; 
  do
  {
    if (((f = (unsigned char)(*(dst++))) >= 'A') && (f <= 'Z')) f -= 'A' - 'a';
    if (((l = (unsigned char)(*(src++))) >= 'A') && (l <= 'Z')) l -= 'A' - 'a';
  } while (--count && f && (f == l));
  return (f - l);
}