#ifndef STACK_HPP
#define STACK_HPP

class Stack {
    public:
        Stack();
        Stack(int max_size);
        ~Stack();

        void Push(int value);
        int Pop();
        int Peek();
        bool isEmpty();

        int getTop();
    private:
        int top;
        int* base;
        int max_size;
};

#endif