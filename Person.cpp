#include <bits/stdc++.h>
#include "Person.h"
using namespace std;

// Default constructor - all fields are blank
Person::Person() {
    setName("");
    setPhoneNumber("");
    setEmailAddress("");
}

// Overloaded constructor - this describes a person with the bare minimum contact information required - name (n) and phone number (p)
Person::Person(string n, string p) {
    setName(n);
    setPhoneNumber(p);
    setEmailAddress("");
}

// Overloaded constructor - this will be used if a third field for an email address is provided. (n - name, p - phone, e - email)
Person::Person(string n, string p, string e) {
    setName(n);
    setPhoneNumber(p);
    setEmailAddress(e);
}

// Destructor
Person::~Person() {
    ;
}

Person::Person(const Person& other) {
    setName(other.getName());
    setPhoneNumber(other.getPhoneNumber());
    setEmailAddress(other.getEmailAddress());
}

// Getter and setter methods (for encapsulation)
string Person::getName() const {
    return name;
}

string Person::getPhoneNumber() const {
    return phoneNumber;
}

string Person::getEmailAddress() const {
    return emailAddress;
}

void Person::setName(string n) {
    name = n;
}

void Person::setPhoneNumber(string p) {
    phoneNumber = p;
}

void Person::setEmailAddress(string e) {
    emailAddress = e;
}

// Generic method to display an individual's contact information
void Person::display() const {
    cout << "Name: " << getName() << "\n"
         << "Phone: " << getPhoneNumber() << "\n";
    if (getEmailAddress() != "") {
        cout << "Email: " << getEmailAddress() << endl;
    }
}
