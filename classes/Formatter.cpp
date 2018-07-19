//
// Created by Moad, Karl on 7/19/18.
//

#include "Formatter.h"

void Formatter::print() {

    for (auto s : _buffer) {
        std::cout << s.toStdString() << " ";
    }
}
