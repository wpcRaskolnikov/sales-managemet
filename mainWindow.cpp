#include "mainWindow.h"
bool MainWindow::mainWindow1()
{
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
	cout << "\t\t请您选择(0-5):";
	return true;
}


