
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

/////////////
//functions//
/////////////

//PRINT LABELS
void course::header()
{
  cout << "\n\nCourse Listing\n-----------------------------------------------\n"
    << "     Courses" << setw(15) <<"      Term" << setw(10) << "Units" <<setw(10) << "Grade\n"
    << "-----------------------------------------------\n";
}

//PRINT COURSE
void course::coutClass() //print course listings
{
  course* head=this;
  for(course* p=head;p;p=p->next)
  {
    cout <<   setw(15) << p->nCourse <<setw(7) << " "<< p->term
      << setw(6) <<  p->units <<  setw(8) << p->grade << endl;
  }
}

//RESTORE FROM courses.dat
course* course::restoreList()
{
  ifstream fin;
  fin.open("courses.dat",ios::binary|ios::in);
  if(!fin) return this;
    
  //read in the number of objects from the disk file
  int nCount;
  fin.read((char*)&nCount, sizeof(int));
  
  //read the objects from the disk file
  course* newHead=this; //new list
  for(int i=0;i<nCount;i++)
  {
    course* newCourse = new course;
    fin.read((char*)newCourse, sizeof(course));
    toLower(newCourse->nCourse);
    newCourse->grade=tolower(newCourse->grade);
    newHead=newCourse->insert(newHead);
  }
  fin.close();
  return newHead;  
}

//SAVE TO courses.dat
void course::saveList()
{
  course* head = this;
  int nCount = 0;
  for(course* p=head;p;p=p->next) nCount++;
  ofstream fout;
  fout.open("courses.dat",ios::out|ios::binary);
    
  //process list to file   
  fout.write((char*)&nCount, sizeof(int));
  for(course* p=head;p;p=p->next)
  {
    fout.write((char*)p, sizeof(course));
  }
  fout.close();
}
//ADD CLASSES
course* course::AddClass()//add class
{
  //get new entry
  cout << "Please enter new course name, term, units, and grade "
    << "with a space between them.\nExample: compsc-110 fa2009 4 a\n";
  course* newCourse = new course;
  cin >> newCourse->nCourse;
  cin >> newCourse->term;
  cin >> newCourse->units;
  cin >> newCourse->grade;
  toLower(newCourse->nCourse);
  newCourse->grade = tolower(newCourse->grade);
  course* head;
  head=this;
  head = newCourse->insert(this);//call
  return head;
}
//INSERT CLASSES ADDED IN AddClass
course* course::insert( course* head) //insertion
{
  course* p, *prev;
  course* t = this;
  for (p=head, prev=0; p; prev=p, p=p->next);
  t->next = p; // p is zero
  if (prev) // pointer to last node
    prev->next = t;
  else // empty list, new node is 1st node
    head = t;
  return head;
}

//UNIT
course* course::sortByUnit() //sort by unit
{
  course* newHead=0; //a new empty list
  course* oldHead=this; // the original list
  while(oldHead)
  {
    course* t = oldHead; // get node from old list
    oldHead= oldHead->next; //remove node from old list
    newHead=t->compareUnits(newHead);//compare and insert 
  }
  return newHead;
}//byUnit

course* course::compareUnits(course* h)
{
  course* p, *prev;
  course* t = this;
  for (p=h, prev=0; p; prev=p, p=p->next)
    if (t->compareUCmp(p) < 0) // if "t" precedes "p"...
      break; // "t" goes between "prev" and "p"
  t->next = p; // "t" inserted before "p"
  if (prev) // "t" inserted after "prev"
    prev->next = t;
  else // "t" added to front of list
    h = t;
  return h;
}

int course::compareUCmp(const course* src)
{
  //handle ties here
  course* dst = this;
  int unitA = dst->units; //dst redefined to unitA
  int unitB = src->units;//src redefined to unitB
  if(dst->units==src->units)//if equal...
    return myStricmp(dst->nCourse,src->nCourse); //sort by description
    
  //compare the units
  if(unitA<unitB)
    return -1; //unitA comes first
  if(unitA>unitB)
    return 1; //unitB comes first
  return 1;
}

//GRADE SORT
course* course::sortByGrade()
{
  course* newHead=0; //a new empty list
  course* oldHead=this; // the original list
  while(oldHead)
  {
    course* t = oldHead; // get node from old list
    oldHead= oldHead->next; //remove node from old list        
    newHead=t->compareGrade(newHead);//compare and insert      
  }
  return newHead;
}//sort by grade

course* course::compareGrade(course* h)
{
  course* p, *prev;
  course* t = this;
  for (p=h, prev=0; p; prev=p, p=p->next)
    if (t->compareGCmp(p) < 0) // if "t" precedes "p"...
      break; // "t" goes between "prev" and "p"
  t->next = p; // "t" inserted before "p"
  if (prev) // "t" inserted after "prev"
    prev->next = t;
  else // "t" added to front of list
    h = t;
  return h;
}

