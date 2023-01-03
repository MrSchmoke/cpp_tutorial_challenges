// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;

    Account *p1 = new Trust_Account("TRUST ME", 2500, 5.0);
    Account *p2 = new Savings_Account("SAVE ME", 1000);
    Account *p3 = new Checking_Account("CHECK ME", 5000);

    vector<Account *> ptraccs;
    ptraccs.push_back(p1);
    ptraccs.push_back(p2);
    ptraccs.push_back(p3);
    display(ptraccs);
    deposit(ptraccs, 5000);
    withdraw(ptraccs, 1000);

    return 0;
}

