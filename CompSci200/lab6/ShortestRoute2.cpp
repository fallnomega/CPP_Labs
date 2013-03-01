// Lab 6b: ShortestRoute2.cpp
// Programmer: Jason Hillin
// Editor(s) used: VS 2010 Express
// Compiler(s) used: VS 2010 Express
//

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Route;
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
    friend class Route;
    friend void printRoute(ostream&, const Route&);
};

class Route
{
private:
  const int index;
  const Leg** leg;
  const double totalDist;
public:
  // create route with first leg
	Route(const Leg& newLeg):leg(new const Leg*[1]),index(1),totalDist(newLeg.distance)
  {
    leg[0]=&newLeg;
  };
    
  //add new leg to the route
	Route(const Route& route,const Leg& newLeg):leg(new const Leg*[route.index+1]),index(route.index+1),totalDist(route.totalDist+newLeg.distance)
  {
	  //cout << totalDist << endl;
    for(int i=0;i<index-1;i++)
    {
      leg[i]=route.leg[i];
    }
    leg[route.index]=&newLeg;  
  };

  //copy contructor
	Route(const Route& temp):index(temp.index),leg(new const Leg*[index]),totalDist(temp.totalDist)
  {
    for(int i =0;i<=temp.index;i++) leg[i]=temp.leg[i];
  };

  //destructor
  ~Route(){delete [] leg;};
  friend void printRoute(ostream&, const Route&);
};

//////////////
//prototypes//
//////////////

void printRoute(ostream&, const Route&);

////////
//main//
////////

int main()
{
  cout << "Programmer: Jason Hillin\nLab 6b: ShortestRoute2.cpp\n"
    << "Description: Route from SF to International Space Station.\n\n";
  Leg a("San Francisco", "Los Angeles", 381.0);
  Route ra(a);// route from San Francisco to Los Angeles
  Leg b("Los Angeles", "Phoenix", 373.0);
  Route rb(ra, b); // route from Los Angeles to Phoenix
  Leg c("Phoenix", "New Orleans", 1520.0);
  Route rc(rb, c); // route from Phoenix to New Orleans
  Leg d("New Orleans", "Cape Canaveral", 692.0);
  Route rd(rc, d); // route from New Orleans to Cape Canaveral
  Leg e("Cape Canaveral", "International Space Station", 214.5);
  Route re(rd, e); // route from Cape Canaveral to International Space Station

  //print the glorious jouney into space
  printRoute(cout,re);
  
  //test copy constructor
  cout << "\n\nTest copy constructor\n";
  { // start local scope 
    Route rCopy = ra; 
    printRoute(cout, rCopy); 
  } // end local scope 
  printRoute(cout, ra);


  cout << endl;
}

/////////////
//functions//
/////////////

void printRoute(ostream& out, const Route& trip) //print 5 objects the routes array
{
  cout << "From " << trip.leg[0]->startCity;
  for(int i = 0;i<=trip.index-1;i++)
  {
    cout << " to " << trip.leg[i]->endCity;
  }
  cout << ",\nthe total distance  is : " << trip.totalDist << " miles"<< endl;
}