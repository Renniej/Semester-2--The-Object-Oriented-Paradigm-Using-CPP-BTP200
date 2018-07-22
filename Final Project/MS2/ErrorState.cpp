
#include <cstring>
#include <iostream>
#include "ErrorState.h"

using namespace std;

namespace AMA {

	
	ErrorState::ErrorState(const char* errorMessage) { //Overloaded constructor

		if (errorMessage != nullptr) {

			m_Error_Message = new char[strlen(errorMessage) + 1];
			strcpy(m_Error_Message, errorMessage);

		}
		else {
			m_Error_Message = nullptr;
		}

	}



	ErrorState::~ErrorState() { //deallocate dynamically allocated memory

		clear();

	}

	void ErrorState::clear() { //deallocate dynamically allocated memory

		
		delete[] m_Error_Message;
		m_Error_Message = nullptr;


	}


	bool ErrorState::isClear() const { // Checks if Error object is in empty state

		return (m_Error_Message == nullptr);

	}


	void ErrorState::message(const char * str) { //Sets error message



		

			if (!isClear()) { //if there is a previously stored message in errorstate

				clear();

			}


			m_Error_Message = new char[strlen(str) + 1];

			strcpy(m_Error_Message, str);




	}

	const char * ErrorState::message() const {  //Displays error message of error object

		return m_Error_Message;

	}




	std::ostream& operator<<(std::ostream& os, const ErrorState &Error_State) {

		if (!Error_State.isClear()) {

			os << Error_State.message();

		}

		return os;

	}




}

