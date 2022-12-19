#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"
#include <vector>

class Movies
{
private:
    std::vector<Movie> collection;
public:
    Movies();
    ~Movies();
    bool add_movie(std::string name, std::string rating, int watched);
    bool movie_watched_again(std::string name);
    void display_movies() const;
};

#endif