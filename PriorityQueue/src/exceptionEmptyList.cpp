#include "ExceptionEmptyList.h"

const char *ExceptionEmptyList::what() const throw() {
    return "PriorityQueue empty !";
}
