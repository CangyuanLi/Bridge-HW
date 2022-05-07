#include <iostream>
#include <string>

bool is_leap_year(int year)
{
    bool divis_by_4 = (year % 4 == 0);
    bool divis_by_100 = (year % 100 == 0);
    bool divis_by_400 = (year % 400 == 0);

    return (divis_by_4 && !divis_by_100) || (divis_by_100 && divis_by_400);
}

std::string map_day_to_string(int day)
{
    std::string day_string;
    switch (day)
    {
        case 1:
            day_string = "Mon";
            break;
        case 2:
            day_string = "Tue";
            break;
        case 3:
            day_string = "Wed";
            break;
        case 4:
            day_string = "Thr";
            break;
        case 5:
            day_string = "Fri";
            break;
        case 6:
            day_string = "Sat";
            break;
        case 7:
            day_string = "Sun";
            break;
    }

    return day_string;
}

std::string map_month_to_string(int month)
{
    std::string month_string;
    switch (month)
    {
        case 1:
            month_string = "January";
            break;
        case 2:
            month_string = "February";
            break;
        case 3:
            month_string = "March";
            break;
        case 4:
            month_string = "April";
            break;
        case 5:
            month_string = "May";
            break;
        case 6:
            month_string = "June";
            break;
        case 7:
            month_string = "July";
            break;
        case 8:
            month_string = "August";
            break;
        case 9:
            month_string = "September";
            break;
        case 10:
            month_string = "October";
            break;
        case 11:
            month_string = "November";
            break;
        case 12:
            month_string = "December";
            break;
    }

    return month_string;
}

int get_days_in_month(int month, bool leap_year)
{
    int num_days;
    if (leap_year && month == 2)
    {
        num_days = 29;
    }
    else if (month == 2)
    {
        num_days = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        num_days = 30;
    }
    else
    {
        num_days = 31;
    }

    return num_days;
}

int print_month_calendar(int num_days, int starting_day)
{
    // print the header
    for (int i = 1; i <= 7; i++)
    {
        std::cout << map_day_to_string(i) << '\t';
    }
    std::cout << '\n';

    int day_column = 1;
    int day = 1;
    while (day <= num_days)
    {
        day_column = 1;
        for (int j = 1; j <= 7; j++)
        {
            if (day > num_days)
            {
                break;
            }
            if (j >= starting_day)
            {
                std::cout << day;
                day += 1;
            }
            day_column += 1;
            std::cout << '\t';
        }
        starting_day = 1;
        std::cout << '\n';
    }
    
    return day_column - 1;
}

void print_year_calendar(int year, int starting_day)
{
    bool leap_year = is_leap_year(year);
    for (int month = 1; month <= 12; month++)
    {
        std::string month_string = map_month_to_string(month);
        int num_days = get_days_in_month(month, leap_year);

        std::cout << month_string << ' ' << year << '\n';
        int last_day = print_month_calendar(num_days, starting_day);
        starting_day = last_day + 1;
        if (starting_day == 8)
        {
            starting_day = 1;
        }

        std::cout << '\n';
    }
}

int main()
{
    int year;
    std::cout << "Please enter the year: ";
    std::cin >> year;

    int starting_day;
    std::cout << "Please enter the starting day of January 1st: ";
    std::cin >> starting_day;

    std::cout << '\n';

    print_year_calendar(year, starting_day);

    return 0;
}
