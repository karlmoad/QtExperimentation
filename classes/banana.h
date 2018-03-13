//
// Created by Moad, Karl on 3/13/18.
//

#ifndef QTEXPERIMENTATION_BANANNA_H
#define QTEXPERIMENTATION_BANANNA_H


#include "classes/Product.h"

class Banana: public Product {
public:
    IMPLEMENT_FACTORY(Banana)
    std::string getName() const override;

private:
    std::string _bname = "Banana";
};


#endif //QTEXPERIMENTATION_BANANNA_H
