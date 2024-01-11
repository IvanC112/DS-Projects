#include <iostream>
#include "Sequence-Dynamic.hh"
#include <cassert>

namespace main_savitch_4 {

sequence::sequence(size_type initial_capacity) {
  
  dataPtr = new value_type[initial_capacity];  //dynammically allocate memory with a capacity of initial_capacity but the sequence is still empty
  used = 0;  
  capacity = initial_capacity;
  current_index = 0;
  
}

sequence::sequence(const sequence& source) {  
  dataPtr = new value_type[source.capacity];
  used = source.used;
  capacity = source.capacity;
  current_index = source.current_index;
  
  std::copy(source.dataPtr, source.dataPtr + used, dataPtr);
  
}

sequence::~sequence() {
  delete [] dataPtr;  //deallocate or freeing memory back to the heap after finished
}

//used = 5
//current = 10
//new = 20

void sequence::resize(size_type new_capacity) {
  if (new_capacity == capacity) {  //if new capacity is already the right size then return and do nothing
    return;
  }
  else if (new_capacity < used) {  //Cannot be less than the number of items already on the list so we set new capacity equal to the size
    new_capacity = used;
  }
  else { 
    capacity = new_capacity;  //set current capacity equal to the new capacity
    value_type *new_dataPtr;  //create a local pointer that will point to this new memory address
    new_dataPtr = new value_type[capacity];  //dynmically allocate new memory
    std::copy(dataPtr, dataPtr + used, new_dataPtr);
    delete [] dataPtr;  //free memory from old memory address
    dataPtr = new_dataPtr;  //let our current pointer point to the memory address of new_dataPtr
  }
}

void sequence::start() {
  if (used > 0) {
    current_index = 0;
}
  
}

void sequence::advance() {
  assert(is_item());
  if (current_index != used-1) {
    current_index++;
  }
  else {
    current_index = used;
  }
}

//Similar to the insert function did in Sequence class but to access the positions of dynamically allocated array, use pointerName notation
void sequence::insert(const value_type& entry) {
  if (used >= capacity) {
    resize(used+1);
  }
  assert(size() < capacity);
  if (!is_item()) {
    if (used == 0) {
    current_index = 0;
    dataPtr[current_index] = entry;
    }
    else {
      for (size_type i = used; i > 0; --i) {
      dataPtr[i] = dataPtr[i - 1];
    }
    dataPtr[0] = entry;
    current_index = 0;
    }
    used++;
  }
   else {
    for (size_type i = used; i > current_index; --i) {
      dataPtr[i] = dataPtr[i - 1];
    }
    dataPtr[current_index] = entry;
    used++;
  }
}


//increase the size of the array with resizeyou
void sequence::attach(const value_type& entry) {
  if (used >= capacity) {
    resize(used+1);
  }
  assert(size() < capacity);
  if (!is_item()) {
    current_index = used;
  } 
  else {
    for (size_type i = used; i > current_index+1; --i) {
      dataPtr[i] = dataPtr[i - 1];
    }
    current_index++;
  }
    dataPtr[current_index] = entry;
    used++;
}

void sequence::remove_current() {
  assert(is_item());
  for (size_type i = current_index+1; i < used; ++i) {
    dataPtr[i-1] = dataPtr[i];
  }
  used--;
}

//Unlike the copy constructor the operator assignment overload function is supposed to copy the content of source object to the existing object, it overrides the elements. If the capacity are not the same then we dynamically allocate a new array to get the same array capacity. Else we make a deep copy by making a copy of the data itself.
void sequence::operator=(const sequence& source) {
  
  value_type *new_dataPtr;

  if (this == &source) {  
    return;
  }
  if (capacity != source.capacity) {
    new_dataPtr = new value_type[source.capacity];
    delete [] dataPtr;
    dataPtr = new_dataPtr;
    capacity = source.capacity; 
  }
    current_index = source.current_index;
    used = source.used;
    std::copy(source.dataPtr, source.dataPtr + used, dataPtr);
}

sequence::size_type sequence::size() const {
  return used;
}

bool sequence::is_item() const {
   if (current_index < used) {
    return true;
  } 
  else {
    return false;
  }
}

sequence::value_type sequence::current() const {
  assert(is_item());
  return dataPtr[current_index];
}



}

