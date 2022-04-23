#include <iostream>
#include <string>

int main()
{
    std::string user_name;
    int current_year, grad_year;

    std::cout << "Please enter your name: ";
    std::cin >> user_name;

    std::cout << "Please enter your graduation year: ";
    std::cin >> grad_year;

    std::cout << "Please enter current year: ";
    std::cin >> current_year;

    /**
     * Possible statuses:
     * 1. Not in college yet
     * 2. Freshman: grad_year = current_year + 4
     * 3. Sophomore: grad_year = current_year + 3
     * 4. Junior: grad_year = current_year + 2
     * 5. Senior: grad_year = current_year + 1
     * 6. Graduated: grad_year <= current_year
     */

    int difference = grad_year - current_year;
    std::string status;

    if (difference <= 0)
    {
        status = "Graduated";
    }
    else if (difference == 1)
    {
        status = "a Senior";
    }
    else if (difference == 2)
    {
        status = "a Junior";
    }
    else if (difference == 3)
    {
        status = "a Sophomore";
    }
    else if (difference == 4)
    {
        status = "a Freshman";
    }
    else if (difference >= 5)
    {
        status = "Not in college yet";
    }

    std::cout << user_name << ", you are " << status;

    return 0;
}
