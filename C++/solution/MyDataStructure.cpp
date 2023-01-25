#include <iostream>
#include <vector>
#include "MyDataStructure.h"

/* Linked List */
template<typename T>
LinkedList<T>::LinkedList()
{
  this->head = NULL;
  this->tail = NULL;
};

template<typename T>
void LinkedList<T>::add_node(T item)
{
  LinkedListNode<T> *new_node;
  new_node->value = item;
  new_node->next = NULL;

  if (this->head == NULL)
  {
    this->head = new_node;
    this->tail = new_node;
  }
  else
  {
    this->tail->next = new_node;
    this->tail = this->tail->next;
  }
  this->size_ ++;
};

template<typename T>
int LinkedList<T>::get_size()
{
  return this->size_;
};

template<typename T>
void LinkedList<T>::print_head()
{
  std::cout << this->head << std::endl;
};

template<typename T>
void LinkedList<T>::print_all()
{
  
};


/* Heap */