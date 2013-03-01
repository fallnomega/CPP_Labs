// Lab 13: History.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express and XCode
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

/////////
//class//
/////////
class course
{
public:
    char nCourse[11];
    char term[7];
    char units;
    char grade;
    course *next;
};
////////////
//function//
////////////
void header();//display labels
void coutClass(course* a); //print class 1
course* restoreList(course* head);//restore from courses.dat 1
void saveList(course* head, int nCount);//write to courses.dat 1
course* AddClass(course* head);//add class 1
course* insert(course*, course*); // insertion 1
course* sortByUnit(course* head); //sort by unit1
course* compareUnits(course* t, course* h);//compare by unit1
int compareUCmp(const course* dst, const course* src);
course* sortByGrade(course* head); //sort by grade
course* compareGrade(course* t, course* h);
char compareGCmp(const course* dst, const course* src);
course* sortByDescription(course* head); //sort by description
course* compareDescr(course* t, course* h);
char compareDCmp(const course* dst, const course* src);
course* sortByTerm(course* head); //SORT BY TERM
course* compareTerm(course* t, course* h);//COMPARE BY TERM
int courseCmp(const course*, const course*); //compare course
int myStricmp(const char* dst, const char* src); //semester compare
int myStrnicmp(const char* dst, const char* src, int count);//tie breaker
void clearList(course* head);//delete list

////////
//main//
////////
int main()
{
    cout << "Lab 13:  History.cpp\n";
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
        head = restoreList(head);
    }
    
    /////////////
    //insertion//
    /////////////
    header();
    for(course* p=head;p;p=p->next) coutClass(p);
    
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
            head=AddClass(head);
            //want to add more prompt
            
            header();
            for(course* p=head;p;p=p->next) coutClass(p);
            
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
                    cout << "Saving to courses.dat" << endl;
                    int nCount=0;
                    for(course* p=head;p;p=p->next) nCount++;
                    saveList(head,nCount);
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
    header();
    for(course* p=head;p;p=p->next) coutClass(p);
    
    cout << "\n\nPress Enter to continue to the sorting shenanigans\n";
    cin.get();
    cout <<"\n\nSort by Units\n--------\n";
    header();
    head = sortByUnit(head);
    for(course* p=head;p;p=p->next) coutClass(p);
    cout << "\nEnter to continue\n";
    cin.get();
    
    cout <<"\n\nSort by Grades\n---------\n";
    header();
    head = sortByGrade(head);
    for(course* p=head;p;p=p->next) coutClass(p);
    cout << "\nPress Enter to continue\n";
    cin.get();
    
    cout <<"\n\nSort by Description\n\n--------------\n";
    header();
    head = sortByDescription(head);
    for(course* p=head;p;p=p->next) coutClass(p);
    cout << "\nPress Enter to continue\n";
    cin.get();
    
    cout << "\n\nSort by Term\n-------\n";
    header();
    head = sortByTerm(head);
    for(course* p=head;p;p=p->next) coutClass(p);
    cout << "\nPress Enter to continue\n";
    cin.get();
    
    //remove all nodes from listing
    clearList(head);
    cout << endl;
}//main

