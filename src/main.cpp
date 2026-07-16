#include <iostream>
#include <algoritmi_i_strukture_podataka/Node.hpp>
#include <algoritmi_i_strukture_podataka/LinkedList.hpp>

using namespace std;

int main() {

    LinkedList lista;

    lista.pushFront(3);
    lista.pushFront(2);
    lista.pushFront(1);
    lista.pushBack(4);

    lista.insert(100, -50);

    lista.printList();

    return 0;
}
