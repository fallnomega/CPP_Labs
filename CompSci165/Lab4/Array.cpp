//// Lab 4: Array.cpp
//// Programmer: Jason Hillin
//// Editor(s) used: Xcode & MS Visual C++ 2010 Express
// Compiler(s) used: g++


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//prototypes
int readArray(int, int[]);
int stat(int, const int[], int&, int&, int&);
int histogram(int, const int[], int[]);

int main ()
{
  cout << "Lab 4: Array.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";

  const int MAX_SCORE = 50; // the maximum # of scores that a user can enter
  int score[MAX_SCORE]; // create storage for up to 50 scores
  int nScores=readArray(MAX_SCORE, score); // read array and return count
  
  int avgScore, minScore, maxScore;
  if(stat(nScores, score, avgScore, minScore, maxScore) == 0)
  {
    cout << "Your Average Score is=" << avgScore << endl
      << "Your Max score is=" << maxScore << endl
      << "Your Min score is=" << minScore << endl;
    int grade[5] = {0}; //={} is for newer compilers only
    histogram(nScores,score,grade);
    cout << "Breakdown of the amount of A's, B's, C's, D's, and F's you have:\n";
    cout << "As: : " << grade[0] << endl;
    cout << "Bs: : " << grade[1] << endl;
    cout << "Cs: : " << grade[2] << endl;
    cout << "Ds: : " << grade[3] << endl;
    cout << "Fs: : " << grade[4] << endl;
  }
  else
    cout << "no data" << endl;
}

//read score data function
int readArray(int MAX_SIZE, int genericList[])
{
  int counter = 0; // count how many scores you've entered
  cout << "The following will accept up to 50 scores.\n";
  cout << "Use a negative number to cancel the program.\n\n";
  cout << "Please enter in your score/scores here:> ";
  // for loop for number input
  for(int i = 0; i < MAX_SIZE;i++)
  {
    cin >> genericList[i];
    if(genericList[i] < 0)
      break; //negative number to break, otherwise continue collecting input
    else
      counter++; // count numbers if no non-negative number entered
  }//for
return counter;
}

//STAT's function
int stat(int aCount, const int aList[], int &avgScore, int &mnScore, int &mxScore)
{
  if(aCount!=0)
  {
    int total=0; //stores grand total of all the grades
    int i=0;// for cycling through elements in the array
    mxScore=0; // maxScore
    mnScore=aList[0]; //minScore
    while(i<aCount) //while loop obtains grand total + min & max score
    {
      if(aList[i]<mnScore) mnScore=aList[i];
      if(aList[i]>mxScore) mxScore=aList[i];
      total+=aList[i];
      i++;
    }//while
  avgScore = total / aCount; // gives the average
  return 0;  //return average
  }//if
  else return 1; //returns 1 if no entries
}
int histogram(int aCount, const int aList[], int grades[5])
{
  if(aCount!=0)
  {
  for(int i=0;i<aCount;i++)//sorts out letter grade tally
  {
  if((aList[i]>=90) && (aList[i]<=100)) grades[0] = grades[0]+1;
  else if((aList[i]>=80) && (aList[i]<=89)) grades[1] = grades[1]+1;
  else if((aList[i]>=70) && (aList[i]<=79)) grades[2] = grades[2]+1;
  else if((aList[i]>=60) && (aList[i]<=69)) grades[3] = grades[3]+1;
  else grades[4] = grades[4]+1;
  }//for
  return 0;  //returns letter grade tally
  }//if
  else return 1; //return 1 if empty.
  return 0;
}