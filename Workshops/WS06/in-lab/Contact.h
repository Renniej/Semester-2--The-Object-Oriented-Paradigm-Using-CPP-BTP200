#ifndef _SICT_CONTACT_H
#define _SICT_CONTACT_H



namespace sict {

	class Contact {

		char m_name[20];
		int * m_PhoneNum;
	public:
		Contact();
		Contact(const char * name, int &PhoneNum, int NumOfDigits);


	};

}

#endif