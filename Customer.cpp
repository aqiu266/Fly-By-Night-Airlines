#include <bits/stdc++.h>
#include "Customer.h"
using namespace std;

// Default Constructor
Customer::Customer() : Person() {}

// Overloaded constructor which will take in two pieces of contact information - name, phone number (bare minimum)
Customer::Customer(string n, string p) : Person(n, p) {}

// Overloaded constructor which will take in three pieces of contact information - name, phone number, email address
Customer::Customer(string n, string p, string e) : Person(n, p, e) {}

// Overloaded constructor which will take in four pieces of contact information - name, phone number, email address, home address
Customer::Customer(string n, string p, string e, string h) : Person(n, p, e) {
    setHomeAddress(h);
}

// Copy Constructor
Customer::Customer(const Customer& other) {
    setName(other.getName());
    setPhoneNumber(other.getPhoneNumber());
    setEmailAddress(other.getEmailAddress());
    setHomeAddress(other.getHomeAddress());
}

// Overloaded assignment operator
Customer& Customer::operator = (const Customer& other) {
    if (this != &other) {
        setName(other.getName());
        setPhoneNumber(other.getPhoneNumber());
        setEmailAddress(other.getEmailAddress());
        setHomeAddress(other.getHomeAddress());
    }

    return *this;
}

// Destructor
Customer::~Customer() {}

// Getter and setter for an extra member variable which is useful for contacting customers - home address
string Customer::getHomeAddress() const {
    return homeAddress;
}

void Customer::setHomeAddress(string h) {
    homeAddress = h;
}

// Overrided display method for customers
void Customer::display() const {
    cout << "\n--- Customer Information ---\n";
    Person::display();
    cout << "Address: " << homeAddress << "\n";
}
