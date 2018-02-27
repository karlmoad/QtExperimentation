//
// Created by Moad, Karl on 2/27/18.
//

#ifndef QTEXPERIMENTATION_EVENTSOURCE_H
#define QTEXPERIMENTATION_EVENTSOURCE_H

#include <iostream>
#include "classes/EventReceiver.h"

#define CALL_MEMBER_FN(object,ptrToMember)  ((object->*ptrToMember))
typedef unsigned long (EventReceiver::*functionPtr)();
typedef EventReceiver* receiverPtr;


class EventSource {

public:
    EventSource()=default;
    void registerReceiver(receiverPtr, functionPtr);
    void raiseEvent();

private:
    functionPtr _func = nullptr;
    receiverPtr _receiver = nullptr;

};


#endif //QTEXPERIMENTATION_EVENTSOURCE_H
