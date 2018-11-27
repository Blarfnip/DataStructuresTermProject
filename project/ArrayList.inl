//
// Created by Saul on 10/16/2018.
//

#include "ArrayList.h"

template <class T>
void ArrayList<T>::doubleCapacity() {
    currCapacity *= 2;
    T* doubledArray = new T[currCapacity];
    for(int i = 0; i < currItemCount; i++) {
        doubledArray[i] = array[i];
    }
    delete[] array;
    array = doubledArray;
}

template <class T>
ArrayList<T>::ArrayList(int initialCapacity){
    if(initialCapacity < 1) {
        throw std::invalid_argument("Initial capacity must be greater than 0");
    }
    array = new T[initialCapacity];
    currCapacity = initialCapacity;
    currItemCount = 0;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arrayListToCopy) {
    array = new T[arrayListToCopy.currCapacity];
    currCapacity = arrayListToCopy.currCapacity;
    currItemCount = arrayListToCopy.currItemCount;
    for(int i = 0; i < currItemCount; i++) {
        array[i] = arrayListToCopy.array[i];
    }
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayListToCopy) {
    if(&arrayListToCopy == this) {
        return *this;
    }

    delete[] array;
    array = new T[arrayListToCopy.currCapacity];
    currCapacity = arrayListToCopy.currCapacity;
    currItemCount = arrayListToCopy.currItemCount;
    for(int i = 0; i < currItemCount; i++) {
        array[i] = arrayListToCopy.array[i];
    }

    return *this;
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete[] array;
}

template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd) {
    if(currItemCount + 1 > currCapacity) {
        doubleCapacity();
    }
    array[currItemCount] = itemToAdd;
    currItemCount++;
}

template <class T>
T ArrayList<T>::getValueAt(int index) {
    if(index < 0 || index >= currItemCount) {
        throw std::out_of_range("Invalid index");
    }
    return array[index];
}

template <class T>
std::string ArrayList<T>::toString() {
    return "Not implemented";//::toString(array, currItemCount);
}

template <class T>
bool ArrayList<T>::isEmpty() {
    return currItemCount < 1;
}

template <class T>
int ArrayList<T>::itemCount() {
    return currItemCount;
}

template <class T>
void ArrayList<T>::clearList() {
    currItemCount = 0;
}
//
//template <class T>
//int ArrayList<T>::find(T itemToFind) {
//    return ::find(array, currItemCount, itemToFind);
//}
//
//template <class T>
//int ArrayList<T>::findLast(T itemToFind) {
//    return ::findLast(array, currItemCount, itemToFind);
//}

template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd) {
    if(currItemCount + 1 > currCapacity) {
        doubleCapacity();
    }
    currItemCount++;
    T nextNum = itemToAdd;
    for(int i = 0; i < currItemCount; i++) {
        T temp = array[i];
        array[i] = nextNum;
        nextNum = temp;
    }
}

template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index) {
    if(currItemCount + 1 > currCapacity) {
        doubleCapacity();
    }
    if(index < 0 || index > currItemCount) {
        throw std::out_of_range("Invalid index");
    }

    currItemCount++;
    T nextNum = itemToAdd;
    for(int i = index; i < currItemCount; i++) {
        T temp = array[i];
        array[i] = nextNum;
        nextNum = temp;
    }
}

template <class T>
T ArrayList<T>::removeValueAtEnd() {
    if(currItemCount < 1) {
        throw std::out_of_range("No values available to remove");
    }
    T output = array[currItemCount - 1];
    currItemCount--;
    return  output;
}

template <class T>
T ArrayList<T>::removeValueAtFront() {
    if(currItemCount < 1) {
        throw std::out_of_range("No values available to remove");
    }
    T output = array[0];
    for(int i = 0; i < currItemCount - 1; i++) {
        array[i] = array[i + 1];
    }
    currItemCount--;
    return output;
}

template <class T>
T ArrayList<T>::removeValueAt(int index) {
    if(currItemCount < 1) {
        throw std::out_of_range("No values available to remove");
    }
    T output = array[index];
    for(int i = index; i < currItemCount - 1; i++) {
        array[i] = array[i + 1];
    }
    currItemCount--;
    return(output);
}

