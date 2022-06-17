// example: class constructor
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle (int,int);
    int area () {return (width*height);}
};

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

class Employee
{
    int id;
    std::string name;
    float hourly_pay;
    int hours_worked;

    public:
        Employee (int, std::string, float);
        std::string name() { return name; };
        int id() { return id; };
};

Employee::Employee (int emp_id, std::string emp_name, float emp_hourly_pay)
{
    id = emp_id;
    name = emp_name;
    hourly_pay = emp_hourly_pay;
}