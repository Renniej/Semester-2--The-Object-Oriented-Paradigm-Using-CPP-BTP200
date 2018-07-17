
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

			//cout << endl << "Name: " << getName() << endl << "Health: " << Health << endl << "Attack: " << attackStrength() << endl << "SuperBonus: " << mSuperBonus << endl << "SuperDefend: " << mSuperDefend << endl;


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


	SuperHero::SuperHero(const SuperHero& org) {



		Hero::SetHeroProperties(org.getName(), org.getHealth(), org.Hero::attackStrength());
		mSuperBonus = org.mSuperBonus;
		mSuperDefend = org.mSuperDefend;




	}

	const SuperHero& SuperHeroBattle(const SuperHero& first, const SuperHero& second) {

		SuperHero cpy1(first);
		SuperHero cpy2(second);


		const SuperHero *winner = nullptr;
		winner = &first;

		int NumofRounds = 0;

		for (int i = 0; i < MAX_ROUNDS && NumofRounds == 0; ++i) {

			//cout << endl << "ROUND " << i << ":" << endl << cpy1.getName() << ": " << cpy1.getHealth() << endl << endl << cpy2.getName() << ": " << cpy2.getHealth() << endl;

			cpy1 -= cpy2.attackStrength() - cpy1.defend();
			cpy2 -= cpy1.attackStrength() - cpy2.defend();


			if (!cpy1.isAlive()) {
				winner = &second;

				NumofRounds = i + 1;

			}
			else if (!cpy2.isAlive()) {
				winner = &first;

				NumofRounds = i + 1;

			}


		}

		cout << "Super Fight! " << first << " vs " << second << " : Winner is " << *winner << " in " << NumofRounds << " rounds." << endl;


		return *winner;

	}


	
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {



		return SuperHeroBattle(first, second);
	

	}


}