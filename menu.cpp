#include"sale.h"

int mainSelect()
{
	int n;
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│         销售信息管理系统         │\n";
	cout << "\t\t ===================================\n";
	cout << "\t\t  ┌─────────────────────────────┐\n";
	cout << "\t\t  │ 1. 人员管理     2. 产品管理 │\n";
	cout << "\t\t  │                             │\n";
	cout << "\t\t  │ 3. 进货商管理   4. 顾客管理 │\n";
	cout << "\t\t  │                             │\n";
	cout << "\t\t  │ 5. 销售管理     0. 退出系统 │\n";
	cout << "\t\t  └─────────────────────────────┘\n";
	cout << "\t\t请您选择(1-4):";
	cin >> n;
	return n;
}

int salesmanManage()
{
	int n;
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             人员管理             │\n";
	cout << "\t\t ===================================\n";
	form();
	cin >> n;
	return n;
}

int productManage()
{
	int n;
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             产品管理             │\n";
	cout << "\t\t ===================================\n";
	form();
	cin >> n;
	return n;
}

int sellerManage()
{
	int n;
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             进货商管理           │\n";
	cout << "\t\t ===================================\n";
	form();
	cin >> n;
	return n;
}

int customerManage()
{
	int n;
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             顾客管理             │\n";
	cout << "\t\t ===================================\n";
	form();
	cin >> n;
	return n;
}

int marketManage()
{
	int n;
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             销售管理             │\n";
	cout << "\t\t ===================================\n";
	form();
	cin >> n;
	return n;
}

void form()
{
	cout << "\t\t   ┌───────────────────────────┐\n";
	cout << "\t\t   │ 1. 添加信息    2. 信息查询│\n";
	cout << "\t\t   │                           │\n";
	cout << "\t\t   │ 3. 修改信息    4. 删除信息│\n";
	cout << "\t\t   │                           │\n";
	cout << "\t\t   │ 5. 遍历信息    0. 返回上级│\n";
	cout << "\t\t   └───────────────────────────┘\n";
	cout << "\t\t请您选择(0-4):";
}