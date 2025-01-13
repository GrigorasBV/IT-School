#include <iostream>
#include "colectie.h"


//fuction prototypes
void increment_watched(Movies& movies, std::string name);
void add_movie(Movies& movies, std::string name, std::string rating, int watched);


void increment_watched(Movies& movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << "watch incremented" << std::endl;
    }
    else {
        std::cout << name << "not found" << std::endl;
    }
}
void add_movie(Movies& movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name, rating, watched)) {
        std::cout << name << "added" << std::endl;
    }
    else
    {
        std::cout << name << "already exist" << std::endl;
    }
}



int main()
{
    Movies my_movies;

    my_movies.display();

    add_movie(my_movies, "Fast and furios", "FB", 2);
    add_movie(my_movies, "Star Wars", "FB", 5);
    add_movie(my_movies, "Singur acasa", "FB", 7);

    my_movies.display();

    increment_watched(my_movies, "Star Wars");

    my_movies.display();

    return 0;


}