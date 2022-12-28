#include <iostream>
#include <fstream>
#include "customer.h"
#include "movie.h"
#include "inventory.h"
#include "store.h"
#include <sstream>
using namespace std;

int main() 
{
    Store store;

    store.readMovieFile("data4movies.txt");

    store.readCustomersFile("data4customers.txt"); 

    store.readCommandFile("data4commands.txt");  

}