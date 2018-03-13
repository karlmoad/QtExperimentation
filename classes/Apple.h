//
// Created by Moad, Karl on 3/13/18.
//

#ifndef QTEXPERIMENTATION_APPLE_H
#define QTEXPERIMENTATION_APPLE_H

#include "classes/Product.h"

class Apple: public Product {
public:
    IMPLEMENT_FACTORY(Apple)
    std::string getName() const override;

private:
    std::string _name ="APPLE";
};


#endif //QTEXPERIMENTATION_APPLE_H
