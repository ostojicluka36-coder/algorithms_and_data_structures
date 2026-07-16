#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"

class LinkedList {
    public:
        LinkedList();
        LinkedList(Node* headNode);

        void printList() const;
        void pushFront(Node* node);
        void pushBack(Node* node);
        void insert(Node* node, int position);
        bool isEmpty() const;
        int size() const;

        Node* getHead() const;
        void setHead(Node* headNode);

    private:
        Node* headNode;
};

#endif