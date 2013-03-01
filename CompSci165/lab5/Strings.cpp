// Lab 5: Strings.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express
// Compiler(s) used: MS Visual C++ 2010 Express

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//PROTOTYPES
int myStrLen(const char[]); // return length of null-terminated string stored in char array
void myStrCpy(char[], const char[]);// copy the contents of the 2nd string into the 1st
int myStrCmp(const char[], const char[]); // return 0 if two strings are equal, else return 1

int main ()
{

  {
    cout << "Lab 5: Strings.cpp\n";
    cout << "Programmer: Jason Hillin\n\n";

    //read any string  
    cout << "Insert word or words here and hit enter to end the input\n>>>";
    char text[128]; // storage for 128 characters
    cin.getline(text, 128);

    // create another string for comparing
    char abc[]="ABC";

    //print the string and compare it
    cout << "String: " << text << endl;
    cout << "Length: " << myStrLen(text)<< endl;
    if(myStrCmp(text, abc)==0) 
      cout << "Your string equals ABC" << endl;
    else 
      cout << "Your string does not equal ABC" << endl;

    //change the string, print it, and compare it
    myStrCpy(text, "ABC");
    cout << "String: " << text << endl;
    cout << "Length: " << myStrLen(text)<< endl;
    if(myStrCmp(text, abc)==0) 
      cout << "The changed string equals ABC" << endl;
    else 
      cout << "The changed string does not equal ABC" << endl << endl;
  }//original


  // replacing myStrLen, myStrCpy, myStrCmp with the strlen, strcmp, and strcpy.
  {
    //read any string  
    cout << "Insert word or words here and hit enter to end the input\n>>>";
    char text[128]; // storage for 128 characters
    cin.getline(text, 128);

    // create another string for comparing
    char abc[]="ABC";

    //print the string and compare it
    cout << "String: " << text << endl;
    cout << "Length: " << strlen(text)<< endl;
    if(strcmp(text, abc)==0) 
      cout << "Your string equals ABC" << endl;
    else 
      cout << "Your string does not equal ABC" << endl;

    //change the string, print it, and compare it
    strcpy(text, "ABC");
    cout << "String: " << text << endl;
    cout << "Length: " << strlen(text)<< endl;
    if(strcmp(text, abc)==0) 
      cout << "The changed string equals ABC" << endl;
    else 
      cout << "The changed string does not equal ABC" << endl << endl;
  }// cstring replacements

}

//FUNCTIONS

//aquire char array length
int myStrLen(const char words[])
{

  int count =0;
  while(true)
  {
    if(words[count]=='\0') break;
    else
    {
      count++;
    }//else
  }//while

  return count;
}//myStrLen

//copy second const char array to first char array
void myStrCpy(char words[], const char aWords[])
{

  int i = 0;
  while(words[i]!='\0')
  {
    words[i] = aWords[i];
    i++;   
  }//while

}//myStrCpy

//compare char arrays to see if they are the same in content
int myStrCmp(const char words[], const char aWords[])
{
  
  int sentinal = 0;
  for(int i=0;sentinal<1;i++)
  {
    if(words[i]!=aWords[i]) sentinal=1;
    if(aWords[i]=='\0') break;
  }//for

  return sentinal;
}//myStrCmp