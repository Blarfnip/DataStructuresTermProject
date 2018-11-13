//
// Created by Saul on 10/2/2018.
//
#include <stdexcept>
#include <cmath>
#include <iostream>
#include "../220-lab-05/ArrayLib.h"

int genRandInt(int min, int max, int& numLinesRun)  {
    if(min > max) {
        int temp = max;
        max = min;
        min = temp;
    }

    if(min == max) {
        return min;
    }

    //Forces inclusion
    if(abs(min) > abs(max)) {
        min--;
    } else if(abs(min) < abs(max)){
        max++;
    } else {
        min--;
        max++;
    }

    numLinesRun += 17;
    //Generates and returns random number
    return (int)((rand() * 1.0 / RAND_MAX) * (max - min) + min);
}

int* genRandArray(int size, int min, int max, int& numLinesRun) {
    int* newArray = new int[size];
    numLinesRun += 9;
    for(int i = 0; i < size; i++) {
        newArray[i] = genRandInt(min, max, numLinesRun);
        numLinesRun++;
    }
    return newArray;
}

std::string toString(const int* arrayPtr, int size) {
    std::string output = "{";
    for(int i = 0; i < size; i++) {
        output += std::to_string(arrayPtr[i]);
        output += (i == size - 1) ? "" : ", ";
    }
    output += "}";
    return output;
}

int find(const int* const arrayPtr, const int size, const int numToFind, const int index, int& numLinesRun) {
    numLinesRun += 5;
    if(size <= 0) {
        numLinesRun += 2;
        return -1;
    } else if(arrayPtr[0] == numToFind) {
        numLinesRun += 2;
        return index;
    } else {
        numLinesRun += 1;
        return find(arrayPtr + 1, size - 1, numToFind, index+1, numLinesRun); //tail recursion
    }
}

int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun) {
    return find(arrayPtr, size, numToFind, 0, numLinesRun);
}

int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun) {
    numLinesRun += 4;
    if(size <= 0) {
        numLinesRun += 2;
        return -1;
    } else if(arrayPtr[size - 1] == numToFind) {
        numLinesRun += 2;
        return size - 1;
    } else {
        numLinesRun += 1;
        return findLast(arrayPtr, size - 1, numToFind, numLinesRun);//tail recursion
    }
}

int findMaxIndex(const int* const arrayPtr, const int size, const int maxIndex, int& numLinesRun) {
    numLinesRun += 4;
    if(size <= 0) {
        numLinesRun += 2;
        return maxIndex;
    } else {
        numLinesRun += 1;
        return findMaxIndex(arrayPtr, size - 1, arrayPtr[size - 1] >= arrayPtr[maxIndex] ? size - 1 : maxIndex, numLinesRun);//tail recursion
    }
}

int findMaxIndex(const int* const arrayPtr, const int size, int& numLinesRun) {
    if(size < 1) throw std::invalid_argument("Array size must be > 1");
    numLinesRun+= 4;
    return findMaxIndex(arrayPtr, size, size - 1, numLinesRun);//tail recursion
}

int* copyArray(const int* arrayToCopy, int size, int& numLinesRun) {
    if(size <= 0) {
        return nullptr;
    }

    int* outputArray = new int[size];
    for(int i = 0; i < size; i++) {
        (numLinesRun)++;
        outputArray[i] = arrayToCopy[i];
    }
    numLinesRun += 9;
    return outputArray;
}

int* genShuffledArray(int size, int& numLinesRun) {
    if(size <= 0) {
        return nullptr;
    }
    numLinesRun += 8;

    int pullListSize = size;
    int* pullList = new int[size];
    for(int i = 0; i < size; i++) {
        pullList[i] = i + 1;
        (numLinesRun)++;
    }

    int* output = new int[size];
    for(int i = 0; i < size; i++) {
        //Get number
        int pullIndex = genRandInt(0, pullListSize - 1, numLinesRun);
        output[i] = pullList[pullIndex];

        //Shift pull list
        for(int k = pullIndex; k < pullListSize - 1; k++) {
            pullList[k] = pullList[k + 1];
            (numLinesRun)++;
        }
        pullListSize--;
        numLinesRun += 6;
    }
    numLinesRun += 6;
    delete[] pullList;
    return output;
}

