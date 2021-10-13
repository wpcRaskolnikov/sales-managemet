#ifndef PRODUCER_H
#define PRODUCER_H
#include<string>
#include<list>
using std::string;
using std::list;
const int PRODUCER_CODE_SIZE = 14;
const int PRODUCER_NAME_SIZE = 20;
const int PRODUCER_GENDER_SIZE = 8;
const int PRODUCER_PHONE_SIZE = 15;
const int PRODUCER_ADDRESS_SIZE = 50;
const int PRODUCER_DATE_SIZE = 12;


class Producer
{
private:
	char name[PRODUCER_NAME_SIZE];
	char phone[PRODUCER_PHONE_SIZE];
	char address[PRODUCER_ADDRESS_SIZE];
public:
	Producer();
	bool setName(string);
	bool setPhone(string);
	bool setAddress(string);
	bool isName(string);
	friend std::istream& operator>>(std::istream& is, Producer& t);
	friend std::ostream& operator<<(std::ostream& os, const Producer& t);
	void static headerShow();
};

bool addProducer(const string);
bool searchProducer(const string);
bool alterProducer(const string);
bool deleteProducer(const string);
bool traverseProducer(const string);
bool alterProducerFromList(list<Producer>::iterator, string, int);

#endif
