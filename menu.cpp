#include"menu.h"
#include"salesman.h"
#include"product.h"
#include"producer.h"
#include"customer.h"
#include"market.h"
#include<iostream>
using namespace std;

bool form()
{
	cout << "\t\t   ����������������������������������������������������������\n";
	cout << "\t\t   �� 1. �����Ϣ    2. ��Ϣ��ѯ��\n";
	cout << "\t\t   ��                           ��\n";
	cout << "\t\t   �� 3. �޸���Ϣ    4. ɾ����Ϣ��\n";
	cout << "\t\t   ��                           ��\n";
	cout << "\t\t   �� 5. ������Ϣ    0. �����ϼ���\n";
	cout << "\t\t   ����������������������������������������������������������\n";
	cout << "\t\t����ѡ��(0-5):";
	return true;
}

bool mainWindow()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��         ������Ϣ����ϵͳ         ��\n";
	cout << "\t\t ===================================\n";
	cout << "\t\t  ��������������������������������������������������������������\n";
	cout << "\t\t  �� 1. ��Ա����     2. ��Ʒ���� ��\n";
	cout << "\t\t  ��                             ��\n";
	cout << "\t\t  �� 3. �����̹���   4. �˿͹��� ��\n";
	cout << "\t\t  ��                             ��\n";
	cout << "\t\t  �� 5. ���۹���     0. �˳�ϵͳ ��\n";
	cout << "\t\t  ��������������������������������������������������������������\n";
	cout << "\t\t����ѡ��(0-5):";
	return true;
}


bool salesmanWindow1::showSalesmanWindow1()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             ��Ա����             ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool salesmanWindow1::salesmanWindow()
{
	showSalesmanWindow1();
	return true;
}

bool salesmanWindow1::runSalesmanWindow(int childChoice)
{
	while (true)
	{
		if (!process1(childChoice))
		{
			break;
		}
	}
	return true;
}

bool childWindow2()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             ��Ʒ����             ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool childWindow3()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             �����̹���           ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool childWindow4()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             �˿͹���             ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool childWindow5()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             ���۹���             ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool process1(int& choice)
{
	if (choice == 0) 
		return false;
	switch (choice)
	{
	case 1:
		system("cls");
		addSalesman(SALESMAN_FILE);
		break;
	case 2:
		system("cls");
		searchSalesman(SALESMAN_FILE);
		break;
	case 3:
		system("cls");
		alterSalesman(SALESMAN_FILE);
		break;
	case 4:
		system("cls");
		deleteSalesman(SALESMAN_FILE);
		break;
	case 5:
		system("cls");
		traverseSalesman(SALESMAN_FILE);
		break;
	default:
		break;
	}
	return true;
}

bool process2(int& choice)
{
	if (choice == 0)
		return false;
	switch (choice)
	{
	case 1:
		system("cls");
		addProduct(PRODUCT_FILE);
		break;
	case 2:
		system("cls");
		searchProduct(PRODUCT_FILE);
		break;
	case 3:
		system("cls");
		alterProduct(PRODUCT_FILE);
		break;
	case 4:
		system("cls");
		deleteProduct(PRODUCT_FILE);
		break;
	case 5:
		system("cls");
		traverseProduct(PRODUCT_FILE);
		break;
	default:
		break;
	}
	return true;
}

bool process3(int& choice)
{
	if (choice == 0)
		return false;
	switch (choice)
	{
	case 1:
		system("cls");
		addProducer(PRODUCER_FILE);
		break;
	case 2:
		system("cls");
		searchProducer(PRODUCER_FILE);
		break;
	case 3:
		system("cls");
		alterProducer(PRODUCER_FILE);
		break;
	case 4:
		system("cls");
		deleteProducer(PRODUCER_FILE);
		break;
	case 5:
		system("cls");
		traverseProducer(PRODUCER_FILE);
		break;
	default:
		break;
	}
	return true;
}

bool process4(int& choice)
{
	if (choice == 0)
		return false;
	switch (choice)
	{
	case 1:
		system("cls");
		addCustomer(CUSTOMER_FILE);
		break;
	case 2:
		system("cls");
		searchCustomer(CUSTOMER_FILE);
		break;
	case 3:
		system("cls");
		alterCustomer(CUSTOMER_FILE);
		break;
	case 4:
		system("cls");
		deleteCustomer(CUSTOMER_FILE);
		break;
	case 5:
		system("cls");
		traverseCustomer(CUSTOMER_FILE);
		break;
	default:
		break;
	}
	return true;
}

bool process5(int& choice)
{
	if (choice == 0)
		return false;
	switch (choice)
	{
	case 1:
		system("cls");
		addMarket(MARKET_FILE);
		break;
	case 2:
		system("cls");
		searchMarket(MARKET_FILE);
		break;
	case 3:
		system("cls");
		alterMarket(MARKET_FILE);
		break;
	case 4:
		system("cls");
		deleteMarket(MARKET_FILE);
		break;
	case 5:
		system("cls");
		traverseMarket(MARKET_FILE);
		break;
	default:
		break;
	}
	return true;
}