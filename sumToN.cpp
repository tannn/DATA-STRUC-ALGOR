/**
 * Sum To N
 * sumToN.cpp
 * Purpose: returns whether there exists two integers in vector that sum to a given integer
 *
 * @author Tanner Marino
 * @version 0.1 10/05/16
 */

#include <vector>
#include "csce310hw002pt02.h"
#include <cmath>
#include <iostream>

using namespace std;

/**
 *
 * @param numbers a vector of integer values, in ascending order
 * @param sum integer value
 * @return will return true if sum of two unique values in vector sum to the integer value
 */
bool sumToN( vector<int> numbers , int sum ){
    for (int i = 0; i < numbers.size(); i ++) {
        for (int j = 1; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == sum)
                return true;
        }
    }
    return false;
}