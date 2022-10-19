#include <iostream>
#include <vector>

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
}