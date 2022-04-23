#include <iostream>

int main()
{
    const int CENTS_IN_DOLLAR = 100;
    const int CENTS_IN_QUARTER = 25;
    const int CENTS_IN_DIME = 10;
    const int CENTS_IN_NICKEL = 5;
    int dollars, cents;

    std::cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";
    std::cin >> dollars >> cents;

    // convert dollars and cents to just cents

    int only_cents = dollars * CENTS_IN_DOLLAR + cents;
    
    int max_quarters = only_cents / CENTS_IN_QUARTER;
    int remaining_cents = only_cents % CENTS_IN_QUARTER;
    
    int max_dimes = remaining_cents / CENTS_IN_DIME;
    remaining_cents = remaining_cents % CENTS_IN_DIME;

    int max_nickels = remaining_cents / CENTS_IN_NICKEL;
    remaining_cents = remaining_cents % CENTS_IN_NICKEL;
    
    std::cout << dollars << " dollars and " << cents << " cents are:\n";
    std::cout << max_quarters << " quarters, "
              << max_dimes << " dimes, "
              << max_nickels << " nickels and "
              << remaining_cents << " pennies";

    return 0;
}
