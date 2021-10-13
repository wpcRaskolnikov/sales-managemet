#ifndef MARKET_H
#define MARKET_H
#include<string>
#include<list>
using std::string;
using std::list;
const int CODE_SIZE = 14;
const int NAME_SIZE = 20;
const int NOTE_SIZE = 30;
const int PHONE_SIZE = 15;
const int DATE_SIZE = 12;

class Market
{
private:
	char salesman[NAME_SIZE];
	char customer[NAME_SIZE];
	char customerPhone[PHONE_SIZE];
	char name[NAME_SIZE];
	char productCode[CODE_SIZE];
	char salesDate[DATE_SIZE];
	char note[NOTE_SIZE];
	int amount;
	double unitPrice;
public:
	Market();
	bool setSalesman(string);
	bool setCustomer(string);
	bool setCustomerPhone(string);
	bool setName(string);
	bool setProductCode(string);
	bool setSalesDate(string);
	bool setNote(string);
	bool setAmount(int);
	bool setUnitPrice(double);
	bool isName(string);
	friend std::istream& operator>>(std::istream& is, Market& t);
	friend std::ostream& operator<<(std::ostream& os, const Market& t);
	void static headerShow();
};

bool addMarket(const string);
bool searchMarket(const string);
bool alterMarket(const string);
bool deleteMarket(const string);
bool traverseMarket(const string);
bool alterMarketFromList(list<Market>::iterator, string, int);

#endif