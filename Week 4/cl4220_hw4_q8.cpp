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
        std::cin >> guess;
        std::cout << "Your guess: " << guess << '\n';

        if (guess == correct_num)
        {
            std::cout << "Congrats! You guessed my number in " << num_guesses << " guesses.";
            break;
        }
        else if (guess < correct_num)
        {
            std::cout << "Wrong! My number is bigger.";
            min = guess + 1;
        }
        else if (guess > correct_num)
        {
            std::cout << "Wrong! My number is smaller.";
            max = guess - 1;
        }

        guesses_remaining -= 1;
        num_guesses += 1;
    }

    return 0;
}
