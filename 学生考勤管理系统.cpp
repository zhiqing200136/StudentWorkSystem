#include<iostream>
#include "managersystem.h"

using namespace std;
int main()
{
	int choice = 0;
	managersystem ms;
	while (true)
	{
		ms.menu();
		cout << "����������ʵ�ֵĹ��ܣ�" << endl;
		cin >> choice;
		while (choice > 7 || choice < 1)
		{
			cout << "�����������������룺" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			ms.Add();
			break;
		}
		case 2:
		{
			ms.Search();
			break;
		}
		case 3:
		{
			ms.ShowMessage();
			break;
		}
		case 4:
		{
			ms.ChangeMessage();
			break;
		}
		case 5:
		{
			ms.DeleteMessage();
			break;
		}
		case 6:
		{
			ms.Count();
			break;
		}
		case 7:
		{
			ms.exitsystem();
			break;
		}
			
		}
		system("pause");
		system("cls");
	}
	return 0;
}