#include <bits/stdc++.h>
#include "Flights.h"
using namespace std;

// Constructor and destructor
Flights::Flights() {
    flightCount = 0;
}

Flights::~Flights() {
    for (int i = 0; i < flightCount; i++){
        cout << "Deleting Flight " << flights[i]->getFlightNumber() << "\n";
        delete flights[i];
    }
}

// Getter and setter for selected flight
Flight* Flights::getSelectedFlight(){
    return selectedFlight;
}

void Flights::setSelectedFlight(Flight* sf){
    selectedFlight = sf;
}

// Flight operations/manipulations which will be done via the main menu
// Add a flight
void Flights::addFlight() {
    if (flightCount == MAXFLIGHTS) {
        cout << "The maximum number of flights has already been reached. Another flight may not be added." << endl;
        return;
    }

    cout << "Please input the flight number:\n";
    string flightNum;
    bool flag = false;
    cin >> flightNum;

    for (int i = 0; i < flightCount; i++){
        if (flights[i]->getFlightNumber() == flightNum) {
            cout << "This flight number is already associated with an existing flight" << endl;
            flag = true;
            break;
        }
    }

    if (!flag) {
        flights[flightCount] = new Flight(flightNum);
        flightCount++;
    }

    cin.get();
}

// Lists out active flights
void Flights::listFlights() {
    if (flightCount > 1) {
        cout << "There are " << flightCount << " active flights right now:" << endl;
    } else if (flightCount == 1) {
        cout << "There is 1 active flight right now:" << endl;
    } else {
        cout << "There are no active flights right now." << endl;
    }

    for (int i = 0; i < flightCount; i++) {
        cout << "Flight " << setw(2) << (i + 1) << ": " << flights[i]->getFlightNumber() << endl;
    }
}

// A method to be used by other methods which indicates which flight the user would like to manipulate
bool Flights::selectFlight(){
    cout << "Please input the flight number:\n";
    string flightNum;
    bool flag = false;
    cin >> flightNum;
    cin.get();

    for (int i = 0; i < flightCount; i++){
        if (flights[i]->getFlightNumber() == flightNum) {
            setSelectedFlight(flights[i]);
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "This flight number is not an existing flight" << endl;
    }
    return flag;
}

// Cancels an entire flight
void Flights::cancelFlight(){
    cout << "Please input flight number:\n";
    string flightNum;
    bool flag = false;
    cin >> flightNum;
    cin.get();

    for (int i = 0; i < flightCount; i++){
        if (flag) {
            flights[i - 1] = flights[i];
        }
        if (flights[i]->getFlightNumber() == flightNum) {
            delete flights[i];
            flag = true;
        }
    }

    if (!flag) {
        cout << "This flight number is not an existing flight" << endl;
    } else {
        flightCount--;
    }
}

// Prints the passengers in by seat ordering and by alphabetical order
void Flights::printPassengers() {
    cout << "Please input the flight number:\n";
    string flightNum;
    bool flag = false;
    cin >> flightNum;
    cin.get();

    for (int i = 0; i < flightCount; i++) {
        if (flights[i]->getFlightNumber() == flightNum) {
            setSelectedFlight(flights[i]);
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "This flight number is not an existing flight" << endl;
    } else {
        getSelectedFlight()->printManifestBySeat();
        getSelectedFlight()->printManifestAlphabetical();
    }
}
