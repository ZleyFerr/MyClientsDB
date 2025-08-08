#include "DataBase_csv.h"

//Z_DB - пространство имён для работы с базой данных Zwork
namespace Z_DB
{
	const std::string DB_name = "zwrk_data.csv";
	std::fstream dataBase;
	int ClientCounter = -1;
}
std::vector<Client> clients;


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
			point = "";
			points.clear();
		}
		else if ( points[3] == "inProgress_notPayed" )	
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), inProgress_notPayed, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
			point = "";
			points.clear();
		}
		else if ( points[3] == "completed_notPayed" )
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), completed_notPayed, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
			point = "";
			points.clear();
		}
		else if ( points[3] == "completed_Payed" )
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), completed_Payed, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
			point = "";
			points.clear();
		}
		else
		{
			Client client( points[0], std::stoi(points[2]), std::stoi(points[4]), notStarted, points[1], Z_DB::ClientCounter++ );
			clients.push_back(client);
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

//Добавленик клиента в ДатаБазу
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
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "notStarted" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			in.close();
		}
		else if ( client.get_workState() == inProgress_Payed )
		{
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "inProgress_Payed" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			in.close();
		}
		else if ( client.get_workState() == inProgress_notPayed )
		{
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "inProgressnot_notPayed" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			in.close();
		}
		else if ( client.get_workState() == completed_notPayed )
		{
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "completed_notPayed" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			in.close();
		}
		else 
		{
			in << client.get_ID() << "," << client.get_workInfo() << "," << client.get_payment() << "," << "completed_Payed" << "," << client.get_timeElapsed_minutes() << "\n";
			std::string toLog = "[INFO] Клиент был добавлен в файл.\n";
			printLog(toLog);
			in.close();
		}

	}
	else
	{
		std::string toLog = "[ERROR] Клиент не был добавлен. Файл закрыт.\n";
		printLog(toLog);
	}
}
