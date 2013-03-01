// Lab 1c
// Programmer: Jason Hillin
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express (DOS)

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cmath>

int main()
{
 
  cout << "Lab 1c\n";
  cout << "Programmer: Jason Hillin\n\n";
  // a quadratic equation solver
  double a, b, c; // the coefficients
  double x1, x2; // the roots
  double d; // b squared minus 4 a c

  // ask for input
  cout << "Solve: Ax2 + Bx + C = 0" << endl;
  cout << "Enter A, B, and C, separated by a space." << endl;
  cin >> a >> b >> c;
  cin.ignore(); // consume ENTER left by above statement

  // compute quadratic roots
  d = b * b - 4.0 * a * c;
  if ((d >= 0.0) && (a != 0.0))
  {
    x1 = (-b + sqrt(d)) / (2.0 * a);
    x2 = (-b - sqrt(d)) / (2.0 * a);
    cout << "roots = " << x1 << " and " << x2 << endl;
  }
  else
    cout << "no quadratic solution" << endl;
 }