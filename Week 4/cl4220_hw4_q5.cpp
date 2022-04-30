#include <iostream>

int main()
{
    int n;
    std::cout << "Please enter a positive integer: ";
    std::cin >> n;

    int start_stars = 1; // the tip of the triangle is always 1
    int start_spaces = 0; // there should be no spaces around the line with the most stars
    int max_stars = n * 2 - 1; // the max number of stars in a line
    int max_spaces = max_stars - 1; // refers to number of spaces in the line with one star

    // first print the top triangle
    // note that there is a symmetrical amount of spaces to the right and left of a seq of stars
    for (int i = 0; i < n; i++)
    {
        // left spaces
        int spaces = start_spaces / 2;
        for (int num_spaces = 0; num_spaces < spaces; num_spaces++)
        {
            std::cout << ' ';
        }
        // stars
        for (int j = 0; j < max_stars; j++)
        {
            std::cout << '*';
        } 
        // right spaces
        for (int num_spaces = 0; num_spaces < spaces; num_spaces++)
        {
            std::cout << ' ';
        }

        max_stars -= 2;
        start_spaces += 2;
        spaces = start_spaces / 2;
        
        std::cout << '\n';
    }

    // do the same as above, but essentially in reverse
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
