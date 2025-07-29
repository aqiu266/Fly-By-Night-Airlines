#include <bits/stdc++.h>
#include "Customer.h" // This object has a has-a relationship with the Customer object - since customers are assigned to seats, the Seat class uses Customer pointers
using namespace std;

#ifndef SEAT_H
#define SEAT_H


class Seat {
    private:
        int seatNumber; // An integer between 1 and 10 inclusive indicating which seat it is
        bool forSale; // True if the seat is not reserved and therefore for sale, false otherwise
        Customer* customer; // Pointer to the Customer object occupying this seat; nullptr if vacant
    public:
        // Constructors
        Seat(); // Default constructor
        Seat(int); // Overloaded constructor allowing for the assignment of a seat number on initialization
        ~Seat(); // Destructor: deletes the object and returns the used memory to the heap
        Seat(const Seat&); // Copy constructor
        Seat& operator=(const Seat&); // Overloaded assignment operator
        // Getter and setter methods
        int getSeatNumber() const; // Returns the seat number
        bool getForSale() const; // Returns whether or not the seat is for sale
        Customer* getCustomer() const; // Returns the pointer to the Customer object if it exists, and nullptr otherwise.
        void setSeatNumber(int);
        void setForSale(bool);
        void setCustomer(Customer*);
        void copyCustomer(Customer*);
        // Seat information manipulation methods
        bool makeReservation(Customer*); // Attempts to reserve the seat for the parameter customer pointer, returning true if successful and setting the customer member variable to the parameter pointer, and false if unsuccessful (unsuccessful if the seat is already reserved)
        bool cancelReservation(); // Attempts to cancel the seat's reservation, returning true and resetting the customer member variable to nullptr, and false if unsuccessful (unsuccessful if the seat has no active reservation)
        void displayStatus() const; // Displays the contact information of the assigned customer, and indicates that the seat is for sale otherwise
};

#endif
