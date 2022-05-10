#include <iostream>

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

bool is_digit(char character)
{   
    char digits [10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    if (is_in_array(character, digits, 10))
    {
        return true;
    }

    return false;
}

bool word_only_has_digits(std::string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (!is_digit(word[i]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::cout << "Please enter a line of text:\n";
    std::string user_line;
    std::getline(std::cin, user_line);

    for (int i = 0; i < user_line.length(); i++)
    {
        // tokenize, assuming a space delimits a word
        std::string word = "";
        while (user_line[i] != ' ')
        {
            if (i == user_line.length())
            {
                break;
            }

            word += user_line[i];
            i += 1;
        }

        if (word_only_has_digits(word))
        {
            for (int j = 0; j < word.length(); j++)
            {
                if (is_digit(word[j]))
                {
                    word[j] = 'x';
                }
            }
        }

        std::cout << word << ' ';
    }
}
