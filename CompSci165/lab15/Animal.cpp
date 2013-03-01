// Lab 15: Animal.cpp
// Programmer: Jason Hillin
// Editor(s) used: XCode
// Compiler(s) used: g++

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ios;
using std::fstream;

#include <cstring>

/////////
//class//
/////////
class animal
{
  public:
  char text[128];
  animal* yes; //yes node
  animal* no;//no node
};
////////////
//function//
////////////
 char getYesNo(char*);
 void greeting();
 void grow(animal*);
 void brag(); 
 void deleteTree(animal*);
 void saveTree(animal*, fstream&);
 void restoreTree(animal*, fstream&);
 void editQ(animal* p);
 void deleteNode(animal* p);
////////
//main//
////////
int main()
{
  cout << "Lab 15:  Animal.cpp\n";
  cout << "Programmer: Jason Hillin\n\n";
  animal* top = new animal;// initialize a "top" pointer named "animal* top" 
  // restore tree from a disk file
  fstream fin;
  fin.open("animal.dat", ios::in|ios::binary);  
  if(!fin)
  {
    animal temp={"elephant",0,0};// set "top" to a newly created node; set its text to "elephant", pointers to 0 
    top=&temp;// set "top" to a newly created node; set its text to "elephant", pointers to 0 
  }
  else 
  {
    restoreTree(top, fin); //restore tree
  }
  fin.close();
  while(true) // start a "while" loop that runs each cycle of the program 
  {
    // invite the user to think of an animal which it will try to guess 
    greeting();
    char answer = getYesNo(&answer);
    if(answer=='n')// await the user's response, and break out of the loop if he declines
    {
      cout << "BOO!!!!" << endl;
      // save tree
      fstream fout;
      fout.open("animal.dat", ios::out|ios::binary);
      saveTree(top, fout);
      fout.close();
      break;
    }
    else if(answer=='d' || answer=='e')
    {
      cout << "No time for that since this is a new game, select y or n for this question \n!" << endl;
    }
    else
    {
      animal* p = top;// declare a pointer "p" to traverse the tree, and initialize it to "top"
      while(true)
      {
        if(p->yes==0)// if p->yes is 0... 
        {
          grow(p);
          break; // break from loop 
        }//if p->yes = 0
        else if(p->yes!=0)// else if p->yes is not 0 
        {
          cout << p->text << endl;// print p->text as a question 
          cout << "Yes or No [y/n]?\n";// ask for a yes/no reply... 
          char yesNo= getYesNo(&yesNo);//...store in "char yesNo" 
          if(yesNo=='y') p=p->yes;// if "yes", set p to p->yes 
          else if(yesNo=='e')
          {
            cout << "Enabling edit mode for the question: "; 
            editQ(p);
          }
          else if(yesNo=='d')
          {
            deleteNode(p);
            continue;
          }
          else p=p->no;// else set p to p->no 
          cout  << endl;
        }
      }//for
    }//else
  }//while  

 deleteTree(top);// reclaim memory 
 cout << endl;
}//main

////////////
//function//
////////////

//yesNo function
 char getYesNo(char*)
 {
   char yesNo;
   while(true)
   {
    cin >> yesNo;
    cin.ignore(1000,10);
    if(yesNo!='n'&& yesNo!='y'&& yesNo!='d'&& yesNo!='e') cout << "Yes or No [y/n]?\n";
    else break;
   }
   return yesNo;
 }

//greeting
 void greeting()
 {
   cout << "\n\nThink of an animal and I'll try to guess it! Okay? [y/n]? >";
 }

//add to the tree
 void grow(animal* p)
 {
   while(true)
   {
          cout << p->text << " y/n?" << endl;//...print p->text as the guessed animal 
          char answer = getYesNo(&answer);// ask user if this is correct 
          if(answer=='y')// if correct, brag and break from loop
          {
            brag();
            break;
          }//if correct 
          else if(answer=='e')
          {
            cout << "Enabling edit mode for the animal: "; 
            editQ(p);
            continue;
          }
          else if(answer=='d')
          {
            continue;
          }

          cout << "Well then, what is it ?\n";// ask user what animal he was thinking of...
          char a[128];//...store in "char a[128]" 
          cin >> a;
          cin.ignore(1000,10);
          cout << "What question should I ask to tell the difference between " // ask what yes/no question differentiates "p->text" from "a".
            << p->text << " and " << a << "?\n";
          char q[128];//...store in "char q[128]" 
          cin.getline(q,128);
          cout << "Which response is correct for " 
            << a << " y or n?" << endl;// ask which response is correct for "a" -- yes or no... 
          char yesNo= getYesNo(&yesNo); //...store in "char yesNo" 
          
          // create two new nodes, names "y" and "n" 
          animal* y = new animal; //setup yes node
          animal *n = new animal; //setup no node
          if(yesNo=='y')// if the correct response for "a" is yes...
          {
            strcpy(y->text,a); // copy "a" into y->text 
            *n=*p;// copy p->text into n->text 

          }//if yes response
          else if(yesNo=='n')// else if the correct response is no... 
          {
            strcpy(n->text,a);// copy "a" into n->text
            *y=*p;// copy p->text into y->text
          }//else if 
          strcpy(p->text,q);// copy "q" into p->text 
          y->yes=0;// set y->yes, n->yes, y->no, and n->no to 0 
          n->yes=0;// set y->yes, n->yes, y->no, and n->no to 0 
          y->no=0;// set y->yes, n->yes, y->no, and n->no to 0 
          n->no=0;// set y->yes, n->yes, y->no, and n->no to 0 
          p->yes=y;// set p->yes to y and p->no to n 
          p->no=n;// set p->yes to y and p->no to n 
          break;
   }
 }

//bragging
 void brag()
 {
   cout << "AI for the win!!!\n\n";
 }

//delete leaves
 void deleteTree(animal *leaf) 
{
  if(leaf!=0) return; 
  deleteTree(leaf->yes); 
  deleteTree(leaf->no);
  delete leaf;
}

 //save list to dat file
 void saveTree(animal* a, fstream& fout)
{ 
  if (a)
  {
    fout.write((char*)a, sizeof(animal));
    saveTree(a->yes, fout);
    saveTree(a->no, fout);
  }   
}

 //retrieve list from file
 void restoreTree(animal* a, fstream& in)
 {
  in.read((char*)a, sizeof(animal));
  if(a->yes)
  {
    restoreTree(a->yes = new animal, in);
    restoreTree(a->no = new animal, in);
  }
 }

 //edit the question
 void editQ(animal* p)
 {
   cout << "What should this be?\n";// ask user what new question should be
   char a[128];//...store in "char a[128]" 
   cin.getline(a,128);
   strcpy(p->text,a); // copy "a" into p->text        
 }
 
 //delete node
 void deleteNode(animal* p)
{
  cout << "Deleting question. What go you want to replace this question with,Elephant [y]"
    << " or another Animal [n]? " << endl;
  char answer = getYesNo(&answer);
  if(answer=='y')
  {
    char ele[128] = "Elephant";
    strcpy(p->text,ele);
  }
  else if(answer=='n')
  {
    char a[128];
    cout << "New animal name: ";
    cin.getline(a, 128);
    strcpy(p->text,a);
  }
  p->yes=0;
  p->no=0;
}
