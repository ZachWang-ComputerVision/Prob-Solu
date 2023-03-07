#ifndef _MY_DATA_STRUCTURE_H_
#define _MY_DATA_STRUCTURE_H_


#include <iostream>
#include <vector>
#include "MyDataStructure.h"

/* Linked List */
// template<typename T>
// LinkedList<T>::LinkedList()
// {
//   this->head = NULL;
//   this->tail = NULL;
// };

// template<typename T>
// void LinkedList<T>::add_node(T item)
// {
//   LinkedListNode<T> *new_node;
//   new_node->value = item;
//   new_node->next = NULL;

//   if (this->head == NULL)
//   {
//     this->head = new_node;
//     this->tail = new_node;
//   }
//   else
//   {
//     this->tail->next = new_node;
//     this->tail = this->tail->next;
//   }
//   this->size_ ++;
// };

// template<typename T>
// int LinkedList<T>::get_size()
// {
//   return this->size_;
// };

// template<typename T>
// void LinkedList<T>::print_head()
// {
//   std::cout << this->head << std::endl;
// };

// template<typename T>
// void LinkedList<T>::print_all()
// {
  
// };


/* Heap */
template <typename T>
class Heap {
  std::vector<T> heap_list;
  int cur_size = 0;
  std::string heap_type;

public:
  Heap(std::string heap_type) : heap_type(heap_type) { };
  void Insert(T item) {
    cur_size ++;
    heap_list.push_back(item);
    bool stop = false;
    int child_idx = cur_size;
    
    if (heap_type == "max") {
      int parent_idx = std::floor(child_idx / 2);
      while (parent_idx > 0 && stop == false) {
        if(heap_list[parent_idx] < heap_list[child_idx]) {
          T hold = heap_list[child_idx];
          heap_list[child_idx] = heap_list[parent_idx];
          heap_list[parent_idx] = hold;
        }
        else {
          stop = true;
        };
        child_idx = parent_idx;
        parent_idx = std::floor(child_idx / 2);
      };
    } 
    else if (heap_type == "min") {
      int parent_idx = std::floor(child_idx / 2);
      while (parent_idx > 0 && stop == false) {
        if(heap_list[parent_idx] > heap_list[child_idx]) {
          T hold = heap_list[child_idx];
          heap_list[child_idx] = heap_list[parent_idx];
          heap_list[parent_idx] = hold;
        }
        else {
          stop = true;
        };
        child_idx = parent_idx;
        parent_idx = std::floor(child_idx / 2);
      };
    } 
    else {
      throw std::invalid_argument("No heap type implementation meets your specified type");
    };
  };
};

#endif