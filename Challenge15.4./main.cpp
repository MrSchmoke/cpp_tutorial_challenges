// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file{"../Challenge15.4./romeoandjuliet.txt"};
    std::ofstream out_file{"../Challenge15.4./poem_out.txt"};

    if(!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
    if(!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    std::string line{};
    int line_number {1};
    while(std::getline(in_file, line)) {
        if(!(line == "\r")) {
            out_file << std::setw(8) << std::left << line_number << line << std::endl;
            line_number++;
        }
        else
            out_file << line << std::endl;
    }

    std::cout << "File copied succesfully!" << std::endl;
    in_file.close();
    out_file.close();

    return 0;
}

