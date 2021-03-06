#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include <fstream>
#include "ErrorState.h"
#include "iProduct.h"


	namespace AMA {

	#define max_sku_length 7
	#define max_unit_length 10
	#define max_name_length 75
	#define TAX_RATE 13





		class Product : public iProduct {

			char * m_PName;
			char m_Type;
			char m_SKU[max_sku_length];
			char m_Unit[max_name_length];
			int m_Current_Inv;
			int m_Needed_Inv;
			double m_Price;
			bool m_Taxable;
			ErrorState m_Error;

		protected:

			void name(const char* name);
			void message(const char* error_msg);

			const char *name() const;
			const char *sku() const;
			const char *unit() const;
			bool taxed() const;
			double price() const;
			double cost() const;
			bool isClear() const; //this isclear is meant for the ErrorState object
			
		
		public:
			Product(char type = 'N');
			Product(const char * sku, const char * pname, const char* desc, int current_inv = 0, bool taxable = true, double price = 0, int needed_inv = 0);
			Product( const Product& orgProduct);
			~Product();

			void quantity(int amount);
			

			bool isEmpty() const;
			double total_cost() const;
			int quantity() const;
			int qtyNeeded() const;

			Product& operator=(const Product& parent);
			bool operator==(const char*SKU) const;
			bool operator>(const char *SKU) const;
			bool operator>(const iProduct& prod) const;
			int operator+=(int amount);

			std::fstream& store(std::fstream& file, bool newLine = true) const;
			std::fstream& load(std::fstream& file);
			std::ostream& write(std::ostream& os, bool linear) const;
			std::istream& read(std::istream& is);
		};

		std::ostream& operator<<(std::ostream& os, const iProduct& prod);
		std::istream& operator>>(std::istream& is,  iProduct& prod);
		double operator+=(double& price, const iProduct& prod);


	}



#endif
