
#include <string>
#include<cstring>
#include <iostream>
#include <iomanip>

using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;


	
	// max returns the largest item in data
	//

	template<typename T>
	double simplifyNum(T num, int dec_places) {

		\

		int Num_Of_Digits = num_of_digits(num);
		return double(num)/ pow(10, Num_Of_Digits - dec_places);
	}
	
	template<typename T> //gets num of digits;
	int num_of_digits( T  base) {

	

		int Num_Of_Digits = 0;

		for (int i = 0; base-1 >= 0; ++i) {
			base /= 10;
			Num_Of_Digits++;
		}


		return Num_Of_Digits;
	}



	template<typename T>
	T max(const T* data, int n) {

		T max = data[0];

		for (int i = 0; i < n; ++i) {

			if (data[i] > max) {

				max = data[i];

			}

		}

		return max;

	}


	// min returns the smallest item in data

	template<typename T>
	T min(const T* data, int n) {

		T min = data[0];

		for (int i = 0; i < n; ++i) {

			if (data[i] < min) {

				min = data[i];

			}

		}

		return min;

	}

        
	// sum returns the sum of n items in data
	//    
   
	template<typename T>
	T sum(const T* data, int n) {

		T sum = 0;

		for (int i = 0; i < n; ++i) {

			sum += data[i];

		}
		//std::cout << "SUM: " << sum<<endl;
		//std::cout << "N: " << n << endl << endl;
		return sum;

	}


	template<typename T>
	double average(const T* data, int n) {

	
		double avg = double(sum(data, n)) / double(n);

		//std::cout << "AVG: " << avg << endl;
		//std::cout << "N: " << n << endl << endl;

		return avg;

	}


	template<typename T>
	bool read(std::istream & input, T * data, int n)
	{
		

		

		for (int i = 0; i < n; ++i) {

			input.get(); // gets delimter
			input >> data[i];
			
		}

		return input.bad() ? false : true;

	}


	template<typename T>
	void display(const char * name, const T * data, int n){

		

		std::cout << std::setw(20) << std::right << name; // display name

		for (int i = 0; i < n; ++i) {

			
			std::cout << std::setw(15) << std::right << data[i];

		}

		cout << endl; 
		


	}


	
	
	// average returns the average of n items in data
	//

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	// display inserts n items of data into std::cout
	//


	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {

		
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);


	
	}

