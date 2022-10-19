#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> list = {5, 10, 15, 20};
    //vector<int> list = {};
    char letter{};

    do {
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit\n" << endl;
        cout << "------------------------------" << endl;
        
        cin >> letter;
        
        if(letter == 'P' || letter =='p')
        {
            cout << "\nShow all numbers of the list!" << endl;
            for(auto l : list)
                cout << l << " ";
            cout << endl;
        }
        else if(letter == 'A' || letter =='a')
        {
            int add_num{}, index{};
            cout << "\nAdd a number to the list: " << endl;
            cin >> add_num;
        
            while(add_num != list.at(index) && index < list.size()) {
                index++;
                if(list.at(list.size()-1) == list.at(index) && add_num != list.at(index)) {
                    list.push_back(add_num);      
                    cout  << add_num << " added to the list!" << endl;
                    break;
                }
                else if(list.at(index) == add_num) {
                    cout << "No duplicate values allowed!" << endl;
                }
            }
        }
        else if(letter == 'M' || letter =='m')
        {
            if(list.size() != 0) {
                double mean{};
                for(auto l : list)
                    mean += l;

                mean /= list.size();

                cout << "The mean value is: " << mean << endl;
            }
            else
                cout << "Unable to calculate the mean - no data" << endl;
        }
        else if(letter == 'S' || letter =='s')
        {
            if(list.size() != 0) {
                int s{};

                for(auto l : list) {
                    if(s == 0 || s >= l)
                        s = l;
                }               
                cout << "The smallest number is: " << s << endl;
            }
            else
                cout << "Unable to determine the smallest number - list is empty!" << endl;
        }
        else if(letter == 'L' || letter =='l')
        {
            if(list.size() != 0) {
                int large{};

                for(auto l : list) {
                    if(large == 0 || large <= l)
                        large = l;
                }
                cout << "The larges number is: " << large << endl;
            }
            else
                cout << "Unable to determine the largest number - list is empty!" << endl;
        }
        else if(letter == 'Q' || letter =='q')
            cout << "\nGoodbye!" << endl;
        else
            cout << "Unknown selection, pleasy try again!" << endl;
    } while(letter != 'Q' && letter != 'q');

    return 0;
}

