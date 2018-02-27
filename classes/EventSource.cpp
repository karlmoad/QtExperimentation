//
// Created by Moad, Karl on 2/27/18.
//

#include "EventSource.h"

void EventSource::registerReceiver(receiverPtr rec, functionPtr func) {
    this->_func = func;
    this->_receiver = rec;
}

void EventSource::raiseEvent() {
    if(this->_func != nullptr && this->_receiver != nullptr){
        std:: cout << "Length of event message: " << (_receiver->*_func)() << std::endl;  // <- Works
        //std:: cout << "Length of event message: " << CALL_MEMBER_FN(this->_receiver, this->_func) << std::endl; <- does not work
    }
}
