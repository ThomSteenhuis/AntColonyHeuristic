#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
using namespace std;

class Customer
{
	size_t customerID;
	vector<int> customerLoad;
	size_t loadContribution = 0;
public:
	void setID(size_t custID);
	size_t getID();
	void setLoads(vector< vector<double> > &data, size_t nrComs);
	vector<int> getLoads();
	size_t getLoadContribution();
	void setLoadContribution();
};

#endif