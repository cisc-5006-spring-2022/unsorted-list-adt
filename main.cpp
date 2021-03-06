#include "UnsortedList.h"
#include "ArrayUnsortedList.h"
#include "LinkedUnsortedList.h"

#include <iostream>

using namespace std;

void testList(UnsortedList<int> &l) {
    l.PutItem(20);
    l.PutItem(19);
    l.PutItem(21);
    l.PutItem(100);
    l.PutItem(-100);
    l.RemoveItem(19);

    int found = l.GetItem(21);
    cout << "Found 21" << endl;

    try {
        found = l.GetItem(19);
    } catch(NotFoundException e) {
        cout << "19 not found - OK" << endl;
    }

    try {
        found = l.GetItem(200);
    } catch(NotFoundException e) {
        cout << "200 not found - OK" << endl;
    }
}

int main() {

    cout << "Linked list" << endl;

    LinkedUnsortedList<int> list = LinkedUnsortedList<int>();
    testList(list);


    list.ResetList();

    cout << endl << "Iterator output:" << endl;

    for(int i = 0; i < list.GetLength(); i++) {
        cout << list.GetNextItem() << endl;
    }


    cout << endl << endl << "Array list" << endl;

    ArrayUnsortedList<int> list2 = ArrayUnsortedList<int>(100);
    testList(list2);


    list2.ResetList();

    cout << endl << "Iterator output:" << endl;

    for(int i = 0; i < list2.GetLength(); i++) {
        cout << list2.GetNextItem() << endl;
    }
}