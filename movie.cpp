// -------------------------------------------------------------------------
// Purpose: Implements the outline for movie object which can be created 
// based on the attributes. Movie objects can be created by reading in the 
// stored data. This class can also display an individual movie and it's 
// characteristics
// -------------------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid.
// -------------------------------------------------------------------------

#include "movie.h"

// --------------------------- Overloaded << -------------------------------
// Displays a complete movie object and it's attributes in print view
// -------------------------------------------------------------------------
ostream& operator<<(ostream &outStream, const Movie &MovieObj) {
  if (MovieObj.type == "C") {
    outStream << MovieObj.type << ", " << MovieObj.stock << ", " << MovieObj.director << ", " << MovieObj.title << ", " << MovieObj.majorActor << " " << MovieObj.releaseMonth << " " << MovieObj.releaseYear;
  }
  if ((MovieObj.type == "D") || (MovieObj.type == "F")) {
    outStream << MovieObj.type << ", " << MovieObj.stock << ", " << MovieObj.director << ", " << MovieObj.title << ", " << MovieObj.releaseYear;
  }
  return outStream; 
}

// ---------------------- Constructor with type ----------------------------
// Creates a movie object by taking in the type
// -------------------------------------------------------------------------
Movie::Movie(string type) {
  if ((type == "D") || (type == "F") || (type == "C")) {
    this->type = type;
  }
}

// ---------- Constructor suitable for drama and comedy objects ------------
// Creates a movie object with the given attributes if it has a valid type
// -------------------------------------------------------------------------
Movie::Movie(string type, int stock, string director, string title, int releaseYear) {
  if ((type == "D") || (type == "F") || (type == "C")) {
    this->type = type;
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseYear = releaseYear; 
  }
}

// --------------- Constructor suitable for classics objects ---------------
// Creates a movie object with the given attributes if it has a valid type
// -------------------------------------------------------------------------
Movie::Movie(string type, int stock, string director, string title, string majorActor, int releaseYear, int releaseMonth) {
  if ((type == "D") || (type == "F") || (type == "C")) {
    this->type = type;
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->majorActor = majorActor;
    this->releaseYear = releaseYear;
    this->releaseMonth = releaseMonth;
  }
}

// ---------------------------- Destructor ---------------------------------
// 
// -------------------------------------------------------------------------
Movie::~Movie() {}

// ------------------------------ getStock ---------------------------------
// Returns the stock amount given the title of a movie
// -------------------------------------------------------------------------
int Movie::getStock(string title) {
  return stock;
}