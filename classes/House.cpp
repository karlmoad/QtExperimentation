//
// Created by Karl Moad on 2/13/18.
//

#include "House.h"

House::House(const QJsonObject &json) {
    if(json.contains("key"))
        this->setKey(json["key"].toString(""));

    this->m_Rooms = json["rooms"].toInt(0);
    this->m_LivingSpace = json["sqft"].toInt(0);
    this->m_Floors = json["floors"].toInt(0);
    this->m_Color = json["color"].toString("");
    this->m_Garagesize = json["garage"].toInt(0);
    this->m_Bathrooms = json["baths"].toInt(0);
}

House::House() : KeyedObject() {}

House::House(const House &toCopy) {
    this->m_Color = toCopy.m_Color;
    this->m_Floors = toCopy.m_Floors;
    this->m_Bathrooms = toCopy.m_Bathrooms;
    this->m_Garagesize = toCopy.m_Garagesize;
    this->m_LivingSpace = toCopy.m_LivingSpace;
    this->m_Rooms = toCopy.m_Rooms;
}

House::~House() {
    //qDebug() << "House : " << this->getKey() << "deleted";
}

QString House::getColor() const {
    return this->m_Color;
}

int House::getNumberOfFloors() const {
    return this->m_Floors;
}

int House::getNumberOfRooms() const {
    return this->m_Rooms;
}

int House::getSquareFeetLivingSpace() const {
    return this->m_LivingSpace;
}

int House::getGarageSize() const {
    return this->m_Garagesize;
}

int House::getNumberOfBathrooms() const {
    return this->m_Bathrooms;
}

House::Builder::Builder() {
    this->instance = new House();
}

House::Builder::Builder(const House &house) {
    this->instance = new House(house);
}

House::Builder::Builder(const QJsonObject &json) {
    this->instance = new House(json);
}

House::Builder *House::Builder::setColor(QString color) {
    this->instance->m_Color = color;
    return this;
}

House::Builder *House::Builder::setFloorCount(int floors) {
    this->instance->m_Floors = floors;
    return this;
}

House::Builder *House::Builder::setRoomCount(int rooms) {
    this->instance->m_Rooms = rooms;
    return this;
}

House::Builder *House::Builder::setLivingSpace(int sqft) {
    this->instance->m_LivingSpace = sqft;
    return this;
}

House::Builder *House::Builder::setGarageSize(int cars) {
    this->instance->m_Garagesize = cars;
    return this;
}

House::Builder *House::Builder::setBathroomCount(int bathrooms) {
    this->instance->m_Bathrooms = bathrooms;
    return this;
}

House *House::Builder::build() {
    return this->instance;
}

