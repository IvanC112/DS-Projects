//Invariant:
//1.head_ptr = the pointer to the first node object in the linked list
//2.tail_ptr = the pointer to the last node object
//3.curor = the pointer to the current item or current node object
//4.precursor = the pointer to the node object before the current item
//5. many_nodes = keeps track of the amount of nodes in the linked list

//RunTime Analysis:
//Copy Constructor: O(N) due to list_copy function
//Assignment Operator: O(N) due to list copy function
//Destructor: O(N) due to lsit_clear function
//Other Member Functions: O(1) constant runtime as they perform a fixed number of operations

#include <iostream>
#include "Sequence.hh"
#include <cassert>

namespace main_savitch_5 {

//The sequence or the linked list has been initialized as empty so we can have the pointers point to Null.
sequence::sequence() {
  
  head_ptr = nullptr;
  tail_ptr = nullptr;
  cursor = nullptr;
  precursor = nullptr;
  many_nodes = 0;
  
}

//there exists a parameter linked list and we are simply copying the elements over
  //we are copying over the parameter linked list object into our existing object
sequence::sequence(const sequence& source) {
    head_ptr = nullptr;  
    tail_ptr = nullptr;
    cursor = nullptr;
    precursor = nullptr;
    many_nodes = 0;

    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;
  
    if (source.cursor != nullptr) {
    if (source.cursor == source.head_ptr) {
      precursor = nullptr;
      cursor = head_ptr;
    }
    else if (source.cursor == source.tail_ptr) {
      cursor = tail_ptr;
      precursor = list_search(source.head_ptr, source.precursor->data());
    }
    else {
      cursor = list_search(source.head_ptr, source.cursor->data());
      precursor = list_search(source.head_ptr, source.precursor->data());
   }
  }
}

//uses the linked list tool kit where it takes in the head_ptr and starting from there, clears all the nodes and return to the heap
sequence::~sequence() {
  list_clear(head_ptr);
  many_nodes = 0;
}

//if the linked list is not empty then the firt node object is the current item (cursor: pointer to current item) else there is not current item
void sequence::start() {
  if (head_ptr != nullptr) {
    cursor = head_ptr;
  }
  else {
    cursor = nullptr;
  }
  precursor = nullptr;
}

//if the current item is the last node object in the linked list then there is no current item
//else if its in the middle or in the beginning then u simply advance the cursor pointer
void sequence::advance() {
  assert(is_item());
  if (cursor->link() == nullptr) {  
    cursor = nullptr;
  }
  else {
    precursor = cursor;
    cursor = cursor->link();
  }
}

//1.there is no current item, there is no linked list then we simply insert a new node
//2.there is no current item due to cursor running off the linked list, we need to insert a new node object in the beginning of the linked list and cursor becomes is the new node object at the beginning
//3. the current item is somewhere in the middle
//4. the current item is in the beginning
void sequence::insert(const value_type& entry) {
  if (!is_item()){
    if (head_ptr == nullptr) {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      tail_ptr = cursor;
      precursor = nullptr;
    }
    else {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = nullptr;
    }
  }
  else {
    if (cursor == head_ptr) {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = nullptr;
    }
    else if (cursor == tail_ptr) {
      list_insert(precursor, entry);
      cursor = precursor->link();
      tail_ptr = cursor;
    }
    else {
    list_insert(precursor, entry);
    cursor = precursor->link();
    }
  }
  many_nodes++;
}

//1. there is no current item, no linked list
//2. there is no current item, yes linked list but ran off the sequence
//3. there is a linked list and current is the last node object
//4. there is a linked list and current is beginning or anywhere
void sequence::attach(const value_type& entry) {
  if (!is_item()) {
    if (head_ptr == nullptr) {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      tail_ptr = cursor;
      precursor = nullptr;
    }
    else {
      list_insert(tail_ptr, entry);
      precursor = tail_ptr;
      cursor = precursor->link();
      tail_ptr = cursor;
    }
  }
  else {
    if (cursor == tail_ptr) {
      list_insert(cursor, entry);
      precursor = cursor;
      cursor = cursor->link();
      tail_ptr = cursor;
  }
    else {
      list_insert(cursor, entry);
      precursor = cursor;
      cursor = cursor->link();
    }
  }
  many_nodes++;
}

void sequence::remove_current() {
  assert(is_item());
  if (cursor == head_ptr) {
    list_head_remove(head_ptr);
    cursor = head_ptr;
    precursor = nullptr;
  }
  else {
    cursor = cursor->link();
    list_remove(precursor);
  }
  many_nodes--;
}


//1. situation where the source sequence does not have a cursor
//2. situation where the source sequence does have a cursor.
//however if there is a cursor theres 2 situation, one where cursor is the head_ptr then there is no precursor, two there is a precursor
//3. in order to assign our current cursor pointer we need to locate the cursor pointer in he original source and assign it to our cursor
void sequence::operator=(const sequence& source) {
  if (this == &source) {
    return;
  }

  list_clear(head_ptr);
  many_nodes = 0;
  
  list_copy(source.head_ptr, head_ptr, tail_ptr);  
  many_nodes = source.many_nodes;

  if (source.cursor != nullptr) {  
    if (source.cursor == source.head_ptr) {  //if the source cursor is in the beginning then a precursor does not exist
      precursor = nullptr;
      cursor = head_ptr;
    }
    else if (source.cursor == source.tail_ptr) {
      cursor = tail_ptr;  
      precursor = list_search(source.head_ptr, source.precursor->data());
    }
    else {
      cursor = list_search(source.head_ptr, source.cursor->data());
      precursor = list_search(source.head_ptr, source.precursor->data());
   }
  }
  else {
    cursor = nullptr;
    precursor = nullptr;
  }
}

sequence::value_type sequence::current() const {
  return cursor->data();
}

}


