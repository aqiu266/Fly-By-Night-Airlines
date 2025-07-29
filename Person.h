#include <bits/stdc++.h>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

// Parent object that customers and flight staff/personnel will inherit, methods centered around contact information
class Person {
    protected:
        string name;
        string phoneNumber;
        string emailAddress;
    public:
	// Constructors: all persons MUST enter a name and a phone number - email address is optional
        Person(); //Default constructor.
        Person(string, string); // Overloaded constructor which takes a name as the first parameter and a phone number as a second parameter
        Person(string, string, string); // Overloaded constructor which takes a name as the first parameter, a phone number as a second parameter, and an email address as the third parameter
        Person(const Person&);
        virtual ~Person(); //Virtual destructor: Ensures proper cleanup for derived classes. *****************************************************
        //Getter and setter methods for access/mutation of person's details.
        string getName() const;
        string getEmailAddress() const;
        string getPhoneNumber() const;
        void setName(string);
        void setEmailAddress(string);
        void setPhoneNumber(string);
        virtual void display() const; // Virtual method for displaying information which will be overrided by Customer and Staff (to be added) classes.
};

#endif
