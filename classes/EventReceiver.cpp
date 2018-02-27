//
// Created by Moad, Karl on 2/27/18.
//

#include "EventReceiver.h"

unsigned long EventReceiver::printMyPrivates() {
    std::cout << this->_Message << std::endl;
    return this->_Message.length();
}
