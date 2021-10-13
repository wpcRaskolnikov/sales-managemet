#pragma warning(disable:4996)
#include<iomanip>
#include"sale.h"

string Filename(Product* p)
{
	return PRODUCTFILE;
}

void HeaderShow(Product* head)
{
	cout << "编 码\t名 称\t总 数\t进 价\t产 商\t入库时间\n";
}

void SearchShow(Product* head)
{
	cout << "请输入需要查询的产品名称\n";
}

void Change(Product* head)
{
	string content, name;
	int type;
	Product* p=nullptr;
	cout << "请输入需要修改的产品名称\n";
	cin >> name;
	HeaderShow(p);
	p = Find(head, name);
	if (!p)
		return;
	cout << "请选择需要修改信息的类别:\n";
	cout << "(1.编码\t2.名称\t3.总数\t4.单价\t5.产商\t6.入库时间(如：xxxx-xx-xx)\n)";
	cin >> type;
	if (type >= 7 || type <= 0)
	{
		cout << "无效输入\n";
		return;
	}
	cout << "请输入新的内容:\n";
	cin >> content;
	switch (type)
	{
	case 1:
		strncpy(p->code, content.c_str(), CODESIZE);
		break;
	case 2:
		strncpy(p->name, content.c_str(), NAMESIZE);
		break;
	case 3:
		p->totalNumber = atoi(content.c_str());
		break;
	case 4:
		p->unitPrice = atof(content.c_str());
		break;
	case 5:
		strncpy(p->producer, content.c_str(), NAMESIZE);
		break;
	case 6:
		strncpy(p->stockDate, content.c_str(), DATESIZE);
		break;
	}
}

void CancelShow1(Product* p)
{
	cout << "请输入需要删除的产品名称\n";
}

void CancelShow2(Product* p)
{
	cout << "请选择需要删除的产品（从上往下，从1开始，取消按0）:\n";
}

void Input(istream& t, Product* p)
{
	t >> p->code >> p->name >> p->totalNumber
		>> p->unitPrice >> p->producer >> p->stockDate;
}

void Output(ostream& t, Product* p)
{
	t.setf(ios::left);
	t << setw(8) << p->code << setw(8) << p->name
		<< setw(8) << p->totalNumber << setw(8) << p->unitPrice
		<< setw(8) << p->producer << p->stockDate << endl;
}