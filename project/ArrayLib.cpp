//
// Created by Saul on 10/2/2018.
//
#include <stdexcept>
#include <cmath>
#include <iostream>
#include "ArrayLib.h"

int genRandInt(int min, int max)  {
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

    //Generates and returns random number
    return (int)((rand() * 1.0 / RAND_MAX) * (max - min) + min);
}

int* genRandArray(int size, int min, int max) {
    int* newArray = new int[size];
    for(int i = 0; i < size; i++) {
        newArray[i] = genRandInt(min, max);
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

int find(const int* const arrayPtr, const int size, const int numToFind, const int index) {
    if(size <= 0) {
        return -1;
    } else if(arrayPtr[0] == numToFind) {
        return index;
    } else {
        return find(arrayPtr + 1, size - 1, numToFind, index+1); //tail recursion
    }
}

int find(const int* arrayPtr, int size, int numToFind) {
    return find(arrayPtr, size, numToFind, 0);
}

int findLast(const int* arrayPtr, int size, int numToFind) {
    if(size <= 0) {
        return -1;
    } else if(arrayPtr[size - 1] == numToFind) {
        return size - 1;
    } else {
        return findLast(arrayPtr, size - 1, numToFind);//tail recursion
    }
}

int findMaxIndex(const int* const arrayPtr, const int size, const int maxIndex) {
    if(size <= 0) {
        return maxIndex;
    } else {
        return findMaxIndex(arrayPtr, size - 1, arrayPtr[size - 1] >= arrayPtr[maxIndex] ? size - 1 : maxIndex);//tail recursion
    }
}

int findMaxIndex(const int* const arrayPtr, const int size) {
    if(size < 1) throw std::invalid_argument("Array size must be > 1");
    return findMaxIndex(arrayPtr, size, size - 1);//tail recursion
}

int* copyArray(const int* arrayToCopy, int size) {
    if(size <= 0) {
        return nullptr;
    }

    int* outputArray = new int[size];
    for(int i = 0; i < size; i++) {
        outputArray[i] = arrayToCopy[i];
    }
    return outputArray;
}

int* genShuffledArray(int size) {
    if(size <= 0) {
        return nullptr;
    }

    int pullListSize = size;
    int* pullList = new int[size];
    for(int i = 0; i < size; i++) {
        pullList[i] = i + 1;
    }

    int* output = new int[size];
    for(int i = 0; i < size; i++) {
        //Get number
        int pullIndex = genRandInt(0, pullListSize - 1);
        output[i] = pullList[pullIndex];

        //Shift pull list
        for(int k = pullIndex; k < pullListSize - 1; k++) {
            pullList[k] = pullList[k + 1];
        }
        pullListSize--;
    }
    delete[] pullList;
    return output;
}

int countOccurrences(const int* arrayPtr, int size, int numToFind) {
    int occurrennces = 0;
    for(int i = 0; i < size; i++) {
        if((arrayPtr[i]) == numToFind) {
            occurrennces++;
        }
    }
    return occurrennces;
}

//BUBBLE SORT
void sort(int* arrayToSort, int size) {
    for(int i = 0; i < size; i++) {
        for(int k = 0; k < size; k++) {
            if(k < size - 1) {
                if(arrayToSort[k] >= arrayToSort[k+1]) {
                    int temp = arrayToSort[k];
                    arrayToSort[k] = arrayToSort[k+1];
                    arrayToSort[k+1] = temp;
                }
            }
        }
    }
}

int binFindRec(const int* const arrayPtr, const int size, const int numToFind, const int runningIndex = 0){//non-tail recursion
    if(size <= 1) { //Base case: size is only one. Returns the if the value is the found number or if it isn't there
        return arrayPtr[0] == numToFind ? runningIndex : -1;
    } else {
        const int newSize = (int)ceil(size / 2.0); //Splits size in two
        if(numToFind == arrayPtr[newSize - 1]) {
            return runningIndex + newSize - 1;
        }else if(numToFind < arrayPtr[newSize - 1]) { //Checks for if the number is in the first half of array
            return binFindRec(arrayPtr, newSize, numToFind, runningIndex); //Recursively calls with the first half as parameters
        } else { //Second half of array
            return binFindRec(arrayPtr + ( newSize ), newSize - size % 2, numToFind, runningIndex + newSize); //recursively calls with the second half as parameters
        }
    }
}

int binFind(const int* const arrayPtr, const int size, const int numToFind) {
    return binFindRec(arrayPtr, size, numToFind);
}

int* merge(const int*a1, int size1, const int* a2, int size2) {
    int head1 = 0;
    int head2 = 0;
    int size = size1 + size2;
    int* copyArray = new int[size];

    if(size <= 0) {
        return nullptr;
    }

    for(int i = 0; i < size; i++) {
        if(a1[head1] <= a2[head2]) {
            if(head1 >= size1) {
                copyArray[i] = a2[head2];
                head2++;
            } else {
                copyArray[i] = a1[head1];
                head1++;
            }
        } else {
            if(head2 >= size2) {
                copyArray[i] = a1[head1];
                head1++;
            } else {
                copyArray[i] = a2[head2];
                head2++;
            }
        }
    }

    return copyArray;
}

int* mergeSort(const int* arrayToSort, int size) {
    if(size < 1) {
        return nullptr;// new int[1] {arrayToSort[0]};
    } else if (size == 1) {
        return new int[1] {arrayToSort[0]};
    }

    int size1 = (int)floor(size / 2.0);
    int* subArray1 = copyArray(arrayToSort, size1);
    int size2 = (int)ceil(size / 2.0);
    int* subArray2 = new int[size2];
    for(int k = size1, i = 0; k < size; k++, i++) {
        subArray2[i] = arrayToSort[k];
    }

    subArray1 = mergeSort(subArray1, size1);
    subArray2 = mergeSort(subArray2, size2);

    int* output = merge(subArray1, size1, subArray2, size2);
    return output;
}