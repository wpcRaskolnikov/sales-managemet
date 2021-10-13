#ifndef SALE_H
#define SALE_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int CODESIZE = 14;
const int NAMESIZE = 20;
const int GENDERSIZE = 8;
const int PHONESIZE = 15;
const int ADRESSSIZE = 50;
const int DATESIZE = 12;
const int NOTESIZE = 30;
const string SALESMANFILE = "D:\\Salesman.txt";
const string CUSTOMERFILE = "D:\\Customer.txt";
const string PRODUCERFILE = "D:\\Producer.txt";
const string PRODUCTFILE = "D:\\Product.txt";
const string MARKETFILE = "D:\\Market.txt";

typedef struct Salesman
{
	char number[CODESIZE];
	char name[NAMESIZE];
	char gender[GENDERSIZE];
	char birthDate[DATESIZE];
	char phone[PHONESIZE];
	char address[ADRESSSIZE];
	char employedDate[DATESIZE];
	struct Salesman* next;
}Salesman;                   //销售员信息 

typedef struct Product
{
	char code[CODESIZE];
	char name[NAMESIZE];
	int totalNumber;
	double unitPrice;
	char producer[NAMESIZE];
	char stockDate[DATESIZE];
	struct Product* next;
}Product;                   //产品信息

typedef struct Market
{
	char salesman[NAMESIZE];
	char customer[NAMESIZE];
	char customerPhone[PHONESIZE];
	char name[NAMESIZE];
	char productCode[CODESIZE];
	int amount;
	double unitPrice;
	char notes[30];
	char salesDate[DATESIZE];
	struct Market* next;
}Market;                   //销售信息

typedef struct Producer
{
	char name[NAMESIZE];
	char phone[PHONESIZE];
	char address[ADRESSSIZE];
	struct Producer* next;
}Producer;             //进货商信息

typedef struct Customer
{
	char name[NAMESIZE];
	char phone[PHONESIZE];
	char address[ADRESSSIZE];
	struct Customer* next;
}Customer;          //顾客信息

/*显示界面函数声明*/
int mainSelect();
int salesmanManage();
int productManage();
int sellerManage();
int customerManage();
int marketManage();
void form();


/*人员管理函数声明*/
string Filename(Salesman* p);
void HeaderShow(Salesman* head);
void SearchShow(Salesman* head);
void Change(Salesman* head);
void CancelShow1(Salesman* p);
void CancelShow2(Salesman* p);
void Input(istream& t, Salesman* p);
void Output(ostream& t, Salesman* p);


/*产品管理函数声明*/
string Filename(Product* p);
void HeaderShow(Product* head);
void SearchShow(Product* head);
void Change(Product* head);
void CancelShow1(Product* p);
void CancelShow2(Product* p);
void Input(istream& t, Product* p);
void Output(ostream& t, Product* p);

/*进货商管理函数声明*/
string Filename(Producer* p);
void HeaderShow(Producer* head);
void SearchShow(Producer* head);
void Change(Producer* head);
void CancelShow1(Producer* p);
void CancelShow2(Producer* p);
void Input(istream& t, Producer* p);
void Output(ostream& t, Producer* p);

/*顾客管理函数声明*/
string Filename(Customer* p);
void HeaderShow(Customer* head);
void SearchShow(Customer* head);
void Change(Customer* head);
void CancelShow1(Customer* p);
void CancelShow2(Customer* p);
void Input(istream& t, Customer* p);
void Output(ostream& t, Customer* p);

/*销售管理函数声明*/
string Filename(Market* p);
void HeaderShow(Market* head);
void SearchShow(Market* head);
void Change(Market* head);
void CancelShow1(Market* p);
void CancelShow2(Market* p);
void Input(istream& t, Market* p);
void Output(ostream& t, Market* p);

//从文件读取信息存入链表
template <typename T>
void Read(T** head)
{
	T* p, * q;
	p = q = nullptr;
	ifstream fp(Filename(p), ios::in);
	q = *head;
	if (fp.peek() != EOF)
	{
		Input(fp, q);
		fp.get();
		while (fp.peek() != EOF)
		{
			p = new T;
			Input(fp, p);
			fp.get();
			q->next = p;
			q = p;
		}
		q->next = nullptr;
	}
	else
	{
		delete* head;
		*head = nullptr;
	}
	fp.close();
}             

