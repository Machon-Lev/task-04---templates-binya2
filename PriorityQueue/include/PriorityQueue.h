#pragma once

#include <iostream>
#include <list>
#include <exception>
template<class T>
struct MyComparator {
    bool operator()(T a, T b) const {
        return a < b;
    }
};

// any templates?
template<class T>
class PriorityQueue {
   
public:
	
   // You need to complete the implement : 
	void push(const T& t); 
	T poll();

private:
    // add relevant data members
    std::list<T> listQueue;
    MyComparator<T> compr;
};
