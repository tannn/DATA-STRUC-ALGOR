/**
 * Our Quick Select
 * ourQuickSelect.cpp
 * Purpose: use Quick Select algorithm to find number of
 * comparisons needed to find a i-th smallest number
 *
 * @author Tanner Marino
 * @version 0.1 10/05/16
 */

#include <vector>
#include "csce310hw002pt01.h"
#include <cmath>
#include <iostream>

using namespace std;


/**
 *
 * @param i smallest number to be found
 * @param numbers a vector of unique integers
 * @return number of comparisons needed to find i-th smallest
 * number using Quick Select algorithm
 */
int ourQuickSelect( int i , vector<int> numbers ) {

    vector<int> smaller;
    vector<int> larger;
    int count = 0;
    int pivot = numbers[0];

    for (int i = 1; i < numbers.size(); i++) {

        if (numbers[i] < pivot)
            smaller.push_back(numbers[i]);
        else
            larger.push_back(numbers[i]);
        count++;
    }

    if (smaller.size() <= 1 && larger.size() <= 1) {
        return count;
    } else if (smaller.size() >= i) {
        return ourQuickSelect(i, smaller) + count;
    } else {
        i -= 1 + smaller.size();
        if (i <= 0) {
            return count;
        }
        return ourQuickSelect(i, larger) + count;
    }
}