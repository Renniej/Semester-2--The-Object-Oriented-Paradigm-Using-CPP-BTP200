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
		int m_year;
		int m_month;
		int m_day;

	public:

		Passenger();
		Passenger(const char* name, const char* dest); 
		Passenger(const char* name, const char* dest, const int year, const int month, const int day);
		const char* name() const;

		bool canTravelWith(const Passenger&) const;

		bool isEmpty() const;
		void display() const;


	};



}
   

#endif