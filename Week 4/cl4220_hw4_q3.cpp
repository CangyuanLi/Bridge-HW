#include <cmath>
#include <iostream>

int main()
{
    /**
     * The algorithm shown in class is to divide the decimal number by 2, save the remainder, and
     * use the new quotient in the next iteration. The remainders are then concatenated in 
     * reverse order, ie. the last iteration is the first digit of the binary number. One way to do
     * this without arrays or strings is to represent the remainder of the first iteration 
     * as the ones place, the second iteration as the tens place, and so on. This is accomplished
     * by multiplying by 1, 10, 100, 1000, and so on. However, this version of the algorithm runs
     * into integer overflow very quickly, and the output will be garbage for any moderately large
     * decimal number, e.g. 2000_{10}.
     * 
     * Therefore, we instead use the algorithm shown in Week 1 Module 2, where we find the max power
     * of 2 the decimal number is able to take (e.g. 75 -> 2^6), take the remainder of 75 - 2^6,
     * and then try with 2^5, 2^4, ..., until 2^0. If a certain power > remainder, then that digit
     * is set to 0 (ex: 0 2^5's fit into 75 - 2^6), and so on.
     */

    int base_ten_number;
    std::cout << "Enter a decimal number:\n";
    std::cin >> base_ten_number;

    // find the max power of 2
    int temp_num = base_ten_number; // declare temp var to avoid destroying input number
    int max_power = 0;
    while (temp_num > 1)
	{
		temp_num /= 2; 
		max_power += 1; 
	}

    std::cout << "The binary representation of " << base_ten_number << " is "; 
    int remainder = base_ten_number;
    int exponent = max_power; // temp variable so we don't change max_power while iterating over it
    for (int i = 0; i < max_power + 1; i++) // loop to max_power + 1 b/c 2^0 is last digit
    {
        int current_power = std::pow(2, exponent);
        remainder = base_ten_number - current_power;

        if (remainder >= 0)
        {
            std::cout << '1';
            base_ten_number = remainder;
        }
        else if (remainder < 0)
        {
            std::cout << '0';
        }

        exponent -= 1;
    }

    return 0;
}
