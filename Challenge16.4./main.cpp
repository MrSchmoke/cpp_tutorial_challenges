// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    std::stack<char> stack{};
    std::queue<char> queue{};

    for(auto &elem : s)
        if(std::isalpha(elem))
        {
            stack.push(std::toupper(elem));
            queue.push(std::toupper(elem));
        }

    if(stack.top() == queue.front())
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