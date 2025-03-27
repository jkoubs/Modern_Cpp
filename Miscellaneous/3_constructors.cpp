#include <iostream>

class Movie {
public:
  std::string Name;
  std::string Genre;
  float Rating;
  int ActorsCounter;
  std::string *Actors;

  // Parameterized Constructor
  Movie(std::string name, std::string genre, float rating) {
    Name = name;
    Genre = genre;
    Rating = rating;
    ActorsCounter = 0;
    Actors = new std::string[ActorsCounter]; // Allocate memory
  }
  ~Movie() {
    delete[] Actors; // Deallocate memory
    Actors = nullptr;
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
    ActorsCounter = original.ActorsCounter;

    Actors = new std::string[ActorsCounter];
    for (int i = 0; i < ActorsCounter; i++) {
      Actors[i] = original.Actors[i];
    }
  }
  // Copy Assignment Operator Constructor
  Movie &operator=(const Movie &original) {
    if (&original !=
        this) { // prevent pb of self destruction that will happen in for loop
      Name = original.Name;
      Genre = original.Genre;
      Rating = original.Rating;
      ActorsCounter = original.ActorsCounter;

      delete[] Actors; // deallocate memory that previous object was holding
                       // before allocating new memory
      Actors = new std::string[ActorsCounter];
      for (int i = 0; i < ActorsCounter; i++) {
        Actors[i] = original.Actors[i];
      }
    }
    return *this;
  }

  void AddActor(std::string newActorName) {
    std::string *newActors = new std::string[ActorsCounter + 1];
    for (int i = 0; i < ActorsCounter; i++) {
      newActors[i] = Actors[i];
    }
    newActors[ActorsCounter] = newActorName;

    delete[] Actors;
    Actors = newActors; // Actors points to new address newActors
    ActorsCounter++;
  }

  void PrintInfo() {
    std::cout << "Movie Name: " << Name << std::endl;
    std::cout << "Genre: " << Genre << std::endl;
    std::cout << "Rating: " << Rating << std::endl;
    std::cout << "Actors: ";
    for (int i = 0; i < ActorsCounter; i++) {
      std::cout << Actors[i] << " ";
    }
    std::cout << "\n\n";
  }
};

int main() {
  Movie movie1("The Dark Knight", "Action", 9.5);
  Movie movie2("The Lion King", "Animated", 8);

  movie1.AddActor("Christian Bale");
  movie1.AddActor("Heath Ledger");

  movie2.AddActor("Daniel D Lewis");
  movie2.AddActor("Jason Bateman");
  movie2.AddActor("Jack Nicholson");

  movie1.PrintInfo();
  Movie movie3(movie1); // Invokes the Copy Constructor
  movie3 = movie2;
  movie3.PrintInfo();
}

/*

* Copy Constructor invoked when creating new object based on existing object

* Copy Assignment Operator Constructor invoked when reassigning values of
existing object with another existing object


Copy and Copy Assignment Operator Constructors are needed when working with
pointers, otherwise not needed.


Let's see a an example with pointers of 3_constructors_with_pointers.cpp

*/