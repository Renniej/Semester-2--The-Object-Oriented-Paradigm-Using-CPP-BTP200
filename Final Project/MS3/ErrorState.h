#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H



namespace AMA {

	class ErrorState {

		char * m_Error_Message;

	public:

		explicit ErrorState(const char* errorMessage = nullptr);


		ErrorState(const ErrorState& em) = delete; //stops copy constructor from being called.
		ErrorState& operator=(const ErrorState& em) = delete;

		virtual ~ErrorState();

		void clear();
		bool isClear() const;
		void message(const char * str);
		const char* message() const;



	};

	std::ostream& operator<<(std::ostream& os, const ErrorState &Error_State);

}




#endif
