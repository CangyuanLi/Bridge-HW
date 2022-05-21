#include <iostream>

int min_in_array(int arr [], int arr_size)
{
    int min_value = arr[0];
    for (int i = 1; i < arr_size ; i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    
    return min_value;
}

int main()
{
    std::cout << "Please enter 20 integers separated by a space:\n";
    int nums [20];
    for (int i = 0; i < 20; i++)
    {
        std::cin >> nums[i];
    }

    int min_value = min_in_array(nums, 20);

    std::cout << "The minimum value is " << min_value << ", and it is located in the following"
              << "indices: ";
    for (int i = 0; i < 20; i++)
    {
        if (nums[i] == min_value)
        {
            std::cout << i << ' ';
        }
    }
    
    return 0;
}
