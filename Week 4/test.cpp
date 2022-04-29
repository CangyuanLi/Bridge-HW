#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, RemValue;
	int DecimalNum, Power = 0; 
	
	cout << "Enter decimal number: " << endl;
	cin >> n;
	
	// Finding maximum power of 2 first
	
	DecimalNum = n; 

	while (DecimalNum > 1)
	{
		DecimalNum /= 2; 
		Power++; 
	}
		
	cout << "The binary representation of " << n << " is "; 

	// Now using the power of 2 to determine how many loops we need to perform. 

	while (Power >= 0)
	{
		RemValue = n - int(pow(2, Power));

		if (RemValue >= 0)
		{
			n = RemValue; 
			cout << "1";
		}
		else 
			cout << "0"; 

		Power--; 
	}

	return 0;
}