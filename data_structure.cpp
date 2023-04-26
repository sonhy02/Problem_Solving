#include <iostream>

using namespace std;

struct node {
    int element;
    struct node* next;

    friend class singlylinkedlist;
};

class singlylinkedlist {

public:
    singlylinkedlist() {
node front;
front.element = NULL;


    }

    void insert_node(int elem, int idx) {
        node Node;
        Node.element = elem;
        Node.next

    }

    void delete_node(int idx) {


    }

    bool empty();


private:
    node *head = NULL;
    node *tail;

};


int main() {

    singlylinkedlist t1;
    t1.insert_node(2, 3);

    return 0;
}