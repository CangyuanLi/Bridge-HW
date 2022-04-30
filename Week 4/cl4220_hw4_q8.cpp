#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    // set seed
    std::srand(std::time(0));

    std::cout << "I thought of a number between 1 and 100! Try to guess it.\n";

    int min = 1;
    int max = 100;
    int correct_num = (rand() % (max - min + 1)) + min;
    int guesses_remaining = 5;
    int num_guesses = 1;
    while (guesses_remaining > 0)
    {
        std::cout << "Range: [" << min << ", " << max << "], "
                  << "Number of guesses left: " << guesses_remaining << '\n';

        int guess;
        std::cout << "Your guess: ";
        std::cin >> guess;

        if (guess == correct_num)
        {
            std::cout << "Congrats! You guessed my number in " << num_guesses << " guesses.";
            break;
        }

        if (guesses_remaining > 1)
        {
            if (guess < correct_num)
            {
                std::cout << "Wrong! My number is bigger.\n";
                if (guess > min)
                {
                    min = guess + 1;
                }
            }
            else if (guess > correct_num)
            {
                std::cout << "Wrong! My number is smaller.\n";
                if (guess < max)
                {
                    max = guess - 1;
                }
            }
        }
        else
        {
            std::cout << "Out of guesses! My number is " << correct_num;
        }

        guesses_remaining -= 1;
        num_guesses += 1;
        std::cout << '\n';
    }

    return 0;
}
