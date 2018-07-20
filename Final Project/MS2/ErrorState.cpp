
#include <cstring>
#include <iostream>
#include "ErrorState.h"

using namespace std;

namespace AMA {

	
	ErrorState::ErrorState(const char* errorMessage) {

		if (errorMessage) {

			m_Error_Message = new char[strlen(errorMessage) + 1];
			strncpy(m_Error_Message, errorMessage, strlen(errorMessage) + 1);

		}
		else {
			m_Error_Message = nullptr;
		}

	}



	ErrorState::~ErrorState() { //deallocate dynamically allocated memory

		clear();

	}

	void ErrorState::clear() { //deallocate dynamically allocated memory

		if (m_Error_Message) {
			if (strlen(m_Error_Message) > 1) {

				delete[] m_Error_Message;
			}
			else {
				delete m_Error_Message;
			}
		}

		m_Error_Message = nullptr;

	}


	bool ErrorState::isClear() const {

		bool isClear = false;

		if (m_Error_Message) {
			isClear = true;
		}

		return isClear;

	}


	void ErrorState::message(const char * str) {



		if (str) {

			if (!isClear()) { //if there is a previously stored message in errorstate

				clear();

			}


			char * tmp = new char[strlen(str) + 1];

			strncpy(m_Error_Message, str, strlen(str) + 1);



		}

	}

	const char * ErrorState::message() const {

		const char * MessageExist = nullptr;

		if (m_Error_Message) {
			MessageExist = m_Error_Message;

		}


		return m_Error_Message;

	}




	std::ostream& operator<<(std::ostream& os, ErrorState &Error_State) {

		if (!Error_State.isClear()) {

			os << Error_State.message();


		}

		return os;

	}




}

