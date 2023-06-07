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



template<class T>
class PriorityQueue {

    std::list<T> listQueue;
    MyComparator<T> compr;

public:

	void push(const T& t); 
	T poll();

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
