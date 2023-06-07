#pragma once
#include <iostream>
#include <exception>

class ExceptionEmptyList : public std::exception{
public:
    virtual const char* what() const throw();
};