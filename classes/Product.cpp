//
// Created by Moad, Karl on 3/13/18.
//

#include "Product.h"


std::map<std::string, Product*> Product::_objects = std::map<std::string, Product*>();

Product* Product::_registerPrototype(std::string id, Product *product) {

    std::cout << "Registering Prototype: " << id << std::endl;
    Product::_objects.insert(std::make_pair(id, product));
    return product;
}

Product *Product::getObject(std::string type) {
    if(Product::_objects.find(type) != Product::_objects.end())
        return Product::_objects[type];
    return nullptr;
}

Product::Product() {

}

Product::~Product() {

}
