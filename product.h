#ifndef PRODUCT_H
#define PRODUCT_H
#include<string>
#include<list>
using std::string;
using std::list;
const int PRODUCT_CODE_SIZE = 14;
const int PRODUCT_NAME_SIZE = 20;
const int PRODUCT_DATE_SIZE = 12;

class Product
{
private:
	char code[PRODUCT_CODE_SIZE];
	char name[PRODUCT_NAME_SIZE];
	char producer[PRODUCT_NAME_SIZE];
	char stockDate[PRODUCT_DATE_SIZE];
	int totalNumber;
	double unitPrice;
public:
	Product();
	bool setCode(string);
	bool setName(string);
	bool setProducer(string);
	bool setStockDate(string);
	bool setTotalNumber(int);
	bool setUnitPrice(double);
	bool isName(string);
	friend std::istream& operator>>(std::istream& is, Product& t);
	friend std::ostream& operator<<(std::ostream& os, const Product& t);
	void static headerShow();
};

bool addProduct(const string);
bool searchProduct(const string);
bool alterProduct(const string);
bool deleteProduct(const string);
bool traverseProduct(const string);
bool alterProductFromList(list<Product>::iterator, string, int);

#endif
