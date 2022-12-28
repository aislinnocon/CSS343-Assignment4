#include "customer.h"

//----------------------------------------------------------------------------
// Customer()
// Customer(): Creates a default constructor and initializes name & id private 
// values
Customer::Customer()
{
    this->firstName = "";
    this->lastName = "";
    this->id = 0; 
}

//----------------------------------------------------------------------------
// Customer()
// Customer(): Creates a constructor and initializes name & id private values 
// to passed in values
Customer::Customer(string firstName, string lastName, int id)
{
    this->firstName = firstName; 
    this->lastName = lastName;
    this->id = id;
}

//----------------------------------------------------------------------------
// ~Customer()
// ~Customer(): Deconstructor
Customer::~Customer()
{

}

//----------------------------------------------------------------------------
// getID()
// getID(): Returns the id of the customer
int Customer::getID() const
{
    return this->id;
}

// IDK if this is necessary but I will double check
string Customer::getName() const
{
    return this->firstName + " " + this->lastName; 
}

//----------------------------------------------------------------------------
// getFirstName()
// getFirstName(): Returns the first name of the customer
string Customer::getFirstName() const
{
    return this->firstName;
}

//----------------------------------------------------------------------------
// getLastName()
// getLastName(): Returns the last name of the customer
string Customer::getLastName() const
{
    return this->lastName; 
}

//----------------------------------------------------------------------------
// showHistory()
// showHistory(): Prints out the history for the customer
void Customer::showHistory()
{
    if (history.size() == 0)
    {
        cout << "Error: Customer has no history." << endl; 
    }
    else
    {
        for (int i = 0; i < history.size(); i++)
        {
            cout << history[i] << endl; 
        }
    }

}

//----------------------------------------------------------------------------
// storeMovie()
// storeMovie(): Takes in the command from the file as a string and stores it 
// within the customer's history
void Customer::storeMovie(string movieCommand)
{
    history.push_back(movieCommand);
}

//----------------------------------------------------------------------------
// overloaded operator<<
// overloaded operator<<: Prints out id, first name & last name of a customer
ostream& operator<<(ostream &output, const Customer &customer) {
    output << customer.getID() << " " << customer.getLastName() << " " << customer.getFirstName(); 
    return output; 
}
