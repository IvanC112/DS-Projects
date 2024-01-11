#include <iostream>
#include "stats.hh"
#include <cassert>

//defining a new namespace and any code in here are considered to be part of namespace main_savitch
//in the statexam.cpp file using this namespace brings all the declarations within scope
namespace main_savitch_2C
{

statistician::statistician() {
  count = 0;
  total = 0.0;
  tinyest = 0.0;
  largest = 0.0;
}

void statistician::next(double r) {
  if (count == 0) {    //starting at count = 0, we will set r to tinyest and largest, so we can have values to compare to
    tinyest = r;
    largest = r;
  }
  else {
    if (r < tinyest) {  //as more arguments are being passed, tinyest and largest are being constantly changed
      tinyest = r;
    }
    if (r > largest) {
      largest = r;
    }
   }
  total+=r;
  count++;
  }

void statistician::reset() {  //resets all variables back to 0
  count = 0;
  total = 0.0;
  tinyest = 0.0;
  largest = 0.0;
}

int statistician::length() const {  //returns the length which is count
  return count;
}

double statistician::sum() const {  //sum is simply the total so return total if called
  return total;
}

double statistician::mean() const {
  assert (count > 0);    //assert checks if condition returns true; if true then returns total/count else returns error message
  return total/count;
}

double statistician::minimum() const {  //if count > 0, then return smallest value
  assert(count > 0);
    return tinyest;
}

double statistician::maximum() const {  //if count > 0, then retunr the largest value 
  assert(count > 0);
  return largest;
}

//given object s1 and s2 that contains all numbers
statistician operator+(const statistician& s1, const statistician& s2) {  
  
  //create a new object that will combine the contents of both object s1 and s2
  statistician combinedObject;  

  //if the objects have 0 entries then return combinedObject as an empty object
  if (s1.length() == 0 && s2.length() ==0) {
    return combinedObject;
  }
  //if s1 is empty combinedObject contains s2
  if (s1.length()  == 0) {
    combinedObject = s2;
  }
  //if s2 is empty combinedObject contains s1
  else if (s2.length() == 0) {
    combinedObject = s1;
  }
  else {
    //didn't know this but you can directly access the private data member if you create a new object of same class, but only with friend function
    combinedObject.count = s1.length() + s2.length();
    combinedObject.total = s1.sum() + s2.sum();
  
  //if else statement to grab the minimum number between object s1 and s2
  if (s1.minimum() < s2.minimum()) {    
    combinedObject.tinyest = s1.minimum();  
  }
  else {
    combinedObject.tinyest = s2.minimum();
  }

  //if else statement to grab the maximum number between s1 and s2
  if (s1.maximum() > s2.maximum()) {     
    combinedObject.largest = s1.maximum();
  }
  else {
    combinedObject.largest = s2.maximum();
  }
  
  }
  return combinedObject;
}

//friend function that only allows for * operator with the object s and a custom data stype double named scale
statistician operator*(double scale, const statistician& s) {
  
  //create a new object called result and multiply object s's contents with scale double
  statistician result;   

  //condition where s equals 0 meaning it can be empty
  if (s.length() == 0) {
    return result;
  }
  else {
    result.count = s.length();
    result.total = scale * s.sum();
    if (scale < 0) {
      result.tinyest = scale*s.maximum();
      result.largest = scale*s.minimum();
    }
    else if (scale >= 0) {
      result.tinyest = scale*s.minimum();
      result.largest = scale*s.maximum();
    }
  }
  return result;
}

bool operator ==(const statistician& s1, const statistician& s2) {

  //if s1 and s2 have zero length then return true
  if (s1.length() == 0 && s2.length() == 0) {  
    return true;
  }
  
  //if the length of both objects are same then everything else has to be the same
  if ((s1.length() == s2.length()) && (s1.sum() == s2.sum()) && (s1.mean() == s2.mean()) && (s1.minimum() == s2.minimum()) & (s1.maximum() == s2.maximum())) {  
    return true;
  }
    
  //everything else return false
  else {
    return false;
  }
  
}

}