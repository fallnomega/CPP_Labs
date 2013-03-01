// Lab 1b
// Programmer: Jason Hillin
// Editor(s) used: VC++ 2010 Express & XCode
// Compiler(s) used: VC++ 2010 Express & g++
//

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;


#include <fstream>
using std::ifstream;

#include <cmath>
#include <cstring>
#include <cstdlib>

const char* delim = " ";
int main()
{
  cout << "Lab 1b\nProgrammer: Jason Hillin\nDescription: General Geometric formulas\n"
    <<"Takes formulas from a txt file, converts them to doubles, then\ncalculates"
    << " area, perimeter,etc before outputting to the users screen."
    << endl << endl;
  // create a file-reading object
  ifstream fin;
  fin.open("geo.txt"); // open a file
  if (!fin.good())
    return 1; // exit if file not found
    
    // read each line of the file
  while (!fin.eof())
  {
    // read an entire line into memory
    char name[512];
    fin.getline(name,512); 

    //index
    int index = 0;

    //array for index of entries
    char* token[4];

    token[0]=strtok(name,delim);
    if(token[0])
    {
      for(index = 1;index<4;index++)
      {
        token[index]=strtok(0,delim);

        if(!token[index]) token[index] = "0";//break;
      }
    }
    for(int i = 0;i<index;i++)
    {
      if((strcmp(token[i],"SQUARE"))==0)
      {
		double a = atof(token[1]);
        double area = a*a;
        double perim = a*4;
        setprecision(2);
        cout << token[0] << " side= " << a;
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << ", area= " << area << ", perimeter= " << perim;
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << endl;
        break;
      }
      else if((strcmp(token[i],"RECTANGLE"))==0)
      {
      double a = atof(token[1]);
      double b = atof(token[2]);
      cout << token[0] << " length = " << a << ", width = " << b;
      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2);
      cout << ", area = " << a*b << ", perimeter = " << (2*a)+(2*b);
      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6);
      cout << endl;
      break;
      }
      else if((strcmp(token[i],"CIRCLE"))==0)
      {
        double pi = 3.1415927;
        double a = atof(token[1]);
        cout << token[0]  << " radius = " << a;
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << ", area = " << pi*pow(a,2) << ", circumference = "
          << 2*(pi*a);
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << endl;
        break;
      }
      else if((strcmp(token[i],"CUBE"))==0)
      {
        double a = atof(token[1]);
        cout << token[0]  << " side = " << a;
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << ", surface area = " << 6*pow(a,2) << ", volume = "
          << pow(a,3);
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << endl;
        break;
      }
      else if((strcmp(token[i],"PRISM"))==0)
      {
        double a = atof(token[1]);
        double b = atoi(token[2]);
        double c = atof(token[3]);
        cout << token[0]  << " length = " << a << ", width = " << b
          << ", height = " << c;
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);
        cout << ", surface area = " << 2*((a*b)+(a*c)+(b*c)) << ", volume = "
          << a*b*c;
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << endl;
        break;
      }
      else if((strcmp(token[i],"CYLINDER"))==0)
      {
        double pi = 3.1415927;
        double a = atof(token[1]); 
        double b = 0;
        b = b + atof(token[2]);
        cout << token[0] << " radius = " << a << ", height = "<< b;
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);             
        cout << ", surface area = " << (2*pi*a)*(a+b) << ", volume = "
          << (pi*pow(a,2)*b);
        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);
        cout << endl;
       break;
      }
      else
      {
        cout << token[0] << " invalid object" << endl;
        break;
      }
    }//for
  }//while
  cout << endl;
}//main 
