// Lab 3b: GeometryHomework3.cpp
// Programmer: Jason Hillin
// Editor(s) used: VS 2010 Express
// Compiler(s) used: VS 2010 Express
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

/////////
//class//
/////////

class Square
{
private:
  double side;
public:
  Square(char*token[4])
  {
    this->side=atof(token[1]);
  }
  void print() const;
};

class Rectangle
{
private:
  double length;
  double width;
public:
  Rectangle(char* token[4])
  {
    this->length = atof(token[1]);
    this->width=atof(token[2]);
  }
  void print() const;
};

class Circle
{
private:
  double radius;
public:
  Circle(char* token[4])
  {
    this->radius = atof(token[1]);
  }
  void print() const;
};

class Cube
{
private:
  double side;
public:
  Cube(char* token[4])
  {
    this->side=atof(token[1]);
  }
  void print() const;
};

class Prism
{
private:
  double length,width, height;
public:
  Prism(char* token[4])
  {
    this->length=atof(token[1]);
    this->width=atof(token[2]);
    this->height=atof(token[3]);
  }
  void print() const;
};

class Cylinder
{
private:
  double radius, height;
public:
  Cylinder(char* token[4])
  {
    this->radius=atof(token[1]);
    this->height=atof(token[2]);
  }
  void print() const;
};

const char* delim = " ";

////////
//main//
////////

int main()
{
  cout << "Lab 3b:GeometryHomework3.cpp\nProgrammer: Jason Hillin\n"
    << "Description: General Geometric formulas using classes and\n"
    << "other things in the beginning of OOP adventures\n" << endl << endl;

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
        Square* s = new Square(token);
        shapes[shapeIdIndex] =s;
        shapeId[shapeIdIndex]=1;
        break;
      }//end if - build Square object
      else if((strcmp(token[i],"RECTANGLE"))==0)//build Rectangle object
      {    
        Rectangle* s = new Rectangle(token);
        shapes[shapeIdIndex]=s;
        shapeId[shapeIdIndex]=2;
        break;
      }//end if - build Rectangle object
      else if((strcmp(token[i],"CIRCLE"))==0)//build Circle object
      {    
        Circle* s = new Circle(token);
        shapes[shapeIdIndex]=s;
        shapeId[shapeIdIndex]=3;
        break;
      }//end if - build Cricle object
      else if((strcmp(token[i],"CUBE"))==0)//build Cube object
      {    
        Cube* s = new Cube(token);
        shapes[shapeIdIndex] =s;
        shapeId[shapeIdIndex]=4;
        break;
      }//end if - build Cube object
      else if((strcmp(token[i],"PRISM"))==0)//build Prism object
      {    
        Prism* s = new Prism(token);
        shapes[shapeIdIndex]=s;
        shapeId[shapeIdIndex]=5;
        break;
      }//end if - build Prism object
      else if((strcmp(token[i],"CYLINDER"))==0)//build Cylinder object
      {    
        Cylinder* s = new Cylinder(token);
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
    if(shapeId[i]==1) ((Square*)shapes[i])->print();
    else if(shapeId[i]==2) ((Rectangle*)shapes[i])->print();
    else if(shapeId[i]==3) ((Circle*)shapes[i])->print();
    else if(shapeId[i]==4) ((Cube*)shapes[i])->print();
    else if(shapeId[i]==5)((Prism*)shapes[i])->print();
    else if(shapeId[i]==6)((Cylinder*)shapes[i])->print();
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
void Square::print() const //calculate and print Square area and perimeter
{
  double a = side;
  double area = a*a;
  double perim = a*4;
  cout << "SQUARE side= " << a;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", area= " << area << ", perimeter= " << perim;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printSquare
void Rectangle::print() const//calculate and print Rectangle area and perimeter
{
  double a = length;
  double b = width;
  cout << "RECTANGLE length = " << a << ", width = " << b;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", area = " << a*b << ", perimeter = " << (2*a)+(2*b);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printRectangle
void Circle::print() const //calculate and print Cicle area and circumference
{
  double pi = 3.1415927;
  double a = radius;
  cout << "CIRCLE radius = " << a;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", area = " << pi*pow(a,2) << ", circumference = "
    << 2*(pi*a);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printCircle
void Cube::print() const//calculate and print Cube surface area and volume
{
  double a = side;
  cout << "CUBE side = " << a;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", surface area = " << 6*pow(a,2) << ", volume = "
    << pow(a,3);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printCube
void Prism::print() const//calculate and print Prism surface area and volume
{
  double a = length;
  double b = width;
  double c = height;
  cout << "PRISM length = " << a << ", width = " << b
    << ", height = " << c;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << ", surface area = " << 2*((a*b)+(a*c)+(b*c)) << ", volume = "
    << a*b*c;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printPrism
void Cylinder::print() const//calculate and print Cylinder surface area and volume
{
  double pi = 3.1415927;
  double a = radius; 
  double b = 0;
  b+=height;
  cout << "CYLINDER radius = " << a << ", height = "<< b;
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);             
  cout << ", surface area = " << (2*pi*a)*(a+b) << ", volume = "
    << (pi*pow(a,2)*b);
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  cout << endl;
}//end function printCylinder