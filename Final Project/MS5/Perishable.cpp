#include "Perishable.h"


namespace AMA {


	Perishable::Perishable(): Product('P'){
	}

	std::fstream & Perishable::store(std::fstream & file, bool newLine) const
	{

		Product::store(file, false);
		file << ',' << m_Expiry_Date;
		
		if (newLine == true) {
			file << '\n';
		}


		return file;

	}

	std::fstream & Perishable::load(std::fstream & file)
	{
		

		Product::load(file);
		m_Expiry_Date.read(file);  //issues might be caused here
		file.get();

		return file;

	}

	std::ostream & Perishable::write(std::ostream & os, bool linear) const
	{
		Product::write(os, linear);

		if (linear == true) {
			os << '|' << m_Expiry_Date;
		}
		else {
			os << endl << "Expiry date: " << m_Expiry_Date;
		}

		return os;
	}

	std::istream & Perishable::read(std::istream & is)
	{
		
		Date tmp;

		Product::read(is);

		if (is.fail() == false) {

			cout << "Expiry date (YYYY / MM / DD): ";

			cin >> tmp; //store istream to Date object


			if (tmp.bad()) {
				
				switch (tmp.errCode()) {

					case NO_ERROR:
						cout << "NO ERROR FOUND, DELETE THIS BEFORE SUBMISSION" << endl;
						break;
					case CIN_FAILED:
						message("Invalid Date Entry");
						break;
					case YEAR_ERROR:
						message("Invalid Year in Date Entry");
						break;
					case MON_ERROR:
						message("Invalid Month in Date Entry");
						break;
					case DAY_ERROR:
						message("Invalid Day in Date Entry");
						break;
				}

			}
			else {
				
				m_Expiry_Date = tmp; //may cause errors
			}
			


		}

		return is;


	}

	const Date & Perishable::expiry() const
	{
		
		return m_Expiry_Date;
	}













}