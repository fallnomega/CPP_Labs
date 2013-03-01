// Lab 10: sLList.cpp
// Programmer: Jason Hillin
// Editor(s) used: MS Visual C++ 2010 Express
// Compiler(s) used: MS Visual C++ 2010 Express

#include <iostream>
using std::cout;
using std::endl;

struct tod
{
  int h; //hours 0-23
  int m; //minutes 0-59
  int s; //seconds 0-59
  char d[32];//description
  tod* next;//link
};

//functions
void coutTod(tod *time);

//main
int main()
{
  cout << "Lab 10: sLList.cpp\n"
    << "Programmer: Jason Hillin\n\n";

  //default listing
  tod noon ={12,0,0,"noon"};
  tod midnight={0,0,0,"midnight"};
  tod dinner={22,30,00,"suppertime"};
  tod lunch={17,45,00,"lunchtime"};
  tod slumber={2,45,00,"bedtime"};

  //setting up default link list
  tod *head = 0; //empty linked list
  head = &midnight;
  midnight.next = &slumber;
  slumber.next=&noon;
  noon.next=&lunch;
  lunch.next=&dinner;
  dinner.next=0;
  
  //print default link list
  for(tod* p=head; p;p=p->next) coutTod(p);

  //add breakfast to linked list
  //and print out updated linked list
  tod breakfast={11,45,00,"breakfast"};
  breakfast.next=slumber.next;
  slumber.next=&breakfast;

  cout << "\n\nAdding breakfast\n\n";
  for(tod* p=head; p;p=p->next) coutTod(p);

  //adding class start time to
  //the linked list and printing
  //out the updated listing
  tod class_starts ={19,0,0,"class starts"};
  class_starts.next=lunch.next;
  lunch.next=&class_starts;
  cout << "\n\nAdding class_start\n\n";
  for(tod* p=head;p;p=p->next) coutTod(p);

  //adding class end time to
  //the linked list and printing
  //out the updated listing
  tod class_end = {21,50,0,"class_ends"};
  class_end.next=class_starts.next;
  class_starts.next=&class_end;
  cout << "\n\nAdding class_end\n\n";
  for(tod *p=head;p;p=p->next) coutTod(p);

  //deletions of meal periods
  cout << "\n\nRemoving meals from the list\n\n";
  //method 1
  slumber.next=&noon;
  //method 2
  noon.next=noon.next->next;
  //method 1
  class_end.next=0;
  for(tod *p=head;p;p=p->next) coutTod(p);

  //adding back the meal periods
  cout << "\n\nSlave labor is illegal so I will \nadd back the meal periods.\n\n";

  //method 1
  breakfast.next=head->next->next;
  head->next->next=&breakfast;
  //method 2
  noon.next=&lunch;
  class_end.next=&dinner;
  for(tod *p=head;p;p=p->next) coutTod(p);

}
//functions
void coutTod(tod *time)
{
  cout << time->d << " is " << time->h
    << ":";
  if(time->m< 10) cout << '0';
  cout << time->m << ":";
  if(time->s< 10) cout << '0';
  cout << time->s << endl;
}