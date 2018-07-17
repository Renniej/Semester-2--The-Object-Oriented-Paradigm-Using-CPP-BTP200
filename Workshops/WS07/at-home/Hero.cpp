
#include <cstring>
#include "Hero.h"


namespace sict {

	 ostream& operator<<(ostream& os, const Hero& hero)  {

		 if (hero.isEmpty()) {

			 os << "No hero";
		 }
		 else {
			 os << hero.mName;
		 }

		 return os;

	}

	 const char* Hero::getName() const {
		 return mName;
	 }


	 const Hero& HeroBattle(const Hero& first, const Hero& second) {

		 Hero cpy1(first);
		 Hero cpy2(second);


		 const Hero *winner = nullptr;
		 winner = &first;

		 int NumofRounds = 0;

		 for (int i = 0; i < MAX_ROUNDS && NumofRounds == 0; ++i) {

			 cpy1 -= cpy2.attackStrength();
			 cpy2 -= cpy1.attackStrength();


			 if (!cpy1.isAlive()) {
				 winner = &second;

				 NumofRounds = i + 1;

			 }
			 else if (!cpy2.isAlive()) {
				 winner = &first;

				 NumofRounds = i + 1;

			 }


		 }

		 cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << *winner << " in " << NumofRounds << " rounds." << endl;


		 return *winner;

	 }


	 const Hero& operator*(const Hero& first, const Hero& second) {

		 return HeroBattle(first, second);

	 }

	void Hero::SetToEmpty() { // set an hero object to empty
		mName[0] = '\0';
		mHealth = 0;
		mAtk = 0;

	}

	bool  Hero::isEmpty() const{ //checks if an object is empty

		bool Empty = false;

		if (mName[0] == '\0') {

			Empty = true;
		}

		return Empty;
	}

	int Hero::getHealth() const {
		return mHealth;
	}

	bool Hero::isAlive() const { //Check if health is above 0

		bool Alive = true;

		if (mHealth <= 0) {
			Alive = false;
		}

		return Alive;

	}

	int Hero::attackStrength() const {

		return mAtk;

	}


	void Hero::operator-=(int Attack) {


		if (Attack > 0) {

			mHealth -= Attack;
		}

		if (mHealth < 0) {
			mHealth = 0;
		}

	}

	Hero::Hero(const Hero& org) {

		strcpy(mName, org.mName);
		mAtk = org.mAtk;
		mHealth = org.mHealth;
	}

	Hero::Hero() { //Default constructor sets hero object to empty state
		SetToEmpty();
	}

	void Hero::SetHeroProperties(const char *Name, int Health, int Attack){

		if (Name != nullptr && Name[0] != '\0' && Health > 0 && Attack > 0) {

			strncpy(mName, Name, 39);
			mName[40] = '\0';

			mHealth = Health;
			mAtk = Attack;
		}
		else {
			SetToEmpty();
		}

	}

	Hero::Hero(const char *Name, int Health, int Attack) { //overloaded hero structor

		SetHeroProperties(Name, Health, Attack);

	}


}


