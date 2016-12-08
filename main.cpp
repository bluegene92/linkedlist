#include <iostream>
#include "node.h"
#include "linkedlist.h"


int main()
{

    Node<std::string> *head = NULL;
    Node<std::string> *tail = NULL;


    Node<int> *n1 = new Node<int>(1, 44);
    Node<int> *n2 = new Node<int>(2, 55);

    n1->set_next(n2);

    std::cout << n1->get_key() << std::endl;
    std::cout << n1->get_data() << std::endl;
    std::cout << n1->get_next()->get_data() << std::endl;

    std::cout << "Using linked list " << std::endl;

    LinkedList<std::string> *myList = new LinkedList<std::string>();

    myList->insertNodeHead(5, "Matt");
    myList->insertNodeHead(6, "Timmy");
    myList->insertNodeHead(7, "Nancy");
    myList->insertNodeHead(8, "Dat");
    myList->insertNodeHead(9, "Tomy");
    myList->insertNodeHead(10, "Taejin");

    myList->print();

    if (myList->isEmpty())
        std::cout << "Linked list is empty" << std::endl;
    else
        std::cout << "Linked list is NOT empty" << std::endl;


    if(myList->deleteNodeHead())
        std::cout << "head of linked list deleted" << std::endl;
    else
        std::cout << "linked list is empty, can't delete the node head" << std::endl;

    myList->print();


    //print reverse
    std::cout << std::endl;
    std::cout << "Printing the reverse" << std::endl;
    myList->printReverse();


    //delete givern key
    std::cout << std::endl;
    std::cout << "Delete with key" << std::endl;
    myList->deleteNodeWithKey(7);
    myList->print();

    return 0;
}
