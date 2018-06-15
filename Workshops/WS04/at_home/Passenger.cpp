/**********************************************************
 * Name: Tai-Juan Rennie
 * Student ID: 101359172	
 * Seneca email: trennie1
 * Date of Completion: 6/8/2018
 **********************************************************/

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {


	// TODO: implement the default constructor here
	Passenger::Passenger() { //Intialize Passenger to empty state
		m_PName[0] = '0';
		m_PDest[0] = '0';
		m_year = 0;
		m_day = 0;
		m_month = 0;
	}





	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* dest) {

		if ( (name && dest)   &&      ( strcmp(name, "") && strcmp(dest, "") )     ) { //check if name & dest are not null

		
			for (int i = 0; i < 32; ++i) { //Intialize passenger to values sent to it
				m_PName[i] = name[i];
				m_PDest[i] = dest[i];
			}

			m_month = 7;
			m_day = 1;
			m_year = 2017;
		} 
		else {

			//can you call constructors within a constructor just like functions??????
			m_PName[0] = '0';
			m_PDest[0] = '0';
			m_year = 0;
			m_day = 0;
			m_month = 0;
		}



	}


	Passenger::Passenger(const char* name, const char* dest, const int year, const int month, const int day) {

		if (   (name && dest) &&   (strcmp(name, "")  &&  strcmp(dest, ""))  && (year == 2017 || year == 2018 || year == 2019 || year == 2020)  &&  (month >= 1 && month <= 12) && (day >= 1 && day <= 31)                 ) { //check if name & dest are not null


			for (int i = 0; i < 32; ++i) { //Intialize passenger to values sent to it
				m_PName[i] = name[i];
				m_PDest[i] = dest[i];
			}

			m_year = year;
			m_month = month;
			m_day = day;


		}

		else {
			m_PName[0] = '0';
		}


	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {

		
		return m_PName[0] == '0'; //if empty state return true else false.

	}




	// TODO: implement display query here
	void Passenger::display() const {

		
		if (!isEmpty()) {
			

			if (m_month < 10) {
				cout << m_PName << " - " << m_PDest << " on " << m_year << "/0" << m_month << "/" << m_day << endl;
			}
			else {
				cout << m_PName << " - " << m_PDest << " on " << m_year << "/" << m_month << "/" << m_day << endl;

			}
			
			}


		else {
			cout << "No passenger!" << endl;
		}


	}

	const char* Passenger::name() const {
		  
		//2 returns isn't good practice... adjust later

		if(!isEmpty()){

			return m_PName;

		}

		else {
			return "";
		}

	}

	bool Passenger::canTravelWith(const Passenger& p2) const {
		
		bool canTravel = false; //assume false till proven true

		if ( ( !strcmp(m_PDest, p2.m_PDest) ) && (m_year == p2.m_year) && (m_month == p2.m_month) && (m_day == p2.m_day)   ) {

			canTravel = true;

		}
	

		return canTravel;



	}

	}


  

    

 
