#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector> 
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// By Aislinn O'Connell
// Started: 5/29/2022
// Last Edited: 6/8/2022
// Customer Class: Creates an individual customer for the movie rental store. 
//      Stores ID, name, and their personal transaction history. 
//   Additional Functions:
//   -- overloaded print operator to print out customers
//   -- stores movie action into personal history
// Implementation and assumptions:
//   -- 
//   -- 
//---------------------------------------------------------------------------


class Customer {  
public:
    Customer();          // default constructor
    Customer(string firstName, string lastName, int id);    // constructor with necessary information
    ~Customer();        // destructor
    int getID() const;  // returns customer ID
    string getName() const;     // returns customer full name
    string getFirstName() const;    // returns customer first name
    string getLastName() const;     // returns customer last name
    void showHistory();             // prints out customer history
    void storeMovie(string movieCommand);       // stores command into customer history

    friend std::ostream& operator<<(std::ostream &output, const Customer &customer); // overloaded << operator
private:
    string firstName;   // customer first name
    string lastName;    // customer last name
    int id;             // customer ID
    vector<string> history;     // customer history
};
#endif     