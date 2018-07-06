#ifndef _SICT_CONTACT_H
#define _SICT_CONTACT_H



namespace sict {

	class Contact {

		char mContact_Name[20];
		int *mPhone_Nums;
		int mNumOfPhoneNums;

	public:

		Contact();
		Contact(const char &name, const int &Phone_Nums, int NumOfPhoneNums);
		~Contact();




	};





}







#endif