#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int n, random, RemGuess, lowrange = 1, highrange = 100;

	srand(time(0));
	random = (rand() % 100) + 1;

	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

	for (RemGuess = 5; RemGuess >= 1; RemGuess--)
	{
		cout << "Range: ["<<lowrange<<", "<<highrange<<"], Number of guesses left: " << RemGuess << endl;
		cout << "Your guess: " << endl;
		cin >> n;

		if (n < 1)
			cout << "Your number is invalid, please enter a number between 1 and 100.";
		else
			if (n == random)
			{
				cout << "Congrats! You guessed my number in " << 6 - RemGuess << " guess(es).";
				break;
			}
			else if (random > n && RemGuess > 1)
			{
				lowrange = n; 
				cout << "Wrong! My number is bigger." << endl;
				cout << endl;
			}
			else if (random < n && RemGuess > 1)
			{
				highrange = n; 
				cout << "Wrong! My number is smaller." << endl;
				cout << endl;
			}
	}

	if (n != random)
		cout << "Out of guesses! My number is " << random << endl; 

	cout << endl;

	return 0;
}