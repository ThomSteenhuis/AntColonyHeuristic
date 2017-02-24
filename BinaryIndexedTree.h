/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryIndexedTree.h
 * Author: Thom
 *
 * Created on 24 februari 2017, 16:23
 */

#ifndef BINARYINDEXEDTREE_H
#define BINARYINDEXEDTREE_H

class BinaryIndexedTree {
public:
    BinaryIndexedTree();
    BinaryIndexedTree(int size);
    virtual ~BinaryIndexedTree();
    bool SetValue(int leaf,double value);
    bool AdjustBranch(int leaf);
    double GetTopValue();
    double GetValue(int leaf);
    int GetDepth();
private:
    int depth;
    double *values;
};

#endif /* BINARYINDEXEDTREE_H */

