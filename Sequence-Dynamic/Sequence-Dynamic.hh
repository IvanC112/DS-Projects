#include <iostream>
#ifndef MAIN_SAVITCH_H
#define MAIN_SAVITCH_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_4 {
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;                                                          //alias for double data types
        typedef size_t size_type; //typedef std::size_t size_type;                          //alias for any variable that represents the size of elements in the class
        static const size_type DEFAULT_CAPACITY = 30; //enum {DEFAULT_CAPACITY = 30}; //    //default capacity which is 30, but can be changed within parameter
        // CONSTRUCTOR
        sequence(size_type initial_capacity = DEFAULT_CAPACITY);                            //constructor
        sequence(const sequence& source);                                                   //copy constructor
        ~sequence( );                                                                       //destructor, delete [] dataPtr;
        // MODIFICATION MEMBER FUNCTIONS
        void start( );                                                                      //same as the previous sequence
        void advance( );                                                                    //same as the previous advance function
        void insert(const value_type& entry);                                               //same as previous function, where u insert new entry element before the current_index
        void attach(const value_type& entry);                                               //same as the previous function where u insert new entry element after the current_index
        void remove_current( );                                                             //same as the previous sequence, given pre condition that there is a current_index for loop to override
        void resize(size_type new_capacity);                                                //allocate a new array with the new capacity and copy the elements from the previous data to the current one
        void operator=(const sequence& source);                                             //Assign a local pointer that points to new memory address and copy elements from parameter object to current
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const;                                                            //returns the size of our array
        bool is_item( ) const;                                                              //returns true if there is a current index else return false
        value_type current( ) const;                                                        //return the current_index
    private:
        value_type *dataPtr;                                                                //pointer to the memory address of array
        size_type used;                                                                     //size of the array or how much of array is used
        size_type capacity;                                                                 //current capacity of the array
        size_type current_index;                                                                    //current index of array
    };
}

#endif

