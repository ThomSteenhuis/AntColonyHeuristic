#include "customer.h"

using namespace std;

void Customer::setID(size_t custID)
{
	customerID = custID;
}

size_t Customer::getID()
{
	return customerID;
}

void Customer::setLoads(vector< vector<double> > &data, size_t nrComs)
{
	for (size_t idx = 0; idx < nrComs; ++idx)
		customerLoad.push_back(data[0][6 + (3 * nrComs) + 3 + 3 + idx + ((customerID - 1) * (nrComs + 3))]);
}

vector<int> Customer::getLoads()
{
	return customerLoad;
}

size_t Customer::getLoadContribution()
{
	return loadContribution;
}

void Customer::setLoadContribution()
{
	for (size_t idx = 0; idx < customerLoad.size(); ++idx)
	{
		if (customerLoad[idx] < 0)
			loadContribution = loadContribution - customerLoad[idx];
	}
}
