
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account{

		double m_Interest;
	
	public:
		
			// TODO: constructor initializes balance and interest rate
		SavingsAccount(double intial, double interest);

			// TODO: perform month end transactions
		void monthEnd();

			// TODO: display inserts the account information into an ostream			
		void display(std::ostream& os) const;
	};
}
#endif
