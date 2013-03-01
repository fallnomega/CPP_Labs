//// Lab 3: avgList.cpp
//// Programmer: Jason Hillin
//// Editor(s) used: Xcode & MS Visual C++ 2010 Express
// Compiler(s) used: g++

#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::ios;
using std::setprecision;

#include <cstdarg>

//function prototype(s)
int avg(int, ...);
double davg(int, ...);
int avgx(int&, int&, int, ...);
double avgx(double&, double&, int, ...);

int main()
{
  cout << "Lab 3: avgList.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";

  //run the average functions

  //integers
  cout << "*Integers*\n";
  cout << "The average of 6 test scores is " << avg( 6, 81, 92, 73, 84, 95, 193) << endl;

  //Floats
  cout << "\n*Floats*\n";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << "The average of 10 float numbers is " << davg(10, 56.6, 1.26, 94.58, 40.64, 78.12, 54.89, 64.78, .98, 900.1, 30.10) << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
    
  //PbR intergers
  cout << "\n*Pass by Reference Integers*\n";
  int a, aMax, aMin;
  a=avgx(aMax, aMin, 8, 81, 92, 73, 84, 95, 61, 37, 49);
  cout << "The average of 8  numbers is " << a << endl;
  cout << "The Minimum number is " << aMin;
  cout << " while the Maximum number is " << aMax << endl;
    
  //PbR Floats
  cout << "\n*Pass by Reference Floats*\n";
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  double b, bMax, bMin;
  b=avgx(bMax, bMin, 9, 162.5, 45.1, 98.56, 82.32, 2.37, 6.59, 47.58, 108.6, 59.78);
  cout << "The average of 9  double numbers is " << b << endl;
  cout << "The Minimum number is " << bMin;
  cout << " while the Maximum number is " << bMax << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
}

//return average of a variable length list of integers
int avg(int n, ...) //"n"  is the number of numbers in the list, "..." is the list
{
  va_list list; //assign the name "list" to the variable length list of numbers
  va_start (list, n); //tell c++ that the list begins after the argument "n"
  int num; //store the list of numbers from the list in "num" as they are "read"
  
  //create the total of "n" numbers in the list
  int total = 0; // track the of the numbers in the list
  for(int i=0;i <n;i++)
  {
    num = va_arg(list, int); //set num equal to the next number on the list, as an int
    total = total + num; //increment the total
  }
  va_end(list); //close the list -- REQUIRED

  //compute and return the average
  return total / n;
}

//return double average of a variable length list of floats
double davg(int x, ...)
{
  va_list dlist;
  va_start (dlist, x);
  double num; 
  double total = 0.0;
  for(int i = 0; i< x;i++)
  {
    num = va_arg(dlist, double);
    total = total+num;
  }
  va_end(dlist);
  return total / x;
}

// returns average, and passes max and min back through argument list
int avgx(int& mx, int& mn, int n, ...) // n is the number of numbers in the list
{
  va_list list; //assign the name "list" to the variable length list of integers
  va_start(list, n); // tell C++ that the list begins AFTER the argument "n"
  int num; //store the numbers from the list in "num" as they are read

  // create the total of "n" numbers in the list
  int total = 0; // track the total of the numbers in the list
  for(int i=0; i < n; i++)
  {
    num = va_arg(list, int); // set num equal to the next number in the list, as an int
    if((i==0) || (mn>num)) // update min value
      mn = num;
    if((i==0) || (mx < num)) // update max value
      mx = num;
    total = total + num; // increment the total
  }
  va_end(list); // close the list -- REQUIRED
  
  // compute and return the average
  return total / n;
}

// returns double average, and passes max and min back through argument list
double avgx(double& mx, double& mn, int n, ...)
{
  va_list dlist;
  va_start(dlist, n);
  double dnum;

  double dtotal = 0.0;
  for(int i=0; i < n; i++)
  {
    dnum = va_arg(dlist, double);
    if((i==0) || (mn>dnum)) // update min 
      mn = dnum;
    if((i==0) || (mx < dnum)) // update max 
      mx = dnum;
    dtotal = dtotal + dnum; // update dtotal
  } //for close
  va_end(dlist); // close
  
  // return double average
  return dtotal / n;
}