/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryIndexedTree.cpp
 * Author: Thom
 * 
 * Created on 24 februari 2017, 16:23
 */

#include "BinaryIndexedTree.h"
#include <cmath>
#include <iostream>

BinaryIndexedTree::BinaryIndexedTree() 
{
    depth = 1;
    values = new double[1];
}

BinaryIndexedTree::BinaryIndexedTree(int size) 
{
    depth = log2(size-0.1)+2;
    int dim = pow(2,depth)-1;
    values = new double[dim];
}

BinaryIndexedTree::~BinaryIndexedTree() 
{
    
}

bool BinaryIndexedTree::SetValue(int leaf,double value)
{
    if(leaf >= 0 && depth >= (int)((log2(leaf+0.9)+2)))
    {
        int index = pow(2,depth-1)-1+leaf;
        *(values+index) = value;
        
        AdjustBranch(leaf);
        
        return true;
    }
    else
    {
        return false;
    }
}

bool BinaryIndexedTree::AdjustBranch(int leaf)
{
    int level = depth;
    int branch = leaf;
    int index;
    int left;
    int right;
    
    while(level > 1)
    {
        level --;
        branch = branch/2;
        index = pow(2,level-1)-1+branch;
        left = pow(2,level)-1+branch*2;
        right = pow(2,level)+branch*2;
        *(values+index) = fmin(*(values+left),*(values+right));
    }
}

double BinaryIndexedTree::GetTopValue()
{
    return *values;
}

double BinaryIndexedTree::GetValue(int leaf)
{
    if(leaf >= 0 && depth >= (int)((log2(leaf+0.9)+2)))
    {
        int index = leaf+pow(2,depth-1)-1;
        return *(values+index);
    }
    else
    {
        return -1;
    }
}

int BinaryIndexedTree::GetDepth()
{
    return depth;
}

