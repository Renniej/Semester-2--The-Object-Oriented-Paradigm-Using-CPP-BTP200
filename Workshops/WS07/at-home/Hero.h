#ifndef _SICT_HERO_H
#define _SICT_HERO_H




#include <iostream>



using namespace std;

const int MAX_ROUNDS = 100;

namespace sict {

	class Hero {
	
		char mName[40];
		int mHealth;
		int mAtk;
		

	protected:
		void SetHeroProperties(const char *Name, int Health, int Attack);
		
		


	public:

		Hero();
		Hero(const char *Name, int  Health, int Attack);
		Hero(const Hero& org);
		void operator-= (int Attack);

		const char* getName() const;

		bool isEmpty() const;
		void SetToEmpty();

		bool isAlive() const;

		int attackStrength() const;
		friend ostream& operator<<(ostream& os, const Hero& hero);
	


	};

	

	const Hero& HeroBattle(const Hero& first, const Hero& second);
	const Hero& operator*(const Hero& first, const Hero& second);
}


#endif // !_SICT_HERO_H
