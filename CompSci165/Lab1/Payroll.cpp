// Lab 1b
// Programmer: Jason Hillin
// Editor(s) used: Notepad++
// Compiler(s) used: VC++ 2010 Express(DOS)

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::ios;
using std::setprecision;

int main()
{
  cout << "Lab 1b" << endl;
  cout << "Programmer: Jason Hillin\n\n";

  // variables
  double hourly_pay;
  double hours_worked;
  double gross_pay;
  double net_pay;

  // ask for input
  cout << "Enter hourly pay and hours worked, separated by a space."
	<< endl;
  cin >> hourly_pay >> hours_worked;
  cin.ignore(); // consume ENTER left by above statement 

  // compute gross pay
  if (hours_worked <= 40.0)
    gross_pay = hours_worked * hourly_pay;
  else
	gross_pay = (40.0 + (hours_worked - 40.0) * 1.5) * hourly_pay;

  // withhold taxes of 30 percent
  net_pay = gross_pay - (0.3 * gross_pay);

  // print the formatted result
  cout.setf(ios::fixed|ios::showpoint);
  cout << "Gross=" << setprecision(2) << gross_pay << endl;
  cout << "Net=" << net_pay << endl;  
}