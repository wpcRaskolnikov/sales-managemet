#include "childWindow.h"
bool ChildWindow::form()
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

bool ChildWindow::childWindow1()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             ��Ա����             ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool ChildWindow::childWindow2()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             ��Ʒ����             ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool ChildWindow::childWindow3()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             �����̹���           ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool ChildWindow::childWindow4()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             �˿͹���             ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}

bool ChildWindow::childWindow5()
{
	system("cls"); /*����*/
	cout << "\t\t ===================================\n";
	cout << "\t\t��             ���۹���             ��\n";
	cout << "\t\t ===================================\n";
	form();
	return true;
}