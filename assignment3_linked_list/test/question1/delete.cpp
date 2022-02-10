#include "delete.h"

void testDeleteFrontEmptyListThrowsException() {
    LinkedList<int> list;
    try {
        list.deleteFront();
    } catch (std::invalid_argument &e) {
        std::cout << "Passed delete front for an empty list test" << std::endl;
    }
}

void testDeleteFrontNonEmptyListSuccess() {
    LinkedList<int> list;
    list.insertBack(0);
    list.insertBack(1);
    list.deleteFront();
    assertEqual(list.toVector(), {1});
    std::cout << "Passed delete front for non empty list test" << std::endl;
}

void testDeleteBackEmptyListThrowsException() {
    LinkedList<int> list;
    try {
        list.deleteBack();
    } catch (std::invalid_argument &e) {
        std::cout << "Passed delete back for an empty list test" << std::endl;
    }
}

void testDeleteBackNonEmptyListSuccess() {
    LinkedList<int> list;
    list.insertBack(0);
    list.insertBack(1);
    list.deleteBack();
    assertEqual(list.toVector(), {0});
    std::cout << "Passed delete back for non empty list test" << std::endl;
}

void testDeleteMidInvalidPositionThrowsException() {
    try {
        LinkedList<int> list;
        list.deleteAt(1); // invalid position
    }
    catch (std::invalid_argument &e) {
        std::cout << "Passed delete mid invalid position" << std::endl;
    }
}

void testDeleteMidValidPositionSuccess() {
    LinkedList<int> list;
    for (int i=0; i<3; i++)
        list.insertBack(i);

    list.deleteAt(0);
    assertEqual(list.toVector(), {1, 2});
    std::cout << "Passed delete mid for non empty list test" << std::endl;
}

void runDeleteTests() {
    testDeleteFrontEmptyListThrowsException();
    testDeleteFrontNonEmptyListSuccess();
    testDeleteBackEmptyListThrowsException();
    testDeleteBackNonEmptyListSuccess();
    testDeleteMidInvalidPositionThrowsException();
    testDeleteMidValidPositionSuccess();
}