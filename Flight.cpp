#include <bits/stdc++.h>
using namespace std;
#include "Flight.h"

// Quicksort function to sort seats by customers' names alphabetically
void seatQuickSort(Seat arr[], int n, int l, int r) {
    Seat pivot = arr[l];
    Seat temp;
    int leftpt = l;
    int rightpt = r;

    while (rightpt > leftpt){
        while (rightpt > leftpt) {
            if (arr[rightpt].getCustomer()->getName() < pivot.getCustomer()->getName()) {
                arr[leftpt] = arr[rightpt];
                break;
            }
            rightpt--;
        }

        while (leftpt < rightpt){
            if (arr[leftpt].getCustomer()->getName() > pivot.getCustomer()->getName()) {
                arr[rightpt] = arr[leftpt];
                break;
            }
            leftpt++;
        }
    }

    arr[rightpt] = pivot;

    if (rightpt - 1 > l) {
        seatQuickSort(arr, n, l, rightpt - 1);
    }
    if (leftpt + 1 < r) {
        seatQuickSort(arr, n, leftpt + 1, r);
    }
}

// Default constructor - no flight number is given yet, but all seats are correctly numbered
Flight::Flight() {
    setFlightNumber("");
    seats = new Seat[10];

    for (int i = 0; i < 10; i++) {
        seats[i].setSeatNumber(i + 1);
    }
}

// Overloaded constructor which takes a flight number and also numbers all seats
Flight::Flight(string fn) {
    setFlightNumber(fn);
    seats = new Seat[10];

    for (int i = 0; i < 10; i++) {
        seats[i].setSeatNumber(i + 1);
    }
}

// Destructor for cancelling flights
Flight::~Flight() {
    cout << "Cancelling Flight " << getFlightNumber() << ". Contacting all customers with reservations and their contact information:\n";
    for (int i = 0; i < 10; i++) {
        if (!seats[i].getForSale()) {
            Customer* c = seats[i].getCustomer();
            cout << "Seat " << setw(2) << seats[i].getSeatNumber() << ":\n";
            if (c != nullptr) c->display();
        }
    }

    delete[] seats;
}

// Getter and setter methods for flight number
string Flight::getFlightNumber() const {
    return flightNumber;
}

void Flight::setFlightNumber(string fn) {
    flightNumber = fn;
}

// Methods for handling operations manipulating or accessing/displaying information on seat reservations
// Flight method for checking if a particular seat is reserved
bool Flight::isReserved(int seatNum){
        return !seats[seatNum - 1].getForSale();
}

// Displays the reservation status for each seat
void Flight::displaySeats() const {
    cout << "Seats for Flight " << flightNumber << ":" << endl;
    for (int i = 0; i < 10; i++) {
        seats[i].displayStatus();
        cout << "---------------------" << endl;
    }
}

// Attempts to reserve a given seat for a given customer
bool Flight::reserveSeat(int seatNum, Customer* c) {
    if (seatNum < 1 || seatNum > 10) {
        cout << "The requested seat does not exist. Please request to reserve a seat of a number between 1 and 10" << endl;
        return false; // do not allow for requests to reserve seats that don't exist
    }

    return seats[seatNum - 1].makeReservation(c); // From here, the Seat makeReservation() method is used on the requested seat to check if a reservation can be made (and to make it if possible).
}

// Attempts to cancel a reservation for a given seat
bool Flight::cancelSeat(int seatNum) {
    if (seatNum < 1 || seatNum > 10) {
        cout << "The requested seat does not exist. Please request to reserve a seat of a number between 1 and 10" << endl;
        return false; // do not allow for requests to cancel reservations for seats that don't exist
    }

    return seats[seatNum - 1].cancelReservation(); // From here, the Seat cancelReservation() method is used on the requested seat to check if the reservation can be cancelled (and to cancel it if possible).
}

// Attempts to cancel a reservation given a customer's name
bool Flight::cancelSeatByName(string name) {
    int seatNum = -1;
    for (int i = 0; i < 10; i++) {
        if (seats[i].getForSale()) continue;
        string cName = seats[i].getCustomer()->getName();
        if (cName != name) {
            continue;
        } else {
            seatNum = seats[i].getSeatNumber();
            break;
        }
    }
    if (seatNum == -1) return false;
    return cancelSeat(seatNum);
}

// Attempts to cancel a reservation given a customer's phone number
bool Flight::cancelSeatByPhone(string phone) {
    int seatNum = -1;
    for (int i = 0; i < 10; i++) {
        if (seats[i].getForSale()) continue;
        string cPhone = seats[i].getCustomer()->getPhoneNumber();
        if (cPhone!=phone) {
            continue;
        } else {
            seatNum = seats[i].getSeatNumber();
            break;
        }
    }
    if (seatNum == -1) return false;
    return cancelSeat(seatNum);
}

// Prints the passenger manifest by passenger's seat number, in ascending order
void Flight::printManifestBySeat() const {
    cout << "\nPassenger Manifest (by seat number):\n";
    for (int i = 0; i < 10; i++) {
        if (!seats[i].getForSale()) {
            Customer* c = seats[i].getCustomer();
            cout << "Seat " << setw(2) << seats[i].getSeatNumber() << ":";
            if (c != nullptr) {
                c->display();
            } else {
                cout << "Not reserved" << endl;
            }
        }
    }
}

// Print the passenger manifest by passenger's name, ordered alphabetically
void Flight::printManifestAlphabetical() const {
    Seat* seatsCopy = new Seat[10];
    int j = 0;

    for(int i = 0; i < 10; i++) {
    	if (!seats[i].getForSale()){
    	    seatsCopy[j] = seats[i];
    	    j++;
    	}
    }

    seatQuickSort(seatsCopy, j, 0, j-1);
    cout << "\nPassenger Manifest (alphabetical):\n";

    for (int i = 0; i < j; i++) {
        Customer* c = seatsCopy[i].getCustomer();
        if (c != nullptr) c->display();
    }

    delete[] seatsCopy;
}
