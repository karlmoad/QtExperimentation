//
// Created by Karl Moad on 2/13/18.
//

#ifndef QTEXPERIMENTATION_CAR_H
#define QTEXPERIMENTATION_CAR_H

#include <QString>
#include <QDebug>
#include "classes/KeyedObject.h"

enum class DriveTrain{
    TWO_WD = 0,
    FOUR_WD = 1,
    ALL_WD = 3,
    NO_WD = 4,
};

class Car : public KeyedObject {
private:
    QString m_Vin;
    int m_CylinderCount = 0;
    int m_HP;
    DriveTrain m_Drivetrain = DriveTrain::NO_WD;
    bool m_ManualTransmission = true;

    explicit Car(const QJsonObject &json);

public:
    Car();
    Car(const Car &toCopy);
    ~Car();
    QString getVin() const;
    int getCylinderCount() const;
    int getHorsePowerRating() const;
    DriveTrain getDriveTrain() const;
    bool isManualTransmission() const;

public:

    class Builder{
    private:
        Car *instance;
    public:
        Builder();
        explicit Builder(const Car &car);
        explicit Builder(const QJsonObject &json);
        Builder* setVehicleIdentificationNumber(QString vin);
        Builder* setCylinderCount(int cylinders);
        Builder* setHorsePowerRating(int hp);
        Builder* setDriveTrain(DriveTrain driveTrain);
        Builder* setManualTransmission();
        Builder* setAutomatictransmission();
        Car* build();
    };
};


#endif //QTEXPERIMENTATION_CAR_H
