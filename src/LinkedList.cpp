#include <iostream>
#include <algoritmi_i_strukture_podataka/LinkedList.hpp>

using namespace std;


// CONSTRUCTORS

LinkedList::LinkedList() {
    this->headNode = nullptr;
}

LinkedList::LinkedList(Node* headNode) {
    this->headNode = headNode;
}

//


// METHODS

void LinkedList::printList() const {
    Node* currentNode = this->headNode;
    int i = 1;
    while (currentNode != nullptr) {
        cout << "Node " << i << " data: ";
        cout << currentNode->getData() << "\n";
        currentNode = currentNode->getNext();
        i++;
    }
}

void LinkedList::pushFront(Node* node) {

    if(node == nullptr) {
        cout << "Error! You can't add nullptr to the list!\n";
        return;
    }

    node->setNext(this->headNode);
    this->headNode = node;
}

void LinkedList::pushBack(Node* node) {
    Node* currentNode = this->headNode;

    if(node == nullptr) {
        cout << "Error! You can't add nullptr to the list!\n";
        return;
    }

    if(currentNode == nullptr) {
        this->headNode = node;
        node->setNext(nullptr);
    }
    else {
        while(currentNode->getNext() != nullptr) {
            currentNode = currentNode->getNext();
        }
        currentNode->setNext(node);
        node->setNext(nullptr);
    }
}

void LinkedList::insert(Node* node, int position) {
    Node* currentNode = this->headNode;

    if(node == nullptr) {
        cout << "Error! You can't add nullptr to the list!\n";
        return;
    }

    if(position <= 0) {
        if(position != 0)
            cout << "Position " << position << " doesn't exist. Pushing the node to the front of the list.\n";
        this->pushFront(node);
        return;
    }

    for(int i = 0; i < position - 1; i++) {
        if(currentNode == nullptr) {
            cout << "Position " << position << " doesn't exist. Pushing the node to the back of the list.\n";
            this->pushBack(node);
            return;
        }
        
        currentNode = currentNode->getNext();
    }


    if(currentNode == nullptr) {
        cout << "Position " << position << " doesn't exist. Pushing the node to the back of the list.\n";
        return;
    }
    else {
        node->setNext(currentNode->getNext());
        currentNode->setNext(node);
    }

}

bool LinkedList::isEmpty() const {
    if(this->headNode == nullptr)
        return true;
    else
        return false;
}

int LinkedList::size() const {
    int i = 0;
    Node* currentNode = this->headNode;
    while(currentNode != nullptr) {
        currentNode = currentNode->getNext();
        i++;
    }
    
    return i;
}

//


// GETTERS AND SETTERS

Node* LinkedList::getHead() const {
    return this->headNode;
}

void LinkedList::setHead(Node* headNode) {
    this->headNode = headNode;
}

//