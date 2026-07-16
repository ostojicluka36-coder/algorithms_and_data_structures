#ifndef NODE_HPP
#define NODE_HPP

class Node {
    public: 
        Node();
        Node(int value);
        Node(int value, Node* nextNode);

        int getData() const;
        Node* getNext() const;

        void setData(int value);
        void setNext(Node* nextNode);

    private: 
        int data;
        Node* next;
};

#endif