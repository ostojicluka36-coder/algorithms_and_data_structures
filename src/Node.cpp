#include <iostream>
#include <algoritmi_i_strukture_podataka/Node.hpp>

using namespace std;

// CONSTRUCTORS

Node::Node() {
    this->data = 0;
    this->next = nullptr;
}

Node::Node(int value) {
    this->data = value;
    this->next = nullptr;
}

Node::Node(int value, Node* nextNode) {
    this->data = value;
    this->next = nextNode;
}

//

// GETTERS AND SETTERS

int Node::getData() const {
    return this->data;
}

Node* Node::getNext() const {
    return this->next;
}

void Node::setData(int value) {
    this->data = value;
}

void Node::setNext(Node* nextNode) {
    this->next = nextNode;
}

//