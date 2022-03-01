#ifndef ARRAY_UNSORTED_LIST_H
#define ARRAY_UNSORTED_LIST_H

#include "UnsortedList.h"

using namespace std;

// An array-based implementation of the unsorted list ADT
template <class ItemType>
class ArrayUnsortedList: public UnsortedList<ItemType> {
    public:
        // Constructor: Initialize the list to a maximum size
        ArrayUnsortedList(int maxSize) {
            this->maxSize = maxSize;
            this->size = 0;
            this->items = new ItemType[maxSize];
        }

        virtual void PutItem(ItemType item) {
            // Put the item at the end of the list
            this->items[this->size] = item;

            // Increment the size counter
            this->size++;
        }

        virtual ItemType GetItem(ItemType item) {
            // Look for the item
            for (int i = 0; i < this->size; i++) {
                if (this->items[i] == item) {
                    // If we found it, return the item
                    return this->items[i];
                }
            }

            // We didn't find it.
            throw NotFoundException();
        }

        virtual void RemoveItem(ItemType item) {
            int i = 0;

            // Look for the item to remove. Per the specification, this
            // function assumes the item is contained in the list.
            for (i = 0; i < this->size; i++) {
                if (this->items[i] == item) {
                    // We found it
                    break;
                }
            }

            // Remove the item we found by overwriting it by the item at the
            // end of the list.
            this->items[i] = this->items[this->size-1];
            this->size--;
        }
        
        virtual int GetLength() {
            return size;
        }

        virtual void ResetList() {
            currentItem = -1;
        }

        virtual ItemType GetNextItem() {
            currentItem++;
            return items[currentItem];
        }

    private:
        int maxSize;
        int size;
        ItemType *items;
        int currentItem;
};

#endif