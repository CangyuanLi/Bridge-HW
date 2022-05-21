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
    // A is 65, a is 97. B is 66, b is 98. So the offset from upper to lower is always + 32
    const int OFFSET_FROM_LOWERCASE = 32;
    char lowercase_char = c;

    if (c >= 'A' && c <= 'Z') // exploit that A to Z are contiguous in ASCII table
    {
        lowercase_char = char(c + OFFSET_FROM_LOWERCASE);
    }
    
    return lowercase_char;
}

std::string clean_string(std::string str)
{
    // strip all but alphabet and lowercase everything
    std::string cleaned_string;
    for (int i = 0; i < str.length(); i++)
    {
        char lowercase_char = str_to_lower(str[i]);
        str[i] = lowercase_char;

        if (str[i] >= 'a' && str[i] <= 'z')
        {
            cleaned_string += str[i];
        }
    }
    
    return cleaned_string;
}

bool are_anagrams(std::string str1, std::string str2)
{
    const int ALPHABET_LEN = 26;
    std::string str1_cleaned = clean_string(str1);
    std::string str2_cleaned = clean_string(str2);

    int str1_len = str1_cleaned.length();
    int str2_len = str2_cleaned.length();

    if (str1_len != str2_len)
    {
        return false;
    }

    int char_counts [ALPHABET_LEN] = { }; // initializes all elements to 0

    for (int i = 0; i < str1_len; i++)
    {
        char char1 = str1_cleaned[i];
        char char2 = str2_cleaned[i];

        // if a character appears both words the same number of times, the counts will cancel out
        char_counts[char1] += 1;
        char_counts[char2] -= 1;
    }

    for (int i = 0; i < ALPHABET_LEN; i++)
    {
        if (char_counts[i] > 0)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    if (are_anagrams("Eleven plus two", "Twelve plus one"))
    {
        std::cout << "These are anagrams";
    }
    else
    {
        std::cout << "These are not anagrams";
    }
