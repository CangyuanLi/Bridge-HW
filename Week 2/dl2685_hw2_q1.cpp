#include <iostream>
using namespace std; 

const float QUARTER = 0.25; 
const float DIME = 0.10;
const float NICKEL = 0.05; 
const float PENNY = 0.01;
const int A_DOLLAR_IN_CENTS = 100; 

int main()
{
    int num_of_quarters, num_of_dimes, num_of_nickels, num_of_pennies; 

    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters: ";
    cin >> num_of_quarters;
    cout << "# of dimes: ";
    cin >> num_of_dimes;
    cout << "# of nickels: ";
    cin >> num_of_nickels;
    cout << "# of pennies: ";
    cin >> num_of_pennies; 

    float sum_of_quarters = QUARTER * num_of_quarters;
    float sum_of_dimes = DIME * num_of_dimes;
    float sum_of_nickels = NICKEL * num_of_nickels; 
    float sum_of_pennies = PENNY * num_of_pennies; 
    float total = sum_of_quarters + sum_of_dimes + sum_of_nickels + sum_of_pennies; 
    int total_dollars = int(total);
    float total_cents = (total - total_dollars) * A_DOLLAR_IN_CENTS; 

    cout << "The total is " << total_dollars << " dollars and " 
        << total_cents << " cents";

    return 0; 
}

