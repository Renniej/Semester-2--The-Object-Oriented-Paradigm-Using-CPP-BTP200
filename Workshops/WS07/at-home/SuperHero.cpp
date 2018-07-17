
#include "Hero.h"
#include "SuperHero.h"


namespace sict {

	SuperHero::SuperHero() {

		SetToEmpty();

	}



	SuperHero::SuperHero(const char* Name, int Health, int Attack, int SuperBonus, int SuperDefend) {
		
		Hero::SetHeroProperties(Name, Health, Attack);


		if (Hero::isEmpty()) {  //If Hero is empty state then set SuperHero specific attributes to 0;
			mSuperBonus = 0;
			mSuperDefend = 0;
		}
		else { // else set superhero attributes to values sent by parameters. 
			mSuperBonus = SuperBonus;
			mSuperDefend = SuperDefend;
		}

	}

	void SuperHero::SetToEmpty() {

		Hero::SetToEmpty();

		mSuperBonus = 0;
        mSuperDefend = 0;


	}

	int SuperHero::attackStrength() const {

		return Hero::attackStrength() + mSuperBonus;

	}

	int SuperHero::defend() const{
		
		return mSuperDefend;

	}

	
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {


		
		return HeroBattle(first, second);

	

	}


}