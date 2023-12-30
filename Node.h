// Dalton Wright
// CSCI 301 01
// Project #6
// Node.h

#ifndef NODE
#define NODE

template<class ItemType>
class Node
{
  private:
    ItemType        nodeItem;
    Node<ItemType>* previous;
    Node<ItemType>* next;

  public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    void setPrev(Node<ItemType>* prevNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
    Node<ItemType>* getPrev() const;
};

#include "Node.cpp"
#endif
