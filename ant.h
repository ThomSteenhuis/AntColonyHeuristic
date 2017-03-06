#ifndef ANT_H
#define ANT_H

#include <vector>
using namespace std;
class Path;

class Ant
{
	size_t antID;
	size_t nrPaths = 0;
	bool feasible;
	vector<bool> customerList;
	size_t currentCost = 0;
	size_t currentCustomer = 0;
	size_t totalDistance = 0;
	vector<Path> pathArray;

public:
	void setAntId(size_t ID);
	size_t getAntId();

	void initializeCustomerList(size_t nrCust);			//First time initialization, depot is set to 0
	void setCustomer(size_t custID, bool change);		//To change whether we can move to a certain customer
	vector<bool> getCustomerList();
};

#endif