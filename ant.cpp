#include "ant.h"

void Ant::setAntId(size_t ID)
{
	antID = ID;
}

size_t Ant::getAntId()
{
	return antID;
}

void Ant::initializeCustomerList(size_t nrCust)
{
	customerList.push_back(0);
	for (size_t idx = 0; idx < nrCust; ++idx)
		customerList.push_back(1);
}

void Ant::setCustomer(size_t custID, bool change)
{
	change == 1 ? customerList[custID] = 1: customerList[custID] = 0;
}

vector<bool> Ant::getCustomerList()
{
	return customerList;
}