//根据输入把信息存入文件
template <typename T>
void Add(T* p)
{
	system("cls");
	ofstream fp(Filename(p), ios::app);
	int n;
	T* pnew = new T;
	do {
		HeaderShow(pnew);
		Input(cin, pnew);
		Output(fp, pnew);
		cout << "是否继续添加（是1，否0）？\n";
		cin >> n;
	} while (n == 1);
	fp.close();
	delete pnew;
}

//查询链表中信息
template <typename T>
void Search(T* head)
{
	string name;
	SearchShow(head);
	cin >> name;
	HeaderShow(head);
	if (!Show(head, name))
	{
		system("cls");
		cout << "没有" << name << "的信息\n";
	}
}

//查询文件中信息
template <typename T>
void Check(T* p)
{
	system("cls");
	T* head;
	head = new T;
	Read(&head);
	if (!head)
	{
		cout << "未添加信息\n";
		cout << "按下回车键返回";
		cin.get();
		cin.get();
		return;
	}
	int n;
	do {
		Search(head);
		cout << "是否继续查询其他信息（是1，否0）？\n";
		cin >> n;
	} while (n == 1);
	delete head;
}

//修改文件数据
template <typename T>
void Alter(T* p)
{
	system("cls");
	T* head;
	head = new T;
	Read(&head);
	if (!head)
	{
		cout << "未添加任何信息\n";
		cout << "按下回车键返回";
		cin.get();
		cin.get();
		return;
	}
	int n;
	do {
		Change(head);
		cout << "是否继续修改其他信息（是1，否0）？\n";
		cin >> n;
	} while (n == 1);
	InputAgain(head);
	delete head;
}

//展示所有同名信息
template <typename T>
bool Show(T* head, string name)
{
	bool flag = false;
	while (head)
	{
		if (name == head->name)
		{
			flag = true;
			Output(cout, head);
		}
		head = head->next;
	}
	return flag;
}

//从链表中寻找到需要修改的数据并返回
template <typename T>
T* Find(T* head, string name)
{
	int n, temp = 1;
	if (!Show(head, name))
	{
		system("cls");
		cout << "没有" << name << "的信息\n";
		return nullptr;
	}
	cout << "请选择需要修改的数据（从上往下，从1开始，取消按0）:\n";
	cin >> n;
	while (head)
	{
		if (name == head->name)
		{
			if (temp == n)
				return head;
			temp++;
		}
		head = head->next;
	}
	return nullptr;
}

//删除文件中信息
template <typename T>
void Delete(T* p)
{
	system("cls");
	T* t = new T;
	T* head = new T;
	head->next = nullptr;
	int n;
	Read(&head);
	if (!head)
	{
		cout << "未添加任何信息\n";
		cout << "按下回车键返回";
		cin.get();
		cin.get();
		return;
	}
	t->next = head;
	do {
		Cancel(t);
		cout << "是否继续删除其他信息（是1，否0）？\n";
		cin >> n;
	} while (n == 1);
	head = t->next;
	InputAgain(head);
	delete t;
	delete head;
}

//删除链表中信息
template <typename T>
void Cancel(T* head)
{
	int n, temp = 1;
	string name;
	T* p, * pold;
	p = pold = nullptr;
	CancelShow1(p);
	cin >> name;
	HeaderShow(p);
	if (!Show(head, name))
	{
		system("cls");
		cout << "没有" << name << "的信息\n";
		return;
	}
	CancelShow2(p);
	cin >> n;
	pold = head;
	p = pold->next;
	while (p)
	{
		if (name == p->name)
		{
			if (temp == n)
			{
				pold->next = p->next;
				delete p;
				p = pold->next;
				cout << "删除成功\n";
				break;
			}
			temp++;
		}
		pold = p;
		p = p->next;
	}
}

//遍历文件信息并展示
template <typename T>
void Traverse(T* p)
{
	system("cls");
	T* head;
	head = new T;
	Read(&head);
	if (head)
		HeaderShow(head);
	else cout << "未添加任何信息\n";
	while (head)
	{
		Output(cout, head);
		head = head->next;
	}
	cout << "按下回车键返回";
	cin.get();
	cin.get();
}

//用链表数据覆盖文件数据
template <typename T>
void InputAgain(T* head)
{
	ofstream fp(Filename(head), ios::out);
	while (head)
	{
		Output(fp, head);
		head = head->next;
	}
	fp.close();
}

#endif