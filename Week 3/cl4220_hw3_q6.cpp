#include <iostream>
#include <string>

int main()
{
    const float EIGHT_SIX_RATE = 0.40;
    const float DAY_NIGHT_RATE = 0.25;
    const float WEEKEND_RATE = 0.15;
    const int EIGHT_AM = 800;
    const int SIX_PM = 1800;

    int started_hour, started_minute;
    char separator;
    std::cout << "Enter the time in 24-hour notation, ex: 13:30:\n";
    std::cin >> started_hour >> separator >> started_minute;

    int length_of_call;
    std::cout << "Enter the length of the call in minutes:\n";
    std::cin >> length_of_call;

    std::string day;
    std::cout << "Enter the day of week (Mo Tu We Th Fr Sa Su):\n";
    std::cin >> day;
    
    int started_time = started_hour * 100 + started_minute;


    float cost;
    if (day == "Sa" || day == "Su")
    {
        cost = length_of_call * WEEKEND_RATE;
    }
    else
    {
        if (started_time >= EIGHT_AM && started_time <= SIX_PM)
        {
            cost = length_of_call * EIGHT_SIX_RATE;
        }
        else
        {
            cost = length_of_call * DAY_NIGHT_RATE;
        }
    }

    std::cout << "The cost of your call is $" << cost;

    return 0;
}
