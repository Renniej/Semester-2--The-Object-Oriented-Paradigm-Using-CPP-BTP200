#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sict {


	SavingsAccount::SavingsAccount(double intial, double interest) : Account(intial) { //sends intial balance value to Account constructor & intializes m_Interest 

		if (interest > 0) { //if interest is postive then set m_interset to parameter.
			m_Interest = interest;
		}
		else { //else set object to safe empty state
			m_Interest = 0.0;
		}

	}

	void SavingsAccount::monthEnd() { //Add earned interest amount to account
		double earned = balance() * m_Interest;
		credit(earned);
	}

	void SavingsAccount::display(std::ostream & os) const { //display saving account info

		
			os << std::fixed << std::setprecision(2) << "Account type: Savings" << endl << "Balance: $" << balance() << endl << "Interest Rate (%): " << 100 * m_Interest << endl;

	}

}