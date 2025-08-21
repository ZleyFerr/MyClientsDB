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