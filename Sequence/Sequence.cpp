#include "Sequence.hh"
#include <cassert>
#include <iostream>

namespace main_savitch_3 {

// initialized the sequence as a empty sequence that can hold 30 elements
sequence::sequence() {
  used = 0;
  current_index = 0;
}

// if the size of the array is greater than zero meaning the sequence is not
// empty then we can set current_index = 0, the initial value.
void sequence::start() {
  if (used > 0) {
    current_index = 0;
  }
}

// If the current item is not the last item in the array then the new item is
// the item immediately after. else there is no longer any new current item so
// we set it equal to used (size).
void sequence::advance() {
  assert(is_item()); 
  if (current_index != used - 1) {
    current_index++;
  }
  else {
    current_index = used;
  }
}

// if there is no current item then the new entry is simply the first index,
// where I set it equal to 0; else we insert the entry before the current_index,
// in order to do that we have to shift all the elements to the right and insert
// the new entry in the location of the current_index
void sequence::insert(const value_type &entry) {
  assert(size() < CAPACITY);
  if (!is_item()) {
    if (used == 0) {
    current_index = 0;
    data[current_index] = entry;
    }
    else {
      for (size_type i = used; i > 0; --i) {
      data[i] = data[i - 1];
    }
    data[0] = entry;
    current_index = 0;
    }
    used++;
  }
   else {
    for (size_type i = used; i > current_index; --i) {
      data[i] = data[i - 1];
    }
    data[current_index] = entry;
    used++;
  }
}


//if there is no item in the beginning then attach the element to the end of sequence
//else shift elements to the right and then the new current_index will be the element that was attached after the old current_index
void sequence::attach(const value_type &entry) {
  assert(size() < CAPACITY);
  if (!is_item()) {
    current_index = used;
  } 
  else {
    for (size_type i = used; i > current_index+1; --i) {
      data[i] = data[i - 1];
    }
    current_index++;
  }
    data[current_index] = entry;
    used++;
}

//Precondition: is_item returns true.
//starting at the element we want to remove, we shift the elements to the left.
void sequence::remove_current() {
  assert(is_item());
  for (size_type i = current_index+1; i < used; ++i) {
    data[i-1] = data[i];
  }
  used--;
}

// Constant Member Functions or Accessors
sequence::size_type sequence::size() const { return used; }

// returns true if there is a current_index but if there isn't a number then return false.
bool sequence::is_item() const {
  if (current_index < used) {
    return true;
  } 
  else {
    return false;
  }
}

// if is_item returns true then there is a valid number meaning we can call
// current() for a current number.
sequence::value_type sequence::current() const {
  assert(is_item());
  return data[current_index];
}

} // namespace main_savitch_3
