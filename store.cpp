// ------------------------------- store.h -------------------------------
//
// Mahsa Mohajeri, CSS 343
// Created:         05/29/22
// Last Modified:   06//22
// ------------------------------------------------------------------------
// Purpose: Create a store by reading in the three data files (Customer, Movie, and // Inventory) consisting of many lines and be able to use the data provided 
// to create to conduct transactions. This class can also display the list of movies 
// in the store as well as customers who have accounts. 
// ------------------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid.
// ------------------------------------------------------------------------

#include "store.h"

// ----------------------- Default Constructor ------------------------
// 
// --------------------------------------------------------------------
Store::Store(){
  
} // end of Store()
// ---------------------------- Destructor ----------------------------
// 
// --------------------------------------------------------------------
Store::~Store()
{
  
} // end of ~Store()

// ---------------------------- loadMovies ----------------------------
// Prints out all the movies in the inventory 
// --------------------------------------------------------------------
void Store::loadMovies()
{
  inventory.printEntireInventory();  
  
} // end of loadMovies()


// ---------------------------- loadMovies ----------------------------
// Prints out all the customers in the system
// --------------------------------------------------------------------
void Store::loadCustomers()
{  
  customersList.printAllData();
} // end of loadCustomers()

// -------------------------- readCommandFile --------------------------
// Reads in all the commands from a text file
// Checks to make sure the commands are valid and fit what we have in the 
// inventory
// Throws errors for invalid information
// ---------------------------------------------------------------------
void Store::readCommandFile(string fileName)
{
  ifstream myFile;
  myFile.open(fileName);
  string line;
  while(getline(myFile,line))
    {
      stringstream ss(line);
      string temp;
      string commandType, mediaType, movieType, movieTitle, directorName, majorActor;
      int customerID, releaseYear, releaseMonth;
      getline(ss, commandType, ' ');

      if (commandType == "I") // NOT WORKING
      {
              // something is going on with I being an entire line and it is not 
      // just equivalent to a line or string that ends with ' ' 
        inventory.printEntireInventory();
      }
      else if(commandType == "H")
      {
        getline(ss, temp, ' ');
        istringstream(temp) >> customerID;
        if(customersList.findItem(customerID) == false)
        {
          cout << "ERROR: No customer with this ID found." << endl;
        }
        else 
        {
          inventory.printCustomerHistory(customerID); 
        }
      }
      else if((commandType == "B") || (commandType == "R"))
      {
        getline(ss, temp, ' ');
        istringstream(temp) >> customerID;
        if(customersList.findItem(customerID) == false)
        {
          cout << "ERROR: No customer with this ID found." << endl;
        } 
        getline(ss, mediaType, ' ');
        if(mediaType != "D")
        {
          cout << "ERROR: Invalid Media Type." << endl;
        }
        getline(ss, movieType, ' ');
        if(movieType == "F")
        {
          getline(ss, movieTitle, ',');
          getline(ss,temp);
          istringstream(temp) >> releaseYear;
          if (inventory.actionComedy("F", " " + movieTitle, releaseYear))
          {
            string history = commandType + " " + movieType + " " + movieTitle + " " + to_string(releaseYear); 
            inventory.storeCustomerHistory(customerID, history); 
            if(commandType == "B"){
              inventory.actionComedy("B", " " + movieTitle, releaseYear);
            }
            else 
            {
              inventory.actionComedy("R", " " + movieTitle, releaseYear);
            }
          }
        }
        else if (movieType == "D")
        {
          getline(ss,directorName,',');
          getline(ss,movieTitle,',');
          if (inventory.actionDrama("F", " " + directorName, movieTitle))
          {
            string history = commandType + " " + movieType + " " + movieTitle + " " + directorName; 
            inventory.storeCustomerHistory(customerID, history); 
            if(commandType == "B")
            {
              inventory.actionDrama("B", " " + directorName, movieTitle);
            }
            else 
            {
              inventory.actionDrama("R", " " + directorName, movieTitle);
            }
          }
        }
        else if (movieType == "C")
        {
          getline(ss, temp, ' ');
          istringstream(temp) >> releaseMonth;
          getline(ss, temp, ' ');
          istringstream(temp) >> releaseYear;
          getline(ss, majorActor, ' ');
          if (inventory.actionClassic("F", releaseMonth, releaseYear, majorActor))
          {
            string history = commandType + " " + movieType + " " + to_string(releaseMonth) + " " + 
              to_string(releaseYear) + " " + majorActor; 
            inventory.storeCustomerHistory(customerID, history); 
            if(commandType == "B")
            {
              inventory.actionClassic("B", releaseMonth, releaseYear, majorActor);
            }
            else 
            {
              inventory.actionClassic("B", releaseMonth, releaseYear, majorActor);
            }
          }
        }
        else
        {
         cout << "ERROR: Invalid movie type." << endl; 
        }
      }
      else
      {
        cout << "ERROR: Invalid command type." << endl;
      }
    }
} // end of readCommandFile