char course::compareGCmp( const course* src)
{
  //handle ties here
  course* dst = this;
  char gradeA = tolower(dst->grade); //dst redefined to unitA.
  char gradeB = tolower(src->grade);//src redefined to unitB.
  if(gradeA==gradeB)//if equal, go based on year course taken
  {
    //compare the years
    int yearA = atoi(dst->term+2);//ignore semester, skip to year
    int yearB = atoi(src->term+2);
    if(yearA<yearB)
      return -1; //termA comes first
    if(yearA>yearB)
      return 1; //termB comes first
  }
  //compare the grades
  if(gradeA<gradeB)
    return -1; //gradeA comes first
  if(gradeA>gradeB)
    return 1; //gradeB comes first
  return 1;
}

//DESCRIPTION SORT
course* course::sortByDescription() //sort by description
{
  course* newHead=0; //a new empty list
  course* oldHead=this; // the original list
  while(oldHead)
  {
    course* t = oldHead; // get node from old list
    oldHead= oldHead->next; //remove node from old list       
    newHead=t->compareDescr(newHead);//compare and insert
  }
  return newHead;
}

course* course::compareDescr(course* h)
{
  course* p, *prev;
  course* t =this;
  for (p=h, prev=0; p; prev=p, p=p->next)
    if (t->compareDCmp(p) < 0) // if "t" precedes "p"...
      break; // "t" goes between "prev" and "p"
  t->next = p; // "t" inserted before "p"
  if (prev) // "t" inserted after "prev"
    prev->next = t;
  else // "t" added to front of list
    h = t;
  return h;
}

char course::compareDCmp( const course* src)
{
  //handle ties here
  course* dst = this;
  if(myStricmp(dst->nCourse,src->nCourse)==0)
    return dst->compareGCmp(src);//if tie, sort based on grade
  else return myStricmp(dst->nCourse,src->nCourse);
}

//TERM SORT
course* course::sortByTerm()//sort by term
{
  course* newHead=0; //a new empty list
  course* oldHead=this; // the original list
  while(oldHead)
  {
    course* t = oldHead; // get node from old list
    oldHead= oldHead->next; //remove node from old list
    newHead=t->compareTerm(newHead);//compare and insert      
  }
  return newHead;
}//sort by term

course* course::compareTerm(course* h) //insertion method
{
  course* p, *prev;
  course* t = this;
  for (p=h, prev=0; p; prev=p, p=p->next)
    if (t->courseCmp(p) < 0) // if "t" precedes "p"...
      break; // "t" goes between "prev" and "p"
  t->next = p; // "t" inserted before "p"
  if (prev) // "t" inserted after "prev"
    prev->next = t;
  else // "t" added to front of list
    h = t;
  return h;
}

int course::courseCmp(const course* b) // header
{ 
  //validate the length
  if((strlen(this->term) !=6) || (strlen(b->term) !=6)) // .. in cstring
    return myStricmp(this->nCourse, b->nCourse);
  if(myStricmp(this->term, b->term)==0)
    return myStricmp(this->nCourse, b->nCourse);

  //handle ties here
  if(myStricmp(this->term, b->term)==0)
    return myStricmp(this->nCourse,b->nCourse);
   
  //compare the years
  int yearA = atoi(this->term + 2); //atoi is found ...
  int yearB = atoi(b->term+2);//..in cstlib
  if(yearA<yearB)
    return -1; //termA comes first
  if(yearA>yearB)
    return 1; //termB comes first
    
  //compare semesters in case of same year
  if(myStrnicmp(this->term, "SP", 2) == 0)
    return -1; //termA comes first
  if(myStrnicmp(this->term,"SU",2) == 0)
    return myStrnicmp(b->term,"SP",2) ? -1: 1;
  return 1;
}
//MISC FUNCTIONS
int course::myStricmp(const char* dst, const char* src)
{
  int f, l;
  do
  {
    if (((f = (unsigned char)(*(dst++))) >= 'A') && (f <= 'Z')) f -= 'A' - 'a';
    if (((l = (unsigned char)(*(src++))) >= 'A') && (l <= 'Z')) l -= 'A' - 'a';
  } while (f && (f == l));
  return(f - l);
}
int course::myStrnicmp(const char* dst, const char* src, int count)
{
  int f, l; 
  do
  {
    if (((f = (unsigned char)(*(dst++))) >= 'A') && (f <= 'Z')) f -= 'A' - 'a';
    if (((l = (unsigned char)(*(src++))) >= 'A') && (l <= 'Z')) l -= 'A' - 'a';
  } while (--count && f && (f == l));
  return (f - l);
}
void course::clearList()//clear list
{
  course* head = this;
  while(head)
  {
    course* next = head->next;
    delete head;
    head=next;
  }//while
}

void course::toLower(char str[])
{
  for(int i=0;str[i]!=0;i++)
  {
    str[i] = tolower(str[i]);
  }
}