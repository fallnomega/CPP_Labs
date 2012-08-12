#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
int choice;
int ochoice;
char a[9]= {'0','1','2','3','4','5','6','7','8'};
int i;

while(true)
{

cout << "\n-------------\n";
cout << "| " << a[0] << " | " << a[1] << " | " << a[2] << " | " << endl;
cout << "-------------\n";
cout << "| " << a[3] << " | " << a[4] << " | " << a[5] << " | " << endl;
cout << "-------------\n";
cout << "| " << a[6] << " | " << a[7] << " | " << a[8] << " | " << endl;
cout << "-------------\n\n";
//x choose
char x = 'x';
char o = 'o';
cout <<"Choose a number for X: ";
cin >> choice;

//////////////////////
//error checks for x//
//////////////////////
while(true)
{
	if((choice>8))
		{
			cout << "Cannot go above 8, choose again!\nChoose a number for X: ";
			cin >> choice;
		}
	else if((a[choice]==o))
	{
		cout << "ERROR! O already has that spot.\nChoose a number for X: ";
		cin >> choice;
	}
	else 
	{
		a[choice]=x;
		break;
	}
}

//////////////////////
//error checks for o//
//////////////////////
cout <<"Choose a number for O: ";
cin >> ochoice;
while(true)
{
	if((ochoice>8))
		{
			cout << "Cannot go above 8, choose again!\nChoose a number for O: ";
			cin >> ochoice;
		}
	else if((a[ochoice]==x))
	{
		cout << "ERROR! X already has that spot.\nChoose a number for O: ";
		cin >> ochoice;
	}
	else 
	{
		a[ochoice]=o;
		break;
	}
}

//////////////////
//X winning rows//
//////////////////
if((a[0]==x)&&(a[1]==x)&&(a[2]==x))
{cout << "\n\n\nX won\n"; break;}
if((a[3]==x)&&(a[4]==x)&&(a[5]==x))
{cout << "\n\n\nX won\n"; break;}
if((a[6]==x)&&(a[7]==x)&&(a[8]==x))
{cout << "\n\n\nX won\n"; break;}
if((a[0]==x)&&(a[3]==x)&&(a[6]==x))
{cout << "\n\n\nX won\n"; break;}
if((a[1]==x)&&(a[4]==x)&&(a[7]==x))
{cout << "\n\n\nX won\n"; break;}
if((a[2]==x)&&(a[5]==x)&&(a[8]==x))
{cout << "\n\n\nX won\n"; break;}
if((a[0]==x)&&(a[4]==x)&&(a[8]==x))
{cout << "\n\n\nX won\n"; break;}
if((a[2]==x)&&(a[4]==x)&&(a[6]==x))
{cout << "\n\n\nX won\n"; break;}

//////////////////
//O winning rows//
//////////////////
if((a[0]==o)&&(a[1]==o)&&(a[2]==o))
{cout << "\n\n\nO won\n"; break;}
if((a[3]==o)&&(a[4]==o)&&(a[5]==o))
{cout << "\n\n\nO won\n"; break;}
if((a[6]==o)&&(a[7]==o)&&(a[8]==o))
{cout << "\n\n\nO won\n"; break;}
if((a[0]==o)&&(a[3]==o)&&(a[6]==o))
{cout << "\n\n\nO won\n"; break;}
if((a[1]==o)&&(a[4]==o)&&(a[7]==o))
{cout << "\n\n\nO won\n"; break;}
if((a[2]==o)&&(a[5]==o)&&(a[8]==o))
{cout << "\n\n\nO won\n"; break;}
if((a[0]==o)&&(a[4]==o)&&(a[8]==o))
{cout << "\n\n\nO won\n"; break;}
if((a[2]==o)&&(a[4]==o)&&(a[6]==o))
{cout << "\n\n\nO won\n"; break;}

}

//////////////////////
//Show board results//
//////////////////////
cout << "\n-------------\n";
cout << "| " << a[0] << " | " << a[1] << " | " << a[2] << " | " << endl;
cout << "-------------\n";
cout << "| " << a[3] << " | " << a[4] << " | " << a[5] << " | " << endl;
cout << "-------------\n";
cout << "| " << a[6] << " | " << a[7] << " | " << a[8] << " | " << endl;
cout << "-------------\n\n";
return 0;
}