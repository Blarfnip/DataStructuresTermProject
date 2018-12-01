//
// Created by Toby Dragon on 9/30/16.
//

#ifndef COMP220_LIST_H
#define COMP220_LIST_H

#include <stdexcept>
#include <string>

template <class T>
class List {
private:
    //Private to disable copying and assigning from outside class, don't implement these methods
    List<T>(const List<T>& listToCopy);
    List& operator=(const List<T>& listToCopy);

public:
    //constructor
    List<T>() {}

    //Destructor
    virtual ~List<T>() {}

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    virtual void insertAtEnd(T itemToAdd)=0;

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual T getValueAt(int index)=0;

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    virtual std::string toString()=0;

    /**
     * checks if there are any valid items in the list
     * @return true if there are no valid items in the list, false otherwise
     */
    virtual bool isEmpty()=0;

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    virtual int itemCount()=0;

    /**
     * makes the list empty of valid items
     * @post the list is empty, such that isEmpty() == true
     */
    virtual void clearList()=0;
//
//    /**
//     * Searches an int array for a certain value
//     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
//     */
//    virtual int find(T numToFind)=0;
//
//    /**
//     * Searches an int array for a certain value
//     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
//     */
//    virtual int findLast(T numToFind)=0;

    /**
     * appends the new item to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    virtual void insertAtFront(T itemToAdd)=0;

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    virtual void insertAt(T itemToAdd, int index)=0;

    /**
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    virtual T removeValueAtEnd()=0;

    /**
     * removes the item at the front of the list, and returns a copy of that item
     * @post the item at the front is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if there is no item to remove
     */
    virtual T removeValueAtFront()=0;

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual T removeValueAt(int index)=0;

};


#endif //COMP220_LIST_H
