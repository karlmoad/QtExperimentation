//
// Created by Moad, Karl on 2/27/18.
//

#ifndef QTEXPERIMENTATION_EVENTSOURCE_H
#define QTEXPERIMENTATION_EVENTSOURCE_H

#include <iostream>
#include <functional>
#include <map>
#include "classes/EventReceiver.h"


class EventSource {

public:
    EventSource(): _current_id_(0) {}

    template <typename T>
    void registerReceiver(T *instance, void(T::*func)()) {
        this->connect([=](){
            (instance->*func)();
        });

    }

    void raise() {
        for(auto it : _slots) {
            it.second();
        }
    }

private:
    void connect(std::function<void()> const& slot) const {
        this->_slots.insert(std::make_pair(++_current_id_, slot));
    }

    mutable std::map<int, std::function<void()>> _slots;
    mutable int _current_id_;
};




#endif //QTEXPERIMENTATION_EVENTSOURCE_H
