#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

template <class T>
class LinkedList
{
public:
    LinkedList();
    void insertNodeHead(int key, T data);
    void print() const;
    void printReverse() const;
    bool isEmpty() const;
    bool deleteNodeHead();
    void deleteNodeWithKey(int key);
private:
    Node<T>* head;
    Node<T>* tail;
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
}

template <class T>
void LinkedList<T>::insertNodeHead(int key, T data)
{
    Node<T> *p_new_node = new Node<T>(key, data);
    if (head == NULL)
    {
        p_new_node->set_next(head);
        this->head = p_new_node;
        this->tail = p_new_node;
        return;
    }

    p_new_node->set_next(head);
    head->set_prev(p_new_node);
    head = p_new_node;
}

template <class T>
void LinkedList<T>::print() const
{
    if (head == NULL)
    {
        std::cout << "Empty linkedlist" << std::endl;
        return;
    }

    Node<T>* ptr_temp = head;
    while (ptr_temp != NULL)
    {
        std::cout << "key: " << ptr_temp->get_key() << " -- data: " << ptr_temp->get_data() << std::endl;
        ptr_temp = ptr_temp->get_next();
    }
}

template <class T>
void LinkedList<T>::printReverse() const
{
    if (tail == NULL)
    {
        std::cout << "Empty Linkedlist" << std::endl;
        return;
    }

    Node<T> *ptr_temp = tail;
    while (ptr_temp != NULL)
    {
        std::cout << "key: " << ptr_temp->get_key() << " -- data: " << ptr_temp->get_data() << std::endl;
        ptr_temp = ptr_temp->get_prev();
    }
}


template <class T>
bool LinkedList<T>::isEmpty() const
{
    return this->head == NULL;
}

template <class T>
bool LinkedList<T>::deleteNodeHead()
{
    if (!isEmpty())
    {
        Node<T>* ptr_temp = head;
        head = head->get_next();
        head->set_prev(NULL);
        delete ptr_temp;
        ptr_temp = NULL;
        return true;
    }
    return false;
}

template <class T>
void LinkedList<T>::deleteNodeWithKey(int key)
{
    Node<T>* ptr_temp = head;

    while (ptr_temp != NULL)
    {
        if (ptr_temp->get_key() == key)
        {
            //check if node is the head or tail
            std::cout << head->get_key() << std::endl;
            if (head->get_key() == key)
            {
                ptr_temp->get_next()->set_prev(NULL);
                head = ptr_temp->get_next();
                delete ptr_temp;
                ptr_temp = NULL;
                return;
            } else if (tail->get_key() == key)
            {
                ptr_temp->get_prev()->set_next(NULL);
                tail = ptr_temp->get_prev();
                delete ptr_temp;
                ptr_temp = NULL;
                return;
            } else
            {
                ptr_temp->get_prev()->set_next(ptr_temp->get_next());
                ptr_temp->get_next()->set_prev(ptr_temp->get_prev());
                delete ptr_temp;
                ptr_temp = NULL;
                return;
            }

        }
        ptr_temp = ptr_temp->get_next();
    }
}


#endif
