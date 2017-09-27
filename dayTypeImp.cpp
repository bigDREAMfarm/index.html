// dayTypeImp Implementation File
#include <iostream>
#include <string>
#include <iomanip>

#include "dayType.h"

using namespace std;

const string daysOfWeek[] = { "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };


void dayType::set(string d, int i)
{
	day = d;
	incrementDay = i;
}

void dayType::print() const
{
	cout << "Day: " << day << "Loc: " << dayLoc <<  endl;
	cout << "Previous Day: " << prevDay << "P:" << daysOfWeek[5] << endl;
	cout << "Next Day: " << nextDay << endl;
	cout << "Day in " << incrementDay << " days: " << calcDay << endl;
}

void dayType::setDay(string d)
{
	day = d;

}

string dayType::getDay() const
{
	return day;
}

void dayType::setLocation(int l)
{
	dayLoc = l;
}

int dayType::getLocation() const
{
	return dayLoc;
}
void dayType::setPrevDay(int dayLoc)
{
	int prevLoc = dayLoc;
	if (dayLoc = 0)
	{
		prevLoc = 6;
		prevDay = daysOfWeek[5];
	}
	else
	{
		prevLoc--;
		prevDay = daysOfWeek[5];
	}
}

string dayType::getPrevDay() const
{
	return prevDay;
}

void dayType::setNextDay(int dayLoc)
{
	{
		int nextLoc = dayLoc;
		if (dayLoc = 6)
		{
			nextLoc = 0;
			nextDay = daysOfWeek[nextLoc];
		}
		else
		{
			nextLoc++;
			nextDay = daysOfWeek[nextLoc];
		}
	}
}
string dayType::getNextDay() const
{
	return nextDay;
}

void dayType::setIncrementDay(int i)
{
	incrementDay = i;
}
int dayType::getIncrementDay()const
{
	return incrementDay;
}

void dayType::setCalcDay(int incrementDay)
{
	for (incrementDay; incrementDay < 7; incrementDay--)
	{
		calcDay = daysOfWeek[incrementDay];
	}
}
string dayType::getCalcDay() const
{
	return calcDay;
}

dayType::dayType(string s, int l, int inc)
{
	day = s;
	dayLoc = l;
	incrementDay = inc;
}