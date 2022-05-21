#include <iostream>
#include <string>

bool is_in_array(char target, char arr [], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    
    return false;
}

char str_to_lower(char c)
{
    char lowercase_char = c;

    if (c >= 'A' && c <= 'Z')
    {
        lowercase_char = char(c + 32);
    }
    
    return lowercase_char;
}

int main()
{
    const int ALPHABET_LEN = 26;
    char WORD_DELIMITERS [3] = { ' ', '.', ',' };

    std::cout << "Please enter a line of text:\n";
    std::string input;
    std::getline(std::cin, input);
    int word_length = input.length();

    int letter_counts [ALPHABET_LEN] = { }; // initializes all elements to 0
    int word_count = 0;

    for (int i = 0; i < word_length; i++)
    {
        char current_char = str_to_lower(input[i]);
        int offset_from_a = current_char - 'a';

        if (is_in_array(current_char, WORD_DELIMITERS, 3) || i == word_length - 1)
        {
            word_count += 1;
        }

        if (current_char >= 'a' && current_char <= 'z')
        {
            letter_counts[offset_from_a] += 1;
        }
    }

    std::cout << word_count << "\twords" << '\n';

    for (int i = 0; i < ALPHABET_LEN; i++)
    {
        int letter_count = letter_counts[i];
        if (letter_count > 0)
        {
            std::cout << letter_count << '\t' << char(i + 'a') << '\n';
        }
    }
    
    return 0;
}
