#include <iostream>

int main() 
{
    const int CENTS_IN_DOLLAR = 100;
    const int CENTS_IN_QUARTER = 25;
    const int CENTS_IN_DIME = 10;
    const int CENTS_IN_NICKEL = 5;
    int num_quarters, num_dimes, num_nickels, num_pennies;

    std::cout << "Please enter number of coins:\n";

    std::cout << "# of quarters: ";
    std::cin >> num_quarters;

    std::cout << "# of dimes: ";
    std::cin >> num_dimes;

    std::cout << "# of nickels: ";
    std::cin >> num_nickels;

    std::cout << "# of pennies: ";
    std::cin >> num_pennies;

    // first convert everything to cents

    int q_cents = num_quarters * CENTS_IN_QUARTER;
    int d_cents = num_dimes * CENTS_IN_DIME;
    int n_cents = num_nickels * CENTS_IN_NICKEL;
    
    int amt_cents = q_cents + d_cents + n_cents + num_pennies;

    int dollars = amt_cents / CENTS_IN_DOLLAR;
    int cents = amt_cents % CENTS_IN_DOLLAR;
 
    std::cout << "The total is " << dollars << " dollars and " << cents << " cents" << "\n";

    return 0;
}
