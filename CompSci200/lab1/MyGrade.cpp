// Lab 1a: MyGrade.txt and MyGrade.cpp
// Programmer: Jason Hillin
// Editor(s) used: XP Notepad + VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
//
#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

int main()
{
  // identifying output statements
  cout << "Programmer: Jason Hillin\nClass average program "
    << "with counter-controlled repitition." << endl;

  int total;//sum total of grades entered by user
  int gradeCounter;// number of the grades to be entered next
  int grade;//grade value entered by user
  int average;// average of grades

  
  //initialization phase
  total = 0;//initialized total
  gradeCounter = 1;//initialized loop counter

  //processing phase
  while(gradeCounter <= 10) // loop 10 times
  {
    cout << "Enter grade: ";//prompt for input
    char cGrade[10];
    cin >> cGrade;//input next grade
    grade=atoi(cGrade);
    total = total + grade;// add grade to total
    gradeCounter = gradeCounter + 1;//increment counter by 1
  }//end while

  //termination phase
  average = total/10; //integer division yiel;ds integer result

  //display total and average of grades
  cout << "\nTotal of all 10 grades is " << total << endl;
  cout << "Class average is " << average << endl;
}//end main