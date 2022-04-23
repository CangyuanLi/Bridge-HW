#include<iostream>
using namespace std;

int main() 
{
	const int HOURS_IN_A_DAY = 24;
	const int MINUTES_IN_A_HOUR = 60; 

	int john_days, john_hours, john_minutes;

	cout << "Please enter the number of days John has worked: ";
	cin >> john_days;
	cout << "Please enter the number of hours John has worked: ";
	cin >> john_hours; 
	cout << "Please enter the number of minutes John has worked: "; 
	cin >> john_minutes; 	
	cout << endl; 

	int bill_days, bill_hours, bill_minutes;

	cout << "Please enter the number of days Bill has worked: ";
	cin >> bill_days;
	cout << "Please enter the number of hours Bill has worked: "; 
	cin >> bill_hours;
	cout << "Please enter the number of minutes Bill has worked: "; 
	cin >> bill_minutes;
	cout << endl;

	int total_minutes = (bill_minutes + john_minutes) % MINUTES_IN_A_HOUR; 
	int hours_round_up = (bill_minutes + john_minutes) / MINUTES_IN_A_HOUR;

	int total_hours = (hours_round_up + bill_hours + john_hours) % HOURS_IN_A_DAY; 
	int days_round_up = (hours_round_up + bill_hours + john_hours) / HOURS_IN_A_DAY;

	int total_days = days_round_up + bill_days + john_days; 

	cout << "The total time both of them worked together is: " 
		<< total_days << " days, " 
		<< total_hours << " hours and " 
		<< total_minutes << " minutes." << endl; 

	return 0; 
}