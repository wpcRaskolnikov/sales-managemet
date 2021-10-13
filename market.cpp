#pragma warning(disable:4996)
#include<iomanip>
#include"sale.h"

string Filename(Market* p)
{
	return MARKETFILE;
}

void HeaderShow(Market* head)
{
	cout << "销售员\t顾 客\t顾客联系方式\t产品名称\t产品编码\t销售数量\t售 价\t说 明\t销售时间\n";
}

void SearchShow(Market* head)
{
	cout << "请输入需要查询的产品名称\n";
}

void Change(Market* head)
{
	Market* p=nullptr;
	string content, name;
	int type;
	cout << "请输入需要修改的销售记录的产品名称\n";
	cin >> name;
	HeaderShow(p);
	p = Find(head, name);
	if (!p)
		return;
	cout << "请选择需要修改信息的类别:\n";
	cout << "(1.销售员\t2.顾 客\t3.顾客联系方式\t4.销售数量\t5.售 价\t6.说 明\t7.销售时间)\n";
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
		strncpy(p->salesman, content.c_str(), NAMESIZE);
		break;
	case 2:
		strncpy(p->customer, content.c_str(), NAMESIZE);
		break;
	case 3:
		strncpy(p->customerPhone, content.c_str(), PHONESIZE);
		break;
	case 4:
		p->amount = atoi(content.c_str());
		break;
	case 5:
		p->unitPrice = atof(content.c_str());
		break;
	case 6:
		strncpy(p->notes, content.c_str(), 30);
		break;
	case 7:
		strncpy(p->salesDate, content.c_str(), DATESIZE);
		break;
	}
	cout << "修改成功\n";
}

void CancelShow1(Market* p)
{
	cout << "请输入需要删除的销售记录的产品名称\n";
}

void CancelShow2(Market* p)
{
	cout << "请选择需要删除的销售记录（从上往下，从1开始，取消按0）:\n";
}

void Input(istream& t, Market* p)
{
	t >> p->salesman >> p->customer >> p->customerPhone
		>> p->name >> p->productCode >> p->amount
		>> p->unitPrice >> p->notes >> p->salesDate;
}

void Output(ostream& t, Market* p)
{
	t.setf(ios::left);
	t << setw(8) << p->salesman << setw(8) << p->customer
		<< setw(16) << p->customerPhone << setw(16) << p->name
		<< setw(16) << p->productCode << setw(16) << p->amount
		<< setw(8) << p->unitPrice << setw(8) << p->notes
		<< p->salesDate << endl;
}