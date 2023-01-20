// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

std::string enter_word()
{
    std::string input_word{};

    std::cout << "Enter the substring to search for: ";
    std::cin >> input_word;
    return input_word;
}

bool find_substring(const std::string &word_read, const std::string &target) {
    std::size_t found = target.find(word_read);
    if(found == std::string::npos)
        return false;
    else
        return true;
}

int word_counter(std::string &input_word)
{
    std::ifstream in_file{"../Challenge15.3./romeoandjuliet.txt"};

    if (!in_file)
    {
        std::cerr << "File open error" << std::endl;
        return 1;
    }

    std::string word_read{};
    int count{}, word_amount{};

    while (in_file >> word_read)
    {
        word_amount++;
        if (find_substring(word_read, input_word))
            count++;

    }
    std::cout << word_amount << " words were searched..." << std::endl;
    return count;
}

void output(const int &word_amount, const std::string &input_word)
{
    std::cout << "The substring " << input_word << " was found " << word_amount << " times\n"
              << std::endl;
}

int main()
{
    std::string input_word = enter_word();
    int word_amount = word_counter(input_word);
    output(word_amount, input_word);
    return 0;
}
