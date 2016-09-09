#include "csce310hw001pt02.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

void printPermutations( string word , int permutations ) {

    const int wordLength = word.size();

    char wordArray[wordLength + 1];
    strcpy(wordArray, word.c_str());

    //0 means arrow is pointing left, 1 means arrow is pointing right
    int* arrowDirection = new int[wordLength];

    char largestMobileElement = '0';
    int largestMobileElementPosition = 0;
    int largestMobileElementDirection = 0;

    cout << string(wordArray) << endl;
    for (int p = 1; p < permutations; p++) {
        //find largest mobile element
        for (int j = 0; j < wordLength; j++) {
            if (arrowDirection[j] == 0 && j!= 0) {
                if (wordArray[j] > largestMobileElement && wordArray[j] > wordArray[j-1]) {
                    largestMobileElement = wordArray[j];
                    largestMobileElementPosition = j;
                    largestMobileElementDirection = 0;
                }
            }
            if (arrowDirection[j] == 1 && j != wordLength - 1) {
                if (wordArray[j] > largestMobileElement && wordArray[j] > wordArray[j+1]) {
                    largestMobileElement = wordArray[j];
                    largestMobileElementPosition = j;
                    largestMobileElementDirection = 1;
                }
            }
        }

        //change arrow direction
        for (int j = 0; j < wordLength ; j++) {
            if (wordArray[j] > largestMobileElement) {
                arrowDirection[j] ^= 1;
            }
        }

        //swap position of characters and their corresponding arrows
        if (largestMobileElementDirection == 0) {
            swap(wordArray[largestMobileElementPosition], wordArray[largestMobileElementPosition - 1]);
            swap(arrowDirection[largestMobileElementPosition], arrowDirection[largestMobileElementPosition - 1]);
        } else {
            swap(wordArray[largestMobileElementPosition], wordArray[largestMobileElementPosition + 1]);
            swap(arrowDirection[largestMobileElementPosition], arrowDirection[largestMobileElementPosition + 1]);
        }

        //reset variables
        largestMobileElement = '0';
        largestMobileElementPosition = 0;
        largestMobileElementDirection = 0;

        cout << string(wordArray) << endl;
    }
    return;
}


int main() {
    printPermutations("cfmqy", 117);

}