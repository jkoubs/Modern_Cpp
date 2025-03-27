#include <iostream>

class Movie {
public:
  std::string Name;
  std::string Genre;
  float Rating;

  // Parameterized Constructor
  Movie(std::string name, std::string genre, float rating) {
    Name = name;
    Genre = genre;
    Rating = rating;
  }
  // Default Constructor
  Movie() {
    Name = "";
    Genre = "";
    Rating = 0;
  }
  // Copy Constructor
  Movie(const Movie &original) {
    Name = original.Name;
    Genre = original.Genre;
    Rating = original.Rating;
  }
  // Copy Assignment Operator Constructor
  Movie &operator=(const Movie &original) {
    Name = original.Name;
    Genre = original.Genre;
    Rating = original.Rating;

    return *this;
  }
};

int main() {
  Movie movie1("The Dark Knight", "Action", 9.5);
  Movie movie2("The Lion King", "Animated", 8);

  Movie movie3;         // calling default constructor
  Movie movie4(movie1); // calling copy constructor
  movie4 = movie2;      // calling assignment constructor
  // movie4.operator=(movie2);

  Movie movie5 = movie1; // calling copy constructor
  movie5 = movie2;       // calling assignment constructor
}

/*

* Copy Constructor invoked when creating new object based on existing object

* Copy Assignment Operator Constructor invoked when reassigning values of
existing object with another existing object


Copy and Copy Assignment Operator Constructors are needed when working with
pointers, otherwise not needed.


Let's see a an example with pointers of 3_constructors_with_pointers.cpp

*/