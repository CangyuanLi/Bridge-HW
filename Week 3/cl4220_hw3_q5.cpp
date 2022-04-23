#include <iostream>
#include <string>

int main()
{
    const float KILOGRAMS_IN_POUND = 0.453592;
    const float METERS_IN_INCH = 0.0254; 

    float weight;
    std::cout << "Please enter weight (in pounds): ";
    std::cin >> weight;

    float height;
    std::cout << "Please enter height (in inches): ";
    std::cin >> height;

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

    std::cout << "The weight status is: " << status;

    return 0;
}
