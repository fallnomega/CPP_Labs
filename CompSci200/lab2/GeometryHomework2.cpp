// Lab 2b: GeometryHomework2.cpp
// Programmer: Jason Hillin
// Editor(s) used: VC++ 2010 Express & XCode & Eclipse
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

struct Square
{
    char name[25];
    double side;
};
struct Rectangle
{
  char name[25];
  double length;
  double width;
};
struct Circle
{
  char name[25];
  double radius;
};

struct Cube
{
  char name[25];
  double side;
};
struct Prism
{
  char name[25];
  double length,width, height;
};
struct Cylinder
{
  char name[25];
  double radius, height;
};
void printSquare(Square* square);
void printRectangle(Rectangle* rectangle);
void printCircle(Circle* circle);
void printCube(Cube* cube);
void printPrism(Prism* prism);
void printCylinder(Cylinder* cylinder);

const char* delim = " ";

int main()
{
  cout << "Lab 2b:GeometryHomework2.cpp\nProgrammer: Jason Hillin\nDescription: General Geometric formulas\n"
    <<"Takes formulas from a txt file and stores in structs, ships it to functions to\ncalculate"
    << " area, perimeter,etc before sending to output functions to print to\nthe users screen."
    << endl << endl;
  // create a file-reading object
  ifstream fin;
  fin.open("geo.txt"); // open a file
  if (!fin.good())
    return 1; // exit if file not found
  	
  void *shapes[100];
	int shapeId[100];
  int shapeIdIndex=0;
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
      }//for token
    }//if token
    for(int i = 0;i<index;i++)//for loop to build objects into shapes array elements
    {
      if((strcmp(token[i],"SQUARE"))==0)//build Square object
      {    
        Square* s = new Square;
        strcpy(s->name,token[0]);
        s->side = atof(token[1]);
        shapes[shapeIdIndex] =s;
        shapeId[shapeIdIndex]=1;
        break;
      }//end if - build Square object
      else if((strcmp(token[i],"RECTANGLE"))==0)//build Rectangle object
      {    
        Rectangle* s = new Rectangle;
        strcpy(s->name,token[0]);
        s->length = atof(token[1]);
        s->width=atof(token[2]);
        shapes[shapeIdIndex]=s;
        shapeId[shapeIdIndex]=2;
        break;
      }//end if - build Rectangle object
      else if((strcmp(token[i],"CIRCLE"))==0)//build Circle object
      {    
        Circle* s = new Circle;
        strcpy(s->name,token[0]);
        s->radius = atof(token[1]);
        shapes[shapeIdIndex]=s;
        shapeId[shapeIdIndex]=3;
        break;
      }//end if - build Cricle object
      else if((strcmp(token[i],"CUBE"))==0)//build Cube object
      {    
        Cube* s = new Cube;
        strcpy(s->name,token[0]);
        s->side = atof(token[1]);
        shapes[shapeIdIndex] =s;
        shapeId[shapeIdIndex]=4;
        break;
      }//end if - build Cube object
      else if((strcmp(token[i],"PRISM"))==0)//build Prism object
      {    
        Prism* s = new Prism;
        strcpy(s->name,token[0]);
        s->length = atof(token[1]);
        s->width=atof(token[2]);
        s->height=atof(token[3]);
        shapes[shapeIdIndex]=s;
        shapeId[shapeIdIndex]=5;
        break;
      }//end if - build Prism object
      else if((strcmp(token[i],"CYLINDER"))==0)//build Cylinder object
      {    
        Cylinder* s = new Cylinder;
        strcpy(s->name,token[0]);
        s->radius = atof(token[1]);
        s->height=atof(token[2]);
        shapes[shapeIdIndex]=s;
        shapeId[shapeIdIndex]=6;
        break;
      }//end if - build Cylinder object
      else//print invalid object
      {
        cout << token[0] << " invalid object" << endl;
        break;
      }//end else - invalid object
    }//end for loop to build objects into shapes array elements
    shapeIdIndex++;
  }//while
  fin.close();

  //traverse array and print shapes to console
  for(int i=0;i<shapeIdIndex;i++)
  {
    if(shapeId[i]==1) printSquare((Square*)shapes[i]);
    else if(shapeId[i]==2)printRectangle((Rectangle*)shapes[i]);
    else if(shapeId[i]==3)printCircle((Circle*)shapes[i]);
    else if(shapeId[i]==4)printCube((Cube*)shapes[i]);
    else if(shapeId[i]==5)printPrism((Prism*)shapes[i]);
    else if(shapeId[i]==6)printCylinder((Cylinder*)shapes[i]);
  }

  //purge array from memory
  for(int i=0;i<shapeIdIndex;i++)
  {
    if(shapeId[i]==1) delete (Square*)shapes[i];
    else if(shapeId[i]==2)delete ((Rectangle*)shapes[i]);
    else if(shapeId[i]==3)delete ((Circle*)shapes[i]);
    else if(shapeId[i]==4)delete ((Cube*)shapes[i]);
    else if(shapeId[i]==5)delete ((Prism*)shapes[i]);
    else if(shapeId[i]==6)delete ((Cylinder*)shapes[i]);
  }
  cout << endl;
}//main 

/////////////
//functions//
/////////////

void printSquare(Square* square) //calculate and print Square area and perimeter
{  
  double a = square->side;
  double area = a*a;
  double perim = a*4;
  cout << square->name << " side= " << a;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", area= " << area << ", perimeter= " << perim;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printSquare
void printRectangle(Rectangle* rectangle)//calculate and print Rectangle area and perimeter
{
  double a = rectangle->length;
  double b = rectangle->width;
  cout << rectangle->name << " length = " << a << ", width = " << b;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", area = " << a*b << ", perimeter = " << (2*a)+(2*b);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printRectangle
void printCircle(Circle* circle)//calculate and print Cicle area and circumference
{
  double pi = 3.1415927;
  double a = circle->radius;
  cout << circle->name  << " radius = " << a;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", area = " << pi*pow(a,2) << ", circumference = "
    << 2*(pi*a);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printCircle
void printCube(Cube* cube)//calculate and print Cube surface area and volume
{
  double a = cube->side;
  cout << cube->name  << " side = " << a;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", surface area = " << 6*pow(a,2) << ", volume = "
    << pow(a,3);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printCube
void printPrism(Prism* prism)//calculate and print Prism surface area and volume
{
  double a = prism->length;
  double b = prism->width;
  double c = prism->height;
  cout << prism->name << " length = " << a << ", width = " << b
    << ", height = " << c;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", surface area = " << 2*((a*b)+(a*c)+(b*c)) << ", volume = "
    << a*b*c;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printPrism
void printCylinder(Cylinder* cylinder)//calculate and print Cylinder surface area and volume
{
  double pi = 3.1415927;
  double a = cylinder->radius; 
  double b = 0;
  b+=cylinder->height;
  cout << cylinder->name << " radius = " << a << ", height = "<< b;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);             
  cout << ", surface area = " << (2*pi*a)*(a+b) << ", volume = "
    << (pi*pow(a,2)*b);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printCylinder