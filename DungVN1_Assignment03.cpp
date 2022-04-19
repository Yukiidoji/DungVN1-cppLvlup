#include <iostream>
using namespace std;

bool isLeapYear(int year);
int numberOfMonth(int month, int year);
void previousDay(int& day, int& month, int& year);
void nextDay(int& day, int& month, int& year);
int main()
{
	int day, month, year;
	cout << " CALENDAR";
	cout << "\n\n Input dd/mm/yyyy\n";
	cout << " day: ";
	cin >> day;
	cout << " month: ";
	cin >> month;
	cout << " year:";
	cin >> year;
	while (year < 0 || month < 0 || month>12 || day<0 || day>numberOfMonth(month, year)) {
		cout << "\ninvalid , try to retype\n";
		cout << " day: ";
		cin >> day;
		cout << " month: ";
		cin >> month;
		cout << " year:";
		cin >> year;
	}

	while (true) {
			cout << "\n================MENU================\n";
			cout << "1. Find the number of month\n";
			cout << "2. Show next day (dd/mm/yyyy)\n";
			cout << "3. Show previous next day (dd/mm/yyyy)\n";
			int n;
			cout << "Select your option: ";
			cin >> n;
			switch (n)
			{
			case 1:
				cout << "The number of month: " << numberOfMonth(month, year);
				break;
			case 2:
				nextDay(day, month, year);
				cout << "Tomorrow: " << day << " / " << month << " / " << year << endl;
				break;
			case 3:
				previousDay(day, month, year);
				cout << "Yesterday: " << day << " / " << month << " / " << year << endl;
				break;
			default:
				cout << "Your choice is not valid!";
			}
		}
		return 0;
	}
	bool isLeapYear(int year) {
		if (year % 4 == 0 && year % 100 != 0)
			return true;
		if (year % 400 == 0)
			return true;
		return false;
	}

	int numberOfMonth(int month, int year) {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			if (isLeapYear(year))
				return 29;
			else
				return 28;
		}
	}
	void previousDay(int& day, int& month, int& year)
	{
		day--;
		if (day == 0)
		{
			month--;
			if (month == 0)
			{
				month = 12;
				year--;
			}

			day = numberOfMonth(month, year);
		}
	}
	void nextDay(int& day, int& month, int& year)
	{
		day++;
		if (day > numberOfMonth(month, year))
		{
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
	}
