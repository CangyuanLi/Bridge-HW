#include <iostream>

int sum_of_squares(int arr [], int arr_size)
{
    int res;
    if (arr_size == 1)    
    {
        return arr[0] * arr[0];
    }
    else
    {
        int size = arr_size - 1;
        res = sum_of_squares(arr, size);

        return res + (arr[size] * arr[size]);
    }
}

bool is_sorted(int arr [], int arr_size)
{
    if (arr_size == 1)
    {
        return true;
    }

    if (arr[arr_size - 1] < arr[arr_size - 2])
    {
        return false;
    }

    return is_sorted(arr, arr_size - 1);
}

int main()
{
    int test_arr [4] = { 2, -1, 3, 10 };
    int res = sum_of_squares(test_arr, 4);
    std::cout << res << '\n';

    int test_arr1 [4] = { 1, 2, 3, 4 };
    int test_arr2 [4] = { 1, 3, 2, 4 };

    std::cout << is_sorted(test_arr1, 4) << '\n';
    std::cout << is_sorted(test_arr2, 4) << '\n';
}