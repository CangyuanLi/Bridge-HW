#include <iostream>

int fib(int n)
{
    int prev_2 = 0;
    int prev_1 = 1;
    int current;
    int i;

    if (n == 0)
    {
        return prev_2;
    }

    for (int i = 2; i <= n; i++)
    {
        current = prev_2 + prev_1;
        prev_2 = prev_1;
        prev_1 = current;
    }
    
    return prev_1;
}

int main()
{
    int n;
    std::cout << "Please enter a positive integer: ";
    std::cin >> n;

    int result = fib(n);

    std::cout << result;
}
