/**********************************************************
* Name: Tai-Juan Rennie
* Student ID:
* Seneca email: trennie1@gmail.com
* Date of Completion: 5/31/2018
**********************************************************/


#include <iostream>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* FamilyName, const char* GivenName, int sin) { //set values for data members of CRA_Account classes


		if (sin >= min_sin && sin <= max_sin) { //check if sin is valid


			//When sim is valid set all values to requested values
			m_SIN = sin;

			for (int i = 0; i < max_name_length; ++i) { 
					
				m_FamilyName[i] = FamilyName[i];
				m_GivenName[i] = GivenName[i];

			}
	
			
		}
		else { //if sim is invalid set CRA_ACCOUNT to empty state (m_SIN = 0);


			m_SIN = 0;

		}


	}

	bool CRA_Account::isEmpty() const {

		bool isEmpty = true;

		if (m_SIN != 0) {
			isEmpty = false;
		}

		return isEmpty;

	}

	void CRA_Account::display() const{

		if (m_SIN == 0) { //if CRA_Account is in empty state then print
			cout << "Account object is empty!" << endl;
		}
		else{ //else if it isnt print data
		
			cout << "Family Name: " << m_FamilyName << endl  << "Given Name : " << m_GivenName << endl << "CRA Account: " << m_SIN << endl;


		}
	}

	CRA_Account::CRA_Account(){ //sets CRA_Account object to empty state on intialization 
		m_SIN = 0;
	}












}