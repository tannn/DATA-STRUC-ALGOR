/**
 * Number of Digits
 * numberOfDigits.cpp
 * Purpose: return the number of digits in a number
 *
 * @author Tanner Marino
 * @version 0.1 10/05/16
 */

#include "numberOfDigits.h"
#include <iostream>

using namespace std;

unsigned long long int numberOfDigits( unsigned long long int digits ){
    unsigned long long int length = to_string(digits).length();
    char buffer[length];
    unsigned long long int totalLength = sprintf(buffer, "%ld", (long) digits);
  return totalLength;
}