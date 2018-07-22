#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	#define INTEREST_RATE 0.05   //interest rate is %5


	// TODO: Allocator function
	//
	
	
	 iAccount* CreateAccount(const char* type, double start_balance) {

		iAccount * ACCT = nullptr;

		if (type[0] == 's' || type[0] == 'S') {
			ACCT = new SavingsAccount(start_balance, INTEREST_RATE);
		}


		return ACCT;

	}







}
