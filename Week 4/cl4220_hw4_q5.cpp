#include <iostream>

int main()
{
    int n;
    std::cout << "Please enter a positive integer: ";
    std::cin >> n;

    int start_stars = 1;
    int start_spaces = 0;
    int max_stars = n * 2 - 1;
    int max_spaces = max_stars - 1;

    // first print the top triangle
    // here we 
    for (int i = 0; i < n; i++)
    {
        int spaces = start_spaces / 2;
        for (int num_spaces = 0; num_spaces < spaces; num_spaces++)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < max_stars; j++)
        {
            std::cout << '*';
        } 

        for (int num_spaces = 0; num_spaces < spaces; num_spaces++)
        {
            std::cout << ' ';
        }

        max_stars -= 2;
        start_spaces += 2;
        spaces = start_spaces / 2;
        
        std::cout << '\n';
    }

    for (int i = 0; i < n; i++)
    {
        int spaces = max_spaces / 2;
        for (int num_spaces = 0; num_spaces < spaces; num_spaces++)
        {
            std::cout << ' ';
        }
        
        for (int j = 0; j < start_stars; j++)
        {
            std::cout << '*';
        }

        for (int num_spaces = 0; num_spaces < spaces; num_spaces++)
        {
            std::cout << ' ';
        }

        start_stars += 2;
        max_spaces -= 2;
        spaces = max_spaces / 2;
        std::cout << '\n';
    }

    return 0;
}
