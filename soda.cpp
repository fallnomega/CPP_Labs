#include <iostream>
#include <string>

using namespace std;
void getDrink();
double getAdd(double a,double b)
{
	double total = a + b;
	cout << "Total: " << total << "\n";
	return 0;
}
void getPrice()
{
	
cout << "1.00 for a [1]Coke\n";
cout << "1.25 for a [2]Diet Coke\n";
cout << "1.50 for a [3]Sprite\n";
cout << "1.75 for a [4]Diet Sprite\n";
cout << "2.00 for a [5]Water\n";
char answer;
cout << "Purchase Drink? : ";
cin >> answer;
if(answer=='y'||answer=='Y')
getDrink();
else cout <<"Bye Bye\n";
}

int main()

{
	string choice;
	double x = 2.25;
	double y = 3.00;
	int item;
	string price;
	cout << "[X to exit]\nGo ahead and purchase [list] or get pricing [price] ? >";
	cin >> choice;
	if(choice=="price") 
	getPrice();
	if(choice=="list")
	getDrink();
	if(choice=="X"||choice=="x") cout << "Bye Bye\n";
	if(choice=="add") getAdd(x, y);
return 0;
}

void getDrink()

{
	while(true)
	{
	char choice;
	cout << "			Choice[1-5]\n			------------\n			[1]Coke\n";
	cout << "			[2]Diet Coke\n			[3]Sprite\n			[4]Diet Sprite\n";
	cout << "			[5]Water\n			-------------------\n			Choice:>>";
	cin >> choice;
		
		if(choice=='1') cout << "Coke\n\n\n\n\n\n";
		else if(choice=='2') cout << "Diet Coke\n\n\n\n\n\n";
		else if(choice=='3') cout << "Sprite\n\n\n\n\n\n";
		else if(choice=='4') cout << "Diet Sprite\n\n\n\n\n\n";
		else if(choice=='5') cout << "Water\n\n\n\n\n\n";
		else cout << "Wrong Choice\n\n\n\n\n\n";
		break;		
	} 
	main();

}

