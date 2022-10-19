#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>


using namespace std;

int main()
{
    //nested loops
    
    //vector<int> vec = {1, 2, 3}; //result: 11
     vector<int> vec = {2, 4, 6, 8}; //result: 140

    int result {}, add {};

    for(int i {}; i < vec.size(); i++)
    {
        add = vec.at(i);
        for(int j{i+1}; j < vec.size(); j++)
            result += add * vec.at(j);
    } 

    cout << "The result is: " << result << endl;
    
    // ---------------------------------------------
    //c-style strings

    char first_name[7] = "Bjarne";
    char last_name[11] = "Stroustrup";
    char whole_name[20]; //more null space at the end

    size_t first_name_length = strlen(first_name);
    size_t last_name_length = strlen(last_name);

    strcpy(whole_name, first_name);
    strcat(whole_name, last_name);

    size_t whole_name_length = strlen(whole_name);

     cout << "The length of the first name, " << first_name << ", is " << first_name_length 
          << " letters long and the length of the last name, " << last_name << ", is " << last_name_length 
          << " letters long. This means that the length of the whole name must be " << whole_name_length << " letters long." << endl;
}