/**********************************************************
* Name: Tai-Juan Rennie
* Student ID:
* Seneca email: trennie1@gmail.com
* Date of Completion: 6/15/2018
**********************************************************/


/// TODO: header file guard

#ifndef _SICT_FRACTION_H
#define _SICT_FRACTION_H





// TODO: create namespace
namespace sict{
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 

		int m_numer; //numerator 
		int m_denom; //demonator


		// TODO: declare private member functions



	public:

		// TODO: declare public member functions

		Fraction();

		Fraction(int numer, int denom);

		int max() const;
		int min() const;

		void reduce();
		int gcd() const;
		bool isEmpty() const;
		void display() const;

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;

		Fraction operator*(const Fraction& rhs) const;

		bool operator==(const Fraction& rhs) const;

		bool operator!=(const Fraction& rhs) const;

		Fraction& operator+=(const Fraction& rhs) ;

	};

		

	}

#endif