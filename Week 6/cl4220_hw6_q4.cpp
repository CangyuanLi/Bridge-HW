#include <cstdlib>
#include <ctime>
#include <iostream>

int generate_random_integer(int lower_bound, int upper_bound)
{
    upper_bound = upper_bound + 1; // the below has upper as exclusive, this changes to inclusive
    int num = (std::rand() % (upper_bound - lower_bound)) + lower_bound;

    return num;
}

void generate_mapping(int map_values [])
{
    for (int i = 0; i <= 9; i++)
    {
        int rand_num = generate_random_integer(1, 3);
        
        map_values[i] = rand_num;
    }
}

void print_mapping(int map_values [])
{
    std::cout << "PIN: ";
    for (int i = 0; i <= 9; i++)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    std::cout << "NUM: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << map_values[i] << ' ';
    }

    std::cout << '\n';
}

int map_original_to_random(int pin, int map_values [])
{
    int correct_pin = 0;
    int place = 1;
    for (int i = 0; i < 5; i++)
    {
        int digit = pin % 10;
        pin /= 10;
        int val = map_values[digit] * place;
        correct_pin += val;
        place *= 10;
    }

    return correct_pin;
}

int main()
{
    const int original_pin = 12345;
    std::srand(std::time(0));

    int map_values [10];
    generate_mapping(map_values);

    std::cout << "Please enter your PIN according to the following mapping:\n";
    print_mapping(map_values);

    int user_pin;
    std::cin >> user_pin;

    int correct_pin = map_original_to_random(original_pin, map_values);

    if (user_pin == correct_pin)
    {
        std::cout << "Your PIN is correct";
    }
    else
    {
        std::cout << "Your PIN is not correct";
    }
    
    return 0;
}
