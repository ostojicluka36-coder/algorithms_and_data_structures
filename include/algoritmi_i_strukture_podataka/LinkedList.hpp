#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        void printList() const;
        void pushFront(int value);
        void pushBack(int value);
        void insert(int value, int position);
        bool isEmpty() const;
        int size() const;

        Node* getHead() const;
        void setHead(Node* headNode);

    private:
        Node* headNode;
};

#endif