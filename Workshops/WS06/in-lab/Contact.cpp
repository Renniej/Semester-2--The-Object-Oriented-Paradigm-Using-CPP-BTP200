#include <cstring>
#include <string>
#include <iostream> //used for debugging
#include "Contact.h"



using namespace std;


namespace sict {


	Contact::Contact() {

		cout << "DEFAULT CONSTRUCTOR CAUSED EMPTY STATE";
		mContact_Name[0] = '\0'; //if mContact_Name[0] is \0 then object is in empty state
		mPhone_Nums = nullptr;
		mNumOfPhoneNums = 0;

	}


	void Contact::NewPhoneNum(int Phone_Num) { //made to avoid code duplication

		cout << "ADDING NEW PHONE NUMBER";

		int * tempPtr = new int[mNumOfPhoneNums + 1];

		for (int j = 0; j < mNumOfPhoneNums; ++j) {

			tempPtr[j] = mPhone_Nums[j];

		}


		tempPtr[++mNumOfPhoneNums] = Phone_Num;

		delete[] mPhone_Nums;

		mPhone_Nums = tempPtr;

		delete[] tempPtr;
	}

	Contact::Contact(const char *name, const int *Phone_Nums, int NumOfPhoneNums)
	{
		bool EmptyState = false;



		string strNum;
		int arrIndex = 0;
		
		
		
	

		if (strlen(name) > 19 ) {
			cout << "OVERLOADED CONSTRUCTOR CAUSED EMPTY STATE";
			mContact_Name[0] = '\0'; //if mContact_Name[0] is \0 then object is in empty state
			mPhone_Nums = nullptr;
			mNumOfPhoneNums = 0;
		}
		else {

			strcpy(mContact_Name, name);
			mContact_Name[strlen(mContact_Name)] = '\0';


			cout << "STRING COPIED, CONTACT NAME IS NOW: " << mContact_Name << ", FROM INPUT:" << *name;

			for (int i = 0; i < NumOfPhoneNums; ++i) {

				// 1 or 2(Can't be 0) + 3(Can't start with 0) + 7(Can't start with 0)
				// Phone number length is either 11 or 12 depending on country code

				
				strNum = to_string(Phone_Nums[i]);
				
				
				// NumLength = 11:  Indexes [0], [1] and [4] can't be 0 
				if (strNum.length() == 11) {
					
					cout << "NUM IS 11 DIGITS";

					if (strNum[0] != '0' && strNum[1] != '0' && strNum[4] != '0') {

						cout << "NUM is valid FOUND AT: " << i << "with number: " << Phone_Nums[i];
						NewPhoneNum(Phone_Nums[i]);

					}


				}

				
				else if (strNum.length() == 12) {
					cout << "NUM IS 12 DIGITS";

					// NumLength = 12: Indexes[0], [1], [2] and [5] can't be 0
					if (strNum[0] != '0' && strNum[1] != '0' && strNum[2] != '0' && strNum[5] != '0') {
						
						cout << "NUM is valid FOUND AT: " << i << "with number: " << Phone_Nums[i];
						NewPhoneNum(Phone_Nums[i]);

					}


				}


			}

		}


		 
	


	}

	Contact::~Contact() {


		cout << "CONTACT GOING OUT OF SCOPE, DEALLOCATING mPhone_Nums";

		delete[] mPhone_Nums;
		mPhone_Nums = nullptr;

	}



}