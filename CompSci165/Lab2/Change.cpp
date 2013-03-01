// Lab 2
// Programmer: Jason Hillin
// Editor(s) used: Xcode & MS Visual C++ 2010 Express
// Compiler(s) used: g++
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::ios;
using std::setprecision;

int main()
{
cout << "Lab 2\n";
cout << "Programmer: Jason Hillin\n\n";
    
//aquire bill amount and amount tendered
cout.setf(ios::fixed|ios::showpoint);
cout << setprecision(2);
double total;
double tendered;
cout << "Please input the amount of the purchase and the amount tendered with a space in between: ";
cin >> total >> tendered;
cin.ignore();

//convert change due from double to int, multiply it by *100
//and add.05 to address rounding issue
double multis = tendered*100 - total*100;
cout << "Change due is: $" << multis/100 << endl;
int multi = multis+.05;
    
//begin the count of currency type returned along in a series of branch statements.
int fifty = 0,twenty = 0,ten = 0,five = 0,one = 0,fifty_cent = 0,quarter = 0,dime = 0,nickle = 0,penny = 0;
int nCount = 0;
while(multi>=nCount)
{
  //50's
  while(nCount+5000<=multi)
  {

    if(nCount+5000>multi) break;
    else
    {
    nCount+=5000;
    fifty++;
    }
  }
  //20's
  while(nCount+2000<=multi)
  {
    if(nCount+2000>multi) break;
    else
    {
    nCount+=2000;
    twenty++;
    }
  }
  //10's
  while(nCount+1000<=multi)
  {
    if(nCount+1000>multi) break;
    else
    {
    nCount+=1000;
    ten++;
    }
  }
  //5's
  while(nCount+500<=multi)
  {
    if(nCount+500>multi) break;
    else
    {
    nCount+=500;
    five++;
    }
  }
  //1's
  while(nCount+100<=multi)
  {
    if(nCount+100>multi) break;
    else
    {
    nCount+=100;
    one++;
    }
  }
  //.50's
  while(nCount+50<=multi)
  {
    if(nCount+50>multi) break;
    else
    {
    nCount+=50;
    fifty_cent++;
    }
  }
  //.25's
  while(nCount+25<=multi)
  {
    if(nCount+25>multi) break;
    else
    {
    nCount+=25;
    quarter++;
    }
  }
  //.10's
  while(nCount+10<=multi)
  {
    if(nCount+10>multi) break;
    else
    {
    nCount+=10;
    dime++;
    }
  }
  //.05's
  while(nCount+5<=multi)
  {
    if(nCount+5>multi) break;
    else
    {
    nCount+=5;
    nickle++;
    }
  }
  //.01's
  while(nCount+1<=multi)
  {
    if(nCount>multi) break;
    else
    {
    penny++;
    nCount++;
    }
  }
break;
}
//breakdown of change that is returned back. 
if(fifty==1) cout << fifty << " $50 bill\n";
  if(fifty>1) cout << fifty << " $50 bills\n";
if(twenty==1) cout << twenty << " $20 bill\n";
  if(twenty>1) cout << twenty << " $20 bills\n";
if(ten>0) cout << ten << " $10 bill\n";
if(five>0) cout << five << " $5 bill\n";
if(one==1) cout << one << " $1 bill\n";
  if(one>1) cout << one << " $1 bills\n";
if(fifty_cent>0) cout << fifty_cent << " 50-cent coin\n";
if(quarter>0) cout << quarter << " 25-cent coin\n";
if(dime==1) cout << dime << " 10-cent coin\n";
  if(dime>1) cout << dime << " 10-cent coins\n";
if(nickle>0) cout << nickle << " 5-cent coin\n";
if(penny==1) cout << penny << " 1-cent coin\n";
  if(penny>1) cout << penny << " 1-cent coins\n";

return 0;
}
