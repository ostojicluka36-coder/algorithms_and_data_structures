#include <iostream>
#include <algoritmi_i_strukture_podataka/LinkedList.hpp>

using namespace std;


// CONSTRUCTORS AND DESTRUCTORS

LinkedList::LinkedList() {
    this->headNode = nullptr;
}

LinkedList::~LinkedList() {
    
    Node* currentNode = this->headNode;
    Node* lastNode = nullptr;

    while(currentNode != nullptr) {
        lastNode = currentNode;
        currentNode = currentNode->getNext();

        delete lastNode;
    }

    this->headNode = nullptr;

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

void LinkedList::pushFront(int value) {

    Node* node = new Node;

    node->setData(value);

    node->setNext(this->headNode);
    this->headNode = node;
}

void LinkedList::pushBack(int value) {
    Node* currentNode = this->headNode;
    Node* node = new Node;

    node->setData(value);

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

void LinkedList::insertBefore(int value, Node* node) {
    if(node == nullptr) {
        cout << "Error! Node you passed was a nullptr!\n";
        return;
    }

    if(node == this->headNode) {
        Node* newNode = this->makeNode(value);
        newNode->setNext(this->headNode);
        this->headNode = newNode;
        return;
    }

    Node* currentNode = this->headNode;
    while(currentNode->getNext() != node && currentNode->getNext() != nullptr) {
        currentNode = currentNode->getNext(); 
    }

    if(currentNode->getNext() == nullptr) {
        cout << "Error! Node you passed isn't on the list!\n";
        return;
    }

    Node* newNode = this->makeNode(value);
    currentNode->setNext(newNode);
    newNode->setNext(node);

}

void LinkedList::insertAfter(int value, Node* node) {
    if(node == nullptr) {
        cout << "Error! Node you passed was a nullptr!\n";
        return;
    }

    Node* tmp = node->getNext();
    Node* newNode = this->makeNode(value);
    node->setNext(newNode);
    newNode->setNext(tmp);
}

void LinkedList::insert(int value, int position) {
    Node* currentNode = this->headNode;

    if(position <= 0) {
        if(position != 0)
            cout << "Position " << position << " doesn't exist. Pushing the node to the front of the list.\n";
        this->pushFront(value);
        return;
    }

    for(int i = 0; i < position - 1; i++) {
        if(currentNode == nullptr) {
            cout << "Position " << position << " doesn't exist. Pushing the node to the back of the list.\n";
            this->pushBack(value);
            return;
        }
        
        currentNode = currentNode->getNext();
    }


    if(currentNode == nullptr) {
        cout << "Position " << position << " doesn't exist. Pushing the node to the back of the list.\n";
        this->pushBack(value);
        return;
    }
    else {
        Node* node = new Node;
        node->setData(value);
        node->setNext(currentNode->getNext());
        currentNode->setNext(node);
    }

}

void LinkedList::deleteNode(Node* node) {
    if(this->isEmpty()) {
        cout << "The list is already empty!\n";
        return;
    }
    
    if(node == nullptr) {
        cout << "Error! Node you passed was a nullptr!\n";
        return;
    }

    if(node == this->headNode) {
        this->headNode = (this->headNode)->getNext();
        delete node;
        return;
    }

    Node* currentNode = this->headNode;
    while(currentNode->getNext() != nullptr && currentNode->getNext() != node ) {
        currentNode = currentNode->getNext(); 
    }

    if(currentNode->getNext() == nullptr) {
        cout << "Error! Node you passed isn't on the list!\n";
        return;
    }

    Node* nextNode = node->getNext();
    currentNode->setNext(nextNode);

    delete node;

}

void LinkedList::deleteAt(int position) {
    if(position < 0 || this->size() <= position) {
        cout << "Error! The position " << position << " doesn't exist on the list.\n";
        return;
    }

    Node* currentNode = this->headNode;
    for(int i = 0; i < position; i++) {
        currentNode = currentNode->getNext();
    }

    this->deleteNode(currentNode);

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

Node* LinkedList::makeNode(int value) {
    Node* node = new Node();
    node->setData(value);
    return node;
}

void LinkedList::concatenate(const LinkedList& list) {
    Node* currentNode = list.headNode;

    while(currentNode != nullptr) {
        this->pushBack(currentNode->getData());
        currentNode = currentNode->getNext();
    }
}

void LinkedList::invert() {
    Node* p = nullptr, *q = nullptr, *r = this->headNode;

    while(r != nullptr) {
        p = q;
        q = r;
        r = r->getNext();

        q->setNext(p);
    }

    this->headNode = q;
}

//


// GETTERS AND SETTERS

Node* LinkedList::getNode(int position) const {
    Node* currentNode = this->headNode;
    int i = 0;

    if(position < 0) {
        cout << "Error! Position can't be negative. Returning nullptr.\n";
        return nullptr;
    }

    while((currentNode != nullptr) && (i < position)) {
        currentNode = currentNode->getNext();
        i++; 
    }

    if(currentNode == nullptr) {
        cout << "Error! No node at position " << position << ". Returning nullptr.\n";
        return nullptr;
    }
    else {
        return currentNode;
    }
}

Node* LinkedList::getHead() const {
    return this->headNode;
}

void LinkedList::setHead(Node* headNode) {
    this->headNode = headNode;
}

//