/**********************************************************
* Name: Tai-Juan Rennie
* Student ID: 101359172
* Seneca email: trennie1
* Date of Completion: 7/7/2018
**********************************************************/

#ifndef _SICT_CONTACT_H
#define _SICT_CONTACT_H



namespace sict {

	class Contact {

		char mContact_Name[20];
		long long *mPhone_Nums;
		int mNumOfPhoneNums;

		void NewPhoneNum(long long Phone_Num); //made due to code duplication
	public:

		Contact();
		Contact(const char *name, const long long *Phone_Nums, int NumOfPhoneNums);

		~Contact();
		bool isEmpty() const;
		void display() const;
		void setToEmpty();



	};





}







#endif