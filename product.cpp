#include<iostream>
#include<fstream>
#include<iomanip>
#include"product.h"
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

void Product::headerShow()
{
	cout << "编 码\t名 称\t总 数\t进 价\t产 商\t入库时间\n";
}

Product::Product()
{
	code[0] = name[0] = '\0';
	producer[0] = stockDate[0] = '\0';
	totalNumber = 0;
	unitPrice = 0.0;
}

bool Product::setCode(string newCode)
{
	memcpy(code, newCode.c_str(), PRODUCT_CODE_SIZE);
	return true;
}

bool Product::setName(string newName)
{
	memcpy(name, newName.c_str(), PRODUCT_NAME_SIZE);
	return true;
}

bool Product::setProducer(string newProducer)
{
	memcpy(producer, newProducer.c_str(), PRODUCT_NAME_SIZE);
	return true;
}

bool Product::setStockDate(string newStockDate)
{
	memcpy(stockDate, newStockDate.c_str(), PRODUCT_DATE_SIZE);
	return true;
}

bool Product::setTotalNumber(int newNumber)
{
	totalNumber = newNumber;
	return true;
}

bool Product::setUnitPrice(double newPrice)
{
	unitPrice = newPrice;
	return true;
}

bool Product::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Product& t)
{
	is >> t.code >> t.name >> t.totalNumber
		>> t.unitPrice >> t.producer >> t.stockDate;
	return is;
}

ostream& operator<<(std::ostream& os, const Product& t)
{
	os.setf(ios::left);
	os << setw(8) << t.code << setw(8) << t.name
		<< setw(8) << t.totalNumber << setw(8) << t.unitPrice
		<< setw(8) << t.producer << t.stockDate;
	return os;
}

bool addProduct(const string fileName)
{
	Product newProduct;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Product::headerShow();
		cin >> newProduct;
		fp << newProduct << endl;
		cout << "是否继续添加（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchProduct(const string fileName)
{
	list<Product> productList;
	readListFromFile(productList, fileName);
	list<Product> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "请输入需要查询的商品名称\n";
		cin >> nameToFind;
		newList = searchFromList(productList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Product::headerShow();
			traverseList(newList);
		}
		cout << "是否继续查询其他商品信息（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterProduct(const string fileName)
{
	list<Product> productList;
	readListFromFile(productList, fileName);
	list<Product> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "请输入需要修改的产品名称\n";
		cin >> nameToFind;
		newList = searchFromList(productList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Product::headerShow();
			traverseList(newList);
			cout << "请选择需要修改的产品（从上往下，从1开始，取消按0）:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = productList.begin(); curr != productList.end(); curr++)
			{
				if (curr->isName(nameToFind))
				{
					if (count == choice)
					{
						int type = 0;
						cout << "请选择需要修改信息的类别:\n";
						cout << "(1.编码\t2.名称\t3.总数\t4.单价\t5.产商\t6.入库时间(如：xxxx-xx-xx)\n)";
						cin >> type;
						if (type >= 7 || type <= 0)
						{
							cout << "无效输入\n";
						}
						else
						{
							string newContent;
							cout << "请输入新的内容:\n";
							cin >> newContent;
							alterProductFromList(curr, newContent, choice);
							listToFile(productList, fileName);
							cout << "修改成功\n";
							break;
						}
					}
					count++;
				}
			}
		}
		cout << "是否继续修改其他产品信息（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool deleteProduct(const string fileName)
{
	list<Product> productList;
	readListFromFile(productList, fileName);
	list<Product> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "请输入需要删除的产品名称\n";
		cin >> nameToFind;
		newList = searchFromList(productList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Product::headerShow();
			traverseList(newList);
			cout << "请选择需要删除的产品（从上往下，从1开始，取消按0）:\n";
			cin >> choice;
			if (deleteFromList(productList, nameToFind, choice))
			{
				listToFile(productList, fileName);
				cout << "删除成功" << endl;
			}
		}
		cout << "是否继续删除其他产品信息（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseProduct(const string fileName)
{
	list<Product> productList;
	readListFromFile(productList, fileName);
	Product::headerShow();
	traverseList(productList);
	cout << "按下回车键返回";
	cin.get();
	cin.get();
	return true;
}

bool alterProductFromList(list<Product>::iterator curr, string newContent, int choice)
{
	switch (choice)
	{
	case 1:
		curr->setCode(newContent);
		break;
	case 2:
		curr->setName(newContent);
		break;
	case 3:
		curr->setTotalNumber(atoi(newContent.c_str()));
		break;
	case 4:
		curr->setUnitPrice(atof(newContent.c_str()));
		break;
	case 5:
		curr->setProducer(newContent);
		break;
	case 6:
		curr->setStockDate(newContent);
		break;
	default:return false;
	}
	return true;
}