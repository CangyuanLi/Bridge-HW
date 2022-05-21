#include <iostream>
#include <string>

std::string *create_words_array(std::string sentence, int &out_words_arr_size)
{
    out_words_arr_size = 1;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ') 
        {
            out_words_arr_size += 1;
        }
    }

    std::string *word_array = new std::string[out_words_arr_size];
    int space_idx = sentence.find(' ');
    int array_idx = 0;
    int word_idx = 0;
    while (array_idx < out_words_arr_size)
    {
        word_array[array_idx] = sentence.substr(word_idx, (space_idx - word_idx));
        array_idx += 1;
        word_idx = space_idx + 1;
        space_idx = sentence.find(' ', word_idx);
    }

    return word_array;
}

int main()
{
    int out_words_arr_size;
    std::string *word_array = create_words_array("this is a test sentence", out_words_arr_size);

    for (int i = 0; i < out_words_arr_size; i++)
    {
        std::cout << word_array[i] << ' ';
    }

    std::cout << out_words_arr_size;
    
    return 0;
}