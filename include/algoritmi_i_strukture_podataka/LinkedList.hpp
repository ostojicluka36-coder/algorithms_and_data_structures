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
        void insertBefore(int value, Node* node);
        void insertAfter(int value, Node* node);
        void insert(int value, int position);
        void deleteNode(Node* node);
        void deleteAt(int position);
        bool isEmpty() const;
        int size() const;
        void concatenate(const LinkedList& list);
        void invert();

        Node* getNode(int position) const;
        Node* getHead() const;
        void setHead(Node* headNode);

    private:
        Node* headNode;

        Node* makeNode(int value);
};

#endif