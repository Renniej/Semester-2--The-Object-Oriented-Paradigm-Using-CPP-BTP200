/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef _SICT_KINGDOM_H
#define _SICT_KINGDOM_H



// TODO: sict namespace
namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {

		char m_name[33];
		int m_population;

	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom &kingdom);
	void display(const Kingdom *kingdom, int num_array);
}




#endif