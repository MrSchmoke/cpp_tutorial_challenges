// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{   
    std::deque<char> deque_char{};
    std::deque<char> deque_reverse_char{};

    
    for(auto &elem : s)
        if(std::isalpha(elem))
            deque_char.push_back(std::toupper(elem));

    std::copy(deque_char.begin(), deque_char.end(), std::front_inserter(deque_reverse_char));
    
    if(deque_char == deque_reverse_char)
        return true;
    else
        return false;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << "Result" << "\t" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << is_palindrome(s)  << "\t" << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}