/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Thom
 *
 * Created on 23 februari 2017, 20:22
 */

#include <cstdlib>
#include <iostream>
#include "BinaryIndexedTree.h"

using namespace std;



/*
 * 
 */
int main(int argc, char** argv) {

    BinaryIndexedTree test = BinaryIndexedTree(5);
    test.SetValue(0,-9);
    test.SetValue(1,3);
    test.SetValue(2,-2);
    test.SetValue(3,4);
    test.SetValue(4,-11);
    
    cout << "Depth: " << test.GetDepth() << "\n";
    cout << "Value 0: " << test.GetValue(0) << "\n";
    cout << "Value 1: " << test.GetValue(1) << "\n";
    cout << "Value 2: " << test.GetValue(2) << "\n";
    cout << "Value 3: " << test.GetValue(3) << "\n";
    cout << "Value 4: " << test.GetValue(4) << "\n";
    cout << "Minimum: " << test.GetTopValue() << "\n";
  
    return 0;
}

