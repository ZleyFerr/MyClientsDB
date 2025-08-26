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
			<< "1. Добавить клиента\n"
			<< "2. Вывести список клиентов\n"
			<< "3. Отсортировать список клиентов по цене заказа\n"
			<< "4. Отсортировать список клиентов по ID\n"
			<< "5. Отсортировать список клиентов по затраченному времени\n"
			<< "6. Узнать статиситику по ID\n"
			<< "7. Вывести топ клиентов по количеству заказов\n"
			<< "8. Вывести топ клиентов по затраченному времени\n"
			<< "9. Вывести топ клиентов по количеству прибыли\n"
			<< "10. Вывести всю статистику\n"
			<< "11. Вывести заработок в час\n"
			<< "12. Вывести общее количество заказов\n"
			<< "13. Вывести общее количество прибыли\n"
			<< "14. Вывести общее количество затраченного времени\n";
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
			std::cout << "Клиент добавлен.\n";
			menuWaitButton();
			break;
		}
		case 2:
		{
			system("cls");
			const std::string toLog_2 = "[INFO] Выбрано выведение списка клиентов на экран.\n";
			printLog(toLog_2);
			printDB();
			menuWaitButton();
			break;
		}
		case 3:
		{
			system("cls");
			const std::string toLog_3 = "[INFO] Выбрана сортировка списка [не исходного] клиентов по payment\n";
			printLog(toLog_3);
			sortDB_payment();
			menuWaitButton();
			break;
		}
		case 4:
		{
			system("cls");
			const std::string toLog_4 = "[INFO] Выбрана сортировка списка [не исходного] клиентов по ID\n";
			printLog(toLog_4);
			sortDB_ID();
			menuWaitButton();
			break;
		}
		case 5:
		{
			system("cls");
			const std::string toLog_5 = "[INFO] Выбрана сортировка списка [не исходного] клиентов по timeElapsedMinutes\n";
			printLog(toLog_5);
			sortDB_timeElapsed();
			menuWaitButton();
			break;
		}
		case 6:
		{
			system("cls");
			const std::string toLog_6 = "[INFO] Выбран вывод статистики по ID\n";
			printLog(toLog_6);
			findUserInDB();
			menuWaitButton();
			break;
		}
		case 7:
		{
			system("cls");
			const std::string toLog_7 = "[INFO] Выбран вывод топа клиентов по количеству заказов\n";
			printLog(toLog_7);
			amountTopPrint();
			menuWaitButton();
			break;
		}
		case 8:
		{
			system("cls");
			const std::string toLog_8 = "[INFO] Выбран вывод топа клиентов по затраченному времени\n";
			printLog(toLog_8);
			timeElapsedTopPrint();
			menuWaitButton();
			break;
		}
		case 9:
		{
			system("cls");
			const std::string toLog_9 = "[INFO] Выбран вывод топа клиентов по принесенной прибыли\n";
			printLog(toLog_9);
			paymentTopPrint();
			menuWaitButton();
			break;
		}
		case 10:
		{
			system("cls");
			const std::string toLog_10 = "[INFO] Выбран вывод всей статистики\n";
			printLog(toLog_10);
			findAllStatistics();
			menuWaitButton();
			break;
		}
		case 11:
		{
			system("cls");
			const std::string toLog_11 = "[INFO] Выбран вывод заработка в час\n";
			printLog(toLog_11);
			findFarmPerHour();
			menuWaitButton();
			break;

		}
		case 12:
		{
			system("cls");
			const std::string toLog_12 = "[INFO] Выбран вывод общего количества заказов\n";
			printLog(toLog_12);
			findTotalOrders();
			menuWaitButton();
			break;
		}
		case 13:
		{
			system("cls");
			const std::string toLog_13 = "[INFO] Выбран вывод общего количества прибыли\n";
			printLog(toLog_13);
			findTotalPayment();
			menuWaitButton();
			break;
		}
		case 14:
		{
			system("cls");
			const std::string toLog_14 = "[INFO] Выбран вывод общего количества затраченного времени\n";
			printLog(toLog_14);
			findTotalTime();
			menuWaitButton();
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

//Функция для ожидания нажатия клавиши, для продолжения
void menuWaitButton()
{
	system("pause");
}
