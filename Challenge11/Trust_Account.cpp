#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
   : Savings_Account {name, balance, int_rate}, num_withdrawals{0} {
}

bool Trust_Account::deposit(double amount) {
    amount += (amount >= bonus_threshold) ? (amount * (int_rate/100)) + 50 : amount * (int_rate/100);
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if((amount <= (balance * percentage)) && num_withdrawals < 3) {
        ++num_withdrawals; 
        return Savings_Account::withdraw(amount);
    }
    else
        // std::cout << "Withdrawal declined. Maximum withdrawals for this years are made." << std::endl;
        return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", Interest Rate: " << account.int_rate << "%]";
    return os;
}