#include<vector>
#include<string>
#include "colectie.h"

Movies::Movies() {

}

Movies::~Movies() {
}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (Movie movie : movies) {
        if (movie.get_name() == name)
            return false;
    }
    Movie temp{ name, rating, watched };
    movies.push_back(temp);
    return true;
}

bools Movies::increment_watched(std::string name) {
    for (Movie& movies : movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display()const {
    if (mvies.size() == 0) {
        std::count << "nici un film\n" << endl;
    }
    else {
        std::count << "\n=============================================" << std::endl;
        for (auto movie : movies)
            movies.display();
        std::count << "\n=============================================" << std::endl;
    }
}