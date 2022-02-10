#ifndef LIST_UNSORTED_LIST_H
#define LIST_UNSORTED_LIST_H

#include <cstddef>  // Required for NULL
#include "UnsortedList.h"

using namespace std;

// Linked list node type: maintains a value and a pointer
// to the next node
template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType *next;
};

// A linked list-based implementation of the unsorted list ADT
template <class ItemType>
class LinkedUnsortedList: public UnsortedList<ItemType> {
    public:
        // Constructor: Initialize an empty list
        LinkedUnsortedList() {
            listData = NULL;
            this->size = 0;
        }

        virtual void PutItem(ItemType item) {
            // Create a new linked list node
            NodeType<ItemType> *newItem = new NodeType<ItemType>;

            // The new node will become the first node in the list.
            // Set its value, then make the current first node
            // come after this one
            newItem->info = item;
            newItem->next = this->listData;
            this->listData = newItem;

            // Increment the size counter
            this->size++;
        }

        virtual ItemType GetItem(ItemType item) {
            // Look for the item using an iterator.
            NodeType<ItemType> *iterator = listData;

            // We know we reached the end of the list if the iterator
            // is NULL.
            while(iterator != NULL) {
                // Did we find the item?
                if(iterator->info == item) {
                    // If so, return it
                    return iterator->info;
                }

                // If not, try the next node
                iterator = iterator->next;
            }

            // If we get here, we cannot have found the item we're
            // looking for.
            throw NotFoundException();
        }

        virtual void RemoveItem(ItemType item) {
            // Note: Per the specification, this function assumes
            // the item is contained in the list.
            
            // Case 1: The item we want to delete is at the
            // front of the list.
            if (listData->info == item) {
                //Set it aside to delete later
                NodeType<ItemType> *tmp = listData;

                // Have the front of the list become the next node
                listData = tmp->next;

                // Delete the target node
                delete tmp;
            }

            // Case 2: The item we want to delete is not at the
            // front of the list.
            else {
                // Look for it using an iterator pointer
                NodeType<ItemType> *iterator = listData;

                // Iterate through the list until we find it
                // Note that we are looking ahead by one!
                // We are asking if the next node matches, not the
                // one that iterator is currently pointing at!
                while(iterator->next->info != item) {
                    iterator = iterator->next;
                }

                // At this point, we found it. Use the same
                // deletion process as above: set the node to be
                // deleted aside for later
                NodeType<ItemType> *tmp = iterator->next;

                // Since we are looking ahead, change our next pointer
                // to point to the node after the one we want to delete
                iterator->next = tmp->next;

                // Delete the target node
                delete tmp;
                
                this->size--;
            }
        }
    private:
        NodeType<ItemType> *listData;
        int size;
};

#endif