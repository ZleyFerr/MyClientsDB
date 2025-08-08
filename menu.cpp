#include "menu.h"

//Консольное меню
void menuStart()
{
	bool isMenu = true;

	while (isMenu)
	{
		system("cls");
		std::cout << "Главное меню программы.\nВведите тот пункт меню, который хотите выбрать:\n"
			<< "0. Выход из программы.\n"
			<< "1. Добавить клиента\n";
		int choice_point = -1;
		std::cin >> choice_point;

		switch (choice_point)
		{
		case 0:
		{
			system("cls");
			const std::string toLog_0 = "[INFO] Программа закрыта.\n";
			printLog(toLog_0);
			isMenu = false;
			break;
		}
		case 1:
		{
			system("cls");
			const std::string toLog_1 = "[INFO] Выбрано добавление клиента в список.\n";
			printLog(toLog_1);
			addClientToDB();
			break;
		}
		default:
			system("cls");
			const std::string toLog_default = "[INFO] Неверный пункт меню был введён.\n";
			printLog(toLog_default);
			break;
		}
	}

}
