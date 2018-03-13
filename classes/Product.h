//
// Created by Moad, Karl on 3/13/18.
//

#ifndef QTEXPERIMENTATION_PRODUCT_H
#define QTEXPERIMENTATION_PRODUCT_H

#include <string>
#include <iostream>
#include <map>


#define IMPLEMENT_FACTORY(TYPE) \
   Product* create() const { return new TYPE(); }

#define REGISTER_PROTOTYPE(TYPE) \
   Product* TYPE ## _myProtoype = \
      Product::_registerPrototype(#TYPE, new TYPE());

class Product {
public:
    Product();
    ~Product();
    virtual std::string getName() const =0;
    static Product* getObject(std::string type);
    static Product* _registerPrototype(std::string id, Product *product);
private:
    static std::map<std::string, Product*> _objects;
};


#endif //QTEXPERIMENTATION_PRODUCT_H
