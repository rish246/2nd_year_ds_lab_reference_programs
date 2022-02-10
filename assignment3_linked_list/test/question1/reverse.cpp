#include "reverse.h"

void testReverseEmptyListSuccess() {
    LinkedList<int> list;
    list.reverse();
    assertEqual(list.toVector(), {});
    std::cout << "Passed reversing empty list test" << std::endl;
}

void testReverseNonEmptyListSuccess() {
    LinkedList<int> list;
    int elements[] = {1, 4, 2, 4};
    for (int i=0; i<4; i++) {
        list.insertBack(elements[i]);
    }

    list.reverse();
    assertEqual(list.toVector(), {4, 2, 4, 1});
    std::cout << "Passed non empty list reversing test" << std::endl;
}

void runReverseTests() {
    testReverseEmptyListSuccess();
    testReverseNonEmptyListSuccess();
}
