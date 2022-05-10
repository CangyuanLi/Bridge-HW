#include <iostream>

void reverse_array(int arr [], int arr_size)
{
    // must be in place
    for (int i = 0; i < arr_size / 2; i++)
    {
        int current_val = arr[i];
        int reversed_index = arr_size - i - 1;
        arr[i] = arr[reversed_index];
        arr[reversed_index] = current_val;
    }
}

void remove_odd(int arr [], int &arr_size)
{
    // shift to the left when we want to delete a member
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            arr_size -= 1;
            for (int j = i; j < arr_size; j++)
            {
                arr[j] = arr[j + 1];
            }

            i -= 1;
        }
    }
}

void split_parity(int arr [], int arr_size)
{
    // move all odds to the front
    int j = 0;
    for (int i = 0; i < arr_size; i++)
    {
        int temp = arr[i];
        bool odd = (temp % 2 != 0);

        if (odd)
        {
            arr[i] = arr[j];
            arr[j] = temp;
            j += 1;
        }
    }
}

void print_array(int arr [], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';
}

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1_size = 5;
    reverse_array(arr1, arr1_size);
    print_array(arr1, arr1_size);

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2_size = 5;
    remove_odd(arr2, arr2_size);
    print_array(arr2, arr2_size);

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3_size = 5;
    split_parity(arr3, arr3_size);
    print_array(arr3, arr3_size);

    return 0;
}
