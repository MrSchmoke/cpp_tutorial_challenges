// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const
    {
        return name;
    }
    std::string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): \n";
}

void play_current_song(const Song &song)
{
    std::cout << "Playing: " << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    std::cout << "The list has currently following songs:\n";
    for (auto &song : playlist)
        std::cout << song << "\n";
    std::cout << "===================================================\n";
    std::cout << std::endl;
    play_current_song(current_song);
}

int main()
{
    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();
    char letter{};

    do
    {
        display_menu();

        std::cin >> letter;
        letter = ::toupper(letter);

        if (letter == 'F')
        {
            current_song = playlist.begin();
            play_current_song(*current_song);
        }
        else if (letter == 'N')
        {
            current_song++;
            if(current_song == playlist.end())
                current_song = playlist.begin();    
            
            play_current_song(*current_song);
        }
        else if (letter == 'P')
        {
            if(current_song == playlist.begin())
                current_song = playlist.end();
            current_song--;

            play_current_song(*current_song);
        }
        else if (letter == 'A')
        {
            std::string song{};
            std::string name{};
            int rating{};

            std::cout << "Enter a songname: \n";
            std::cin >> song;

            std::cout << "Enter the artists name: \n";
            std::cin >> name;

            std::cout << "Enter the rating (1-5):\n";
            std::cin >> rating;
            std::cout << std::endl;

            playlist.emplace_front(song, name, rating);
        }
        else if (letter == 'L')
        {
            display_playlist(playlist, *current_song);
        }
        else
            std::cout << "Illegal choice, try again..";
    } while (letter != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}