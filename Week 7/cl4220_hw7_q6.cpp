#include <iostream>
#include <vector>

// taken from the lecture
void resize_array(int *&arr, int current_size, int new_size)
{
    int *temp = new int [new_size];
    for (int i = 0; i < current_size; i++)
    {
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
}

void main1()
{
    int size = 0;
    int *arr = new int [size];
    
    std::cout << "Please enter a sequence of positive integers, each in a separate line.\n"
              << "End your input by typing -1.\n";
    
    int idx = 0;
    while (true)
    {
        int input;
        std::cin >> input;
        if (input == -1)
        {
            break;
        }
        arr[idx] = input;
        idx += 1;
        
        if (idx == size) // when we hit the limit, increase the size
        {
            resize_array(arr, size, idx + 1);
        }
    }

    size = idx;

    std::cout << "Please enter a number you want to search:\n";
    int target_num;
    std::cin >> target_num;

    std::cout << target_num << " shows in lines ";

    int num_occurences = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target_num)
        {
            num_occurences += 1;
        } 
    }

    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target_num)
        {
            std::cout << i + 1;
            if (count == num_occurences)
            {
                std::cout << '.';
            }
            else
            {
                std::cout << ", ";
            }
            count += 1;
        }
    }
}

void main2()
{
    std::cout << "Please enter a sequence of positive integers, each in a separate line.\n"
              << "End your input by typing -1.\n";
    
    std::vector<int> vec;
    while (true)
    {
        int input;
        std::cin >> input;
        if (input == -1)
        {
            break;
        }
        vec.push_back(input);
    }

    std::cout << "Please enter a number you want to search:\n";
    int target_num;
    std::cin >> target_num;

    int num_occurences = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target_num)
        {
            num_occurences += 1;
        }
    }

    std::cout << target_num << " shows in lines ";
    
    int count = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target_num)
        {
            std::cout << i + 1;
            if (count == num_occurences)
            {
                std::cout << '.';
            }
            else
            {
                std::cout << ", ";
            }
            count += 1;
        }
    }
}

int main()
{
    std::cout << "Using arrays:\n";
    main1();
    std::cout << "\n\n";

    std::cout << "Using vector:\n";
    main2();

    return 0;
}
