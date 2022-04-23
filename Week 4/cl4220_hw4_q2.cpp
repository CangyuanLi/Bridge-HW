#include <iostream>
#include <map>
#include <string>

int main()
{
    int base_ten_number;
    std::cout << "Enter a decimal number:\n";
    std::cin >> base_ten_number;

    std::map<int, char> roman_numeral_map = {
        {1000, 'M'},
        {500, 'D'},
        {100, 'C'},
        {50, 'L'},
        {10, 'X'},
        {5, 'V'},
        {1, 'I'}
    };

    int remainder = base_ten_number;
    std::string roman_result_string;
    for (auto iter = roman_numeral_map.rbegin(); iter != roman_numeral_map.rend(); iter++)
    {
        int roman_numeral = iter -> first;
        char roman_char = iter -> second;
        
        int num_numerals = remainder / roman_numeral;
        remainder = remainder % roman_numeral;

        for (int i = 0; i < num_numerals; i++)
        {
            roman_result_string.push_back(roman_char);
        }
    }

    std::cout << base_ten_number << " is " << roman_result_string;

    return 0;
}
