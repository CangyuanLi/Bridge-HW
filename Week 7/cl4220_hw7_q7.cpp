#include <iostream>

int *find_missing(int arr [], int n, int &res_arr_size)
{
    // we know it is between 0 and n, so the max size is n + 1
    int temp_arr [n + 1];
    /// fill array with 0s
    for (int i = 0; i < n + 1; i++)
    {
        temp_arr[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        int arr_val = arr[i];
        temp_arr[arr_val] += 1; // increment the index associated with the value
    }

    res_arr_size = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (temp_arr[i] == 0)
        {
            res_arr_size += 1;
        }
    }

    int *missing_arr = new int [res_arr_size];
    int j = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (temp_arr[i] == 0)
        {
            missing_arr[j] = i;
            j += 1;
        }
    }

    return missing_arr;
}

int main()
{
    int test_arr [6] = { 3, 1, 3, 0, 6, 4 };
    
    int res_arr_size;
    int *res_arr = find_missing(test_arr, 6, res_arr_size);

    for (int i = 0; i < res_arr_size; i++)
    {
        std::cout << res_arr[i] << ' ';
    }
    
    return 0;
}
