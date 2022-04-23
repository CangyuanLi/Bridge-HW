#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

bool almost_equal(float a, float b, float epsilon = __FLT_EPSILON__)
{
    return std::abs(a - b) <= ( (std::abs(a) > std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
}

struct q1Answer {
    float base_price;
    float price_after_discount;
    float final_price;
};

q1Answer q1(float item1_price, float item2_price, char has_club_card, float tax_rate)
{
    const float CLUB_DISCOUNT_RATE = .1;

    q1Answer answer;

    tax_rate = tax_rate / 100;

    float base_price = item1_price + item2_price;

    if (item1_price < item2_price)
    {
        item1_price = item1_price / 2;
    }
    else
    {
        item2_price = item2_price / 2;
    }

    float price_after_discount = item1_price + item2_price;

    if (has_club_card == 'y' || has_club_card == 'Y')
    {
        price_after_discount = price_after_discount * (1 - CLUB_DISCOUNT_RATE);
    }

    float final_price = price_after_discount * (1 + tax_rate);

    answer.base_price = base_price;
    answer.price_after_discount = price_after_discount;
    answer.final_price = final_price;

    return answer;
}

void q1_checks()
{
    q1Answer test1 = q1(10, 20, 'y', 8.25);
    assert((test1.base_price == 30));
    assert(almost_equal(test1.price_after_discount, 22.5));
    assert(almost_equal(test1.final_price, 24.35625));
}

std::string q2(int current_year, int grad_year)
{
    int difference = grad_year - current_year;
    std::string status;

    switch (difference)
    {
        case 0:
            status = "Graduated";
            break;
        case 1:
            status = "Senior";
            break;
        case 2:
            status = "Junior";
            break;
        case 3:
            status = "Sophomore";
            break;
        case 4:
            status = "Freshman";
            break;
        default:
            status = "Not in college yet";
            break;
    }

    return status;
}

void q2_checks()
{
    assert((q2(2015, 2019) == "Freshman"));
}

struct q3Answer
{
    std::string solution_type;
    float x1 = NAN;
    float x2 = NAN;
};

q3Answer q3(double a, double b, double c)
{
    q3Answer answer;

    bool infinite_solutions = (a == 0 && b == 0 && c == 0);
    bool no_solutions = (a == 0 && b == 0 && c != 0);
    bool valid_linear_equation = (a == 0 && b != 0);

    if (infinite_solutions)
    {
        answer.solution_type = "infinite";
    }
    else if (no_solutions)
    {
        answer.solution_type = "none";
    }
    else if (valid_linear_equation)
    {
        double x = (0 - c) / b;
        answer.solution_type = "one real";
        answer.x1 = x;
    }

    // now deal with the rest of the cases

    double discriminant = (b * b) - (4 * a * c);

    bool no_real_solutions = (a != 0 && discriminant < 0);
    bool one_real_solution = (a != 0 && discriminant == 0);
    bool two_real_solutions = (a != 0 && discriminant > 0);

    if (no_real_solutions)
    {
        answer.solution_type = "no real";
    }
    else if (one_real_solution)
    {
        // in this case it doesn't matter + / - since they are the same
        double x = (-1 * b + std::sqrt(discriminant)) / (2 * a);
        answer.solution_type = "one real";
        answer.x1 = x;
    }
    else if (two_real_solutions)
    {
        double x1 = (-1 * b + std::sqrt(discriminant)) / (2 * a);
        double x2 = (-1 * b - std::sqrt(discriminant)) / (2 * a);
        answer.solution_type = "two real";
        answer.x1 = x1;
        answer.x2 = x2;
    }

    return answer;
}

void q3_checks()
{
    q3Answer test1 = q3(1, 4, 4);
    assert((test1.solution_type == "one real"));
    assert((test1.x1 == -2));

    q3Answer test2 = q3(0, 0, 4);
    assert((test2.solution_type == "none"));

    q3Answer test3 = q3(0, 0, 0);
    assert((test3.solution_type == "infinite"));

    q3Answer test4 = q3(0, 2, -2);
    assert((test4.x1 == 1));
}

int q4(float num, int round_type)
{
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    int integer_num = (int)num;
    bool is_integer = (num - integer_num == 0);
    bool is_positive = (num > 0);
    bool is_negative = (num < 0);

    int rounded_num;
    if (is_integer)
    {
        rounded_num = integer_num;
    }
    else 
    {
        switch (round_type)
        {
            case FLOOR_ROUND:
                // floor is basically the integer part of the float
                if (is_negative)
                {
                    rounded_num = (int)(num - 1);
                }
                else
                {
                    rounded_num = integer_num;
                }
                break;
            case CEILING_ROUND:
                // ceiling is rounding up, no matter what
                // so increment the number by 1, so that 3.00...01 -> 4.00...01
                if (is_positive)
                {
                    rounded_num = (int)(num + 1);
                }
                else
                {
                    rounded_num = (int)num;
                }
                break;
            case ROUND:
                if (is_positive)
                {
                    rounded_num = (int)(num + 0.5);
                }
                else
                {
                    rounded_num = (int)(num - 0.5);
                }
                break;
        }
    }
    
    return rounded_num;
}

int am_q4(double numInput, int choice)
{
    using namespace std;
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    int lower, upper, roundedOutput;
    double dLower, dUpper;

    switch (choice)
    {
    case FLOOR_ROUND:
    {  
        if (numInput >= 0)
            roundedOutput = int(numInput);
        
        else
            roundedOutput = (int(numInput) - 1);
        
        break;
    }
    case CEILING_ROUND:
    {    
        if (numInput >= 0)
            roundedOutput = ( int(numInput) + 1);
        else
            roundedOutput = int(numInput);
        break;
    }
    case ROUND:

        if (numInput >=0)
        {
            lower = int(numInput);
            dLower = double(lower);

            if ((numInput - dLower) <= 0.49) 
            {   
                roundedOutput = int(numInput);
            }
            else
            {
                roundedOutput = int(numInput) + 1;
            }
        }
        else
        {
            upper = int(numInput);
            dUpper = double(upper);

            if ((dUpper - numInput) <= 0.5)
            {   
                roundedOutput = int(numInput);
            }
            else
            {
                roundedOutput = (int(numInput) - 1);
            }
        }
        break;
    
    default:
        cout<<"This is an invalid choice"<<endl;
    }

    return roundedOutput;
}

void am_q4_checks()
{
    // for (int i = -100; i < 100; i++)
    // {
    //     assert((am_q4(i, 1) == i));
    //     assert((am_q4(i, 2) == i));
    //     assert((am_q4(i, 3) == i));
    // }

    float to_check [6] = { -3.6, -3.5, -3.3, 3.3, 3.5, 3.6 };
    for (int i = 0; i < 6; i ++)
    {
        float input = to_check[i];
        assert((am_q4(input, 1) == std::floor(input)));
        assert((am_q4(input, 2) == std::ceil(input)));
        assert((am_q4(input, 3) == std::round(input)));
    }
}

void q4_checks()
{
    for (int i = -100; i < 100; i++)
    {
        assert((q4(i, 1) == i));
        assert((q4(i, 2) == i));
        assert((q4(i, 3) == i));
    }

    float to_check [12] = { -4.6, -4.5, -4.3, -3.6, -3.5, -3.3, 3.3, 3.5, 3.6, 4.3, 4.5, 4.6 };
    for (int i = 0; i < 12; i ++)
    {
        float input = to_check[i];
        assert(q4(input, 1) == std::floor(input));
        assert((q4(input, 2) == std::ceil(input)));
        assert((q4(input, 3) == std::round(input)));
    }
}

std::string q5(float weight, float height)
{
    const float KILOGRAMS_IN_POUND = 0.453592;
    const float METERS_IN_INCH = 0.0254; 

    float weight_in_kg = weight * KILOGRAMS_IN_POUND;
    float height_in_meters = height * METERS_IN_INCH;

    float bmi = weight_in_kg / (height_in_meters * height_in_meters);

    std::string status;
    if (bmi < 18.5)
    {
        status = "Underweight";
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        status = "Normal";
    }
    else if (bmi >= 25 && bmi < 30)
    {
        status = "Overweight";
    }
    else if (bmi >= 30)
    {
        status = "Obese";
    }

    return status;
}

int main()
{
    q1_checks();
    q2_checks();
    q3_checks();
    q4_checks();
    // am_q4_checks();

    return 0;
}