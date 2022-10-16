#include <iostream>

using namespace std;

int main()
{
    int total_cents{}; 
    
    cout << "Enter an amount in cents: ";
    cin >> total_cents;
    cout << "You can provide this chage as follows: " << endl;

    int dollars{}, quarters{}, dimes{}, nickels{}, pennies{}, balance{};
    
    // version01
    // dollars = total_cents / 100;
    // quarters = ((total_cents)-(dollars * 100)) / 25;
    // dimes =  ((total_cents)-(dollars * 100) - (quarters*25)) / 10;
    // nickels = ((total_cents)-(dollars * 100) - (quarters*25) - (dimes*10)) / 5;
    // pennies = ((total_cents)-(dollars * 100) - (quarters*25) - (dimes*10) - (nickels * 5));

    // version02
    dollars = total_cents / 100;
    balance = total_cents % 100;

    quarters = balance / 25;
    balance %= 25;

    dimes = balance / 10;
    balance %= 10;

    nickels = balance / 5;
    balance %= 5;

    pennies = balance;

    cout << balance << endl;
    cout << "dollars: " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;

    return 0;
}