#include "SavingsAccount.h" 
#include "ChequingAccount.h"
namespace sict {

	// define interest rate
	//
	#define INTEREST_RATE 0.05   //interest rate is %5
	#define TRANSACTION_FEE 0.50
	#define MONTHLY_FEE 2.00

	// TODO: Allocator function
	//
	
	
	 iAccount* CreateAccount(const char* type, double start_balance) {

		iAccount * ACCT = nullptr;

		if (type[0] == 's' || type[0] == 'S') {
			ACCT = new SavingsAccount(start_balance, INTEREST_RATE);
		}
		else if  (type[0] == 'C' || type[0] == 'C') {
			ACCT = new ChequingAccount(start_balance, TRANSACTION_FEE, MONTHLY_FEE);
		}


		return ACCT;

	}







}
