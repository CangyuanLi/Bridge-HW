#include <iostream>

int main()
{
    int num1, num2;

    std::cout << "Please enter two positive integers, separated by a space:\n";
    std::cin >> num1 >> num2;

    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
    std::cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
    std::cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
    std::cout << num1 << " / " << num2 << " = " << (float)num1 / (float)num2 << "\n";
    std::cout << num1 << " div " << num2 << " = " << num1 / num2 << "\n";
    std::cout << num1 << " mod " << num2 << " = " << num1 % num2 << "\n";

    return 0;
}
