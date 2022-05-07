#include <cmath>
#include <iostream>

void analyze_divisors(int num, int &out_count_divs, int &out_sum_divs)
{
    int num_divisors = 0;
    int sum = 0;
    for (int i = 1; i < std::sqrt(num); i++)
    {
        if (num % i == 0)
        {
            num_divisors += 1;
            sum += i;
        }
    }

    for (int i = std::sqrt(num); i > 0; i--)
    {
        if (num % i == 0)
        {
            num_divisors += 1;
            sum += (num / i);
        }
    }

    out_count_divs = num_divisors - 1;
    out_sum_divs = sum - num;
}

bool is_perfect(int num)
{
    int count;
    int sum;
    analyze_divisors(num, count, sum);

    return sum == num;
}

bool is_amicable(int num1, int num2, int sum1, int sum2)
{
    return (num1 == sum2) && (num2 == sum1) && (num1 != num2);
}

int main()
{
    int M;
    std::cout << "Please enter a positive integer M >= 2: ";
    std::cin >> M;

    // perfect numbers
    std::cout << '\n';
    std::cout << "The list of perfect numbers: ";
    for (int i = 2; i <= M; i++)
    {
        if (is_perfect(i))
        {
            std::cout << i << ' ';
        }
    }
    
    // amicable numbers
    std::cout << '\n';
    std::cout << "The list of amicable numbers: ";

    for (int i = 2; i <= M; i++)
    {
        int count1;
        int sum1;
        analyze_divisors(i, count1, sum1);

        int num2 = sum1;
        int count2;
        int sum2;
        analyze_divisors(num2, count2, sum2);

        if (is_amicable(i, num2, sum1, sum2) && num2 > i)
        {
            std::cout << '(' << i << ", " << num2 << ") ";
        }
    }

    return 0;
}
