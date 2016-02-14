/*
 * Class Date, implementation.
 * The next() function in this implementation cannot handle leap years.
 */

#include "date.h"

#include <ctime>   /* for C routines time and localtime */
#include <iostream>
#include <utility> /* for swap */

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if (day == daysPerMonth[month - 1]) {
		day = 1;
		if (month == 12) {
			month = 1;
			year++;
		} else {
			month++;
		}
	} else {
		day++;
	}
}

ostream& operator<<(ostream& os, const Date& d) {
	os << d.getYear() << "-" << d.getMonth() << "-" << d.getDay();
	return os;
}

istream& operator>>(istream& is, Date& date) {
	int year;
	int month;
	int day;

	is >> year;
	if (is.get() != '-') {is.setstate(ios_base::failbit); return is;}
	is >> month;
	if (is.get() != '-') {is.setstate(ios_base::failbit); return is;}
	is >> day;

	// Kolla om strängen e slut.
	
	date = Date(year, month, day);
	return is;
}