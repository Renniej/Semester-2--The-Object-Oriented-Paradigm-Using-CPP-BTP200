// TODO: add file header comments here
/**********************************************************
 * Name: Tai-Juan Rennie
 * Student ID: 101359172	
 * Seneca email: trennie1
 * Date of Completion: 6/8/2018
 **********************************************************/
// TODO: add header file guard here

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H




// TODO: declare your namespace here
namespace sict {

	// TODO: define the Passenger class here
	class Passenger {

		char m_PName[32];
		char m_PDest[32];

	public:

		Passenger();
		Passenger(const char* name, const char* dest); 
		bool isEmpty() const;
		void display() const;


	};



}
   

#endif