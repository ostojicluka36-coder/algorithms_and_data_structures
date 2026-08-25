#include <iostream>
#include <algoritmi_i_strukture_podataka/LinkedList.hpp>
#include <algoritmi_i_strukture_podataka/Stack.hpp>

using namespace std;

int main() {

    Stack s(100);

    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Pop();
    s.Pop();
    s.Push(200);
    s.Push(300);
    s.Push(4);
    s.Push(5);

    for(int i = 0; i < 5; i++) {
        cout << s.Pop() << endl;
    }

    return 0;
}
