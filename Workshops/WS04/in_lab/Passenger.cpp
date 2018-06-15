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
	}



	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* dest) {

		if ( (name && dest)   &&      ( strcmp(name, "") && strcmp(dest, "") )     ) { //check if name & dest are not null

		
			for (int i = 0; i < 32; ++i) { //Intialize passenger to values sent to it
				m_PName[i] = name[i];
				m_PDest[i] = dest[i];
			}
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
			cout << m_PName << " - " << m_PDest << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}


	}

		

	}


  

    

 
