	//ODOMETER EXAMPLE FOR NESTED LOOPS

#include <iostream>
#include <iomanip>
using namespace std;

#ifdef __GNUC__
#include <unistd.h>
#elif defined _WIN32
#include <cstdlib>
#endif

int main()
{
cout << "CTRL-C to exit ...\n";

for (int thousands = 0; thousands < 10; thousands++)
{
	for (int hundreds = 0; hundreds < 10; hundreds++)
	{
		for (int tens = 0; tens < 10; tens++)
		{
			for (int ones = 0; ones < 10; ones++)
			{
				cout << thousands << hundreds << tens << ones << ' ';
				cout.flush();
#ifdef __GNUC__
				sleep(1);
#elif defined _WIN32
				_sleep(1000);
#endif
//				cout << '\r';
			}
		}
	}
}

return 0;
}
