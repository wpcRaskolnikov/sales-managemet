#include "childWindow.h"
bool ChildWindow::form()
{
	cout << "\t\t   ┌───────────────────────────┐\n";
	cout << "\t\t   │ 1. 添加信息    2. 信息查询│\n";
	cout << "\t\t   │                           │\n";
	cout << "\t\t   │ 3. 修改信息    4. 删除信息│\n";
	cout << "\t\t   │                           │\n";
	cout << "\t\t   │ 5. 遍历信息    0. 返回上级│\n";
	cout << "\t\t   └───────────────────────────┘\n";
	cout << "\t\t请您选择(0-5):";
	return true;
}

bool ChildWindow::childWindow1()
{
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             人员管理             │\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool ChildWindow::childWindow2()
{
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             产品管理             │\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool ChildWindow::childWindow3()
{
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             进货商管理           │\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool ChildWindow::childWindow4()
{
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             顾客管理             │\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool ChildWindow::childWindow5()
{
	system("cls"); /*清屏*/
	cout << "\t\t ===================================\n";
	cout << "\t\t│             销售管理             │\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}