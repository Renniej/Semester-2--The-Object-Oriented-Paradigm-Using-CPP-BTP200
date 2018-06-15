/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

/**********************************************************
* Name:  Tai-Juan Rennie
* Student ID: 101359172	
* Seneca email: Trennie1 
* Date of Completion: 5/30/2018
**********************************************************/ 


// TODO: include the necessary headers

#include <iostream>
#include <cstdio>
#include "Kingdom.h"

using namespace std;




// TODO: the sict namespace

namespace sict {

// TODO:definition for display(...) 
	void display(const Kingdom &kingdom) {  //display population

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;

	}

	void display(const Kingdom *kingdom, int num_array) {  //display total population of all kingdoms

		int sum = 0;

		cout << "------------------------------" << endl << "Kingdoms of SICT" << endl << "------------------------------" << endl;

		for (int i = 0; i < num_array; ++i) { //Calculate sum 

			sum += kingdom[i].m_population; // sum = sum + kingdom[i]
			cout << i+1 << ". " <<kingdom[i].m_name << ", population " << kingdom[i].m_population << endl; //Print kingdom name & population
		}

		cout << "------------------------------" << endl;



		cout << "Total population of SICT: " << sum << endl;  //print total population of all kingdoms combined

	}

}

   
