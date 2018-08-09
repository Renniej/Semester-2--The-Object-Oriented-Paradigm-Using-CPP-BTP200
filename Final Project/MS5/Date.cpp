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



using namespace std;


namespace AMA {






	Date::Date()
	{
		
			SetToEmpty();
			errCode(0);
		
	}

	Date::Date(int year, int month, int day) {
		 
		//cout << "Overloaded Constructor Called(" << year << " " << month <<  " " << day << ")" << endl;


		int Error_Code = CheckInput(year, month, day);


		if (Error_Code == 0) { //if date parameters are valid then set them to date object

			//cout << "Overloaded Constructor parameters are VALID" << endl;
			SetDate(year, month, day, Error_Code);
		}

		else { // else set date object to safe empty state and specificy the error

			//cout << "Overloaded Constructor parameters are INVALID" << endl;

			SetToEmpty();
			errCode(Error_Code);
		}


	}

	void Date::SetDate(int year, int month, int day, int Error_Code) {
		m_year = year;
		m_month = month;
		m_day = day;
		errCode(Error_Code);
		SetComparator();
	}

	int Date::CheckInput(int year, int month, int day) const
	{

		//cout << "CHECKINPUT(" << year << " " << month << " " << day << ")" << endl;
		//cout << "MAX YEAR VALUE: " << max_year << "    " << "MIN YEAR VALUE: " << min_year << endl;
		int Error_Code;

		if (year >= min_year && year <= max_year) {
		

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

		//cout << "CheckInput Returns ERROR_CODE: " << Error_Code << endl;

		return Error_Code;
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


	void Date::SetComparator() { //self-explaintory
		m_comparator = m_year * 372 + m_month * 13 + m_day;
		//cout << "M_COMPARATOR = " << m_comparator << endl;
	}


	void Date::errCode(int errorCode) { //sets error code of 
		m_error_state = errorCode;
	}

	int Date::errCode() const { //Displays error code
		return m_error_state;
	}

	bool Date::bad() const {  //checks if date object is in an error_state

		bool bad_Date = false;

		if (m_error_state != 0) {
			bad_Date = true;
		}

		return bad_Date;
	}




	bool Date::operator==(const Date& rhs) const {

		bool AreEqual = false;

		if (rhs.m_comparator == m_comparator) {
			AreEqual = true;
		}

		return AreEqual;
	}

	bool Date::operator!=(const Date& rhs) const {

		return (rhs.m_comparator != m_comparator);
	}


	bool Date::operator<(const Date& rhs) const {

		bool isSmaller = false;

		if (m_comparator < rhs.m_comparator) {
			isSmaller = true;
		}

		return isSmaller;


	}

	bool Date::operator>(const Date& rhs) const {


		bool isGreater = false;

		if (m_comparator > rhs.m_comparator) {
			isGreater = true;
		}

		return isGreater;

	}

	bool Date::operator>=(const Date& rhs) const {


		bool isGreater = false;

		if (m_comparator >= rhs.m_comparator) {
			isGreater = true;
		}

		return isGreater;

	}



	bool Date::operator<=(const Date& rhs) const {


		return (m_comparator <= rhs.m_comparator);

	}

	std::ostream& operator<<(std::ostream& ostr, const Date& date) {

		date.write(ostr);
		return ostr;

	}

	std::istream& operator>>(std::istream& istr, Date& date) {

		return date.read(istr);

	}



	std::istream& Date::read(std::istream& istr) {

		char ignore; //ignores slashes and dashes

		int year;
		int month;
		int day;
		

		istr >> year >> ignore >> month >> ignore >> day;

		int Error_Code = CheckInput(year, month, day);

		if (istr.fail()) {

			errCode(1);	//Set object's error code to CIN_FAILED
		}

		else if ( Error_Code == 0) { //if input is valid then Set Date object

			SetDate(year, month, day, 0);

		}
		else {
			errCode(Error_Code);
		}
		

		return istr;


	}

	std::ostream& Date::write(std::ostream& ostr) const {

		string day;
		string month;

		if (m_comparator != 0) {

			day = to_string(m_day);
			month = to_string(m_month);

			if (m_day < 10) {
				day.insert(0,"0");
			}

			if (m_month < 10) {
				month.insert(0, "0");
			}


			
				ostr << m_year << "/" << month << "/" << day;
			
		}
		else {
			ostr << "0/00/00";
		}

		return ostr;

	}



}