// -------------------------- readCustomersFile --------------------------
// Reads in all the data provided in the customers text file
// Creates all the customer accounts and puts them in a hashtable 
// -----------------------------------------------------------------------
void Store::readCustomersFile(string fileName)
{
  ifstream myFile;
  myFile.open(fileName);
  string line;
  while(!myFile.eof()){
    getline(myFile, line);
    if(line.empty())
    {
      break;
    }
    stringstream parseLine(line);
    int ID;
    string firstName, lastName;
    parseLine >> ID >> lastName >> firstName;
    Customer newCustomer = Customer(firstName, lastName,ID);
    addCustomer(ID, newCustomer);
    }
} // end of readCustomerFile

// ---------------------------- readMovieFile ----------------------------
// Reads the list of movies provided in the text file 
// and creates a new movie object
// -----------------------------------------------------------------------
void Store::readMovieFile(string fileName)
{
  ifstream myFile;
  myFile.open(fileName);
  string line;
  while(getline(myFile,line))
    {
     stringstream ss(line);
      string movieType, director, title, majorActor, majorActorFirstName, majorActorLastName, temp;
      int stock, releaseYear, releaseMonth;
      getline(ss,movieType,',');
      getline(ss,temp,',');
      istringstream(temp) >> stock;
      getline(ss,director,',');
      getline(ss,title,',');
      if(movieType == "C" || movieType == "c")
      {
        getline(ss,majorActorFirstName,' ');
        getline(ss,majorActorLastName, ' ');
        majorActor = majorActorFirstName + majorActorLastName;
        getline(ss,temp,' ');
        getline(ss,temp,' ');
        istringstream(temp) >> releaseMonth;
        getline(ss,temp,' ');
        istringstream(temp) >> releaseYear;
        Movie newMovie = Movie("C", stock,director,title,majorActor,releaseYear,releaseMonth);
        inventory.addMovie(newMovie);
      }
      else if(movieType == "F" || movieType == "f")
      {
        getline(ss,temp);
        istringstream(temp) >> releaseYear;
        Movie newMovie = Movie("F", stock,director,title,releaseYear);
        inventory.addMovie(newMovie);
      }
      else if(movieType == "D" || movieType == "d")
      {
        getline(ss,temp);
        istringstream(temp) >> releaseYear;
        Movie newMovie = Movie("D", stock,director,title,releaseYear);
        inventory.addMovie(newMovie);
      }
      else 
      {
        cout << "Error: Invalid Movie Type." << endl; 
      }
      
    } 
} // end of readUserFile

// ---------------------------- addCustomer ----------------------------
// Adds customer to the hashtable 
// -----------------------------------------------------------------------
bool Store::addCustomer(int ID, Customer customer)
{
  customersList.insertItem(ID, customer);
  return true;
  
  
} // end of addCustomer

// ---------------------------- findCustomer ----------------------------
// Searches the hashtable for the customer using their ID 
// Returns false if the customer with that ID is not found
// -----------------------------------------------------------------------
bool Store::findCustomer(int ID)
{
  return customersList.findItem(ID);
  
} // end of findCustomer