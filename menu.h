#ifndef MENU_H
#define MENU_H
#include<string>
using std::string;

const string SALESMAN_FILE = "D:\\Salesman.txt";
const string PRODUCT_FILE = "D:\\Product.txt";
const string PRODUCER_FILE = "D:\\Producer.txt";
const string CUSTOMER_FILE = "D:\\Customer.txt";
const string MARKET_FILE = "D:\\Market.txt";

bool mainWindow();
bool childWindow1();
bool childWindow2();
bool childWindow3();
bool childWindow4();
bool childWindow5();
bool process1(int& choice);
bool process2(int& choice);
bool process3(int& choice);
bool process4(int& choice);
bool process5(int& choice);

#endif
