// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace AMA {

	Date::Date() {
		SetToEmpty();
		errCode(0);
	}


	Date::Date(int year, int month, int day) {

		int Error_Code;

		if (m_year > min_year && m_year < max_year) {
			if (month >= 1 && month <= 12) {

				if (day >= 1 && day <= mdays(month, year)) {

					Error_Code = 0; //No errors were found in paraemeters
				}
				else {
					Error_Code = 4; //Day value is invalid
				}

			}
			else {
				Error_Code = 3; //Month is invalid
			}




		}
		else {
			Error_Code = 2; //Year is invalid
		}



		if (Error_Code == 0) { //if date parameters are valid then set them to date object
			m_year = year;
			m_month = month;
			m_day = day;
			errCode(Error_Code);
			SetComparator();
		}
		else { // else set date object to safe empty state and specificy the error
			SetToEmpty();
			errCode(Error_Code);
		}


	}



	int Date::mdays(int mon, int year)const {// number of days in month mon_ and year year_
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::SetToEmpty() { //sets date object to empty state
		m_year = 0;
		m_month = 0;
		m_day = 0;
		SetComparator(); // sets m_comparator to 0

	}


	int Date::SetComparator() { //self-explaintory
		m_comparator = m_year * 372 + m_month * 13 + m_day;
	}


	void Date::errCode(int errorCode) { //sets error code of 
		m_error_state = errorCode;
	}
	
	int Date::errCode() const { //Displays error code
		return m_error_state;
	}

	bool Date::bad() const {

		bool bad_Date = false;

		if (m_error_state != 0) {
			bad_Date = true;
		}

		return bad_Date;
	}








}