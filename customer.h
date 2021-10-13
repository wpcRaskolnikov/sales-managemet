#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
#include<list>
using std::string;
using std::list;
const int CUSTOMER_CODE_SIZE = 14;
const int CUSTOMER_NAME_SIZE = 20;
const int CUSTOMER_GENDER_SIZE = 8;
const int CUSTOMER_PHONE_SIZE = 15;
const int CUSTOMER_ADDRESS_SIZE = 50;
const int CUSTOMER_DATE_SIZE = 12;


class Customer
{
private:
	char name[CUSTOMER_NAME_SIZE];
	char phone[CUSTOMER_PHONE_SIZE];
	char address[CUSTOMER_ADDRESS_SIZE];
public:
	Customer();
	bool setName(string);
	bool setPhone(string);
	bool setAddress(string);
	bool isName(string);
	friend std::istream& operator>>(std::istream& is, Customer& t);
	friend std::ostream& operator<<(std::ostream& os, const Customer& t);
	void static headerShow();
};

bool addCustomer(const string);
bool searchCustomer(const string);
bool alterCustomer(const string);
bool deleteCustomer(const string);
bool traverseCustomer(const string);
bool alterCustomerFromList(list<Customer>::iterator, string, int);

#endif
