//
// Created by Moad, Karl on 7/19/18.
//

#ifndef QTEXPERIMENTATION_FORMATTER_H
#define QTEXPERIMENTATION_FORMATTER_H

#include <vector>
#include <QString>
#include <iostream>

class Formatter {

public:
    Formatter()=default;
    ~Formatter()=default;

    //base case handeling of variadic add function
    void add(){
        _buffer.push_back("\n");
    }

    template <typename T, typename... Types>
    void add(T var1, Types... var2) {
        _buffer.push_back(var1);
        add(var2...);
    }


    void print();

private:
    std::vector<QString> _buffer;
};


#endif //QTEXPERIMENTATION_FORMATTER_H
