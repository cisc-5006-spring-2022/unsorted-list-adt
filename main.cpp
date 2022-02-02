#include "UnsortedList.h"
#include "ArrayUnsortedList.h"

#include <iostream>

using namespace std;

void testList(UnsortedList<int> &l) {
    l.PutItem(20);
    l.PutItem(19);
    l.PutItem(21);
    l.PutItem(100);
    l.PutItem(-100);
    l.RemoveItem(19);

    int found = l.GetItem(20);
    cout << found << endl;

    try {
        found = l.GetItem(200);
    } catch(NotFoundException e) {
        cout << "200 not found" << endl;
    }
}

int main() {
    ArrayUnsortedList<int> list = ArrayUnsortedList<int>(100);
    testList(list);
}