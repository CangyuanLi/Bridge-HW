#include <iostream>

void odds_keep_evens_flip(int arr [], int arr_size)
{
    // create two arrays, one to hold the evens and one to hold the odds
    int odds_arr [arr_size];
    int evens_arr [arr_size];

    int evens_index = 0;
    int odds_index = 0;
    for(int i = 0; i < arr_size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evens_arr[evens_index] = arr[i];
            evens_index += 1;
        }
        else
        {
            odds_arr[odds_index] = arr[i];
            odds_index += 1;
        }
    }
    
    // since the odds come first, just copy the array (ignoring the junk values)
    // into the master array
    for (int i = 0; i < odds_index; i++)
    {
        arr[i] = odds_arr[i];
    }
    
    std::cout << '\n';

    // since the evens are in the back half, we need to start at the end of the odds
    // and we iterate through the evens in reverse order to "flip" them
    for (int i = evens_index - 1; i >= 0; i--)
    {
        arr[odds_index] = evens_arr[i];
        odds_index += 1;
    }
}

int main()
{
    int arr [6] = { 5, 2, 11, 7, 6, 4 };
    
    odds_keep_evens_flip(arr, 6);
    
    std::cout << "The final array is: \n";
    for (int i = 0; i < 6; i++)
    {
        std::cout << arr[i] << ' ';
    }

    return 0;
}
