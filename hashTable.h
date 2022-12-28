// -------------------------------- hashTable.h --------------------------------
// Mahsa Mohajeri, CSS 343
// Created:         06/02/ 22
// Last Modified:   06/08/22
// -----------------------------------------------------------------------------
// Purpose: This class will implement the HashTable class
// -----------------------------------------------------------------------------
// Notes: Uses a template
// -----------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "hashNode.h"
#include <string>
#include <iostream>
using namespace std;


//template
template <typename Key, typename Val, typename Function = keyHash<Key> >

class HashTable
{

public:
// ------------------------ Constructor -----------------------------------
// Creates a hash table using hashNodes
// ------------------------------------------------------------------------
HashTable()
{
    table = new HashNode<Key, Val> * [TABLE_SIZE]();
} // end of Hashtable

// ------------------------ Destructor -----------------------------------
// Deletes all the data stored in the table
// -----------------------------------------------------------------------
 ~HashTable()
 {
    delete[] table;
 } // end of ~HashTable

// ----------------------- insertItem ----------------------------------
// Inserts item into the hashTable using the key and val
// ---------------------------------------------------------------------
void insertItem(const Key& k, const Val& v)
{
    int hashVal = function(k);
    HashNode<Key, Val>* p = NULL;
    HashNode<Key, Val>* item = table[hashVal];
    while (item && item->getKey() != k)
    {
        p = item;
        item = item->getNext();
    }
    if (!item)
    {
        item = new HashNode<Key, Val>(k, v);
        if (!p)
        {
            table[hashVal] = item;
        }
        else
        {
            p->setNext(item);
        }
    }
    else
    {
        item->setVal(v);
    }
} // end of insertItem

// ------------------------ findItem -----------------------------------
// Finds item in the hashTable using the key
// ---------------------------------------------------------------------
bool findItem(const Key& k)
{
    int hashVal = function(k);
    HashNode<Key, Val>* item = table[hashVal];
    while (item)
    {
        if (item->getKey() == k)
        {
            return true;
        }
        item = item->getNext();
    }
    return false;
} // end of findItem

Val* retrieve(const Key& k)
{
    Val* val = nullptr;
    int hashVal = function(k);
    HashNode<Key, Val>* item = table[hashVal];
    while (item)
    {
        if (item->getKey() == k)
        {
            //val = item;
            return val;
        }
        item = item->getNext();
    }
  return val;
} // end of retrieve

//---------------------------- removeItem ---------------------------------
// Removes given desired item from the hash table
// Uses item key to find item first and then removes it
// ------------------------------------------------------------------------
void removeItem(const Key& k)
{
    int hashVal = function(k);
    HashNode<Key, Val>* p = NULL;
    HashNode<Key, Val>* item = table[hashVal];
    while (item && item->getKey() != k)
    {
        p = item;
        item = item->getNext();
    }
    if (!item)
    {
        return;
    }
    else
    {
        if (!p)
        {
            table[hashVal] = item->getNext();
        }
        else
        {
            p->setNext(item->getNext());
        }
        delete item;
    }
} // end of removeItem

//---------------------------- printAllData -------------------------------
// Iterates through the table and prints all the vals stored 
// ------------------------------------------------------------------------
void printAllData()
{
   for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashNode<Key, Val>* item = table[i];
        while (item)
        {
          cout << item->getVal() << endl;
          item = item->getNext();
        }
    }
} // end of printAllData

private:

    HashNode<Key, Val>** table;
    Function function;
};

#endif //RENTALSTORE_HASHTABLE_H
