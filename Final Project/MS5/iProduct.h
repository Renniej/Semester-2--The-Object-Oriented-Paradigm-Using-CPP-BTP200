#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H

#include <iostream>
#include <fstream>

using namespace std;
namespace AMA {

	class iProduct {
		 
	public:

		virtual ~iProduct() 
			{}

		virtual std::fstream& store(std::fstream& file, bool newline = true) const = 0;

		virtual std::fstream& load(std::fstream& file) = 0;

		virtual std::ostream& write(std::ostream& os, bool linear)const = 0;

		virtual std::istream& read(std::istream& is) = 0;

		virtual bool operator==(const char* unit) const = 0;

		virtual double total_cost() const = 0;

		virtual const char* name() const = 0;

		virtual void quantity(int num) = 0;

		virtual int qtyNeeded() const = 0;


		virtual int quantity() const = 0;

		virtual int operator+=(int num) = 0;


		virtual bool operator >(const iProduct&) const = 0;
	
		

	};

	std::ostream& operator<<(std::ostream& os, const iProduct& prod);
	std::istream& operator>>(std::istream& is, iProduct& prod);
	double operator+=(double& price, const iProduct& prod); 

	iProduct * CreateProduct(); 
	iProduct* CreatePerishable(); 




}



#endif
