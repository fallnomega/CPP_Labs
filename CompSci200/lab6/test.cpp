// Lab 6b: ShortestRoute2.cpp
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
    Leg(const char* const startLoc,const char* const endLoc, const double miles):
    startCity(startLoc),endCity(endLoc), distance(miles){};
    class Route;
    friend void printRoute(ostream&, const Route&);
    friend void printLeg(ostream&, const Leg&);
};

class Route 
{ 
const int count; //number of Legs in array 
const Leg** const route; //dynamically-sized array of Legs 

public: 
Route(const Leg &leg) //constructor to create a Route 
: count(1), route(new const Leg*[count]) 
{ 
route[0] = &leg; 
} 

Route(const Route &r, const Leg &leg) //constructor to add a Leg to Route 
: count(r.count + 1), route(new const Leg*[count]) 
{ 
for(int i=0; i < r.count; i++) //traverse route 
route[i] = r.route[i]; //copy existing route 
route[count - 1] = &leg; //add new leg to route 
} 

Route(const Route &r) //copy constructor 
: count(r.count), route(new const Leg*[count]) 
{ 
for(int i=0; i < r.count; i++) //traverse route 
route[i]=r.route[i]; //copy route 
} 

friend void printRoute(ostream&, const Route&); //print function 
friend double getDist(const Route &r); //return distance of a route 
bool isGreaterThan(const Route&) const; //compare function 

~Route() //destructor 
{ 
delete[] route; //delete dynamically allocated memory 
} 
};

//////////////
//prototypes//
//////////////

void printLeg(ostream&, const Leg&);
void printRoute(ostream&, const Route&);

////////
//main//
////////

int main()
{
    cout << "Programmer: Jason Hillin\nLab 5b: ShortestRoute2.cpp\n"
    << "Description: Route from SF to Omaha.\n\n";
    Leg a("San Francisco", "Sacramento", 70.0);
    Leg b("Sacramento", "Reno", 120.0);
    Leg c("Reno", "Salt Lake City", 500.0);
    Leg d("Salt Lake City", "Denver", 300.0);
    Leg e("Denver", "Omaha", 500.0);
    
    printLeg(cout,a);
    printLeg(cout,b);
    printLeg(cout,c);
    printLeg(cout,d);
    printLeg(cout,e);
    
    cout << "Before Route(a)\n";
    Route ra(a);
    cout << "After Route(a)\n";// route from San Francisco to Sacramento
    Route rb(ra, b); // route from San Francisco to Reno
    Route rc(rb, c); // route from San Francisco to Salt Lake City
    Route rd(rc, d); // route from San Francisco to Denver
    Route re(rd, e); // route from San Francisco to Omaha
    
    //printRoute(cout, rc);
    
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
void printRoute(ostream& out, const Route& trip) //print 5 objects the routes array
{
  for(int i = 0;i<trip.count;i++) cout << trip[i].count << endl;
}