#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Logs.h"
/*
Текущее состояние задачи
*/
enum EclientWorkState
{
	notStarted,							// 0. Не начата
	inProgress_Payed,				// 1. В процессе и Оплачено
	inProgress_notPayed,		// 2. В процессе и НЕ оплачено
	completed_notPayed,			// 3. Завершена и НЕ оплачено
	completed_Payed,				// 4. Завершена и оплачено
	statesCounter						// 5. Количество состояний задачи
};

class Client
{
private:
	std::string ID = "";                        // ID телеграмма пользователя или его номер
	int payment = 0;														// Цена за работу
	int timeElapsed_minutes = 0;								// Затраченное время в минутах
	EclientWorkState workState = notStarted;		// Статус задачи
	std::string workInfo = "";                  // Описание задачи
	int numberInTable = 0;											// Номер в таблице [Присваеывается автоматически]
	std::string workComment = "";								// Комментарий к задаче [Пуст по умолчанию]
	
public:
	//Конструкторы
	Client() {};

	Client(std::string ID, int payment, int timeElapsed_minutes, EclientWorkState workState, std::string workInfo, int numberInTable)
		: ID(ID), payment( payment ), timeElapsed_minutes( timeElapsed_minutes ), workState( workState ), workInfo( workInfo ), numberInTable( numberInTable )
	{
		std::string toLog  = "[DEBUG] Клиент добавлен: " + ID + " " + std::to_string( payment ) + " "
			+ std::to_string( timeElapsed_minutes ) + " " + std::to_string( workState ) + " " + workInfo + " " 
			+ std::to_string( numberInTable ) + " " + workComment + "\n";

		printLog(toLog);
	};

	///Геттеры
	//получить ID телеграмма пользователя или его номер
	std::string get_ID() const;
	//получить цену за работу
	int get_payment() const;
	//получить затраченное время в минутах
	int get_timeElapsed_minutes() const; 
	//получить статус задачи
	EclientWorkState get_workState() const;
	//получить описание задачи
	std::string get_workInfo() const;
	//получить номер в таблице
	int get_numberInTable() const;
	//получить комментарий к задаче
	std::string get_workComment() const;

	///Сеттеры
	//задать ID телеграмма пользователя или его номер
	void set_ID();
	void set_ID( std::string ID );
	//задать цену за работу
	void set_payment();
	void set_payment( int payment );
	//задать затраченное время в минутах
	void set_timeElapsed_minutes();
	void set_timeElapsed_minutes( int timeElapsed_minutes );
	//задать статус задачи
	void set_workState();
	void set_workState( EclientWorkState workState );
	//задать описание задачи
	void set_workInfo();
	void set_workInfo( std::string workInfo );
	//задать комментарий к задаче
	void set_workComment();
	void set_workComment( std::string workComment );
	//Задаётся номер в табличке
	void set_numberInTable(int number);
};

