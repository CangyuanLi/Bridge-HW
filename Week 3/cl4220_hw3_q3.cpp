#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
    double a, b, c;

    std::cout << "Please enter the value of a: ";
    std::cin >> a;

    std::cout << "Please enter the value of b: ";
    std::cin >> b;

    std::cout << "Please enter the value of c: ";
    std::cin >> c;

    /**
     * There are 6 cases
     * 1. Infinite number of solutions: a = b = c = 0
     * 2. No real solutions: b^2 - 4ac < 0
     * 3. One real solution: b^2 - 4ac = 0
     * 4. Two real solutions: b^2 - 4ac > 0
     * 5. No solutions: a = b = 0 and c != 0
     * 6. Linear equation with one solution: a = 0 and b != 0
     */

    // first deal the cases where a is 0.
    // make sure that infinite / no solutions come first, since they dominate the rest of the cases

    bool infinite_solutions = (a == 0 && b == 0 && c == 0);
    bool no_solutions = (a == 0 && b == 0 && c != 0);
    bool valid_linear_equation = (a == 0 && b != 0);

    if (infinite_solutions)
    {
        std::cout << "This equation has infinite solutions";
    }
    else if (no_solutions)
    {
        std::cout << "This equation has no solutions";
    }
    else if (valid_linear_equation)
    {
        double x = (0 - c) / b;
        std::cout << "This equation has one real solution x=" << x;
    }

    // now deal with the rest of the cases

    double discriminant = (b * b) - (4 * a * c);

    bool no_real_solutions = (a != 0 && discriminant < 0);
    bool one_real_solution = (a != 0 && discriminant == 0);
    bool two_real_solutions = (a != 0 && discriminant > 0);

    // print only one decimal place
    std::cout << std::fixed << std::setprecision(1);

    if (no_real_solutions)
    {
        std::cout << "This equation has no real solutions";
    }
    else if (one_real_solution)
    {
        // in this case it doesn't matter + / - since they are the same
        double x = (-1 * b + std::sqrt(discriminant)) / (2 * a);
        std::cout << "This equation has a single real solution x=" << x;
    }
    else if (two_real_solutions)
    {
        double x1 = (-1 * b + std::sqrt(discriminant)) / (2 * a);
        double x2 = (-1 * b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "This equation has two real solutions x1=" << x1 << " and x2=" << x2;
    }

    return 0;
}
