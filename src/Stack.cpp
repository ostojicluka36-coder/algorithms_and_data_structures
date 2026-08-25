#include <iostream>
#include "algoritmi_i_strukture_podataka/Stack.hpp"

// CONSTRUCTORS AND DESTRUCTORS

Stack::Stack() {
    this->base = new int[10];
    this->top = -1;
    this->max_size = 10;
}

Stack::Stack(int max_size) {
    this->base = new int[max_size];
    this->top = -1;
    this->max_size = max_size;
}

Stack::~Stack() {
    delete[] this->base;
    std::cout << "Stack memory freed.\n";
}

//

// METHODS

void Stack::Push(int value) {
    if(this->top + 1 < this->max_size) {
        this->top++;
        this->base[this->top] = value;
    }
    else {
        std::cout << "Stack full!\n";
        return;
    }
}

int Stack::Pop() {
    if(this->isEmpty()) {
        std::cout << "The stack is empty!\n";
        return 0; // To get rid of the compiler warning
    }
    else {
        this->top--;
        return this->base[this->top + 1];
    }
}

int Stack::Peek() {
    if(!this->isEmpty()) {
        return this->base[this->top];
    }
    else {
        std::cout << "The stack is empty! Returning 0!\n";
        return 0;
    }

}

bool Stack::isEmpty() {
    if (this->top == -1) {
        return true;
    }
    else {
        return false;
    }
}

//

// GETTERS AND SETTERS

int Stack::getTop() {
    return this->top;
}

//
