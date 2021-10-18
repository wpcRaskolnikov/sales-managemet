#include"menu.h"
#include"salesman.h"
#include"product.h"
#include"producer.h"
#include"customer.h"
#include"market.h"
#include<iostream>
using std::cin;
using std::string;


int main()
{
	int mainChoice, childChoice;
	while (true)
	{
		mainWindow();
		cin >> mainChoice;
		switch (mainChoice)
		{
		case 1:
			while (true)
			{
				childWindow1 childWindow1;
				childWindow1.showChildWindow1();
				cin >> childChoice;
				if (!process1(childChoice))
				{
					break;
				}
			}
			break;
		case 2:
			while (true)
			{
				childWindow2();
				cin >> childChoice;
				if (!process2(childChoice))
				{
					break;
				}
			}
			break;
		case 3:
			while (true)
			{
				childWindow3();
				cin >> childChoice;
				if (!process3(childChoice))
				{
					break;
				}
			}
			break;
		case 4:
			while (true)
			{
				childWindow4();
				cin >> childChoice;
				if (!process4(childChoice))
				{
					break;
				}
			}
			break;
		case 5:
			while (true)
			{
				childWindow5();
				cin >> childChoice;
				if (!process5(childChoice))
				{
					break;
				}
			}
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
	return 0;
}
