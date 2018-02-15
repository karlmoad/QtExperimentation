//
// Created by Karl Moad on 2/13/18.
//

#include "Car.h"

Car::Car(const QJsonObject &json) {
    if(json.contains("key")){
        this->setKey(json["key"].toString(""));
    }

    this->m_Vin = json["vin"].toString("");
    this->m_HP = json["hp"].toInt(0);
    this->m_CylinderCount = json["cylinders"].toInt(0);
    this->m_ManualTransmission = json["manual"].toBool(false);
    this->m_Drivetrain = (DriveTrain)json["drive"].toInt(4);
}

Car::Car() : KeyedObject() {}

Car::Car(const Car &toCopy): KeyedObject(toCopy) {
    this->m_Vin = QString(toCopy.m_Vin);
    this->m_CylinderCount = toCopy.m_CylinderCount;
    this->m_HP = toCopy.m_HP;
    this->m_Drivetrain = toCopy.m_Drivetrain;
    this->m_ManualTransmission = toCopy.m_ManualTransmission;
}

Car::~Car() {}

QString Car::getVin() const {
    return this->m_Vin;
}

int Car::getCylinderCount() const {
    return this->m_CylinderCount;
}

int Car::getHorsePowerRating() const {
    return this->m_HP;
}

DriveTrain Car::getDriveTrain() const {
    return this->m_Drivetrain;
}

bool Car::isManualTransmission() const {
    return this->m_ManualTransmission;
}

Car::Builder::Builder() {
    this->instance = new Car();
}

Car::Builder::Builder(const Car &car) {
    this->instance = new Car(car);
}

Car::Builder::Builder(const QJsonObject &json) {
    this->instance = new Car(json);
}

Car::Builder *Car::Builder::setVehicleIdentificationNumber(QString vin) {
    this->instance->m_Vin = vin;
    return this;
}

Car::Builder *Car::Builder::setCylinderCount(int cylinders) {
    this->instance->m_CylinderCount = cylinders;
    return this;
}

Car::Builder *Car::Builder::setHorsePowerRating(int hp) {
    this->instance->m_HP = hp;
    return this;
}

Car::Builder *Car::Builder::setDriveTrain(DriveTrain driveTrain) {
    this->instance->m_Drivetrain = driveTrain;
    return this;
}

Car::Builder *Car::Builder::setManualTransmission() {
    this->instance->m_ManualTransmission = true;
    return this;
}

Car::Builder *Car::Builder::setAutomatictransmission() {
    this->instance->m_ManualTransmission = false;
    return this;
}

Car *Car::Builder::build() {
    return this->instance;
}
