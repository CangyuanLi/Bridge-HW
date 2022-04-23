#include <iostream>
using namespace std; 

int main()
{
	int integer_one, integer_two;

	cout << "Please enter two positive integers, separated by a space:" << endl;
	cin >> integer_one >> integer_two; 

	int sum = integer_one + integer_two; 
	int substraction = integer_one - integer_two; 
	int multiplication = integer_one * integer_two; 
	float division = float(integer_one) / float(integer_two);
	int div = integer_one / integer_two;
	int mod = integer_one % integer_two;

	cout << integer_one << " + " << integer_two << " = " << sum << endl;
	cout << integer_one << " - " << integer_two << " = " << substraction << endl;
	cout << integer_one << " * " << integer_two << " = " << multiplication << endl;
	cout << integer_one << " / " << integer_two << " = " << division << endl;
	cout << integer_one << " div " << integer_two << " = " << div << endl;
	cout << integer_one << " mod " << integer_two << " = " << mod << endl;

	return 0; 
}