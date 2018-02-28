//
// Created by Moad, Karl on 2/27/18.
//

#ifndef QTEXPERIMENTATION_EVENTRECEIVER_H
#define QTEXPERIMENTATION_EVENTRECEIVER_H

#include <iostream>

class EventReceiver {

public:
    EventReceiver()=default;
    void setMyName(std::string const &name);
    void printMe();
private:
    std::string _name;
    std::string _Message="This is private but we are going to print it";
};


#endif //QTEXPERIMENTATION_EVENTRECEIVER_H
