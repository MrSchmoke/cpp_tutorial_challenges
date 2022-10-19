#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int total_cents{}; 

    cout << "Enter an amount in cents: ";
    cin >> total_cents;
    cout << "You can provide this chage as follows: " << endl;

    const int dollar_val{100}, quarter_val{25}, dime_val{10}, nickel_val{5}; 
    int dollars{}, quarters{}, dimes{}, nickels{}, pennies{}, balance{};
    
    // version01
    // dollars = total_cents / dollar_val;
    // quarters = ((total_cents)-(dollars * dollar_val)) / quarter_val;
    // dimes =  ((total_cents)-(dollars * dollar_val) - (quarters * quarter_val)) / dime_val;
    // nickels = ((total_cents)-(dollars * dollar_val) - (quarters * quarter_val) - (dimes * dime_val)) / nickel_val;
    // pennies = ((total_cents)-(dollars * dollar_val) - (quarters * quarter_val) - (dimes * dime_val) - (nickels * nickel_val));

    // version02
    dollars = total_cents / dollar_val;
    balance = total_cents % dollar_val;

    quarters = balance / quarter_val;
    balance %= quarter_val;

    dimes = balance / dime_val;
    balance %= dime_val;

    nickels = balance / nickel_val;
    balance %= nickel_val;

    pennies = balance;

    cout << "dollars: " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;

    return 0;
}