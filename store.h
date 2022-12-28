// ------------------------------- store.h -------------------------------
//
// Mahsa Mohajeri, CSS 343
// Created:         05/29/22
// Last Modified:   05/8/22
// ------------------------------------------------------------------------
// Purpose: Create a store by reading in the three data files (Customer, Movie, and // Inventory) consisting of many // lines and be able to use the data provided 
// to create to conduct transactions. This class can also display the list of movies 
// in the store as well as customers who have accounts. 
// ------------------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid.
// ------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include "customer.h"
#include "movie.h"
#include "inventory.h"
#include "hashTable.h"
#include "string"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Store{
public: 
  Store();
  ~Store();
  void loadMovies();
  void loadCustomers();
  void readCommandFile(string fileName);
  void readCustomersFile(string fileName);
  void readMovieFile(string fileName);
  bool addCustomer(int hashkey, Customer customer);
  bool findCustomer(int ID);
private:
  Inventory inventory;
  HashTable<int, Customer> customersList;
    
};
#endif
