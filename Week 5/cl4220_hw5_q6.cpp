#include <iostream>

double e_approx(int n)
{
    const double numerator = 1.0;
    double e = 1;
    double denominator = 1;

    for (int i = 1; i <= n; i++)
    {
        denominator *= i;
        e += (numerator / denominator);
    }

    return e;
}

int main()
{
    std::cout.precision(30);

    for (int i = 1; i <= 15; i++)
    {
        std::cout << "n = " << i << '\t' << e_approx(i) << '\n';
    }
    
    return 0;
}
