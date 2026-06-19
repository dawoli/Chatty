#include <iostream>
using namespace std;
 class Date
{
public:
	void Inti(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date()
	{
	}
	Date(int year, int month, int day)
	{
			_year = year;
			_month = month;
			_day = day;
	}
 
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
 
private:
	int _year;
	int _month;
	int _day;
};
 
 
int main()
{
	
	Date d1(2023,11,11);
	Date d2(2023, 11, 12);
	d1.Print();
	d2.Print();
	return 0;
}
