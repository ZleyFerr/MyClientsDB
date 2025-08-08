#pragma once
#include "Client.h"

std::string Client::get_ID() const
{
	return ID;
}

int Client::get_payment() const
{
	return payment;
}

int Client::get_timeElapsed_minutes() const
{
	return timeElapsed_minutes;
}

EclientWorkState Client::get_workState() const
{
	std::cout << workState << "\n";
	return workState;
}

std::string Client::get_workInfo() const
{
	return workInfo;
}

int Client::get_numberInTable() const
{
	return numberInTable;
}

std::string Client::get_workComment() const
{
	return workComment;
}

void Client::set_ID() 
{
	std::cout << "\nTelegramm ID или номер: ";
	std::cin >> ID;
	std::string toLog = "[DEBUG] ID был изменён у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_ID( std::string ID ) 
{
	this->ID = ID;
	std::string toLog = "[DEBUG] ID был изменён у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_payment()
{
	std::cout << "\nПлата за услугу: ";
	std::cin >> payment;
	std::string toLog = "[DEBUG] Плата была изменена у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_payment( int payment )
{
	this->payment = payment;
	std::string toLog = "[DEBUG] Плата была изменена у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_timeElapsed_minutes()
{
	std::cout << "\nЗатраченное время (в минутах): ";
	std::cin >> timeElapsed_minutes;
	std::string toLog = "[DEBUG] Время было изменено у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_timeElapsed_minutes( int timeElapsed_minutes )
{
	this->timeElapsed_minutes = timeElapsed_minutes;
	std::string toLog = "[DEBUG] Время было изменено у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_workState()
{
	std::cout << "\nСтатус работы: \n"
		<< "0 - Не начат.\n"
		<< "1 - В процессе, оплачен.\n"
		<< "2 - В процессе, НЕ оплачен.\n"
		<< "3 - Завершён, НЕ оплачен.\n"
		<< "4 - Завершён, оплачен.\n"
		<< "Введите текущий этой задачи статус: ";
	short int workStateID = 0;
	std::cin >> workStateID;
	std::cin.ignore();


	switch ( workStateID )
	{
	case 0:
		workState = notStarted;
		break;
	case 1:
		workState = inProgress_Payed;
		break;
	case 2:
		workState = inProgress_notPayed;
		break;
	case 3:
		workState = completed_notPayed;
		break;
	case 4:
		workState = completed_Payed;
		break;
	default:
		break;
	}
	std::string toLog = "[DEBUG] Статус работы был изменён у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_workState( EclientWorkState workState )
{
	this->workState = workState;
	std::string toLog = "[DEBUG] Статус работы был изменён у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_workInfo()
{
	std::cout << "\nОписание работы: ";
	std::cin.ignore(100000, '\n');
	std::getline(std::cin, workInfo);
	std::string toLog = "[DEBUG] Описание работы было изменено у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_workInfo( std::string workInfo )
{
	this->workInfo = workInfo;
	std::string toLog = "[DEBUG] Описание работы было изменено у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_workComment()
{
	std::cout << "\nКомментарий к работе: ";
	std::cin.ignore(100000, '\n');
	std::getline(std::cin, workComment);
	std::string toLog = "[DEBUG] Комментарий к работе был изменён у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_workComment( std::string workComment )
{
	this->workComment = workComment;
	std::string toLog = "[DEBUG] Комментарий к работе был изменён у записи под номером " + std::to_string(numberInTable) + "\n";
	printLog(toLog);
}

void Client::set_numberInTable(int number)
{
	numberInTable = number;
	std::string toLog = "[DEBUG] номер был присвоен, номер записи: " + std::to_string(numberInTable) + "\n";
}
