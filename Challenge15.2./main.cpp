// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::ifstream in_file{"../Challenge15.2./responses.txt"};

    if(!in_file) {
        std::cerr << "File open error" << std::endl;
        return 1;
    }

    std::string solution{}, name{}, response{};
    int score {}, denominator {}, numerator {0};
    double avg_score {};
    const int total_width {30};
    const int field_width1 {15};
    const int field_width2 {15};

    in_file >> solution;

    std::cout   << setw(field_width1) << std::left << "\n\nStudent" 
                << setw(field_width2) << std::right << "Score" 
                << std::endl;
    std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    while(!in_file.eof()) {
        in_file >> name;
        in_file >> response;

        for(size_t index{0}; index < response.length(); index++)
            if(solution.at(index) == response.at(index))
                score++;
        
        std::cout   << setw(field_width1) << std::left << name
                    << setw(field_width2) << std::right << score 
                    << std::endl;
        numerator += score;
        denominator++;
        score = 0;
    }
    avg_score = static_cast<double>(numerator)/denominator;
    std::cout << setprecision(1) << std::fixed;
    std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;

    std::cout   << std::setfill(' ') << setw(field_width1) << std::left << "Average Score" 
                << setw(field_width2) << std::right << avg_score
                << "\n\n" 
                << std::endl;
    
    in_file.close();
    return 0;
}

