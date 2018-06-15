// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace

using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		//safe empty state variables
		m_numer = 0;
		m_denom = 0;

	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numer, int denom) {
		
		if (numer >= 0 && denom > 0) { //check if parameters are valid
			
			//Set values from parameter to object variables
			m_numer = numer;
			m_denom = denom;
		} 
		else { //else set object to empty sate
			m_numer = 0;
			m_denom = 0;
		}

	}

	// TODO: implement the max query

	int Fraction::max() const {

		int biggest;

		if (m_numer > m_denom){

			biggest = m_numer;


			}
		else {
			biggest = m_denom;
		}

		return biggest;


	}


	// TODO: implement the min query
	int Fraction::min() const {

		int lowest;

		if (m_numer < m_denom) {

			lowest = m_numer;

		}
		else {
			lowest = m_denom;
		}

		return lowest;


	}

	// gcd returns the greatest common divisor of num and denom
	//


	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier

	void Fraction::reduce() { //divide numerator & denomator by return value of gcd() function

		int divisor = gcd();
		
		m_numer /= divisor;
		m_denom /= divisor;
		


	}

	// TODO: implement the display query
	
	void Fraction::display() const {

		if (!isEmpty()) {

			if (m_denom == 1) {
				cout << m_numer << endl;
			}
			else {

				cout << m_numer << "/" << m_denom << endl;
			}

		}
		else {
			cout << "no fraction stored" << endl;
		}


	}


	// TODO: implement the isEmpty query

	bool Fraction::isEmpty() const {

		bool Empty = false;

		if (m_denom == 0) {
			Empty = true;
		}
		
		return Empty;

	}

	// TODO: implement the + operator

	Fraction Fraction::operator+(const Fraction& rhs) const {


		//Because safe empty state is 0/0, I dont need a an if statement to check.
		// I may have an if statement for optimization purposes but im not sure if it'd make a big difference.
		Fraction New;

		
		New.m_numer = (m_numer * rhs.m_denom) + (m_denom * rhs.m_numer);
		New.m_denom = m_denom * m_numer;

		New.reduce();

		return New;

	}

}