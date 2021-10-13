#include<iostream>
#include<fstream>
#include<iomanip>
#include"Producer.h"
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


void Producer::headerShow()
{
	cout << "姓 名\t联系电话\t联系地址\n";
}

Producer::Producer()
{
	name[0] = '\0';
	phone[0] = address[0] = '\0';
}

bool Producer::setName(string newName)
{
	memcpy(name, newName.c_str(), PRODUCER_NAME_SIZE);
	return true;
}

bool Producer::setPhone(string newPhone)
{
	memcpy(phone, newPhone.c_str(), PRODUCER_PHONE_SIZE);
	return true;
}

bool Producer::setAddress(string newAddress)
{
	memcpy(address, newAddress.c_str(), PRODUCER_ADDRESS_SIZE);
	return true;
}

bool Producer::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Producer& t)
{
	is >> t.name >> t.phone >> t.address;
	return is;
}

ostream& operator<<(std::ostream& os, const Producer& t)
{
	os.setf(ios::left);
	os << setw(8) << t.name << setw(16) << t.phone
		<< t.address;
	return os;
}

bool addProducer(const string fileName)
{
	Producer newProducer;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Producer::headerShow();
		cin >> newProducer;
		fp << newProducer << endl;
		cout << "是否继续添加（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchProducer(const string fileName)
{
	list<Producer> producerList;
	readListFromFile(producerList, fileName);
	list<Producer> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "请输入需要查询的进货商姓名\n";
		cin >> nameToFind;
		newList = searchFromList(producerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Producer::headerShow();
			traverseList(newList);
		}
		cout << "是否继续查询其他进货商信息（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterProducer(const string fileName)
{
	list<Producer> producerList;
	readListFromFile(producerList, fileName);
	list<Producer> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "请输入需要修改的进货商姓名\n";
		cin >> nameToFind;
		newList = searchFromList(producerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Producer::headerShow();
			traverseList(newList);
			cout << "请选择需要修改的进货商（从上往下，从1开始，取消按0）:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = producerList.begin(); curr != producerList.end(); curr++)
			{
				if (curr->isName(nameToFind))
				{
					if (count == choice)
					{
						int type = 0;
						cout << "请选择需要修改信息的类别:\n";
						cout << "(1.姓名\t2.联系电话\t3.联系地址)\n";
						cin >> type;
						if (type >= 4 || type <= 0)
						{
							cout << "无效输入\n";
						}
						else
						{
							string newContent;
							cout << "请输入新的内容:\n";
							cin >> newContent;
							alterProducerFromList(curr, newContent, choice);
							listToFile(producerList, fileName);
							cout << "修改成功\n";
							break;
						}
					}
					count++;
				}
			}
		}
		cout << "是否继续修改其他销售员信息（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool deleteProducer(const string fileName)
{
	list<Producer> producerList;
	readListFromFile(producerList, fileName);
	list<Producer> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "请输入需要删除的进货商姓名\n";
		cin >> nameToFind;
		newList = searchFromList(producerList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Producer::headerShow();
			traverseList(newList);
			cout << "请选择需要删除的进货商（从上往下，从1开始，取消按0）:\n";
			cin >> choice;
			if (deleteFromList(producerList, nameToFind, choice))
			{
				listToFile(producerList, fileName);
				cout << "删除成功" << endl;
			}
		}
		cout << "是否继续删除其他进货商信息（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseProducer(const string fileName)
{
	list<Producer> producerList;
	readListFromFile(producerList, fileName);
	Producer::headerShow();
	traverseList(producerList);
	cout << "按下回车键返回";
	cin.get();
	cin.get();
	return true;
}

bool alterProducerFromList(list<Producer>::iterator curr, string newContent, int choice)
{
	switch (choice)
	{
	case 1:
		curr->setName(newContent);
		break;
	case 2:
		curr->setPhone(newContent);
		break;
	case 3:
		curr->setAddress(newContent);
		break;
	default:return false;
	}
	return true;
}