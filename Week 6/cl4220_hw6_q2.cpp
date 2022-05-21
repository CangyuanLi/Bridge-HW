#include <iostream>
#include <string>

bool is_palindrome(std::string str)
{
    int length = str.length();
    bool palindrome = true;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != str[length - i - 1]) // gets opposite index
        {
            palindrome = false;
            break;
        }
    }
    
    return palindrome;
}

int main()
{
    std::cout << "Please enter a word: ";
    std::string word;
    std::getline(std::cin, word);

    bool palindrome = is_palindrome(word);

    if (palindrome)
    {
        std::cout << word << " is a palindrome";
    }
    else
    {
        std::cout << word << " is not a palindrome";
    }
    
    return 0;
}
