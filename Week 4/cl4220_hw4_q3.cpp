#include <iostream>

int main()
{
    int base_ten_number;
    std::cout << "Enter a decimal number:\n";
    std::cin >> base_ten_number;

    int binary_result = 0;
    int digits_place = 1;
    int quotient = base_ten_number;
    while (quotient > 0)
    {
        int remainder = quotient % 2;
        binary_result += remainder * digits_place;

        quotient /= 2;
        digits_place *= 10;
    }

    std::cout << "The binary representation of " << base_ten_number << " is " << binary_result;
    
    return 0;
}
