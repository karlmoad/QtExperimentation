//
// Created by Moad, Karl on 2/13/18.
//

#include <iostream>
#include "classes/Person.h"
#include "classes/Car.h"
#include "classes/House.h"
#include <QSharedPointer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QList>

int main() {


    QString obj = "{\"key\":\"{1e98c284-e313-4c9b-8067-05b261a2ac28}\", \"name\":\"John Doe\", \"height\":56, \"gender\":1}";
    
    QJsonDocument jdoc = QJsonDocument::fromJson(obj.toUtf8());

    QSharedPointer<Person> p1 = QSharedPointer<Person>(Person::Builder(jdoc.object()).build());

    QSharedPointer<Person> p2 = QSharedPointer<Person>(Person::Builder(*p1).setName("Jane Doe")->setGender(Gender::FEMALE)->build());

    QSharedPointer<Person>  p3 = QSharedPointer<Person>(Person::Builder().setName("Jim Doe")->setHeightInInches(60)->setGender(Gender::MALE)->build());

    std::cout << "Person 3: Key: " << p3->getKey().toStdString()
              << " Name: " << p3->getName().toStdString()
              << " IN: " << p3->getHeightInInches()
              << " CM:" << p3->getHeightinCentimeters()
              << " SEX: " << (p3->getGender() == Gender::FEMALE ? "Female" : "Male")
              << std::endl;

    std::cout << "Person 2: Key: " << p2->getKey().toStdString()
              << " Name: " << p2->getName().toStdString()
              << " IN: " << p2->getHeightInInches()
              << " CM:" << p2->getHeightinCentimeters()
              << " SEX: " << (p2->getGender() == Gender::FEMALE ? "Female" : "Male")
              << std::endl;

    std::cout << "Person 1: Key: " << p1->getKey().toStdString()
              << " Name: " << p1->getName().toStdString()
              << " IN: " << p1->getHeightInInches()
              << " CM:" << p1->getHeightinCentimeters()
              << " SEX: " << (p1->getGender() == Gender::FEMALE ? "Female" : "Male")
              << std::endl;


    QList<QSharedPointer<House>> homes;

    homes.append(QSharedPointer<House>(House::Builder().setColor("Blue")
                                               ->setBathroomCount(2)
                                               ->setFloorCount(1)
                                               ->setGarageSize(1)->setLivingSpace(1800)
                                               ->setRoomCount(10)->build()));

    homes.append(QSharedPointer<House>(House::Builder().setColor("Red")
                                               ->setBathroomCount(1)
                                               ->setFloorCount(1)
                                               ->setLivingSpace(1100)
                                               ->setRoomCount(7)->build()));

    homes.append(QSharedPointer<House>(House::Builder().setColor("Grey")
                                               ->setBathroomCount(3)
                                               ->setFloorCount(3)
                                               ->setLivingSpace(3200)
                                               ->setGarageSize(4)
                                               ->setRoomCount(15)->build()));


    for(int i = 0; i < homes.size(); i++){
        QSharedPointer<House> item = homes.at(i);
        std::cout << "House: " << i
                  << " Key: " << item->getKey().toStdString()
                  << " Square Feet: " << item->getSquareFeetLivingSpace()
                  << " Rooms: " << item->getNumberOfRooms()
                  << " Bathrooms: " << item->getNumberOfBathrooms()
                  << " Garage Spaces: " << item->getGarageSize()
                  << " Number of floors: " << item->getNumberOfFloors() << std::endl;
    }

    QList<QSharedPointer<Car>> cars;
    cars.append(QSharedPointer<Car>(Car::Builder().setVehicleIdentificationNumber("123456")
                                            ->setCylinderCount(4)
                                            ->setManualTransmission()
                                            ->setDriveTrain(DriveTrain::TWO_WD)
                                            ->setHorsePowerRating(102)
                                            ->build()));

    cars.append(QSharedPointer<Car>(Car::Builder().setVehicleIdentificationNumber("JHFIJADOCNASOPDNC423E")
                                            ->setCylinderCount(6)
                                            ->setAutomatictransmission()
                                            ->setDriveTrain(DriveTrain::TWO_WD)
                                            ->setHorsePowerRating(189)
                                            ->build()));

    cars.append(QSharedPointer<Car>(Car::Builder().setVehicleIdentificationNumber("NJNQI2NRJKNQ-340-2809284")
                                            ->setCylinderCount(8)
                                            ->setManualTransmission()
                                            ->setDriveTrain(DriveTrain::FOUR_WD)
                                            ->setHorsePowerRating(350)
                                            ->build()));

    cars.append(QSharedPointer<Car>(Car::Builder().setVehicleIdentificationNumber("38483F0H3047H07402HHH")
                                            ->setCylinderCount(10)
                                            ->setManualTransmission()
                                            ->setDriveTrain(DriveTrain::ALL_WD)
                                            ->setHorsePowerRating(590)
                                            ->build()));

    cars.append(QSharedPointer<Car>(Car::Builder().setVehicleIdentificationNumber("HHH5H5HH5HH0W90RU4U093QJ")
                                            ->setCylinderCount(4)
                                            ->setManualTransmission()
                                            ->setDriveTrain(DriveTrain::ALL_WD)
                                            ->setHorsePowerRating(210)
                                            ->build()));

    cars.append(QSharedPointer<Car>(Car::Builder().setVehicleIdentificationNumber("5Y82Y82Y845Y809488948594")
                                            ->setCylinderCount(6)
                                            ->setManualTransmission()
                                            ->setDriveTrain(DriveTrain::FOUR_WD)
                                            ->setHorsePowerRating(250)
                                            ->build()));

    cars.append(QSharedPointer<Car>(Car::Builder().setVehicleIdentificationNumber("ZZZZZZ")
                                            ->setCylinderCount(4)
                                            ->setManualTransmission()
                                            ->setDriveTrain(DriveTrain::NO_WD)
                                            ->setHorsePowerRating(90)
                                            ->build()));

    cars.append(QSharedPointer<Car>(Car::Builder().setVehicleIdentificationNumber("987654321")
                                            ->setCylinderCount(5)
                                            ->setManualTransmission()
                                            ->setDriveTrain(DriveTrain::TWO_WD)
                                            ->setHorsePowerRating(120)
                                            ->build()));

    for(int i = 0; i < cars.size(); i++){
        QSharedPointer<Car> c = cars.at(i);
        std::cout << "Car :" << i
                  << " Key : " << c->getKey().toStdString()
                  << " VIN :" << c->getVin().toStdString()
                  << " Engine Cyl: " << c->getCylinderCount()
                  << " HP: " << c->getHorsePowerRating()
                  << " DT: " << (int)c->getDriveTrain()
                  << std::endl;
    }

    std::cout << "____END OF LINE____";

    return 0;
}
