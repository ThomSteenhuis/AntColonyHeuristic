#ifndef MAIN_H
#define MAIN_H
#include "customer.h"
#include "ant.h"
#include "path.h"

size_t instanceIndex;
size_t nrCommodities;
size_t nrCustomers;
size_t vehicleCap;
size_t travelCap;
size_t costParameter;
vector<vector<double>> coordinatesMatrix;
vector<vector<double>> distanceMatrix;
vector<size_t> commodityWeight;
vector<size_t> commodityCost;
vector<size_t> initialInv;
vector<Customer> customerArray;
vector<Ant> antArray;

#endif