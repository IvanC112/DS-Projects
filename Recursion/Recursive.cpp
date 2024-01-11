
#include <iostream>
#include "Recursive.hh"
#include <cassert>

using namespace std;

//outs is simply cout instead of acutally writing cout
//n = 8 then binary version is, 8 4 2 1 = 1000
//recursive call will be 8, 4, 2, 1, but the execution will be 1, 2, 4, 8,
//                         1 0 0 0                                 1 0 0 0
//thinking recursively there needs to be a base case to stop the infinite recursion, which the variant expression is n and everytime a recursion call is made we decrement n such that when it reaches 1 the recursion stops.

//Variant Expression: N is the variant expression in which will be decremented until reaching base case of 1 therefore terminating all recursive calls
//Threshold: N == 1
void binary_print(ostream& outs, unsigned int n) {  
  if (n == 0) {  
    outs << 0;
  }
    else if (n==1) {
      outs << 1;
    }
    else {
      binary_print(outs, n/2);
      outs << n%2;
    }
}

//Variant Expression: M is the variant variable that will incremented until reaching the value of n therefore terminating all recursive calls
//Threshold: The threshold is m <= n
void triangle(ostream& outs, unsigned int m, unsigned int n) {
   if (m <= n) {
     for (size_t i = 0; i < m; ++i){
       outs << "*";
     }
     outs << endl;
     triangle(outs, m + 1, n);
     for (size_t i = 0; i < m; ++i){
       outs << "*";
     }
     outs << endl;
    }
}

//in order to rewrite this function such that the runtime is log(n), we need to rewrite it such that the input value or the problem itself is being divided by 2 each time the recursive call is made
//using the formula x^2n = x^n * x^n

//Variant Expression: The variant expression is n varaible, dividing the variable n by 2 but when it reaches o, the function termiantes all recursive calls when n == 0 as it simply returns 1; any value to the power of 0 is 1
//Threshold: n == 0, the base case where if we pass all recursive calls are temrinated
double power(double x, int n) {
  if (x == 0) {
    assert(n > 0);
    return 0;
  }
  if (n == 0) {
    return 1.0;
  }
  if (n > 0) {
    if (n % 2 == 0) {
      return power(x, n/2) * power(x, n/2);
    }
    else {
      return x * power(x, n/2) * power(x, n/2);
    }
  } 
  else {
    return 1.0 / power(x, -n);
  }
}

// precondition: m <=n; 
//postcondition: print out the above pattern by calling number from m to n 

//Variant Expression: incrementing m until it reaches the same value as n, therefore ending infinite recursive calls
//Threshold: m <= n
void indented_sentences(size_t m, size_t n, size_t indentation) {
  if (m <= n) {
    for (unsigned int i =0; i <indentation; ++i) {
      cout << " "; 
    }
    cout << "This was written by calling number " << m << endl;
    indented_sentences(m+1, n, indentation+2);
    for (unsigned int j= 0; j < indentation; ++j) {
      cout << " ";
    }
    cout << "This was also written by calling number " << m << endl;
  }
}



