#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{

    try
    {
        std::unique_ptr<Account> moe_acc = std::make_unique<Checking_Account>("Moe", 100);
        std::cout << "Use moe_acc" << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    try {
        std::unique_ptr<Account> curl_acc = std::make_unique<Checking_Account>("Curl", 1000);
        curl_acc->deposit(300);
        curl_acc->withdraw(1500);
        
        std::cout << "Use curl_acc" << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch(const InsufficientFundsException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
