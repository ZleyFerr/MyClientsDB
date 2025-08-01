#include <windows.h>
#include "Client.h"

int main()
{
	createLogFile();

	//Локализация
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ru");


	int ClientCounter = 0;

	Client client_1( "@Test", 1000, 60, inProgress_notPayed, "V16 - N13", ClientCounter++ );

	client_1.set_workState();
	client_1.get_workState();

}
