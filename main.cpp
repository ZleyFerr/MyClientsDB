#include "menu.h"

int main()
{
	createLogFile(); //Создание файла логов
	setupDB(); // Начало работы с базой данных
	menuStart();
}
