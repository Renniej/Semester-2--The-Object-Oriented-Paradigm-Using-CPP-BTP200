#include <cstring>
#include "Product.h"

namespace AMA {

	void Product::Deallocate() {

		if (strlen(m_PName) > 1) {

			delete[] m_PName;
		}
		else {
			delete m_PName;
		}
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


	Product::Product(char type = 'N') { //Sets type of object
		m_Type = type;
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


	bool Product::isEmpty() const {
		return (m_Type == 'N');
	}

	double Product::total_cost() const{ //returns quantity * (cost or price) depending on if the product is taxable

		return taxed() ? cost() * quantity() : price() * quantity();

	}

	Product::Product(const char * sku, const char * pname, const char* desc, int current_inv = 0, bool taxable = true, double price = 0, int needed_inv = 0) {
		//Assumes all parameters are within valid constraints

		//Copy over sku, pname and description
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

	Product::~Product() {
		Deallocate();
	}


}