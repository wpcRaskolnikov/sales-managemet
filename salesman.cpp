#include<iostream>
#include<fstream>
#include<iomanip>
#include<list>
#include<string>
#include"salesman.h"
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

void Salesman::headerShow()
{
	cout << "代 号\t\t姓 名\t性别\t联系电话\t联系地址\t\t\t出生年月日\t入职时间\n";
}

Salesman::Salesman()
{
	code[0] = name[0] = '\0';
	gender[0] = birthDate[0] = '\0';
	phone[0] = address[0] = '\0';
	employeeDate[0] = '\0';
}

bool Salesman::setCode(string newCode)
{
	memcpy(code, newCode.c_str(), SALESMAN_CODE_SIZE);
	return true;
}

bool Salesman::setName(string newName)
{
	memcpy(name, newName.c_str(), SALESMAN_NAME_SIZE);
	return true;
}

bool Salesman::setGender(string newGender)
{
	memcpy(gender, newGender.c_str(), SALESMAN_GENDER_SIZE);
	return true;
}

bool Salesman::setBirthDate(string newBirthDate)
{
	memcpy(birthDate, newBirthDate.c_str(), SALESMAN_DATE_SIZE);
	return true;
}

bool Salesman::setPhone(string newPhone)
{
	memcpy(phone, newPhone.c_str(), SALESMAN_PHONE_SIZE);
	return true;
}

bool Salesman::setAddress(string newAddress)
{
	memcpy(address, newAddress.c_str(), SALESMAN_ADDRESS_SIZE);
	return true;
}

bool Salesman::setEmployeeDate(string newEmployeeDate)
{
	memcpy(employeeDate, newEmployeeDate.c_str(), SALESMAN_DATE_SIZE);
	return true;
}

bool Salesman::isName(string newName)
{
	if (newName == name)
	{
		return true;
	}
	return false;
}

istream& operator>>(std::istream& is, Salesman& t)
{
	is >> t.code >> t.name >> t.gender >> t.phone
		>> t.address >> t.birthDate
		>> t.employeeDate;
	return is;
}

ostream& operator<<(std::ostream& os, const Salesman& t)
{
	os.setf(ios::left);
	os << setw(16) << t.code << setw(8) << t.name
		<< setw(8) << t.gender << setw(16) << t.phone
		<< setw(32) << t.address << setw(16) << t.birthDate
		<< t.employeeDate;
	return os;
}

bool addSalesman(const string fileName)
{
	Salesman newSalesman;
	ofstream fp(fileName, ios::app);
	int flag = 1;
	do {
		Salesman::headerShow();
		cin >> newSalesman;
		fp << newSalesman << endl;
		cout << "是否继续添加（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	fp.close();
	return true;
}

bool searchSalesman(const string fileName)
{
	list<Salesman> salesmanList;
	readListFromFile(salesmanList, fileName);
	list<Salesman> newList;
	string nameToFind;
	int flag = 1;
	do
	{
		cout << "请输入需要查询的销售员姓名\n";
		cin >> nameToFind;
		newList = searchFromList(salesmanList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Salesman::headerShow();
			traverseList(newList);
		}
		cout << "是否继续查询其他销售员信息（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool alterSalesman(const string fileName)
{
	list<Salesman> salesmanList;
	readListFromFile(salesmanList, fileName);
	list<Salesman> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "请输入需要修改的销售员姓名\n";
		cin >> nameToFind;
		newList = searchFromList(salesmanList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Salesman::headerShow();
			traverseList(newList);
			cout << "请选择需要修改的销售员（从上往下，从1开始，取消按0）:\n";
			int count = 1;
			cin >> choice;
			for (auto curr = salesmanList.begin(); curr != salesmanList.end(); curr++)
			{
				if (curr->isName(nameToFind))
				{
					if (count == choice)
					{
						int type = 0;
						cout << "请选择需要修改信息的类别:\n";
						cout << "(1.代号\t2.姓名\t3.性别\t4.联系电话\t5.联系地址\t6.出生年月日\t7.入职时间)\n";
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
							alterSalesmanFromList(curr, newContent, choice);
							listToFile(salesmanList, fileName);
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

bool deleteSalesman(const string fileName)
{
	list<Salesman> salesmanList;
	readListFromFile(salesmanList, fileName);
	list<Salesman> newList;
	string nameToFind;
	int flag = 1, choice = 0;
	do
	{
		cout << "请输入需要删除的销售员姓名\n";
		cin >> nameToFind;
		newList = searchFromList(salesmanList, nameToFind);
		if (newList.size() == 0)
		{
			cout << "没有" << nameToFind << "的信息\n";
		}
		else
		{
			Salesman::headerShow();
			traverseList(newList);
			cout << "请选择需要删除的销售员（从上往下，从1开始，取消按0）:\n";
			cin >> choice;
			if (deleteFromList(salesmanList, nameToFind, choice))
			{
				listToFile(salesmanList, fileName);
				cout << "删除成功" << endl;
			}
		}
		cout << "是否继续删除其他销售员信息（是1，否0）？\n";
		cin >> flag;
	} while (flag == 1);
	return true;
}

bool traverseSalesman(const string fileName)
{
	list<Salesman> salesmanList;
	readListFromFile(salesmanList, fileName);
	Salesman::headerShow();
	traverseList(salesmanList);
	cout << "按下回车键返回";
	cin.get();
	cin.get();
	return true;
}

bool alterSalesmanFromList(list<Salesman>::iterator curr, string newContent, int choice)
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
		curr->setGender(newContent);
		break;
	case 4:
		curr->setPhone(newContent);
		break;
	case 5:
		curr->setAddress(newContent);
		break;
	case 6:
		curr->setBirthDate(newContent);
		break;
	case 7:
		curr->setEmployeeDate(newContent);
		break;
	default:return false;
	}
	return true;
}