// dayType.h Specification File
#include <string>

using namespace std;

const int listLength = 7;

class dayType
{
public:
	void set(string, int);
	void print() const;

	void setLocation(int);
	int getLocation() const;

	void setDay(string);
	string getDay() const;

	void setPrevDay(int);
	string getPrevDay()const;

	void setNextDay(int);
	string getNextDay() const;

	void setIncrementDay(int);
	int getIncrementDay()const;

	void setCalcDay(int);
	string getCalcDay() const;

	dayType(string = "",int =0, int = 0);


private:

	string day;
	string nextDay;
	string prevDay;
	string calcDay;
	int incrementDay;
	string daysOfWeek[listLength];
	int dayLoc;

};