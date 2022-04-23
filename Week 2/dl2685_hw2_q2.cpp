#include <iostream>
using namespace std; 

const float QUARTER = 25;
const float DIME = 10;
const float NICKEL = 5;
const int A_DOLLAR_IN_CENTS = 100;

int main()
{
	int dollars, cents;

	cout << "Please enter your amount in the format of dollars"
		" and cents separated by a space:" << endl;
	cin >> dollars >> cents;
	cout << dollars << " dollars and " << cents << " cents are:" << endl;

	int dollars_in_cents = dollars * A_DOLLAR_IN_CENTS;
	int total_amount_in_cents = dollars_in_cents + cents;

	int num_of_quarters = total_amount_in_cents / QUARTER; 
	int sum_of_quarters = num_of_quarters * QUARTER; 
	int remaining_amount_in_cents = total_amount_in_cents - sum_of_quarters; 

	int num_of_dimes = remaining_amount_in_cents / DIME;
	int sum_of_dimes = num_of_dimes * DIME;
	remaining_amount_in_cents -= sum_of_dimes; 

	int num_of_nickels = remaining_amount_in_cents / NICKEL; 
	int sum_of_nickels = num_of_nickels * NICKEL; 
	remaining_amount_in_cents -= sum_of_nickels; 

	int num_of_pennies = remaining_amount_in_cents; 

	cout << num_of_quarters << " quarters, " 
		<< num_of_dimes << " dimes, " 
		<< num_of_nickels << " nickels and " 
		<< num_of_pennies << " pennies"; 

	return 0; 
}