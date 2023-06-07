#pragma once

#include <iostream>
#include <list>
#include "ExceptionEmptyList.h"
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

template<class T>
T PriorityQueue<T>::poll() {
    if (listQueue.empty())
        throw ExceptionEmptyList();
    T front = listQueue.front();
    listQueue.pop_front();
    return front;
}

template<class T>
void PriorityQueue<T>::push(const T &element ) {
    auto it = listQueue.begin();
    while (it != listQueue.end() && compr(*it, element))
        it++;
    listQueue.insert(it,element);
}