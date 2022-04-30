#include <iostream>

int main()
{
    int n;
    std::cout << "Please enter a positive integer: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int num = i;
        int num_even_digits = 0;
        int num_odd_digits = 0;

        // look at each digit in the number
        while (num > 0)
        {
            int temp = num % 10;
            num /= 10;

            if (temp % 2 == 0)
            {
                num_even_digits += 1;
            }
            else if (temp % 2 != 0)
            {
                num_odd_digits += 1;
            }
        }

        if (num_even_digits > num_odd_digits)
        {
            std::cout << i << '\n';
        }
    }
    
    return 0;
}
