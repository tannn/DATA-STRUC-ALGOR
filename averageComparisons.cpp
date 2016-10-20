/**
 * Average Comparisons
 * averageComparisons.cpp
 * Purpose: find average number of comparisons needed to find element using binary search
 *
 * @author Tanner Marino
 * @version 0.1 10/05/16
 */

#include <vector>
#include "averageComparisons.h"
#include <iostream>

using namespace std;

/**
 *
 * @param number a vector of integers
 * @return average number of comparisons required to successfully
 * find an element in the vector using binary search
 */
double averageComparisons( vector<int> number ){
    double comparisons = 0;
    
    for (int i = 0; i < number.size(); i++) {
        int min = 0;
        int max = number.size() - 1;
        int guess = (min + max) / 2;
        
        while (number[guess] != number[i]) {
            comparisons++;
            if (number[guess] < number[i]) {
                min = guess + 1;
            } else {
                max = guess - 1;
            }
            
            guess = (min + max) / 2;
        }
    }
    return comparisons / number.size() + 1;
}
