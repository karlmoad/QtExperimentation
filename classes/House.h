//
// Created by Karl Moad on 2/13/18.
//

#ifndef QTEXPERIMENTATION_HOUSE_H
#define QTEXPERIMENTATION_HOUSE_H

#include <QString>
#include <QDebug>
#include "classes/KeyedObject.h"

class House : public KeyedObject{
private:
    QString m_Color;
    int m_Floors = 0;
    int m_Rooms = 0;
    int m_Bathrooms = 0;
    int m_LivingSpace = 0;
    int m_Garagesize = 0;

    explicit House(const QJsonObject &json);

public:
    House();
    House(const House &toCopy);
    ~House();

    QString getColor() const;
    int getNumberOfFloors() const;
    int getNumberOfRooms() const;
    int getSquareFeetLivingSpace() const;
    int getNumberOfBathrooms() const;
    int getGarageSize() const;


    class Builder{
    private:
        House *instance;
    public:
        Builder();
        explicit Builder(const House &house);
        explicit Builder(const QJsonObject &json);
        Builder* setColor(QString color);
        Builder* setFloorCount(int floors);
        Builder* setRoomCount(int rooms);
        Builder* setLivingSpace(int sqft);
        Builder* setBathroomCount(int bathrooms);
        Builder* setGarageSize(int cars);
        House* build();
    };
};


#endif //QTEXPERIMENTATION_HOUSE_H
