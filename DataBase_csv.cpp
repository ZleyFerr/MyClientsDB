#include "DataBase_csv.h"

//Z_DB - пространство имён для работы с базой данных Zwork
namespace Z_DB
{
	const std::string DB_name = "zwrk_data.csv";
	std::fstream dataBase;
	int ClientCounter = -1;
}

//Список клиентов
std::vector<Client> clients;
//Список ID клиентов
std::set<std::string> clientsID;

//Топ клиентов по количеству заказов
std::vector<amountOfOrdersTop> amountOfOrdersIDtop;
//Топ клиентов по общей цене заказов
std::vector<paymentTop> paymentIDtop;
//Топ клиентов времени выполнения заказов
std::vector<timeElapsedTop> timeElapsedIDtop;

//Открытие файла датабазы
void openDB()
{
	Z_DB::dataBase.open(Z_DB::DB_name, std::ios::in | std::ios::out);
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (!Z_DB::dataBase.is_open())
	{
		std::string toLog = "[ERROR] Ошибка открытия файла.\n";
		printLog(toLog);
		return;
	}
	else
	{
		std::string toLog = "[INFO] Файл zwrk_data.csv открыт.\n";
		printLog(toLog);
	}
}

//Парсинг файла датабазы
void parseDB()
{
	std::string line;
	Z_DB::ClientCounter+=2;

	std::string toLogParse_start = "[INFO] Начало парсинга базы данных.\n";
	std::string toLogParse_end = "[INFO] Конец парсинга базы данных.\n";
	std::string toLogParse_info = "[INFO] ID payment Time Status Info NumberInTable Comment\n";
	
	printLog( toLogParse_start );
	printLog( toLogParse_info );

	while ( std::getline( Z_DB::dataBase, line ) )
	{

		std::string point;
		std::vector<std::string> points;
		std::stringstream word(line);

		while ( std::getline( word, point, ',' ) )
		{
			points.push_back(point);
		}

		if ( points[3] == "inProgress_Payed" )
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), inProgress_Payed, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
			clientsID.insert(client.get_ID());
			point = "";
			points.clear();
		}
		else if ( points[3] == "inProgress_notPayed" )	
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), inProgress_notPayed, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
			clientsID.insert(client.get_ID());
			point = "";
			points.clear();
		}
		else if ( points[3] == "completed_notPayed" )
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), completed_notPayed, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
			clientsID.insert(client.get_ID());
			point = "";
			points.clear();
		}
		else if ( points[3] == "completed_Payed" )
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), completed_Payed, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
			clientsID.insert(client.get_ID());
			point = "";
			points.clear();
		}
		else
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), notStarted, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
			clientsID.insert(client.get_ID());
			point = "";
			points.clear();
		}
	}
	printLog(toLogParse_end);
}

//Преднастройка датабазы при открытии программы
void setupDB()
{
	openDB();
	parseDB();
}

//Добавление клиента в Дб
void addClientToDB()
{
	Client client;
	client.set_numberInTable(Z_DB::ClientCounter++);
	client.set_ID();
	client.set_workInfo();
	client.set_payment();
	client.set_timeElapsed_minutes();
	client.set_workState();
	clients.push_back(client);
	std::string toLog = "[DEBUG] Клиент добавлен: " + client.get_ID() + " " + std::to_string(client.get_payment()) + " "
		+ std::to_string(client.get_timeElapsed_minutes()) + " " + std::to_string(client.get_workState()) + " " + client.get_workInfo() + " "
		+ std::to_string(client.get_numberInTable()) + " " + client.get_workComment() + "\n";
	printLog(toLog);

	Z_DB::dataBase.close();
	std::ofstream in(Z_DB::DB_name, std::ios::app);

	if ( in.is_open() )
	{
		if( client.get_workState() == notStarted )
		{
			in << "\n";
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "notStarted" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			clientsID.insert(client.get_ID());
			in.close();
		}
		else if ( client.get_workState() == inProgress_Payed )
		{
			in << "\n";
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "inProgress_Payed" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			clientsID.insert(client.get_ID());
			in.close();
		}
		else if ( client.get_workState() == inProgress_notPayed )
		{
			in << "\n";
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "inProgressnot_notPayed" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			clientsID.insert(client.get_ID());
			in.close();
		}
		else if ( client.get_workState() == completed_notPayed )
		{
			in << "\n";
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "completed_notPayed" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			clientsID.insert(client.get_ID());
			in.close();
		}
		else 
		{
			in << "\n";
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "completed_Payed" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			clientsID.insert(client.get_ID());
			in.close();
		}

	}
	else
	{
		std::string toLog = "[ERROR] Клиент не был добавлен. Файл закрыт.\n";
		printLog(toLog);
	}
}

