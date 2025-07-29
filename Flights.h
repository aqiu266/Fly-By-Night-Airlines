#include "Flight.h"
using namespace std;
#ifndef FLIGHTS_H_
#define FLIGHTS_H_
const int MAXFLIGHTS = 10;
class Flights {
private:
    int flightCount; // Live count of the number of active flights
    Flight* flights[MAXFLIGHTS]; // Array of flights
    Flight* selectedFlight; // Selected flight to book/cancel
public:
    // Constructor and destructor
    Flights();
    virtual ~Flights();
    // Getter and setter
    Flight* getSelectedFlight();
    void setSelectedFlight(Flight*);
    // Methods for main menu options/operations
    void addFlight();
    void listFlights();
    bool selectFlight();
    void cancelFlight();
    void printPassengers();
};

#endif
