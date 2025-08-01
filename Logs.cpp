#include "Logs.h"
std::ofstream currentLogFile;

//Создания файла с логом
void createLogFile()
{

  std::time_t now = std::time(nullptr);
  struct tm tstruct;

  if (localtime_s(&tstruct, &now) != 0)
  {
    std::cerr << "Ошибка получения времени." << std::endl;
    return;
  }

  std::stringstream ss;
  ss << std::put_time(&tstruct, "%Y %m %d %H %M %S");
  std::string formattedTime;
  formattedTime = ss.str();

  std::string LogName_part1 = "Log [";
  std::string LogName_part2 = formattedTime;
  std::string LogName_part3 = "].txt";

  std::string LogFileName = LogName_part1 + LogName_part2 + LogName_part3;
  currentLogFile.open(LogFileName);
  currentLogFile << "Дата Время Действие\n";
}

//Вывод сообщения с временем
void printLog(std::string LogMessage)
{
  std::time_t now = std::time(nullptr);
  struct tm tstruct;

  if (localtime_s(&tstruct, &now) != 0)
  {
    std::cerr << "Ошибка получения времени." << std::endl;
    return;
  }

  std::stringstream ss;
  ss << std::put_time(&tstruct, "%Y-%m-%d %H:%M:%S");
  std::string formattedTime = ss.str();
  std::cout << "[" << formattedTime << "]: " << LogMessage;
  currentLogFile << "[" << formattedTime << "]: " << LogMessage;
}

//Вывод времени 
void printLog()
{
  std::time_t now = std::time(nullptr);
  struct tm tstruct;

  if (localtime_s(&tstruct, &now) != 0)
  {
    std::cerr << "Ошибка получения времени" << std::endl;
    return;
  }

  std::stringstream ss;
  ss << std::put_time(&tstruct, "%Y-%m-%d %H:%M:%S");
  std::string formattedTime = ss.str();
  std::cout << "[" << formattedTime << "] ";
  currentLogFile <<  "[" << formattedTime << "] ";
}
