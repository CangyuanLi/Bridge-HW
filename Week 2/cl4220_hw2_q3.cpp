#include <iostream>

int main()
{
    const int MINUTES_IN_HOUR = 60;
    const int HOURS_IN_DAY = 24;
    // John

    int j_days, j_hours, j_minutes;

    std::cout << "Please enter the number of days John has worked: ";
    std::cin >> j_days;

    std::cout << "Please enter the number of hours John has worked: ";
    std::cin >> j_hours;

    std::cout << "Please enter the number of minutes John has worked: ";
    std::cin >> j_minutes;

    // Bill

    std::cout << "\n";

    int b_days, b_hours, b_minutes;

    std::cout << "Please enter the number of days Bill has worked: ";
    std::cin >> b_days;

    std::cout << "Please enter the number of hours Bill has worked: ";
    std::cin >> b_hours;

    std::cout << "Please enter the number of minutes Bill has worked: ";
    std::cin >> b_minutes;

    // Calculation

    int both_days = j_days + b_days;
    int both_hours = j_hours + b_hours;
    int both_minutes = j_minutes + b_minutes;

    int additional_hours = both_minutes / MINUTES_IN_HOUR;
    int minutes_final = both_minutes % MINUTES_IN_HOUR;

    int new_hours = both_hours + additional_hours;
    int additional_days = new_hours / HOURS_IN_DAY;
    int hours_final = new_hours % HOURS_IN_DAY;

    int days_final = both_days + additional_days;

    // Print result

    std::cout << "The total time both of them worked together is: " 
              << days_final << " days, "
              << hours_final << " hours and "
              << minutes_final << " minutes.";
             
    return 0;
}
