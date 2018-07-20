#ifndef ERRORSTATE_H
#define ERRORSTATE_H





class ErrorState {

	char *ptr;

public :

	explicit ErrorState(const char* errorMessage = nullptr);
	
	ErrorState(const ErrorState& em) = delete; //stops copy constructor from being called.
	ErrorState& operator=(const ErrorState& em) = delete;
	virutal ~ErrorState();
	
	void clear();
	bool isClear() const;
	void message(const char * str);
	const char* message() const;



};

std::ostream& operator<<(const char* message, std::ostream& os);



#endif
