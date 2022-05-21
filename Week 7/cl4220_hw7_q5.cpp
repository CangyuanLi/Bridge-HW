#include <iostream>

void print_array(int arr[], int arr_size)
{
    for(int i = 0; i <= arr_size - 1; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int *get_pos_nums1(int *arr, int arr_size, int &out_pos_arr_size)
{
    out_pos_arr_size = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0)
        {
            out_pos_arr_size += 1;
        } 
    }

    int *out_arr = new int [out_pos_arr_size];
    int j = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0)
        {
            out_arr[j] = arr[i];
            j += 1;
        }
    }

    return out_arr;
}

int *get_pos_nums2(int *arr, int arr_size, int *out_pos_arr_size_ptr)
{
    *out_pos_arr_size_ptr = 0; // dereference the pointer
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0)
        {
            *out_pos_arr_size_ptr += 1;
        } 
    }

    int *out_arr = new int [*out_pos_arr_size_ptr];
    int j = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0)
        {
            out_arr[j] = arr[i];
            j += 1;
        }
    }

    return out_arr;
}

void get_pos_nums3(int *arr, int arr_size, int *&out_pos_arr, int &out_pos_arr_size)
{
    out_pos_arr_size = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0) 
        {
            out_pos_arr_size += 1;
        }
    }

    int *out_arr = new int [out_pos_arr_size];
    int j = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0) 
        {
            out_arr[j] = arr[i];
            j += 1;
        }
    }

    out_pos_arr = out_arr;
}

void get_pos_nums4(int *arr, int arr_size, int **out_pos_arr_ptr, int *out_pos_arr_size_ptr)
{
    *out_pos_arr_size_ptr = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0)
        {
            *out_pos_arr_size_ptr += 1;
        }
    }
    
    int *out_arr = new int [*out_pos_arr_size_ptr];
    int j = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0)
        {
            out_arr[j] = arr[i];
            j += 1;
        }
    }

    *out_pos_arr_ptr = out_arr;
}

int main()
{
    // Test array
    int test_array [6] = { 3, -1, -3, 0, 6, 4 };

    //-------------- Part A --------------//
    std::cout << "Part A: ";
    int out_pos_arr_size1;
    int *new_array1 = get_pos_nums1(test_array, 6, out_pos_arr_size1);

    print_array(new_array1, out_pos_arr_size1);
    delete [] new_array1;

    //-------------- Part B --------------//
    std::cout << "Part B: ";
    int out_pos_arr_size_ptr2;
    int *new_array2 = get_pos_nums2(test_array, 6, &out_pos_arr_size_ptr2); // & gets address of var

    print_array(new_array2, out_pos_arr_size_ptr2);
    delete [] new_array2;

    //-------------- Part C --------------//
    std::cout << "Part C: ";
    int out_pos_arr_size3;
    int *new_array3 = nullptr;
    get_pos_nums3(test_array, 6, new_array3, out_pos_arr_size3);

    print_array(new_array3, out_pos_arr_size3);
    delete [] new_array3;

    //-------------- Part D --------------//
    std::cout << "Part D: ";
    int out_pos_arr_size4;
    int *new_array4 = nullptr;
    // ** is pointer to pointer. So we declare *new_array4 to be a pointer, and get the address
    // using &
    get_pos_nums4(test_array, 6, &new_array4, &out_pos_arr_size4);

    print_array(new_array4, out_pos_arr_size4);
    delete[] new_array4;

    return 0;
}
