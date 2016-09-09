#include "csce310hw001pt01.h"
#include <iostream>

using namespace std;

unsigned long long int numberOfDigits( unsigned long long int digits ){
    unsigned long long int length = to_string(digits).length();
    char buffer[length];
    unsigned long long int totalLength = sprintf(buffer, "%ld", (long) digits);
  return totalLength;
}