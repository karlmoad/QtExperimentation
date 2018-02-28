//
// Created by Moad, Karl on 2/27/18.
//

#include "EventReceiver.h"

void EventReceiver::printMe() {
    std::cout << this->_Message << " - From: " << this->_name << std::endl;
}

void EventReceiver::setMyName(std::string const &name) {
    this->_name = name;
}
