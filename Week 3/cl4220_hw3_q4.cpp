#include <iostream>

int main()
{
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    float num;
    std::cout << "Please enter a real number:\n";
    std::cin >> num;

    int round_type;
    std::cout << "Choose your rounding method:\n"
              << "1. Floor round\n"
              << "2. Ceiling round\n"
              << "3. Round to the nearest whole number\n";
    std::cin >> round_type;

    int integer_num = (int)num;
    bool is_integer = (num - integer_num == 0);
    bool is_positive = (num > 0);
    bool is_negative = (num < 0);

    int rounded_num;
    if (is_integer)
    {
        rounded_num = integer_num;
    }
    else 
    {
        switch (round_type)
        {
            case FLOOR_ROUND:
                // floor is basically the integer part of the float
                if (is_negative)
                {
                    rounded_num = (int)(num - 1);
                }
                else
                {
                    rounded_num = integer_num;
                }
                break;
            case CEILING_ROUND:
                // ceiling is rounding up, no matter what
                // so increment the number by 1, so that 3.00...01 -> 4.00...01
                if (is_positive)
                {
                    rounded_num = (int)(num + 1);
                }
                else
                {
                    rounded_num = (int)num;
                }
                break;
            case ROUND:
                if (is_positive)
                {
                    rounded_num = (int)(num + 0.5);
                }
                else
                {
                    rounded_num = (int)(num - 0.5);
                }
                break;
        }
    }

    std::cout << rounded_num;

    return 0;
}
