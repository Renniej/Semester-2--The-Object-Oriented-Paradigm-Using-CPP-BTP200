#include <cstring>
#include <string>
#include <iostream>
#include "Product.h"



using namespace std;
namespace AMA {



	//---Procteded functions
	void Product::name(const char* Pname) {  //Changes name of object


	

		//Allocate new memory for name change then copy name over
		
				delete[] m_PName;
			
		if (Pname != nullptr) {
			m_PName = new char[strlen(Pname) + 1];
			strcpy(m_PName, Pname);
		}
	

	}

	void Product::message(const char* error_msg) {
		m_Error.message(error_msg);
	}

	const char* Product::name() const { //returns name
		return m_PName;
	}

	const char *Product::sku() const{ //returns SKU
		return m_SKU;
	}

	bool Product::taxed() const {  //returns whether or not product is taxable
		return m_Taxable;
	}

	double Product::price() const {
		return m_Price;
	}

	double Product::cost() const {  //return total price of one product (including tax)

		return taxed() ?  ( price()* ((double)TAX_RATE / 100.00) ) + price() : price(); //Sends approriate cost depending on if product is taxable

	}

	bool Product::isClear() const {

		return m_Error.isClear();

	}


	const char * Product::unit() const {
		return m_Unit;
	}


	Product::Product(char type) { //Sets object to empty state + sets the type of product
		m_Type = type;
		m_PName = nullptr;

	

	}

	void Product::quantity(int amount) { //sets inventory on hand amount
		m_Current_Inv = amount;
	}

	int Product::quantity() const { //returns quantity on hand
		return m_Current_Inv;
	}

	int Product::qtyNeeded() const {

		return m_Needed_Inv;

	}


	bool Product::isEmpty() const {  //check if object is in empty state
		return (m_Price == -999);
	}

	double Product::total_cost() const{ //returns quantity * (cost or price) depending on if the product is taxable

		return taxed() ? cost() * quantity() : price() * quantity();

	}

	Product::Product(const char * sku, const char * pname, const char* desc, int current_inv , bool taxable , double price, int needed_inv ) {
		//Assumes all parameters are within valid constraints

		//Copy over sku, pname and description
		m_Type = 'N';
		strcpy(m_SKU, sku);
		m_PName = nullptr;
		name(pname);
		strcpy(m_Unit, desc);


		m_Current_Inv = current_inv;
		m_Needed_Inv = needed_inv;
		m_Taxable = taxable;
		m_Price = price;
		
	
	}

	Product::Product(const Product& orgProduct) { //Copy properties of orginal product to a new seperate product
		
		
		*this = orgProduct;

	}

	Product::~Product() { //Destructor that deallocates dynamically allocated name
		delete[] m_PName;
		m_PName = nullptr;
	}

	Product& Product::operator=(const Product& parent) {

		

		if (this != &parent) {

			name(parent.name());

			strcpy(m_SKU, parent.sku());
			strcpy(m_Unit, parent.unit());

			m_Error.message(parent.m_Error.message());

			m_Current_Inv = parent.quantity();
			m_Needed_Inv = parent.qtyNeeded();
			m_Taxable = parent.taxed();
			m_Price = parent.price();

			return *this;
		}
	}

	std::fstream & Product::store(std::fstream & file, bool newLine) const
	{
		
		if (file.is_open()) {

					file << m_Type << ","
		
					 << sku() << ","
		
					 << unit() << ","
			
					 << *m_PName << ","

					<< m_Error.message() << ","
		
					 << qtyNeeded() << ","

					 << quantity() << ","
			
					 << price() << ","
	
					 << taxed() ? "True" : "False";
			
		}

			

			if (newLine == true) {
				file << endl;
			}
		

		
		return file;


	}



	std::fstream& Product::load(std::fstream& file) {

		
		string Name;
		string Type;
		string SKU;
		string Unit;
		string Cur_Inv;
		string Needed_Inv;
		string Price;
		string Taxable;
		string errMsg;

		if (file.is_open()) {

		
					std::getline(file, Type, ',');

					std::getline(file, SKU, ',');
		
					std::getline(file, Unit, ',');
			
					std::getline(file, Name, ',');
				

					std::getline(file, errMsg, ',');
		
					std::getline(file, Needed_Inv, ',');
		
					std::getline(file, Cur_Inv, ',');
		
					std::getline(file, Price, ',');
			
					std::getline(file, Taxable, ',');
					

					//Copy data to current Product oject

					//.c_str() convers strings to const char * 's
					name(Name.c_str());  //Sends String "Name" as Const Char * to Name operator
					m_Type = Type[0];

					strcpy(m_SKU, SKU.c_str());
					strcpy(m_Unit, Unit.c_str());

					m_Error.message(errMsg.c_str());
					m_Current_Inv = stoi(Cur_Inv);  //stoi converts string to int
					m_Needed_Inv = stoi(Needed_Inv);

					m_Price = stof(Price); //stof converts string to float(double)

					m_Taxable = (Taxable == "True" ? true : false);
				

			}



		return file;
	}

