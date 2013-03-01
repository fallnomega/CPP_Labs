// Lab 7a: ioCopy.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express
// Compiler(s) used: MS Visual C++ 2010 Express
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

//main body
int main ()
{
  cout << "Lab 7a: ioCopy.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";

  //User determines file to open
  //program retrieves data from it.
  ifstream fin;
  char fileName[200];
  cout << "Name of file to open ? (include path if needed): \n";
  cin.getline(fileName, 200);
  fin.open(fileName);
  if(!fin.good()) 
  {
    cout << "Input File does not exist!\n";
    return 0;
  }//if
  else 
  {
    cout << "\nOpening File > " << fileName << endl;
  }//else

  //User specifies file to output to
  cout << "File name to copy the contents of " << fileName << " to? (include path if needed): \n";
  char oFileName[200];
  cin.getline(oFileName, 200);

  //test to see if output file can be opened.
  //if it can then write to destination file.
  ofstream fout;
  fout.open(oFileName);
  if(!fout.good())
  {
    cout << "Unable to open " << oFileName << " !\n";
    return 0;
  }//if
  else
  {
    cout << "\nOpening output file " << oFileName
      << " to copy contents to.\n\n";
  }//else

  //loop to output data from the input file
  //to the screen and write data to output file
  char buf[512];
  while(1)
  {
    if(fin.eof())
      break;
    fin.getline(buf, 512);
    cout << buf << endl;
    fout << buf << endl;
  }//while
  fin.close();
  fout.close();
}
  
