#include "Flights.h"
#include <iostream>
#include <cstdlib>
const int clearLines = 34;
using namespace std;

void clearScreen() {
    for (int i = 0; i < clearLines; i++) cout << endl; // Visually removes clutter
}

void displayFlightMenu() {
    cout << "--- Flight Seat Reservation Menu ---\n";
    cout << "1. View Seat Status\n";
    cout << "2. Reserve a Seat\n";
    cout << "3. Cancel a Reservation\n";
    cout << "4. Cancel by Name\n";
    cout << "5. Cancel by Phone Number\n";
    cout << "6. Back to Main Menu\n";
    cout << "Choose an option: ";
}

void displayMainMenu(){
    cout << "\n--- Flight Management System Menu ---\n";
    cout << "1. Add Flight\n";
    cout << "2. List Flights\n";
    cout << "3. Check, Book or Cancel Ticket(s)\n";
    cout << "4. Cancel Flight\n";
    cout << "5. Print Passenger Manifest\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int bookTicket(Flight* flight){
    int choice;
    string pName;
    string pNumber;
    bool firstTimeFlag2 = true;

    while (true) {
        if (firstTimeFlag2) {
	    firstTimeFlag2 = false;
        } else {
            clearScreen();
        }

        displayFlightMenu();

        if (!(cin >> choice)) {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input. Please enter a number.\n";
            cout << "\nPress Enter to continue...";
            cin.get();
            cin.get();
            continue;
        }

        cin.ignore();
        switch (choice) {
            case 1:
                flight->displaySeats();
                break;
            case 2: {
                int seatNum;
                string name, phone, email, address;
                cout << "Enter seat number (1-10): ";
                cin >> seatNum;

                if (flight->isReserved(seatNum)) {
                    cin.get();
                    cout << "This seat is already reserved.\n";
                    break;
                }

                cin.ignore();
                cout << "Name: "; getline(cin, name);
                cout << "Phone: "; getline(cin, phone);
                cout << "Email: "; getline(cin, email);
                cout << "Address: "; getline(cin, address);

                Customer* c = new Customer(name, phone, email, address);
                if (flight->reserveSeat(seatNum, c)) {
                    cout << "Seat reserved successfully.\n";
                } else {
                    cout << "Failed to reserve seat.\n";
                    delete c;
                }
                break;
            }
            case 3: {
                int seatNum;
                cout << "Enter seat number to cancel (1-10): ";
                cin >> seatNum;
                cin.get();
                if (flight->cancelSeat(seatNum)) {
                    cout << "Reservation canceled.\n";
                } else {
                    cout << "No reservation found for that seat.\n";
                }
                break;
            }
            case 4: {
                cout << "Enter Customer's name: ";
                cin >> pName;
                cin.get();
                if (flight->cancelSeatByName(pName)) {
                    cout << "Reservation canceled.\n";
                } else {
                    cout << "No reservation found with that name.\n";
                }
                break;
            }
            case 5: {
                cout << "Enter Customer's phone number: ";
                cin >> pNumber;
                cin.get();
                if (flight->cancelSeatByPhone(pNumber)) {
                    cout << "Reservation canceled.\n";
                } else {
                    cout << "No reservation found with that phone number.\n";
                }
                break;
            }
            case 6: {
                cout << "Back to Main Menu!\n";
                return 0;
            }
            default: {
                cout << "Invalid option. Try again.\n";
            }
            
        }
        cout << "\nPress Enter to continue...";
        cin.get();
    }
}

int main() {
    int choice;
    Flights booking;
    bool firstTimeFlag1 = true;

    while (true) {
        if (firstTimeFlag1) {
            firstTimeFlag1 = false;
        } else {
            clearScreen();
        }

        displayMainMenu();

        if (!(cin >> choice)) {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input. Please enter a number.\n";
            cout << "\nPress Enter to continue...";
            cin.get();
            continue;
        }

        cin.ignore();
        switch (choice) {
            case 1:
                booking.addFlight();
                break;
            case 2:
                booking.listFlights();
                break;
            case 3:
                if (booking.selectFlight()) {
                    bookTicket(booking.getSelectedFlight());
                }
                break;
            case 4:
                booking.cancelFlight();
                break;
            case 5:
                booking.printPassengers();
                break;
            case 6:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";

        }
        cout << "\nPress Enter to continue...";
        cin.get();
    }

    return 0;
}
