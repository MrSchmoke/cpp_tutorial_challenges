#include <iostream>

using namespace std;

int main() {
    int small_rooms {0};
    int big_rooms {0};
    int estimate_days {30};

    const double price_per_small_room {20.00};
    const double price_per_big_room {30.00};
    const double tax {0.06};

    cout << "Hello, Welcome to Martin's Cleaning Service" << endl;
    cout << "\nHow many small rooms would you like cleaned? ";
    cin >> small_rooms;
    cout << "How many big rooms would you like cleaned? ";
    cin >> big_rooms;

    double sum_of_cost {(small_rooms * price_per_small_room) + (big_rooms * price_per_big_room)};
    double total_tax {sum_of_cost * tax};
    double total {total_tax + sum_of_cost};

    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_rooms << endl;
    cout << "Number of big rooms: " << big_rooms << endl;
    cout << "price per small room: $" << price_per_small_room << endl;
    cout << "price per big room: $" << price_per_big_room << endl;
    cout << "Cost: $" << sum_of_cost << endl;
    cout << "Tax: $" << total_tax << endl;
    cout << "==============================" << endl;
    cout << "Total estimate: $" << total << endl;
    cout << "This estimate is valid for " << estimate_days << " days." << endl;

    return 0;
}