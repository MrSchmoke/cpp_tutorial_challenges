#include <iostream>

int main() 
{
    int favnum = 0;
    std::cout << "Enter your favorite number between 1 and 100: " << std::endl;
    std::cin >> favnum;
    std::cout << "Amazing!! That's my favorite number too!" << std::endl;
    std::cout << "No really! " << favnum << " is my favorite number!" << std::endl;  
}