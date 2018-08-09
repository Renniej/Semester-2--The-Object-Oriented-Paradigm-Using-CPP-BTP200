#ifndef _AMA_PERISHABLE_H
#define _AMA_PERISHABLE_H

#include "Product.h"
#include "Date.h"


namespace AMA {


	class Perishable : Product {

		Date m_Expiry_Date;

		Perishable();

		std::fstream& store(std::fstream& file, bool newLine = true) const;

		std::fstream& load(std::fstream& file);

		std::ostream& write(std::ostream& os, bool linear) const;

		std::istream & read(std::istream& is);

		const Date& expiry() const;
	};



}



#endif