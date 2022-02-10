#include "insert.h"


void testInsertFrontSuccess() {
    LinkedList<int> list;
    for (int i=0; i<5; i++) {
        list.insertFront(i);
    }
    assertEqual(list.toVector(), {4, 3, 2, 1, 0});
    std::cout << "Passed insert in front of the list test" << std::endl;
}


void testInsertAtPositionInvalidPosThrowsException() {
    try {
        int invalidPos1 = 1, invalidPos2 = -1;
        LinkedList<int> list;
        list.insertAt(invalidPos1, 1);
        list.insertAt(invalidPos2, 2);
    } catch (std::invalid_argument &e) {
        std::cout << "Passed insert at front invalid position test" << std::endl;
    }
}

void testInsertAtPositionValidPosSuccess() {
    LinkedList<int> list;
    for (int i=0; i<3; i++) {
        list.insertBack(i);
    }
    list.insertAt(2, -43);
    assertEqual(list.toVector(), {0, 1, -43, 2});
    std::cout << "Passed insert in mid of the list with valid position test" << std::endl;

}

void testInsertMidSuccess() {
    testInsertAtPositionInvalidPosThrowsException();
    testInsertAtPositionValidPosSuccess();
    std::cout << "Passed Insert in the middle of the list test" << std::endl;
}

void testInsertEndSuccess() {
    LinkedList<int> list;
    for (int i=0; i<5; i++) {
        list.insertBack(i);
    }
    assertEqual(list.toVector(), {0, 1, 2, 3, 4});
    std::cout << "Passed insert at end of the list test" << std::endl;

}


void runInsertTests() {
    testInsertFrontSuccess();
    testInsertAtPositionInvalidPosThrowsException();
    testInsertAtPositionValidPosSuccess();
    testInsertEndSuccess();
    testInsertMidSuccess();
}