	std::ostream & Product::write(std::ostream & os, bool linear) const
	{
		

		if (linear == true) {  //I dont think we meet width requirements, look back on guide

					os.width(max_sku_length);
					os << m_SKU << '|';
			
					os.width(20);
					os << m_PName << '|';
			
					os.width(7);
					os << cost() << '|';
			

					os.width(4);
					os << quantity() << '|';


					os.width(10);
					os << unit() << '|';
			
					os.width(4);
					os << qtyNeeded() << '|';
				
				

			}

		else {


					os << "Sku: " << m_SKU << '|' << endl;
		
					os << "Name: " << *m_PName << '|' << endl;
			
					os << "Price: " << taxed() ? cost() : price(); 
					os << '|' << endl;
			
					os << "Quantity on hand: " << quantity() << '|' << endl;
				
					os << "Quantity needed: " << qtyNeeded() << '|' << endl;
				
				

			}


		
		

		return os;

	}

	std::istream& Product::read(std::istream & is)
	{


		char Taxable;
		bool ErrorFound = false;
		string Name;

		Product tmp;


		for (int i = 0; i < 7 && ErrorFound == false; ++i) {

			switch (i) {

				case 0:
					cout << "Sku: ";
					is >> tmp.m_SKU;
					break;

				case 1:
					cout << "Name (no spaces): ";
					is >> Name;
					tmp.name(Name.c_str());
					break;

				case 2:
					cout << "Unit: ";
					is >> tmp.m_Unit;
					break;

				case 3:
					cout << "Taxed? (y/n): ";
					is >> Taxable;
					if (Taxable == 'Y' || Taxable == 'y') {
						tmp.m_Taxable = true;
					}
					else if (Taxable == 'N' || Taxable == 'n') {
						tmp.m_Taxable = false;
					}
					else {
						is.setstate(std::ios::failbit);
						ErrorFound = true;
						m_Error.message("Only(Y)es or (N)o are acceptable");
					}
					break;

				case 4:
					cout << "Price: ";
					is >> tmp.m_Price;

					if (tmp.m_Price < 0) {
						is.setstate(std::ios::failbit);
						ErrorFound = true;
						m_Error.message("Invalid Price Entry");
					}

					break;

				case 5:
					cout << "Quantity on hand: ";
					is >> tmp.m_Current_Inv;

					if (tmp.m_Current_Inv < 0) {
						is.setstate(std::ios::failbit);
						ErrorFound = true;
						m_Error.message("Invalid Quantity Entry");
					}

					break;

				case 6:
					cout << "Quantity needed: ";
					is >> tmp.m_Needed_Inv;
					
					if (tmp.m_Needed_Inv < 0) {
						is.setstate(std::ios::failbit);
						ErrorFound = true;
						m_Error.message("Invalid Quantity Needed Entry");
					}

					break;


			}


		}


		if (!ErrorFound) { //if error is not found then copy tmp Product object to current
			*this = tmp;
			
		}


		return is;
	}


	bool Product::operator==(const char * SKU) const {

		return (strcmp(sku(), SKU) == 0);

	}

	bool Product::operator>(const char * SKU) const
	{
		return  (strcmp(sku(), SKU )> 0);
	}

	bool Product::operator>(const Product & prod) const 
	{
		
		return (strcmp(name(), prod.name()) > 0);

	}

	int Product::operator+=(int amount) {

		if (amount > 0) {
			m_Current_Inv += amount;
		}

		return quantity();
	}


	




	std::ostream & operator<<(std::ostream & os, const Product & prod)
	{
		prod.write(os, true);
		return os;
	}

	std::istream & operator>>(std::istream & is,  Product & prod)
	{
		prod.read(is);
		return is;
	}

	double operator+=(double & price, const Product & prod)
	{
		
		price += prod.total_cost();
		return price;

	}

	

}