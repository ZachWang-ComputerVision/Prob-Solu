#include <iostream>
#ifndef _MY_DATA_STRUCTURE_H_
#define _MY_DATA_STRUCTURE_H_


// Stack
// Queue
// Priority Queue
// Linked List
// Hash Table
// Heap
// Tree


// Bubble Sort
// Selection Sort
// Insertion Sort
// Merge Sort
// QuickSort
// Counting Sort
// Set


template<typename T>
struct LinkedListNode
{
  T value;
  LinkedListNode<T> *next; 
};


template<typename T>
class LinkedList
{
private:
  int size_ = 0;
  LinkedListNode<T> *head, *tail;

public:
  LinkedList();
  void add_node(T item);
  int get_size();
  void print_head();
  void print_all();
};

#endif