int countOccurrences(const int* arrayPtr, int size, int numToFind, int& numLinesRun) {
    int occurrennces = 0;
    for(int i = 0; i < size; i++) {
        if((arrayPtr[i]) == numToFind) {
            occurrennces++;
            (numLinesRun)++;
        }
        numLinesRun += 2;
    }
    numLinesRun += 9;
    return occurrennces;
}

//BUBBLE SORT
void sort(int* arrayToSort, int size, int& numLinesRun) {
    for(int i = 0; i < size; i++) {
        for(int k = 0; k < size; k++) {
            if(k < size - 1) {
                if(arrayToSort[k] >= arrayToSort[k+1]) {
                    int temp = arrayToSort[k];
                    arrayToSort[k] = arrayToSort[k+1];
                    arrayToSort[k+1] = temp;
                    numLinesRun += 4;
                }
                numLinesRun += 1;
            }
            numLinesRun += 2;
        }
        numLinesRun += 2;
    }
    numLinesRun += 3;
}

int binFindRec(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun, const int runningIndex = 0){//non-tail recursion
    if(size <= 1) { //Base case: size is only one. Returns the if the value is the found number or if it isn't there
        numLinesRun += 3;
        return arrayPtr[0] == numToFind ? runningIndex : -1;
    } else {
        const int newSize = (int)ceil(size / 2.0); //Splits size in two
        numLinesRun += 3;
        if(numToFind == arrayPtr[newSize - 1]) {
            return runningIndex + newSize - 1;
        }else if(numToFind < arrayPtr[newSize - 1]) { //Checks for if the number is in the first half of array
            return binFindRec(arrayPtr, newSize, numToFind, numLinesRun, runningIndex); //Recursively calls with the first half as parameters
        } else { //Second half of array
            return binFindRec(arrayPtr + ( newSize ), newSize - size % 2, numToFind, numLinesRun, runningIndex + newSize); //recursively calls with the second half as parameters
        }
    }
}

int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun) {
    return binFindRec(arrayPtr, size, numToFind, numLinesRun);
}

int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun) {
    int head1 = 0;
    int head2 = 0;
    int size = size1 + size2;
    int* copyArray = new int[size];

    if(size <= 0) {
        return nullptr;
    }
    numLinesRun += 10;

    for(int i = 0; i < size; i++) {
        if(a1[head1] <= a2[head2]) {
            if(head1 >= size1) {
                copyArray[i] = a2[head2];
                head2++;
                (numLinesRun) += 3;
            } else {
                copyArray[i] = a1[head1];
                head1++;
                (numLinesRun) += 3;
            }
            (numLinesRun) += 1;
        } else {
            if(head2 >= size2) {
                copyArray[i] = a1[head1];
                head1++;
                (numLinesRun) += 3;
            } else {
                copyArray[i] = a2[head2];
                head2++;
                (numLinesRun) += 3;
            }
            (numLinesRun) += 1;
        }
        (numLinesRun) += 1;
    }

    numLinesRun += 3;

    return copyArray;
}

int* mergeSort(const int* arrayToSort, int size, int& numLinesRun) {
    if(size < 1) {
        (numLinesRun) += 5;
        return nullptr;// new int[1] {arrayToSort[0]};
    } else if (size == 1) {
        return new int[1] {arrayToSort[0]};
    }

    int size1 = (int)floor(size / 2.0);
    int* subArray1 = copyArray(arrayToSort, size1, numLinesRun);
    int size2 = (int)ceil(size / 2.0);
    int* subArray2 = new int[size2];
    (numLinesRun) += 7;
    for(int k = size1, i = 0; k < size; k++, i++) {
        subArray2[i] = arrayToSort[k];
        (numLinesRun) += 1;
    }

    subArray1 = mergeSort(subArray1, size1, numLinesRun);
    subArray2 = mergeSort(subArray2, size2, numLinesRun);

    int* output = merge(subArray1, size1, subArray2, size2, numLinesRun);
    return output;
}