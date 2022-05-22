#include <algorithm>
#include <iostream>

{ 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
int min_in_array1(int arr [], int arr_size)
{
    if (arr_size == 1)
    {
        return arr[0];
    }
    else
    {
        int min_val = min_in_array1(arr, arr_size - 1);
        if (arr[arr_size - 1] < min_val)
        {
            return arr[arr_size - 1];
        }
        else
        {
            return min_val;
        }
    }
}

int min_in_array2(int arr [], int low, int high)
{
    if (arr_size == 1)
    {
        return arr[0];
    }
    else
    {
        int min_val = min_in_array1(arr, arr_size - 1);
        if (arr[arr_size - 1] < min_val)
        {
            return arr[arr_size - 1];
        }
        else
        {
            return min_val;
        }
    }
}

int main()
{
    int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
    int res1, res2, res3, res4;
    res1 = min_in_array1(arr, 10);
    std::cout << res1;
    // res2 = min_in_array2(arr, 0, 9);
    // std::cout << res1 << ' ' << res2 << std::endl; //should both be -9
    // res3 = min_in_array2(arr, 2, 5);
    // res4 = min_in_array1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
    // std::cout << res3 << ' ' << res4 << std::endl; //should both be 
}