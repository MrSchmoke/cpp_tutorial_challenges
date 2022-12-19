#include <iostream>
#include "Movies.h"

int main() {
    Movies movies;
    movies.add_movie("Predator", "PG-13", 1);
    movies.add_movie("Predator2", "PG-13", 3);
    movies.add_movie("Terminator", "PG-13", 0);
    movies.movie_watched_again("Predator2");    
    movies.display_movies();
}