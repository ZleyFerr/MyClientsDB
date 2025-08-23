#include "ClientSorting.h"

bool sort_by_payment(const Client a, const Client b)
{
	return a.get_payment() < b.get_payment();
}

bool sort_by_ID(const Client a, const Client b)
{
	return a.get_ID() < b.get_ID();
}

bool sort_by_timeElapsedMinutes(const Client a, const Client b)
{
	return a.get_timeElapsed_minutes() < b.get_timeElapsed_minutes();
}

bool sort_by_amount(const amountOfOrdersTop a, const amountOfOrdersTop b)
{
	return a.amountOfOrders < b.amountOfOrders;
}

bool sort_by_payment_top(const paymentTop a, const paymentTop b)
{
	return a.payment < b.payment;
}

bool sort_by_timeElapsed_top(const timeElapsedTop a, const timeElapsedTop b)
{
	return a.timeElapsed < b.timeElapsed;
}
