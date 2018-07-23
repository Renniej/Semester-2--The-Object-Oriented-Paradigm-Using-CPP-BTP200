
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {

		double m_Trans_Fee;
		double m_Monthly_Fee;


		public:
			// TODO: constructor initializes account balance and transaction fee

			ChequingAccount(double intial_bal, double trans_fee, double monthly_fee);

			// TODDO: credit adds +ve amount to the balance

			bool credit(double amount);

			// TODO: debit subtracts a +ve amount from the balance

			bool debit(double amount);

			// TODO: month end

			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream& os) const;

	};
}
#endif
