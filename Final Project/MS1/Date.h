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

#include <iostream>

using namespace std;

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;

  class Date {



	  int m_year;
	  int m_month;
	  int m_day;

	  int m_comparator;
	  int m_error_state;


     int mdays(int year, int month)const;
	 void errCode(int errorCode);
	 void SetToEmpty();
	 int SetComparator();

  public:
	  Date();
	  Date(int year, int month, int day);

	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr);

	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;

	


 
  };

  void operator<<(std::istream& istr);
  void operator>>(std::istream& istr);



}
#endif