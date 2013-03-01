#ifndef COURSE_H 
#define COURSE_H
class course
{
  char nCourse[11];
  char term[7];
  char units;
  char grade;
  course *next;
///////////////////////
//function prototypes//
///////////////////////
public:
static int menu();
static char getYesNo();
static void header();//display labels
void coutClass(); //print class 
course* restoreList();//restore from courses.dat 
void saveList();//write to courses.dat 
course* AddClass();//add class 
course* insert(course*); // insertion 
course* sortByUnit(); //sort by unit
course* compareUnits(course* h);//compare by unit
int compareUCmp( const course* src);
course* sortByGrade(); //sort by grade
course* compareGrade( course* h);// compare by grade
char compareGCmp(const course* src);
course* sortByDescription(); //sort by description
course* compareDescr(course* h); // compare by course
char compareDCmp(const course* src);
course* sortByTerm(); //SORT BY TERM
course* compareTerm(course* h);//compare by term
int courseCmp(const course*); //compare course
static int myStricmp(const char* dst, const char* src); //semester compare
static int myStrnicmp(const char* dst, const char* src, int count);//tie breaker
void clearList();//delete list
void toLower(char str[]);// to lower function
course* deleteNode(course*, course&); // delete node

};

#endif