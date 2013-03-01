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
static void header();//display labels
void coutClass(); //print class 1
course* restoreList();//restore from courses.dat 1
void saveList();//write to courses.dat 1
course* AddClass();//add class 1
course* sortByUnit(); //sort by unit1
course* sortByGrade(); //sort by grade
course* sortByDescription(); //sort by description
course* sortByTerm(); //SORT BY TERM
void clearList();//delete list
static int myStricmp(const char* dst, const char* src); //semester compare
static int myStrnicmp(const char* dst, const char* src, int count);//tie breaker
course* insert(course*); // insertion 1
course* compareUnits(course* h);//compare by unit
int compareUCmp( const course* src);
course* compareGrade( course* h);
char compareGCmp(const course* src);
course* compareDescr(course* h);
char compareDCmp(const course* src);
course* compareTerm(course* h);//COMPARE BY TERM
int courseCmp(const course*); //compare course
void toLower(char str[]);
};

#endif