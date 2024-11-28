/*
Name : Bahar Parsaeian
Email: bparsaeian@myseneca.ca
Student ID: 118314210
Date: 2024-11-27

Academic Integrity:
I declare that this submission is the result of my own work
and I only copied the code that my professor provided to complete my workshops and assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/
#include "Utilities.h"
#include "Station.h"
#include "CustomerOrder.h"

#include <iostream>
#include <vector>
#include <iomanip>

namespace seneca
{
	// necessary because its static
	size_t CustomerOrder::m_widthField{};


	//default constructor
	CustomerOrder::CustomerOrder() = default; 


	/*
	
	a custom 1-argument constructor that takes a reference 
	to an unmodifiable string. This constructor uses a local
	Utilities object to extract the tokens from the string 
	and populate the current instance. 
	The fields in the string are (separated by a delimiter):
	Customer Name
	Order Name
	the list of items making up the order (at least one item)
	*/
	CustomerOrder::CustomerOrder(const std::string& record)
	{
		bool more = true;
		
		Utilities util;
		
		std::vector<std::string> tokens;

		size_t pos = 0u;

		while (more){
			tokens.push_back(util.extractToken(record, pos, more));
		}

		if (m_widthField < util.getFieldWidth()){
			m_widthField = util.getFieldWidth();
		}

		m_name = tokens[0];
		m_product = tokens[1];

		if (tokens.size() > 2){
			m_cntItem = tokens.size() - 2;
			m_lstItem = new Item * [m_cntItem];

			for (size_t i = 0; i < m_cntItem; i++){
			
				m_lstItem[i] = new Item(tokens[i + 2]);
			}
		}
		else{
		
			m_cntItem = 0;
			
			m_lstItem = nullptr;
		}
	}


	// This operator should "promise" that it doesn't throw exceptions.
	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw "Error";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			for (size_t i = 0; i < m_cntItem; i++){
		
				delete m_lstItem[i];
		
			}
		
			delete[] m_lstItem;
			
			// move everything
			m_lstItem = src.m_lstItem;

			m_cntItem = src.m_cntItem;

			m_product = src.m_product;

			m_name = src.m_name;
			

			// set everything empty
			src.m_lstItem = nullptr;

			src.m_cntItem = 0u;

			src.m_product = "";

			src.m_name = "";
		
			
			
		}

		return *this;

	}


	//destructor for the ** is to delete the [i] and delete the enitre thing with [] too
	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++){
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////
	// bool functions fro seeting if item and orders are filled: 


	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool result = true;

		for (size_t i = 0; i < m_cntItem; i++){

			if (m_lstItem[i]->m_itemName == itemName){

				if (!m_lstItem[i]->m_isFilled){

					result = false;

				} } }

        return result;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool result = true;

		for (size_t i = 0; i < m_cntItem && result; i++){
		
			if (m_lstItem[i]->m_isFilled == false){
			
				result = false;
			
			} }
	
		return result;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	//functions that display messages: 
	
	/*
	example use: 
	std::cout << "CustomerOrders::fillItem()" << std::endl; // Test #6
	tmp2.fillItem(theStations[0], std::cout);
	tmp2.fillItem(theStations[i], std::cout);


	*/
	
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool done = false;

		for (size_t i = 0; i < m_cntItem && !done; i++){
		
			if ( !m_lstItem[i]->m_isFilled && m_lstItem[i]->m_itemName == station.getItemName()){
				if (station.getQuantity()){
				
					m_lstItem[i]->m_isFilled = true;
					
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
				}
				else{
					os << "    Unable to Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
				}
				done = true;
			}
		}
	}
	/*  
	
	example use: 

	station.display(std::cout, false);
	station.display(std::cout, true);

	
	*/
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;

		for (size_t i = 0; i < m_cntItem; i++){
			
			os << "[" 
			   << std::setfill('0') 
			   << std::setw(6) 
			   << m_lstItem[i]->m_serialNumber 
			   << "] " 
			   << std::left 
			   << std::setfill(' ') 
			   << std::setw(m_widthField) 
			   << m_lstItem[i]->m_itemName 
			   << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") 
			   << std::endl;
	
		}
	}
}