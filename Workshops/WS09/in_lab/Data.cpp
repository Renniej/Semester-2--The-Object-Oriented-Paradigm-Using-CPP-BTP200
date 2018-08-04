#include <cmath>
#include "Data.h"

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//




	



	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {



		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"


		if (population != nullptr && year != nullptr) {

			
			int Population_Change = population[0] - population[n - 1];

			if (Population_Change < 0) {
				Population_Change *= -1;
			}
			


		

			//Get num of digit
		

			
			


			std::cout << "Population change from " << year[0] << " to " <<  year[n-1] << " is " << std::setprecision(2) << std::fixed << (simplifyNum(Population_Change,  2)) << " million" << std::endl;

		}



		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

	

		
		std::cout << "Violent Crime trend is " << (violentCrimeRate[0] < violentCrimeRate[n-1]? "up" : "down") << std::endl;


		// Q3 print the GTA number accurate to 0 decimal places


		std::cout << "There are " << std::setprecision(2) << std::fixed << (simplifyNum(average(grandTheftAuto, n), 1)) << " million Grand Theft Auto incidents on average a year" << std::endl;


		// Q4. Print the min and max violentCrime rates

		//Find max and min crime rates
	

		std::cout << "The Minimum Violent Crime rate was " << int(min(violentCrimeRate, n)) << std::endl;
		std::cout << "The Maximum Violent Crime rate was "<< int(max(violentCrimeRate, n))<< std::endl;


	}



}