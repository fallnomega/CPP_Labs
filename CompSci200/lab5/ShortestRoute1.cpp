// Lab 5b: ShortestRoute1.cpp
// Programmer: Jason Hillin
// Editor(s) used: VS 2010 Express
// Compiler(s) used: VS 2010 Express
//

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

/////////
//class//
/////////

class Leg
{
private:
  const char* const startCity;
  const char* const endCity;
  const double distance;
public:
  Leg::Leg(const char* const startLoc,const char* const endLoc, const double miles):
  startCity(startLoc),endCity(endLoc), distance(miles){};
  
  friend void printLeg(ostream&, const Leg&);
};

//////////////
//prototypes//
//////////////

void printLeg(ostream&, const Leg&);

////////
//main//
////////

int main()
{
  cout << "Programmer: Jason Hillin\nLab 5b: ShortestRoute1.cpp\n"
    << "Description: Scenic route from SF to Portland.\n\n";

  //routes object array from SF to Portland
  const Leg routes[]=
  {
    Leg("San Francisco", "San Jose", 20.0),
    Leg("San Jose", "Los Angeles",340),
    Leg ("Los Angeles","Houston",1546),
    Leg ("Houston", "Austin",162),
    Leg("Austin","Portland",2057)
  };
  
  for(int i =0;i<5;i++) printLeg(cout,routes[i]); //print objects in routes array
  cout << endl;
}

/////////////
//functions//
/////////////

void printLeg(ostream& out, const Leg& trip) //print 5 objects the routes array
{
  out << trip.startCity << " to " << trip.endCity << ", " << 
    trip.distance << " miles." << endl;
}
