#include <iostream>
#include <map>
#include <string>

int main()
{
    int base_ten_number;
    std::cout << "Enter a decimal number:\n";
    std::cin >> base_ten_number;

    // we always want to apply the highest number first (otherwise we get a 1000 I's)
    // so when we iterate go from 1000 (M) to 1 (I)
    const int roman_numerals [7] = { 1000, 500, 100, 50, 10, 5, 1 };

    std::cout << base_ten_number << " is ";

    int remainder = base_ten_number;
    std::string roman_result_string;
    for (int i = 0; i < 7; i++)
    {
        // map each value to the corresponding roman numeral character
        int roman_numeral = roman_numerals[i];
        char roman_char;
        switch (roman_numeral)
        {
            case 1000:
                roman_char = 'M';
                break;
            case 500:
                roman_char = 'D';
                break;
            case 100:
                roman_char = 'C';
                break;
            case 50:
                roman_char = 'L';
                break;
            case 10:
                roman_char = 'X';
                break;
            case 5:
                roman_char = 'V';
                break;
            case 1:
                roman_char = 'I';
                break;
        }
        
        int num_numerals = remainder / roman_numeral;
        remainder = remainder % roman_numeral;

        for (int i = 0; i < num_numerals; i++)
        {
           std::cout << roman_char;
        }
    }

    return 0;
}
