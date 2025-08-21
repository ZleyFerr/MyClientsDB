#pragma once
#include "DataBase_csv.h"

void topsFill();
void amountTopPrint();
void paymentTopPrint();
void timeElapsedTopPrint();

struct amountOfOrdersTop
{
	std::string ID = "";
	int amountOfOrders = 0;
};

struct paymentTop
{
	std::string ID = "";
	int payment = 0;
};

struct timeElapsedTop
{
	std::string ID = "";
	int timeElapsed = 0;
};