#include <bits/stdc++.h>
#include "Seat.h"
using namespace std;

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight {
    private:
        string flightNumber; // Flight number/code - will take the next inputted line
        Seat* seats; // Array of seats, will have a size of 10 to represent each of the 10 seats (index  i represents seat i+1 - i.e. index 0 is seat 1, index 1 is seat 2, etc.)
    public:
        // Constructors and destructor for Flight class
        Flight();
        Flight(string);
        ~Flight(); // Destructor is used when cancelling flights

        // Getter and setter for flight number
        string getFlightNumber() const;
        void setFlightNumber(string);

        // Flight method for checking if a particular seat on the flight is reserved
        bool isReserved(int);

        // Methods which handle the manipulation and display of a flight's seats
        void displaySeats() const;
        bool reserveSeat(int, Customer*);
        bool cancelSeat(int);
        bool cancelSeatByName(string);
        bool cancelSeatByPhone(string);
        void printManifestBySeat() const;
        void printManifestAlphabetical() const;
};

#endif
