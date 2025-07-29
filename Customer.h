#include <bits/stdc++.h>
#include "Person.h" // inherits (is-a relationship) the Person class
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer : public Person {
    private:
        string homeAddress; // Customer's home address
    public:
	// Constructors
        Customer(); // Default constructor
        Customer(string, string); // Overloaded constructor taking name and then phone number as parameters
        Customer(string, string, string); // Overloaded constructor for name, phone number, and email address as parameters in that order
        Customer(string, string, string, string);
        Customer(const Customer&); // Copy constructor
        Customer& operator=(const Customer&); // Overloaded assignment operator for deep copy
        ~Customer(); // Destructor: deletes the object and returns the used memory to the heap
        // Getter and setter methods
        string getHomeAddress() const;
        void setHomeAddress(string);
	// Information display method
        void display() const override; // override Person::display()
};

#endif
