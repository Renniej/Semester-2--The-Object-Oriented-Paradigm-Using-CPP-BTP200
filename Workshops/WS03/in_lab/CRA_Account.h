/**********************************************************
* Name: Tai-Juan Rennie
* Student ID:
* Seneca email: trennie1@gmail.com
* Date of Completion: 5/31/2018
**********************************************************/

#ifndef _CRA_ACCOUNT_H
#define _CRA_ACCOUNT_H


namespace sict {



	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;


	class CRA_Account {

		char m_FamilyName[max_name_length];
		char m_GivenName[max_name_length];
		int m_SIN;

	public:
		void set(const char* , const char* , int );
		bool isEmpty() const;
		void display() const;
		CRA_Account();
	};


}


#endif




