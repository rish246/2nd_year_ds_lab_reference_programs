#include "LinkedList.h"

#define DUMMY_VALUE -999900983

template <typename T>
LinkedList<T>::LinkedList() {
    head = new ListNode(DUMMY_VALUE);
    size = 0;
}

template <typename T>
void LinkedList<T>::insertAt(int position, T element) {
    checkPositionValidity(position);
    ListNode *nodeAtPos = nodeAt(position); 
    ListNode *nodeAfterPos = nodeAtPos->next;
    nodeAtPos->next = new ListNode(element);
    nodeAtPos->next->next = nodeAfterPos;
    size++;
}

template <typename T>
void LinkedList<T>::insertFront(T element) {
    insertAt(0, element);
}

template <typename T>
void LinkedList<T>::insertBack(T element) {
    insertAt(size, element);
}

template <typename T>
void LinkedList<T>::deleteFront() {
    if (isEmpty())
        throw std::invalid_argument("Can't delete an element from an empty list");
    deleteAt(0);
}

template <typename T>
void LinkedList<T>::deleteBack() {
    if (isEmpty())
        throw std::invalid_argument("Can't delete an element from an empty list");
    deleteAt(size-1);
}

template <typename T>
void LinkedList<T>::deleteAt(int position) {
    checkPositionValidity(position);
    size--;
    ListNode *nodePrecedingDeletingNode = nodeAt(position);
    ListNode *deletingNode = nodePrecedingDeletingNode->next;
    ListNode *nodeSucceedingDeletingNode = deletingNode->next;
    nodePrecedingDeletingNode->next = nodeSucceedingDeletingNode;
    deletingNode->next = nullptr;
    delete deletingNode;
}

template <typename T>
void LinkedList<T>::sort() {
    // bubbleSort
    if (size <= 1) return;
    for (int i = 0; i <= size; i++) {
        ListNode *curNode = head, *nextNode = head->next;
        while (nextNode != nullptr) {
            if (curNode->data > nextNode->data)
                swapValues(curNode, nextNode);
            curNode = nextNode, nextNode = nextNode->next;
        }
    }
}


template <typename T>
void LinkedList<T>::reverse() {
    ListNode *tempHead = head->next;
    ListNode* prev = nullptr, *cur = tempHead;
    while (cur != nullptr) {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    tempHead = prev;
    head->next = tempHead;
}

template <typename T>
void LinkedList<T>::print() {
    for (ListNode* current = head->next; current != nullptr; current = current->next) {
        std::cout << current->data << ',';
    }
    std::cout << std::endl;
}

template <typename T>
int LinkedList<T>::length() {
    return size;
}

template <typename T>
LinkedList<T>::ListNode::ListNode(T _data): data(_data), next(nullptr) {}


template <typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::nodeAt(int position) {
    checkPositionValidity(position);
    ListNode *result = head;
    for (int i = 0; i < position; i++) {
        result = result->next;
    }
    return result;
}

template <typename T>
void LinkedList<T>::swapValues(ListNode *first, ListNode *second) {
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

template <typename T>
void LinkedList<T>::checkPositionValidity(int position) {
    if (position < 0 || position > size)
        throw std::invalid_argument("Invalid position passed");
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() {
    std::vector<T> vectorRepresentation;
    for (ListNode *temp = head->next; temp != nullptr; temp = temp->next)
        vectorRepresentation.push_back(temp->data);
    return vectorRepresentation;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return head->next == nullptr;
}