/////////////
//functions//
/////////////
//PRINT LABELS
void header()
{
    cout << "\n\nCourse Listing\n-----------------------------------------------\n"
    << "     Courses" << setw(15) <<"      Term" << setw(10) << "Units" <<setw(10) << "Grade\n"
    << "-----------------------------------------------\n";
}
//PRINT COURSE
void coutClass(course* a) //print course listings
{
    cout <<   setw(15) << a->nCourse <<setw(7) << " "<< a->term
    << setw(6) <<  a->units <<  setw(8) << a->grade << endl;
}
//RESTORE FROM courses.dat
course* restoreList(course* head)
{
    ifstream fin;
    fin.open("courses.dat",ios::binary|ios::in);
    if(!fin) return head;
    
    //read in the number of objects from the disk file
    int nCount;
    fin.read((char*)&nCount, sizeof(int));
    //read the objects from the disk file
    course* newHead=head; //new list
    for(int i=0;i<nCount;i++)
    {
        course* newCourse = new course;
        fin.read((char*)newCourse, sizeof(course));
        newHead=insert(newCourse,newHead);
    }
    fin.close();
    return newHead;
    
}
//SAVE TO courses.dat
void saveList(course* head, int nCount)
{
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
//GET CLASSES
course* AddClass(course* head)//add class
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
    return head;
}
//INSERT CLASSES ADDED IN AddClass
course* insert(course* t, course* head) //insertion
{
    course* p, *prev;
    for (p=head, prev=0; p; prev=p, p=p->next);//to self: for the love of god remember the ;
    t->next = p; // p is zero
    if (prev) // pointer to last node
        prev->next = t;
    else // empty list, new node is 1st node
        head = t;
    return head;
}
//UNIT
course* sortByUnit(course* head) //sort by unit
{
    course* newHead=0; //a new empty list
    course* oldHead=head; // the original list
    while(oldHead)
    {
        course* t = oldHead; // get node from old list
        oldHead= oldHead->next; //remove node from old list
        
        newHead=compareUnits(t,newHead);//compare and insert
        
    }
    return newHead;
}//byUnit
course* compareUnits(course* t, course* h)
{
    course* p, *prev;
    for (p=h, prev=0; p; prev=p, p=p->next)
        if (compareUCmp(t, p) < 0) // if "t" precedes "p"...
            break; // "t" goes between "prev" and "p"
    t->next = p; // "t" inserted before "p"
    if (prev) // "t" inserted after "prev"
        prev->next = t;
    else // "t" added to front of list
        h = t;
    return h;
}
int compareUCmp(const course* dst, const course* src)
{
    //handle ties here
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
course* sortByGrade(course* head)
{
    course* newHead=0; //a new empty list
    course* oldHead=head; // the original list
    while(oldHead)
    {
        course* t = oldHead; // get node from old list
        oldHead= oldHead->next; //remove node from old list
        
        newHead=compareGrade(t,newHead);//compare and insert
        
    }
    return newHead;
}//sort by grade
course* compareGrade(course* t, course* h)
{
    course* p, *prev;
    for (p=h, prev=0; p; prev=p, p=p->next)
        if (compareGCmp(t, p) < 0) // if "t" precedes "p"...
            break; // "t" goes between "prev" and "p"
    t->next = p; // "t" inserted before "p"
    if (prev) // "t" inserted after "prev"
        prev->next = t;
    else // "t" added to front of list
        h = t;
    return h;
}
char compareGCmp(const course* dst, const course* src)
{
    //handle ties here
    char gradeA = dst->grade; //dst redefined to unitA.
    char gradeB = src->grade;//src redefined to unitB.
    if(dst->grade==src->grade)//if equal, go based on year course taken
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
course* sortByDescription(course* head) //sort by description
{
    course* newHead=0; //a new empty list
    course* oldHead=head; // the original list
    while(oldHead)
    {
        course* t = oldHead; // get node from old list
        oldHead= oldHead->next; //remove node from old list
        
        newHead=compareDescr(t,newHead);//compare and insert
        
    }
    return newHead;
}
course* compareDescr(course* t, course* h)
{
    course* p, *prev;
    for (p=h, prev=0; p; prev=p, p=p->next)
        if (compareDCmp(t, p) < 0) // if "t" precedes "p"...
            break; // "t" goes between "prev" and "p"
    t->next = p; // "t" inserted before "p"
    if (prev) // "t" inserted after "prev"
        prev->next = t;
    else // "t" added to front of list
        h = t;
    return h;
}
char compareDCmp(const course* dst, const course* src)
{
    //handle ties here
    if(tolower(*dst->nCourse)==tolower(*src->nCourse))
        return compareGCmp(dst,src);//if tie, sort based on grade
    
    //compare if not a tie
    if(tolower(*dst->nCourse)<tolower(*src->nCourse))
        return -1; //dst comes first
    if(tolower(*dst->nCourse)>tolower(*src->nCourse))
        return 1; //src comes first
    
    return 1;
}
//TERM SORT
course* sortByTerm(course* head)//sort by term
{
    course* newHead=0; //a new empty list
    course* oldHead=head; // the original list
    while(oldHead)
    {
        course* t = oldHead; // get node from old list
        oldHead= oldHead->next; //remove node from old list
        
        newHead=compareTerm(t,newHead);//compare and insert
        
    }
    return newHead;
}//sort by term
course* compareTerm(course* t, course* h) //insertion method
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
//MISC FUNCTIONS
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
void clearList(course* head)//clear list
{
    while(head)
    {
        course* next = head->next;
        delete head;
        head=next;
    }//while
}