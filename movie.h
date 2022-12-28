// ------------------------------- movie.h --------------------------------
// Kirtiashna Chandra, CSS 343
// Created:         05/27/22
// Last Modified:   
// ------------------------------------------------------------------------
// Purpose: Create an outline for a movie object which can be created based
// on the attributes. Movie objects can be created by reading in the stored
// data. This class can also display an individual movie and it's 
// characteristics
// ------------------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid.
// ------------------------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
using namespace std;

class Movie {
  // overloaded << operator 
  friend std::ostream& operator<<(std::ostream &outStream, const Movie &MovieObj);
public:
  // constructor with type
  Movie(string type);
  // constructor suitable for drama and comedy objects
  Movie(string type, int stock, string director, string title, int releaseYear);
  // constructor suitable for classics object
  Movie(string type, int stock, string director, string title, string majorActor, int releaseYear, int releaseMonth);
  // destructor
  ~Movie();
  // getter for stock
  int getStock(string title);

  // characteristics of movie object
  string director, title, majorActor, type;
  int stock, releaseYear,releaseMonth;
};

#endif // MOVIE_H