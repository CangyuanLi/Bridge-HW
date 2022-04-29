#include <iostream>

int main()
{
    int base_ten_number;
    std::cout << "Enter a decimal number:\n";
    std::cin >> base_ten_number;

    /**
     * The algorithm shown in class is to divide the decimal number by 2, save the remainder, and
     * use the new quotient in the next iteration. The remainders are then concatenated in 
     * reverse order, ie. the last iteration is the first digit of the binary number. Since we are
     * not allowed to use arrays or strings, represent the remainder of the first iteration 
     * as the ones place, the second iteration as the tens place, and so on. This is accomplished
     * by multiplying by 1, 10, 100, 1000, and so on.
     */

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
