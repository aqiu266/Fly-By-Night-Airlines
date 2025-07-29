#include <bits/stdc++.h>
#include "Customer.h"
#include "Seat.h"
using namespace std;

// Default Constructor
Seat::Seat() {
    setSeatNumber(0);
    setForSale(true);
    customer = nullptr; // For some reason, when working with passenger manifest alphabetical, a program-crashing is entered where using setCustomer() doesn't work because the initial data at where customer is is not nullptr, and upon deleting that data, the program crashes.
}

// Overloaded constructor to number seats by taking the seat number as a parameter
Seat::Seat(int number) {
    setSeatNumber(number);
    setForSale(true);
    customer = nullptr;
}

Seat::Seat(const Seat& other) {
    setSeatNumber(other.getSeatNumber());
    setForSale(other.getForSale());
    copyCustomer(other.getCustomer());
}

Seat& Seat::operator = (const Seat& other) {
    if (this != &other) {
        setSeatNumber(other.getSeatNumber());
        setForSale(other.getForSale());
        copyCustomer(other.getCustomer());
    }

    return *this;
}

// Destructor to return memory to the heap and ensure no memory leaks
Seat::~Seat() {
    delete customer;
}

void Seat::copyCustomer(Customer* c){
	Customer* cc = new Customer(c->getName(), c->getPhoneNumber(), c->getEmailAddress(), c->getHomeAddress());
	customer = cc;
}
// Getter and setter methods for encapsulation
int Seat::getSeatNumber() const {
    return seatNumber;
}

bool Seat::getForSale() const {
    return forSale;
}

Customer* Seat::getCustomer() const {
    return customer;
}

void Seat::setSeatNumber(int number) {
    seatNumber = number;
}

void Seat::setForSale(bool saleStatus) {
    forSale = saleStatus;
}

void Seat::setCustomer (Customer* c) {
    if (customer != nullptr) {
        delete customer;
    }
    customer = c;
}

// Reserving a seat for a customer given by a Customer object pointer - will check if the seat can be reserved (is not reserved yet/is empty) and will return true and reserve the seat if yes and return false and not reserve the seat if no
bool Seat::makeReservation(Customer* c) {
    if (getForSale()) {
        setCustomer(c);
        setForSale(false);
        return true;
    }

    cout << "This seat is already reserved" << endl;    
    return false;
}

// Cancelling a reservation for a seat - will check if the seat is currently reserved and will return true if yes and cancel the reservation, and return false if not reserved.
bool Seat::cancelReservation() {
    if (getForSale()) {
        cout << "This seat is not currently reserved" << endl;
        return false; // means that there is not currently a reservation
    }

    // if the previous if block ran, this section wouldn't run, so it is guaranteed that there must currently be a reservation for the next three lines to run
    setCustomer(nullptr);
    setForSale(true);
    return true;
}

// Displays the reservation status of the seat - indicating "Available" if not reserved/for sale and indicating "Reserved" followed by contact information if reserved.
void Seat::displayStatus() const {
    cout << "Seat " << seatNumber << ":" << endl;

    if (getForSale()) {
        cout << "Available" << endl;
    } else {
        cout << "Reserved";
        getCustomer()->display();
    }
}
