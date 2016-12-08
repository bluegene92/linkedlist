#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
    // ~Node();
    Node(int key, T data);
    int get_key() const;

    T get_data() const;
    Node* get_next() const;
    Node* get_prev() const;

    void set_next(Node *p_next);
    void set_prev(Node *p_prev);
private:
    int key;
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <class T>
Node<T>::Node(int key, T data)
{
    this->key = key;
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

// template <class T>
// Node<T>::~Node()
// {
//     delete next;
//     delete prev;
//     next = NULL;
//     prev = NULL;
// }

template <class T>
int Node<T>::get_key() const
{
    return this->key;
}

template <class T>
T Node<T>::get_data() const
{
    return this->data;
}

template <class T>
Node<T>* Node<T>::get_next() const
{
    return next;
}

template <class T>
Node<T>* Node<T>::get_prev() const
{
    return prev;
}

template <class T>
void Node<T>::set_next(Node<T>* p_next)
{
    this->next = p_next;
}

template <class T>
void Node<T>::set_prev(Node<T>* p_prev)
{
    this->prev = p_prev;
}

#endif
