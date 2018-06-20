#include <string>
#include "Contact.h"


using namespace std;

namespace sict {


	Contact::Contact() {
		 m_name[0] = '\0';
		 m_PhoneNum = nullptr;
	}


	Contact::Contact(const char * name, int &Phone, int NumOfDigits) {

		bool ValidInputs = false;

		if (strlen(name) <= 19   && (NumOfDigits == 12 || NumOfDigits == 11) ) {

			if (NumOfDigits == 11) {
				Phone[2] = 2;
			}


		}

		else {
			m_name[0] = '\0';
			m_PhoneNum = nullptr;
		}
	
	
	}



}