#include "Account.h"



namespace sict {

	Account::Account(double balance) {  //Constructor that accepts a intial balance value

		if (balance > 0) { //if balance value set is postive then set object's balance to it.
			m_Balance = balance;
		}
		else { //else intialize m_Balance to 0.
			m_Balance = 0.0;
		}

	}

	bool Account::credit(double credit) { //Add money to balance

		int Success = false;

		if (credit > 0) { //if credit is a postive value add it to m_Balance
			m_Balance += credit;
			Success = true;
		}

		return Success;

	}

	bool Account::debit(double debit) { //deducts money from balance
		int Success = false;

		if (debit > 0) { //if debit is a postive value subtract it to m_Balance
			m_Balance -= debit;
			Success = true;
		}

		return Success;
	}

	double Account::balance() const{ //Display balance of Account object
		return m_Balance;
	}




}
