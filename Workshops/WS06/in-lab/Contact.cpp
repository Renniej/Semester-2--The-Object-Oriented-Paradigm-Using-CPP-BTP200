#include <cstring>
#include <iostream> //used for debugging
#include "Contact.h"



using namespace std;


namespace sict {


	Contact::Contact() {

		mContact_Name[0] = '\0'; //if mContact_Name[0] is \0 then object is in empty state
		mPhone_Nums = nullptr;
		mNumOfPhoneNums = 0;

	}

	Contact::Contact(const char & name, const int & Phone_Nums, int NumOfPhoneNums)
	{
		bool EmptyState = false;
		
		// 1 or 2(Can't be 0) + 3(Can't start with 0) + 7(Can't start with 0)
		// Max length = 12, Min length = 11


		if (!name || strlen(name) > 20) {
			cout << "HELLO";
		}


	}





}