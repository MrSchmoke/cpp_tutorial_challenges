#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string message{};
    cout << "Enter a String-literal: " << endl;
    cin >> message;
    for(size_t i{}; i < message.length(); i++)
    {   
        for(size_t x{}; x < message.length()-i-1; x++)
            cout << " ";
        if(i == 0){
            cout << message.at(i) <<endl;
            continue;
        } else {
            for(size_t k{}; k <= i-1; k++)
                cout << message.at(k);

            for(size_t j{i+1}; j > 0; j--)
                cout << message.at(j-1);

            cout << endl;
        }
    }
    return 0;
}