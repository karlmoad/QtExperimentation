//
// Created by Karl Moad on 3/4/18.
//

#ifndef QTEXPERIMENTATION_REACTOR_H
#define QTEXPERIMENTATION_REACTOR_H


class Reactor {

public:
    Reactor(int i): a(++i), b(++i), x(++i){}

    int getA() const {
        return a;
    }

    int getB() const {
        return b;
    }

    int getX() const {
        return x;
    };


private:
    int a;
    int x;
    int b;
};


#endif //QTEXPERIMENTATION_REACTOR_H
