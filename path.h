#ifndef PATH_H
#define PATH_H
#include "ant.h"

using namespace std;

class Path
{
	size_t distance = 0;
	size_t pathCost = 0;
	vector<size_t> customerList = { 0 };
public:
	void addCustomer(size_t custID);
};

#endif
