#include <iomanip>
#include <iostream>
using namespace std;

int main()

{
	cout << "The time is \n ____________\n";
	for (int hours = 0; hours < 24; hours++)
	{
		for (int mins = 0; mins < 60; mins++)
		{
			for (int sec = 0; sec<60; sec++)
			{
				cout << hours << ":"<<mins<<":"<<sec<<"\r";
			}
		}
	}

return 0;
}
