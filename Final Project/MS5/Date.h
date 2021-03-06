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
#ifndef AMA_DATE_H
#define AMA_DATE_H


#include <string>
#include <iostream>

using namespace std;



namespace AMA {
	#define NO_ERROR    0  
	#define CIN_FAILED  1  
	#define YEAR_ERROR  2  
	#define MON_ERROR   3  
	#define DAY_ERROR   4 


	const int min_year = 2000;
	const int max_year = 2030;

			class Date {



				int m_year;
				int m_month;
				int m_day;

				int m_comparator;
				int m_error_state;


				int mdays(int year, int month)const;
				
				
				void SetToEmpty();
				void SetComparator();


				void SetDate(int year, int month, int day, int Error);
				int CheckInput(int year, int month, int day) const;

			

				void errCode(int errorCode);
			public:
				
				Date();
				Date(int year, int month, int day);

				
				bool bad() const;


				int errCode() const;
				std::istream& read(std::istream& istr);
				std::ostream& write(std::ostream& ostr) const;

				bool operator==(const Date& rhs) const;
				bool operator!=(const Date& rhs) const;
				bool operator<(const Date& rhs) const;
				bool operator>(const Date& rhs) const;
				bool operator<=(const Date& rhs) const;
				bool operator>=(const Date& rhs) const;
				




			};

			std::ostream& operator<<(std::ostream& ostr, const Date& date);
			std::istream& operator>>(std::istream& istr,  Date& date);



		}





#endif