//Вывод списка клиентов в консоль
void printDB()
{
	std::cout << "----------СПИСОК КЛИЕНТОВ--------------\n";
	for (auto i = 0; i < clients.size(); i++)
	{
		std::cout << i << " ID: " << clients[i].get_ID() << "\n"
			<< "цена услуги: " << clients[i].get_payment() << "\n"
			<< "времени затрачено: " << clients[i].get_timeElapsed_minutes() << "\n"
			<< "описание задачи: " << clients[i].get_workInfo() << "\n";
		std::cout << "------------------------\n";
	}
	const std::string toLog = "[INFO] список клиентов успешно выведен.\n";
	printLog(toLog);
}

//Сортировка ДБ по ID
void sortDB_ID()
{
	std::sort(clients.begin(), clients.end(), sort_by_ID);
	const std::string toLog = "[INFO] Сортировка ДБ [не исходной] по ID успешно выполнена.\n";
	printLog(toLog);
	std::cout << "ДБ отсортирована по ID [min -> max]\n";
}

//Сортировка ДБ по затраченному времени
void sortDB_timeElapsed()
{
	std::sort(clients.begin(), clients.end(), sort_by_timeElapsedMinutes);
	const std::string toLog = "[INFO] Сортировка ДБ [не исходной] по затраченному времени успешно выполнена.\n";
	printLog(toLog);
	std::cout << "ДБ отсортирована по затраченному времени [min -> max]\n";
}

//Сортировка ДБ по цене заказа
void sortDB_payment()
{
	std::sort(clients.begin(), clients.end(), sort_by_payment);
	const std::string toLog = "[INFO] Сортировка ДБ [не исходной] по цене заказа успешно выполнена.\n";
	printLog(toLog);
	std::cout << "ДБ отсортирована по цене заказа [min -> max]\n";
}

//Поиск статистики юзера в ДБ по айди
void findUserInDB()
{
	std::string ID_ForFind = "";
	std::cout << "ID для поиска [@ можно упустить]: ";
	std::cin >> ID_ForFind;

	std::string toLogFind1 = "[INFO] ID введеный пользователем: " + ID_ForFind + "\n";
	printLog(toLogFind1);

	bool is_ID_in_DB = false;
	std::string ID_temp = "@" +  ID_ForFind;
	if ((std::find(clientsID.begin(), clientsID.end(), ID_ForFind) != clientsID.end()) || (std::find(clientsID.begin(), clientsID.end(), ID_temp) != clientsID.end())) is_ID_in_DB = true;
	if(is_ID_in_DB)
	{
		int TimeElapsed_IDForFind = 0;
		int payment_IDForFind = 0;
		int amountOfOrders_IDForFind = 0;

		if (ID_ForFind[0] == '@')
		{
			for (int i = 0; i < clients.size(); i++)
			{
				if (clients[i].get_ID() == ID_ForFind)
				{
					amountOfOrders_IDForFind++;
					payment_IDForFind += clients[i].get_payment();
					TimeElapsed_IDForFind += clients[i].get_timeElapsed_minutes();
				}
			}
			std::cout << "ID: " << ID_ForFind << "\n"
				<< "Общая сумма: " << payment_IDForFind << "\n"
				<< "Времени затрачено всего: " << TimeElapsed_IDForFind << "\n"
				<< "Количество заказов: " << amountOfOrders_IDForFind << "\n";

			const std::string toLogSuccess = "[INFO] Информация о пользователе выведена в консоль.\n";
			printLog(toLogSuccess);
		}

		else if (ID_ForFind[0] != '@')
		{
			std::string tempClientID = "@" + ID_ForFind;
			
			for (int i = 0; i < clients.size(); i++)
			{
				if (clients[i].get_ID() == tempClientID)
				{
					amountOfOrders_IDForFind++;
					payment_IDForFind += clients[i].get_payment();
					TimeElapsed_IDForFind += clients[i].get_timeElapsed_minutes();
				}
			}
			std::cout << "ID: " << ID_ForFind << "\n"
				<< "Общая сумма: " << payment_IDForFind << "\n"
				<< "Времени затрачено всего: " << TimeElapsed_IDForFind << "\n"
				<< "Количество заказов: " << amountOfOrders_IDForFind << "\n";

			const std::string toLogSuccess = "[INFO] Информация о пользователе выведена в консоль.\n";
			printLog(toLogSuccess);
		}
	}
	else
	{
		std::cout << "ID введенный вами не был найден в БД\n";
		const std::string toLog = "[INFO] ID введеный пользователем не был найден в БД\n";
		printLog(toLog);
	}
}

//Заполнение топов по определенным параметрам
void topsFill()
{
	for (int i = 0; i < clientsID.size(); i++)
	{
		amountOfOrdersTop amountObj;
		paymentTop paymentObj;
		timeElapsedTop timeElapsedObj;
		amountOfOrdersIDtop.push_back(amountObj);
		paymentIDtop.push_back(paymentObj);
		timeElapsedIDtop.push_back(timeElapsedObj);
	}

	for (int i = 0; i < clients.size(); i++)
	{

	}
}



