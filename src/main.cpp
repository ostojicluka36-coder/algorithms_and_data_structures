#include <iostream>
#include <algoritmi_i_strukture_podataka/LinkedList.hpp>

using namespace std;

int main() {

    LinkedList lista;
    LinkedList lista2;

    lista2.pushFront(300);
    lista2.pushFront(400);

    lista.pushFront(3);
    lista.pushFront(2);
    lista.pushFront(1);
    lista.pushBack(4);

    lista.insert(100, -50);

    lista.printList();

    lista.getNode(-3);
    cout << lista.getNode(1) << endl;
    lista.getNode(100);

    cout << "\n";

    lista.deleteAt(1);
    lista.printList();
    cout << "\n";
    lista.deleteNode(lista.getNode(2));
    lista.printList();
    cout << "\n";
    lista.deleteNode(nullptr);

    lista.concatenate(lista2);
    lista.printList();
    cout << "\n";

    lista.invert();
    lista.printList();


    return 0;
}
