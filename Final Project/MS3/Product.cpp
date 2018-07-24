#include <cstring>
#include <string>
#include <iostream>
#include "Product.h"



using namespace std;
namespace AMA {

	void Product::Deallocate() {

		if (strlen(m_PName) > 1) {

			delete[] m_PName;
		}
		else {
			delete m_PName;
		}

		m_PName = nullptr;
	}


	//---Procteded functions
	void Product::name(const char* name) {  //Changes name of object

		if (m_PName != nullptr) {  //if m_PName is alreadt allocating memory then deallocate it
			Deallocate();
		}

		//Allocate new memory for name change then copy name over
		m_PName = nullptr;
		m_PName = new char[strlen(name) + 1]; 
		strcpy(m_PName, name);


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

		return taxed() ? price()* ((double)TAX_RATE / 100.00) : price(); //Sends approriate cost depending on if product is taxable

	}

	bool Product::isClear() const {

		return m_Error.isClear();

	}


	const char * Product::unit() const {
		return m_Desc;
	}


	Product::Product(char type = 'N') { //Sets object to empty state + sets the type of product
		m_Type = type;
		m_PName = new char[5];

		strcpy(m_PName, "NULL");
		strcpy(m_SKU, "0000");
		strcpy(m_Desc, "Empty State");
		m_Current_Inv = -999;
		m_Needed_Inv = -999;
		m_Price = -999;
		m_Taxable = false;

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

	Product::Product(const char * sku, const char * pname, const char* desc, int current_inv = 0, bool taxable = true, double price = 0, int needed_inv = 0) {
		//Assumes all parameters are within valid constraints

		//Copy over sku, pname and description
		m_Type = 'N';
		strcpy(m_SKU, sku);
		name(pname);
		strcpy(m_Desc, desc);


		m_Current_Inv = current_inv;
		m_Needed_Inv = needed_inv;
		m_Taxable = taxable;
		m_Price = price;
		
	
	}

	Product::Product(const Product& orgProduct) { //Copy properties of orginal product to a new seperate product
		
		
		*this = orgProduct;

	}

	Product::~Product() { //Destructor that deallocates dynamically allocated name
		Deallocate();
	}

	Product& Product::operator=(const Product& parent) {

		
		
		name(parent.name());
		strcpy(m_SKU, parent.sku());
		strcpy(m_Desc, parent.unit());

		m_Current_Inv = parent.quantity();
		m_Needed_Inv = parent.qtyNeeded();
		m_Taxable = parent.taxed();
		m_Price = price();

		return *this;

	}

	std::fstream & Product::store(std::fstream & file, bool newLine = true) const
	{
		
		if (file.is_open()) {

			for (int i = 0; i < 8; ++i) {

				switch (i) {

				case 0:
					file << m_Type << ",";
					break;

				case 1:
					file << sku() << ",";
					break;
				case 2:
					file << unit() << ",";
					break;
				case 3:
					file << name() << ",";
					break;

				case 4:
					file << qtyNeeded() << ",";
					break;
				case 5:
					file << quantity() << ",";
					break;
				case 6:
					file << price() << ",";
					break;
				case 7:
					file << taxed() ? "True" : "False";
					break;
				}

			}

			if (newLine == true) {
				file << endl;
			}
		}

		else {
			cout << "STORE FUNCTION ERROR: FILE IS NOT OPEN" << endl;
		}
		return file;


	}



	std::fstream& Product::load(std::fstream& file) {

		string Name;
		string Type;
		string SKU;
		string Desc;
		string Cur_Inv;
		string Needed_Inv;
		string Price;
		string Taxable;

		if (file.is_open()) {

			for (int i = 0; i < 8; ++i) {  //Grab data stored in each coloum of record

				switch (i) {

				case 0:
					std::getline(file, Type, ',');
					break;
				case 1:
					std::getline(file, SKU, ',');
					break;
				case 2:
					std::getline(file, Desc, ',');
					break;
				case 3:
					std::getline(file, Name, ',');
					break;

				case 4:
					std::getline(file, Needed_Inv, ',');
					break;
				case 5:
					std::getline(file, Cur_Inv, ',');
					break;
				case 6:
					std::getline(file, Price, ',');
					break;
				case 7:
					std::getline(file, Taxable, ',');
					break;
				}

			}


			//Copy data to current Product oject

			//.c_str() convers strings to const char * 's
			name(Name.c_str());  //Sends String "Name" as Const Char * to Name operator
			m_Type = Type[0];

			strcpy(m_SKU, SKU.c_str());
			strcpy(m_Desc, Desc.c_str());

			m_Current_Inv = stoi(Cur_Inv);  //stoi converts string to int
			m_Needed_Inv = stoi(Needed_Inv);

			m_Price = stof(Price); //stof converts string to float(double)

			m_Taxable = (Taxable == "True" ? true : false);

		}
		else {
			cout << "LOAD FUNCTION ERROR: FILE IS NOT OPEN" << endl;
		}
		

		return file;
	}

	std::ostream & Product::write(std::ostream & os, bool linear) const
	{
		

		if (linear == true) {  //I dont think we meet width requirements, look back on guide

			for (int i = 0; i < 6; ++i) {  

				switch (i) {

				case 0:
					os << m_SKU << '|';
					break;
				case 1:
					os << m_PName << '|';
					break;
				case 2:
					os << cost() << '|';
					break;
				case 3:
					os << quantity() << '|';
					break;

				case 4:
					os << unit() << '|';
					break;
				case 5:
					os << qtyNeeded() << '|';
					break;
				}

			}


		}
		else {

			for (int i = 0; i < 5; ++i) {  

				switch (i) {

				case 0:
					os << "Sku: " << m_SKU << '|' << endl;
					break;
				case 1:
					os << "Name: " << *m_PName << '|' << endl;
					break;
				case 2:
					os << "Price: " << taxed() ? cost() : price(); 
					os << '|' << endl;
					break;
				case 3:
					os << "Quantity on hand: " << quantity() << '|' << endl;
					break;

				case 4:
					os << "Quantity needed: " << qtyNeeded() << '|' << endl;
					break;
				}

			}


		}
		

		return os;

	}

	std::istream& Product::read(std::istream & is)
	{


		char Taxable;
		bool ErrorFound = false;
		
		Product tmp;


		for (int i = 0; i < 7 && !is.fail(); ++i) {

			switch (i) {

				case 0:
					is >> tmp.m_SKU;
					break;

				case 1:
					is >> tmp.m_PName;
					break;

				case 2:
					is >> tmp.m_Desc;
					break;

				case 3:
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
					is >> tmp.m_Price;

					if (tmp.m_Price < 0) {
						is.setstate(std::ios::failbit);
						ErrorFound = true;
						m_Error.message("Invalid Price Entry");
					}

					break;

				case 5:
					is >> tmp.m_Current_Inv;

					if (tmp.m_Current_Inv < 0) {
						is.setstate(std::ios::failbit);
						ErrorFound = true;
						m_Error.message("Invalid Quantity Entry");
					}

					break;

				case 6:
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

		return (sku() == SKU);

	}

	bool Product::operator>(const char * SKU) const
	{
		return (sku() > SKU);
	}

	bool Product::operator>(const Product & prod) const 
	{
		
		return (name() > prod.name());

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
	}

	std::istream & operator>>(std::istream & is,  Product & prod)
	{
		prod.read(is);
	}

	double operator+=(double & price, const Product & prod)
	{
		
		price += prod.total_cost();
		return price;

	}

	

}