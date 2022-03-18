#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

int main() {
    Node head = {0, nullptr};

    Node *new_node_1 = new Node;
    head.next = new_node_1;
    new_node_1->value = 1;
    new_node_1->next = new Node{2, nullptr};

    Node * current = &head;
    while(current != nullptr) {
        cout << current->value << endl;
        current = current->next;
    }
}
