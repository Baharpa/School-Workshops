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

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include "Station.h"

#include <vector>

#include <string>

#include <iostream>


namespace seneca
{
    class CustomerOrder {
    private:
      
        struct Item {    
            
            std::string m_itemName;
           
            size_t m_serialNumber{ 0 };
            
            bool m_isFilled{ false };

            Item(const std::string& src) : m_itemName(src) {}
        };

        std::string m_name;
        
        std::string m_product;
        
        size_t m_cntItem{ 0 };
        
        Item** m_lstItem{ nullptr };
        
        static size_t m_widthField;

    public:
      
        //default i jusr did = default; in the .cpp
        CustomerOrder() {};
        
        CustomerOrder(const std::string& record);
        
        CustomerOrder(const CustomerOrder& src);
        
        CustomerOrder& operator=(const CustomerOrder& src) = delete;
        
        // use noexcept in the instructions
        CustomerOrder(CustomerOrder&& src) noexcept;
        

        // use noexcept in the instructions
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;
        
        ~CustomerOrder();


        bool isOrderFilled() const;
        
        bool isItemFilled(const std::string& itemName) const;
        
        void fillItem(Station& station, std::ostream& os);
        
        void display(std::ostream& os) const;


    };
}


#endif 