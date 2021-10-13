#include<iomanip>
#include"sale.h"

string Filename(Salesman *p)
{
	return SALESMANFILE;
}

void HeaderShow(Salesman* head)
{
	cout << "代 号\t\t姓 名\t性别\t联系电话\t联系地址\t\t\t出生年月日\t入职时间\n";
}

void SearchShow(Salesman* head)
{
	cout << "请输入需要查询的销售员姓名\n";
}

void Change(Salesman* head)
{
	Salesman* p=nullptr;
	string content, name;
	int type;
	cout << "请输入需要修改的销售员姓名\n";
	cin >> name;
	HeaderShow(p);
	p = Find(head, name);
	if (!p)
		return;
	cout << "请选择需要修改信息的类别:\n";
	cout << "(1.代号\t2.姓名\t3.性别\t4.联系电话\t5.联系地址\t6.出生年月日\t7.入职时间)\n";
	cin >> type;
	if (type >= 8 || type <= 0)
	{
		cout << "无效输入\n";
		return;
	}
	cout << "请输入新的内容:\n";
	cin >> content;
	switch (type)
	{
	case 1:
		memcpy(p->number, content.c_str(), CODESIZE);
		break;
	case 2:
		memcpy(p->name, content.c_str(), NAMESIZE);
		break;
	case 3:
		memcpy(p->gender, content.c_str(), GENDERSIZE);
		break;
	case 4:
		memcpy(p->phone, content.c_str(), PHONESIZE);
		break;
	case 5:
		memcpy(p->address, content.c_str(), ADRESSSIZE);
		break;
	case 6:
		memcpy(p->birthDate, content.c_str(), DATESIZE);
		break;
	case 7:
		memcpy(p->employedDate, content.c_str(), DATESIZE);
		break;
	}
	cout << "修改成功\n";
}

void CancelShow1(Salesman* p)
{
	cout << "请输入需要删除的销售员姓名\n";
}

void CancelShow2(Salesman* p)
{
	cout << "请选择需要删除的销售员（从上往下，从1开始，取消按0）:\n";
}

void Input(istream& t, Salesman* p)
{
	t >> p->number >> p->name >> p->gender
		>> p->phone >> p->address >> p->birthDate
		>> p->employedDate;
}

void Output(ostream& t, Salesman* p)
{
	t.setf(ios::left);
	t << setw(16) << p->number << setw(8) << p->name
		<< setw(8) << p->gender << setw(16) << p->phone
		<< setw(32) << p->address << setw(16) << p->birthDate
		<< p->employedDate << endl;
}