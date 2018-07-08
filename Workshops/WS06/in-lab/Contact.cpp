/**********************************************************
* Name: Tai-Juan Rennie
* Student ID: 101359172
* Seneca email: trennie1
* Date of Completion: 7/7/2018
**********************************************************/


#include <cstring>
#include <string>
#include <iostream> //used for debugging
#include "Contact.h"



using namespace std;


namespace sict {

	void Contact::setToEmpty() { //Function that sets object to empty state (Made to avoid code duplication)

		mContact_Name[0] = '\0'; //if mContact_Name[0] is \0 then object is in empty state
		mPhone_Nums = nullptr;
		mNumOfPhoneNums = 0;
	}

	Contact::Contact() {//Default constructor that sets object to empty state

		 
		setToEmpty();

	}


	void Contact::NewPhoneNum(long long Phone_Num) { // Function adds new phone number to Contact Object (made to avoid code duplicatio)n

		



		if (mNumOfPhoneNums != 0) {
			long long * tempPtr = new long long[mNumOfPhoneNums+1]; //Create a temporary phone_nums pointer that's bigger by 1 spot then previous mNumPhoneNums


			//Copy data from current mPhone_Nums to temporary ptr
			for (int j = 0; j < mNumOfPhoneNums; ++j) {

				tempPtr[j] = mPhone_Nums[j];
				
			}



			tempPtr[mNumOfPhoneNums] = Phone_Num; //Add new phone number to tmp ptr

		
			//Depending on if mPhone_Nums is an array or single long long, deallocate it's memory
			if (mNumOfPhoneNums == 1) {
				delete mPhone_Nums;
			}
			else {
				delete[] mPhone_Nums;
			}

			
			mPhone_Nums = tempPtr; //Set mPhone_Nums pointer to tempPtr's address

			mNumOfPhoneNums++; //Process of enlarging array is complete and we can add +1 to number of phone number counter variable

			tempPtr = nullptr;
		}

		else { //If mPhone_Nums isn't intialized yet then 
		
			mPhone_Nums = new long long; //reserve some memory real estate
			*mPhone_Nums = Phone_Num; //set the value in the memory estate Phone_Num

			mNumOfPhoneNums++; //Dictate that there is now a value in Phone_Num by adding 1 to counter

		}
	}

	Contact::Contact(const char *name, const long long *Phone_Nums, int NumOfPhoneNums) //Overloaded function for filling all 
	{

		mPhone_Nums = nullptr;
		mNumOfPhoneNums = 0;


		string strNum;
		if (name != nullptr && name[0] != '\0' ) { //Check to make sure all fields are valid

	
			

				strncpy(mContact_Name, name, 20); //Set name of contact object
				mContact_Name[19] = '\0'; //set null termintor to the 20th index


				
				//Check for valid Phone numbers in phone_nums array and add them to the Contact Object
				for (int i = 0; i < NumOfPhoneNums; ++i) {

					


					strNum = to_string(Phone_Nums[i]); // string used for checking formatting

					// 1 or 2(Can't start with 0) + 3(Can't start with 0) + 7(Can't start with 0)
					// Phone number length is either 11 or 12 depending on country code

					
					if (strNum.length() == 11) {

						// NumLength = 11:  Indexes [0], [1] and [4] can't be 0 
						if (strNum[0] != '0' && strNum[1] != '0' && strNum[4] != '0') { //If phone number is doesn't have 0's in specified indexes then add number to object

							
							NewPhoneNum(Phone_Nums[i]);

						}


					}


					else if (strNum.length() == 12) { 
					

						// NumLength = 12: Indexes[0], [1], [2] and [5] can't be 0
						if (strNum[0] != '0' && strNum[1] != '0' && strNum[2] != '0' && strNum[5] != '0') {//If phone number is doesn't have 0's in specified indexes then add number to object

							NewPhoneNum(Phone_Nums[i]);

						}


					}


				

			    }



		}
		else { //If parameters are invalid then object is set to empty state
			setToEmpty();
		}

	

	}

	Contact::~Contact() {

		
		//Deallocates dynamic memory (mPhone_Nums)

		if (mNumOfPhoneNums != 1) {
			delete[] mPhone_Nums;
		}
		else {
			delete mPhone_Nums;
		}

		
		

	}

	bool Contact::isEmpty() const //Check if object is in empty state
	{
		bool EmptyState = false;

		if (mContact_Name[0] == '\0') { // if null terminator is in index 0 of name then contact is in empty state
			EmptyState = true;
		}

		return EmptyState;
	}

	void Contact::display() const { //Display Contact Objects phone numbers

		string strNum;

		if (isEmpty()) { //If object is in empty state then print empty state
			cout << "Empty Contact!" << endl;
		}
		else {
			
			cout << mContact_Name << endl;

			//Print all phone numbers found in object
			for (int i = 0; i < mNumOfPhoneNums; ++i) {


				
				strNum = to_string(mPhone_Nums[i]); //strNum = "XXXXXXXXXXXX" or "XXXXXXXXXXX"  (11 OR 12 characters)
				
				//formatting
				//Length dictates how to get correct format

				if (strNum.length() == 11) {
					
					//strNum =  (+X) XXX XXXXXXX
					strNum.insert(0, "(+");
					strNum.insert(3, ") ");
					strNum.insert(8, " ");

					
					

				}

				
				else if (strNum.length() == 12) {

					//strNum =  (+XX) XXX XXXXXXX
					strNum.insert(0, "(+");
					strNum.insert(4, ") ");
					strNum.insert(9, " ");
					
				}

				//Once number is formatted properly print it
				cout << strNum << endl;



				
			}


		}

	}

}