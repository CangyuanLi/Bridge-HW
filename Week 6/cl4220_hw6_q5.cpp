#include <iostream>

int main()
{
    std::cout << "Please enter your name:\n";
    std::string first_name, middle_name, last_name;
    std::cin >> first_name >> middle_name >> last_name;

    std::cout << last_name << ", " << first_name << ' ' << middle_name[0] << '.';
}
