#ifndef _SICT_SUPERHERO_H
#define _SICT_SUPERHERO_H


#include "Hero.h"


namespace sict {

	class SuperHero : public Hero {

		int mSuperBonus;
		int mSuperDefend;
	

		void SetToEmpty();

	public:



		SuperHero();
		SuperHero(const char* Name, int Health, int Attack, int SuperAttack, int SuperDefend);
		
		int attackStrength() const;
		int defend() const;

		


		



	};
	
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}


#endif
