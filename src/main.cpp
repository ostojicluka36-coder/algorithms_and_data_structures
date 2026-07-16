#include <iostream>
#include <algoritmi_i_strukture_podataka/Node.hpp>
#include <algoritmi_i_strukture_podataka/LinkedList.hpp>

using namespace std;

int main() {

    Node node3(30);
    Node node2(20, &node3);
    Node node1(10, &node2);

    LinkedList list(&node1);
    LinkedList lista0;
    //list.printList();

    cout << list.isEmpty() << endl;
    cout << list.size() << endl;


    return 0;
}
