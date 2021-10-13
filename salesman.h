#ifndef SALESMAN_H
#define SALESMAN_H
#include<string>
#include<list>
using std::string;
using std::list;
const int SALESMAN_CODE_SIZE = 14;
const int SALESMAN_NAME_SIZE = 20;
const int SALESMAN_GENDER_SIZE = 8;
const int SALESMAN_PHONE_SIZE = 15;
const int SALESMAN_ADDRESS_SIZE = 50;
const int SALESMAN_DATE_SIZE = 12;

class Salesman
{
private:
	char code[SALESMAN_CODE_SIZE];
	char name[SALESMAN_NAME_SIZE];
	char gender[SALESMAN_GENDER_SIZE];
	char birthDate[SALESMAN_DATE_SIZE];
	char phone[SALESMAN_PHONE_SIZE];
	char address[SALESMAN_ADDRESS_SIZE];
	char employeeDate[SALESMAN_DATE_SIZE];
public:
	Salesman();
	bool setCode(string);
	bool setName(string);
	bool setGender(string);
	bool setBirthDate(string);
	bool setPhone(string);
	bool setAddress(string);
	bool setEmployeeDate(string);
	bool isName(string);
	friend std::istream& operator>>(std::istream& is, Salesman& t);
	friend std::ostream& operator<<(std::ostream& os, const Salesman& t);
	void static headerShow();
};

bool alterSalesmanFromList(list<Salesman>::iterator, string, int);
bool addSalesman(const string);
bool searchSalesman(const string);
bool alterSalesman(const string);
bool deleteSalesman(const string);
bool traverseSalesman(const string);

#endif
