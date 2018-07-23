// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include <iomanip>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee

	ChequingAccount::ChequingAccount(double intial_bal, double trans_fee, double monthly_fee) : Account(intial_bal) { //Intializes Object's data members

		if (trans_fee > 0) { //if trans_fee is a postive value then intiate object's Trans fee with its value.
			m_Trans_Fee = trans_fee;
		}
		else { //else set object's Trans fee to 0.0;
			m_Trans_Fee = 0;
		}


		if (monthly_fee > 0) {// if monthly fee is a postive value then intiate object's monthly fee with its value.
			m_Monthly_Fee = monthly_fee;
		}
		else { //else set object's monthly fee to 0.0;
			m_Monthly_Fee = 0;
		}
	
	}


	// credit (add) an amount to the account balance and charge fee
	bool ChequingAccount::credit(double amount) {

		//cout << "1.ChequingAccount credit( " << amount << " ) Called" << endl;

		bool Success = false;

		if (Account::credit(amount) == true) { //if credit transaction was successful then deduct transaction fee

			//cout << "2.Account Credit call inside was successful, balance is now: $" << balance() << endl;
			Success = Account::debit(m_Trans_Fee);  //deducts transaction fee
			//cout << "3. TRANSACTION FEE WAS SUCCESSFUL( " << m_Trans_Fee << " ), balance is now: $" << balance() << endl;
		}


		//cout << "4.ChequingAccount credit( " << amount << " ) returned " << Success << endl;

		return Success;

	}





	// debit (subtract) an amount from the account balance and charge fee
	bool ChequingAccount::debit(double amount) {
		
		//cout << "1.ChequingAccount debit( " << amount << " ) Called" << endl;
		bool Success = false;

		if (Account::debit(amount) == true) { //if debit transaction was successful then deduct transaction fee

			//cout << "2.Account debit call inside was successful, balance is now: $" << balance() << endl;

			Success = Account::debit(m_Trans_Fee);  //deducts transaction fee

			//cout << "3. TRANSACTION FEE WAS SUCCESSFUL( " << m_Trans_Fee << " ), balance is now: $" << balance() << endl;

		}

		//cout << "4. ChequingAccount debit( " << amount << " ) returned" << Success << endl;

		return Success;

	}

	void ChequingAccount::monthEnd() {  //Deducts monthly fee from balance

		debit(m_Monthly_Fee);

	}

	void ChequingAccount::display(std::ostream& os) const {
		os << std::fixed << std::setprecision(2) << "Account type: Chequing" << endl << "Balance: $" << balance() << endl << "Per Transaction Fee: " << m_Trans_Fee << endl << "Monthly Fee: " << m_Monthly_Fee << endl;
	}






	// display inserts account information into ostream os
	//




}