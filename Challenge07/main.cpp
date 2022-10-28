#include <iostream>
#include <vector>

using namespace std;

void showMenu(vector<int>);
void showNumbers(const vector<int> &list);
void addNumbers(vector<int> &list);
void calcMean(vector<int> &list);
void smallestNumber(vector<int> &list);
void largestNumber(vector<int> &list);
char getSelection();

int main() {
    vector<int> list = {5, 10, 15, 20};
    showMenu(list);
    return 0;
}

void showMenu(vector<int> list) {
    char letter{};
    do {
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit\n" << endl;
        cout << "------------------------------" << endl;
        
        letter = getSelection();
        switch(letter)
        {
            case 'P':
                showNumbers(list);
                break;
            case 'A':
                addNumbers(list);
                break;
            case 'M':
                calcMean(list);   
                break;
            case 'S':
                smallestNumber(list);
                break;
            case 'L':
                largestNumber(list);
                break;
            case 'Q':
                cout << "\nGoodbye!" << endl;
            default:
                cout << "Unknown selection, pleasy try again!" << endl;
        }
    } while(letter != 'Q');
}

void showNumbers(const vector<int> &list)
{
    cout << "\nShow all numbers of the list!" << endl;
    for(auto l : list)
        cout << l << " ";
    cout << endl;
}

char getSelection() {
    char letter{};
    cin >> letter;
    return toupper(letter);
}

void addNumbers(vector<int> &list)
{
    int add_num{}, index{};
    cout << "\nAdd a number to the list: " << endl;
    cin >> add_num;
        
    while(add_num != list.at(index) && index < list.size()) 
    {
        index++;
        if(list.at(list.size()-1) == list.at(index) && add_num != list.at(index)) 
        {
            list.push_back(add_num);      
            cout  << add_num << " added to the list!" << endl;
            break;
        }
        else if(list.at(index) == add_num) 
            cout << "No duplicate values allowed!" << endl;
        
    }
}

void calcMean(vector<int> &list)
{
    if(list.size() != 0)
    {
        double mean{};
        for(auto l : list)
            mean += l;

        mean /= list.size();
        cout << "The mean value is: " << mean << endl;
    }
    else
        cout << "Unable to calculate the mean - no data" << endl;
}

void smallestNumber(vector<int> &list)
{
    if(list.size() != 0)
    {
        int s{};

        for(auto l : list)
            if(s == 0 || s >= l)
                s = l;
        cout << "The smallest number is: " << s << endl;
    }
    else
        cout << "Unable to determine the smallest number - list is empty!" << endl;
}

void largestNumber(vector<int> &list)
{
    if(list.size() != 0) {
        int large{};

        for(auto l : list) 
            if(large == 0 || large <= l)
                large = l;
        cout << "The larges number is: " << large << endl;
    }
    else
        cout << "Unable to determine the largest number - list is empty!" << endl;
}