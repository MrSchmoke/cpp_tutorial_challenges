#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

    const string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string message{}, encoded{}, decoded{};

    cout << "Enter a secret message: ";
    getline(cin, message);
    cout << "You entered: " << message << endl;

    for(char m : message)
    {
        size_t pos = alphabet.find(m);

        if(pos != string::npos) {
            char new_char{ key.at(pos) };
            encoded += new_char;
        } else {
            encoded += m;
        }
    }

    cout << "Encoded message: " << encoded << endl;

    for(char e : encoded)
    {
        size_t pos = key.find(e);
        if(pos != string::npos) {
            char new_char{alphabet.at(pos)};
            decoded += new_char;
        } else {
            decoded += e;
        }
    }

    cout << "Decoded message: " << decoded << endl;
    return 0;
}