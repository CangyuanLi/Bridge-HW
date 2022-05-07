#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> mystery_algorithm(std::vector<int> vec, int p)
{
    auto n = vec.size();
    int i = 1;
    int j = n;

    int swap_count = 0;
    int count1 = 0;
    int count2 = 0;
    while (i < j)
    {
        while (i < j && vec[i-1] < p)
        {
            i += 1;
            count1 += 1;
        }
        while (i < j && vec[j-1] >= p)
        {
            j -= 1;
            count2 += 1;
        }

        // std::cout << "i is " << i << " j is " << j << '\n';
        
        if (i < j)
        {
            std::swap(vec[i-1], vec[j-1]);
            swap_count += 1;
        }
    }

    std::cout << "Count 1: " << count1 << '\n';
    std::cout << "Count 2: " << count2 << '\n';
    std::cout << "Swap count: " << swap_count << '\n';
    
    return vec;
}

int main()
{
    // std::vector<int> vec { 4, -1, 3, -2, 18, -39, -1, 2, 1, -2, -19, 4, 2, 3, 1, -8 };
    // std::vector<int> vec { -5, -1, -2, -4, -3, -2, -1, -8 };
    // std::vector<int> vec { -5, -1, -2, -4, -2, -1, -8, 3 };
    // std::vector<int> vec { -2, -1, -45, -23, -2, 1, 2, 3, 4, 5, 6, 7, 8};
    // std::vector<int> vec { 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, -2, -3, -4, -5, -6 };

    std::random_device rnd_device;
    std::mt19937 mersenne_engine {rnd_device()};
    std::uniform_int_distribution<int> dist {-100, 100};
    auto gen = [&dist, &mersenne_engine](){
                return dist(mersenne_engine);
               };
    std::vector<int> vec(10000);
    std::generate(vec.begin(), vec.end(), gen);

    // std::sort(vec.begin(), vec.end());

    const int p = 0;

    int num_neg = 0;
    int num_pos = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < p)
        {
            num_neg += 1;
        }
        else if (vec[i] >= p)
        {
            num_pos += 1;
        }
    }

    std::cout << "Number < p: " << num_neg << '\n';
    std::cout << "Number >= p: " << num_pos << '\n';

    std::vector<int> output_vector = mystery_algorithm(vec, p);

    // for (int i = 0; i < output_vector.size(); i++)
    // {
    //     std::cout << output_vector[i] << ", ";
    // }
    
    return 0;
}