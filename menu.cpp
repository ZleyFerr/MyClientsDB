#include "menu.h"

//���������� ����
void menuStart()
{
	bool isMenu = true;

	while (isMenu)
	{
		system("cls");
		std::cout << "������� ���� ���������.\n������� ��� ����� ����, ������� ������ �������:\n"
			<< "0. ����� �� ���������.\n"
			<< "1. �������� �������\n";
		int choice_point = -1;
		std::cin >> choice_point;

		switch (choice_point)
		{
		case 0:
		{
			system("cls");
			const std::string toLog_0 = "[INFO] ��������� �������.\n";
			printLog(toLog_0);
			isMenu = false;
			break;
		}
		case 1:
		{
			system("cls");
			const std::string toLog_1 = "[INFO] ������� ���������� ������� � ������.\n";
			printLog(toLog_1);
			addClientToDB();
			break;
		}
		default:
			system("cls");
			const std::string toLog_default = "[INFO] �������� ����� ���� ��� �����.\n";
			printLog(toLog_default);
			break;
		}
	}

}
