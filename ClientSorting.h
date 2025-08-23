#pragma once
#include "Client.h"
#include <algorithm>
#include "DataBase_TopCreator.h"

bool sort_by_payment(const Client a, const Client b);
bool sort_by_ID(const Client a, const Client b);
bool sort_by_timeElapsedMinutes(const Client a, const Client b);
bool sort_by_amount(const amountOfOrdersTop a, const amountOfOrdersTop b);
bool sort_by_payment_top(const paymentTop a, const paymentTop b);
bool sort_by_timeElapsed_top(const timeElapsedTop a, const timeElapsedTop b);
