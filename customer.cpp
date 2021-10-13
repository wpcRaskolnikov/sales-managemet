#pragma warning(disable:4996)
#include<iomanip>
#include"sale.h"

string Filename(Customer* p)
{
	return CUSTOMERFILE;
}

void HeaderShow(Customer* head)
{
	cout << "姓 名\t联系电话\t联系地址\n";
}

void SearchShow(Customer* head)
{
	cout << "请输入需要查询的顾客姓名\n";
}

void Change(Customer* head)
{
	string content, name;
	int type;
	Customer* p=nullptr;
	cout << "请输入需要修改的顾客的姓名\n";
	cin >> name;
	HeaderShow(p);
	p = Find(head, name);
	if (!p)
		return;
	cout << "请选择需要修改信息的类别:\n";
	cout << "(1.姓名\t2.联系电话\t3.联系地址)\n";
	cin >> type;
	if (type >= 4 || type <= 0)
	{
		cout << "无效输入\n";
		return;
	}
	cout << "请输入新的内容:\n";
	cin >> content;
	switch (type)
	{
	case 1:
		strncpy(p->name, content.c_str(), NAMESIZE);
		break;
	case 2:
		strncpy(p->phone, content.c_str(), PHONESIZE);
		break;
	case 3:
		strncpy(p->address, content.c_str(), ADRESSSIZE);
		break;
	}
	cout << "修改成功\n";
}

void CancelShow1(Customer* p)
{
	cout << "请输入需要删除的顾客姓名\n";
}

void CancelShow2(Customer* p)
{
	cout << "请选择需要删除的顾客（从上往下，从1开始，取消按0）:\n";
}

void Input(istream& t, Customer* p)
{
	t >> p->name >> p->phone >> p->address;
}

void Output(ostream& t, Customer* p)
{
	t.setf(ios::left);
	t << setw(8) << p->name << setw(16) << p->phone
		<< p->address << endl;
}