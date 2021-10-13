#include<iostream>
#include<fstream>
#include<iomanip>
#include"market.h"
#include"process.h"
using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::setw;

void Market::headerShow()
{
	cout << "销售员\t顾 客\t顾客联系方式\t产品名称\t产品编码\t销售数量\t售 价\t说 明\t销售时间\n";
}

Market::Market()
{
	salesman[0] = customer[0] = '\0';
	customerPhone[0] = name[0] = '\0';
	productCode[0] = salesDate[0] = '\0';
	note[0] = '\0';
	amount = 0;
	unitPrice = 0.0;
}

bool Market::setSalesman(string newSalesman)
{
	memcpy(salesman, newSalesman.c_str(), NAME_SIZE);
	return true;
}

bool Market::setCustomer(string newCustomer)
{
	memcpy(customer, newCustomer.c_str(), NAME_SIZE);
	return true;
}

bool Market::setCustomerPhone(string newCustomerPhone)
{
	memcpy(customerPhone, newCustomerPhone.c_str(), PHONE_SIZE);
	return true;

}

bool Market::setName(string newName)
{
	memcpy(name, newName.c_str(), NAME_SIZE);
	return true;
}

bool Market::setProductCode(string newProductCode)
{
	memcpy(productCode, newProductCode.c_str(), CODE_SIZE);
	return true;
}

bool Market::setSalesDate(string newSalesDate)
{
	memcpy(salesDate, newSalesDate.c_str(), NAME_SIZE);
	return true;
}

bool Market::setNote(string newNote)
{
	memcpy(note, newNote.c_str(), NOTE_SIZE);
	return true;
}

bool Market::setAmount(int newAmount)
{
	amount = newAmount;
	return true;
}

bool Market::setUnitPrice(double newUnitPrice)
{
	unitPrice = newUnitPrice;
	return true;
}

bool Market::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Market& t)
{
	is >> t.salesman >> t.customer >> t.customerPhone
		>> t.name >> t.productCode >> t.amount
		>> t.unitPrice >> t.note >> t.salesDate;
	return is;
}

ostream& operator<<(std::ostream& os, const Market& t)
{
	os.setf(ios::left);
	os << setw(8) << t.salesman << setw(8) << t.customer
		<< setw(16) << t.customerPhone << setw(16) << t.name
		<< setw(16) << t.productCode << setw(16) << t.amount
		<< setw(8) << t.unitPrice << setw(8) << t.note
		<< t.salesDate;
	return os;
}

bool addMarket(const string fileName)
{
	Market newMarket;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Market::headerShow();
		cin >> newMarket;
		fp << newMarket << endl;
		cout << "是否继续添加（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchMarket(const string fileName)
{
	list<Market> marketList;
	readListFromFile(marketList, fileName);
	list<Market> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "请输入需要查询的产品名称\n";
		cin >> nameToFind;
		newList = searchFromList(marketList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Market::headerShow();
			traverseList(newList);
		}
		cout << "是否继续查询其它产品名称（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterMarket(const string fileName)
{
	list<Market> marketList;
	readListFromFile(marketList, fileName);
	list<Market> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "请输入需要修改的销售记录的产品名称\n";
		cin >> nameToFind;
		newList = searchFromList(marketList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Market::headerShow();
			traverseList(newList);
			cout << "请选择需要修改的销售记录（从上往下，从1开始，取消按0）:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = marketList.begin(); curr != marketList.end(); curr++)
			{
				if (curr->isName(nameToFind))
				{
					if (count == choice)
					{
						int type = 0;
						cout << "请选择需要修改信息的类别:\n";
						cout << "(1.销售员\t2.顾 客\t3.顾客联系方式\t4.销售数量\t5.售 价\t6.说 明\t7.销售时间)\n";
						cin >> type;
						if (type >= 8 || type <= 0)
						{
							cout << "无效输入\n";
						}
						else
						{
							string newContent;
							cout << "请输入新的内容:\n";
							cin >> newContent;
							alterMarketFromList(curr, newContent, choice);
							listToFile(marketList, fileName);
							cout << "修改成功\n";
							break;
						}
					}
					count++;
				}
			}
		}
		cout << "是否继续修改其他销售记录（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool deleteMarket(const string fileName)
{
	list<Market> marketList;
	readListFromFile(marketList, fileName);
	list<Market> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "请输入需要删除的销售记录的产品名称\n";
		cin >> nameToFind;
		newList = searchFromList(marketList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Market::headerShow();
			traverseList(newList);
			cout << "请选择需要删除的销售记录（从上往下，从1开始，取消按0）:\n";
			cin >> choice;
			if (deleteFromList(marketList, nameToFind, choice))
			{
				listToFile(marketList, fileName);
				cout << "删除成功" << endl;
			}
		}
		cout << "是否继续删除其他销售记录（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseMarket(const string fileName)
{
	list<Market> marketList;
	readListFromFile(marketList, fileName);
	Market::headerShow();
	traverseList(marketList);
	cout << "按下回车键返回";
	cin.get();
	cin.get();
	return true;
}

bool alterMarketFromList(list<Market>::iterator curr, string newContent, int choice)
{
	switch (choice)
	{
	case 1:
		curr->setSalesman(newContent);
		break;
	case 2:
		curr->setCustomer(newContent);
		break;
	case 3:
		curr->setCustomerPhone(newContent);
		break;
	case 4:
		curr->setAmount(atoi(newContent.c_str()));
		break;
	case 5:
		curr->setUnitPrice(atof(newContent.c_str()));
		break;
	case 6:
		curr->setNote(newContent);
		break;
	case 7:
		curr->setSalesDate(newContent);
		break;
	default:return false;
	}
	return true;
}