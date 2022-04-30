#include <iostream>

int main()
{
    int num_even_numbers, count;
    std::cout << "Please enter a positive integer: ";
    std::cin >> num_even_numbers;

    // Section A- while loop
    std::cout << "Section A\n";

    int even_num = 2;
    count = num_even_numbers;
    while (count > 0)
    {
        std::cout << even_num << '\n';
        even_num += 2;
        count -= 1;
    }

    std::cout << '\n';

    // Section B- for loop
    std::cout << "Section B\n";

    even_num = 2;
    count = num_even_numbers;
    for (int i = 0; i < count; i++)
    {
        std::cout << even_num << '\n';
        even_num += 2;
    }
    
    return 0;
}