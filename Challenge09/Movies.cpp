#include "Movies.h"
#include "Movie.h"
#include <iostream>

std::vector<Movie> collection;

Movies::Movies() {

}

Movies::~Movies() {

}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    Movie movie(name, rating, watched);

    for(const Movie &movie: collection)
        if(movie.get_name() == name)
            return false;
   
    Movie temp {name, rating, watched};
    collection.push_back(temp);
    return true;
}

void Movies::display_movies() const {
    if(collection.size() == 0)
        std::cout << "No movies to display!" << std::endl;
    else {
        for (const auto &movie: collection)
            movie.display();
    }
}

bool Movies::movie_watched_again(std::string name) {
    for(Movie &movie: collection) {
        if(movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
   
    return false;
}

