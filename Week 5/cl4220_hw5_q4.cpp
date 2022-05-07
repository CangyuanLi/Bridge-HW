#include <cmath>
#include <iostream>

void print_divisors(int num)
{
    for (int i = 1; i < std::sqrt(num); i++)
    {
        if (num % i == 0)
        {
            std::cout << i << ' ';
        }
    }

    for (int i = std::sqrt(num); i > 0; i--)
    {
        if (num % i == 0)
        {
            std::cout << num / i << ' ';
        }
    }
}

int main()
{
    int num;
    std::cout << "Please enter a positive integer >= 2: ";
    std::cin >> num;

    print_divisors(num);

    return 0;
}