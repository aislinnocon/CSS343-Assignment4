#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector> 
#include <iostream>
#include <map> 
#include "movie.h"
using namespace std;

//---------------------------------------------------------------------------
// By Aislinn O'Connell
// Started: 5/29/2022
// Last Edit: 6/8/2022
// Inventory Class: Keeps track of all the movies in the inventory and manages
//      borrowing and returning of movies. 
//   Additional Functions:
//   -- prints out entire inventory
//   -- prints out error messages when movie stock is too low to borrow
//   -- stores and prints a specific customer history
// Implementation and assumptions:
//   -- information passed in for the movie types stays specific to type
//   -- no additional types of movie are introduced to the rental store system
//---------------------------------------------------------------------------


class Inventory {  
public:
    Inventory();                        // default constructor
    ~Inventory();                       // destructor
    void addMovie(Movie movie);         // adds movie to specific vector
    void printEntireInventory();        // prints out the entire movie inventory
    void printWorkingInventory();       // prints out entire movie inventory with stock specifically highlighted

    bool actionComedy(string action, string title, int year);               // borrows, returns, and searches for comedies
    bool actionDrama(string action, string director, string title);         // borrows, returns, and searches for dramas
    bool actionClassic(string action, int month, int year, string majorActor);  // borrows, returns, and searches for classics

    void storeCustomerHistory(int id, string history);      // stores a specific customer's history
    void printCustomerHistory(int id);                      // prints a specific customer's history
    
private:
    vector<Movie> classics;         // vector containing all classics movies
    vector<Movie> comedies;         // vector containing all comedy movies
    vector<Movie> dramas;           // vector containing all drama movies

    map<int, vector<string>> customerHistory;     // map containing all the customer history
};
#endif     