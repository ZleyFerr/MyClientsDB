#include <windows.h>
#include "Client.h"

int main()
{
	//Локализация
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ru");

	int ClientCounter = 0;

	Client client_1("@Test", 1000, 60, notStarted, "V16 - N13", ClientCounter++);
	std::cout << ClientCounter;
	client_1.set_ID("@User_001");
	std::cout << client_1.get_ID() << "\n";
	client_1.set_ID();
	std::cout << client_1.get_ID() << "\n";
	client_1.set_workState();
	std::cout << client_1.get_workState() << "\n";
}
