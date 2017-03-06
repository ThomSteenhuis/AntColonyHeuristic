#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>
#include <chrono>
#include <string>
#include <iterator>
#include <cmath>

using namespace std;

#include "main.h"

double distance(size_t cust1, size_t cust2)
{
	double temp = pow((coordinatesMatrix[cust2][0] - coordinatesMatrix[cust1][0]), 2) + pow((coordinatesMatrix[cust2][1] - coordinatesMatrix[cust1][1]), 2);
	double distance = sqrt(temp);
	return distance;
}

void constructDistanceMatrix(vector< vector<double> > &data)
{
	for (size_t idx1 = 0; idx1 < nrCustomers; ++idx1)
	{
		vector<double> temp;
		distanceMatrix.push_back(temp);
		for (size_t idx2 = 0; idx2 < nrCustomers; ++idx2)
		{
			distanceMatrix[idx1].push_back(distance(idx1,idx2));
		}
	}
}

int main()
{
	//Data input
	ifstream inputData;												//Object to perform input operations on
	inputData.open("inputfile.txt");
	vector< vector<double> > instanceData;							//Matrix to store instance data
		
	string temp;													//Read the data line by line, and store in matrix
	while (getline(inputData, temp)) {
		istringstream buffer(temp);
		vector<double> line{ istream_iterator<double>(buffer),
			istream_iterator<double>() };
		instanceData.push_back(line);
	}
	
	//Data for one instance
	instanceIndex = instanceData[0][0];
	nrCustomers = instanceData[0][1];
	nrCommodities = instanceData[0][2];
	vehicleCap = instanceData[0][3];
	travelCap = instanceData[0][4];
	costParameter = instanceData[0][5];

	for (size_t idx = 0; idx < nrCommodities; ++idx)									//Initialize commodity weights
		commodityWeight.push_back(instanceData[0][6 + idx]);

	for (size_t idx = 0; idx < nrCommodities; ++idx)									//Initialize commodity cost of inventory
		commodityCost.push_back(instanceData[0][6 + nrCommodities + idx]);

	for (size_t idx = 0; idx < nrCommodities; ++idx)									//Initialize initial depot inventory
		initialInv.push_back(instanceData[0][6 + (2 * nrCommodities) + 3 + idx]);		

	Customer depot;
	depot.setID(0);
	depot.setLoads(instanceData, nrCommodities);
	customerArray.push_back(depot);

	for (size_t idx = 0; idx < nrCustomers; ++idx)										//Initialize customers and set IDs/loads
	{
		Customer tempCustomer;
		tempCustomer.setID(instanceData[0][6 + (3 * nrCommodities) + 3 + (idx * 5)]);
		tempCustomer.setLoads(instanceData, nrCommodities);
		tempCustomer.setLoadContribution();
		customerArray.push_back(tempCustomer);
	}

	for (size_t idx1 = 0; idx1 < nrCustomers; ++idx1)			//Set coordinates and determine distances
	{
		vector <double> temp;
		coordinatesMatrix.push_back(temp);
		for (size_t idx2 = 0; idx2 < 2; ++idx2)
		{
			coordinatesMatrix[idx1].push_back(instanceData[0][6 + (2 * nrCommodities) + 1 + idx2 + (idx1 * (nrCommodities + 3))]);
		}
	}
	constructDistanceMatrix(coordinatesMatrix);

	//ANT COLONY START
	size_t nrAnts = 1;
	for (size_t idx = 0; idx < nrAnts; ++idx)
	{
		Ant temp;
		temp.setAntId(idx);
		antArray.push_back(temp);
	}

	for (size_t ant = 0; ant < nrAnts; ++ant)
	{

	}

	//TEST

	//Print distance matrix
	/*
	for (size_t idx1 = 0; idx1 < nrCustomers; ++idx1)
	{
		for (size_t idx2 = 0; idx2 < nrCustomers; ++idx2)
		{
			cout << distanceMatrix[idx1][idx2] << ' ';
		}
		cout << '\n';
	}
	*/

	getchar();
}