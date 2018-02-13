//
// Created by Moad, Karl on 2/13/18.
//

#include <iostream>
#include "classes/Person.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>

int main() {


    QString obj = "{\"key\":\"1e98c284-e313-4c9b-8067-05b261a2ac28\", \"name\":\"John Doe\", \"height\":56, \"gender\":1}";



    QJsonDocument jdoc = QJsonDocument::fromBinaryData(obj.toUtf8());

    Person *p1 = Person::Builder(jdoc.object()).build();


    Person *p2 = Person::Builder(*p1).setName("Jane Doe")->setGender(Gender::FEMALE)->build();

    Person *p3 = Person::Builder().setName("Jim Doe")->setHeightInInches(60)->setGender(Gender::MALE)->build();


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


    std::cout << "Person 3: Key: " << p3->getKey().toStdString()
              << " Name: " << p3->getName().toStdString()
              << " IN: " << p3->getHeightInInches()
              << " CM:" << p3->getHeightinCentimeters()
              << " SEX: " << (p3->getGender() == Gender::FEMALE ? "Female" : "Male")
              << std::endl;

    std::cout << "____END OF LINE____ YOU SILLY RABBIT";



    delete p1;
    delete p2;
    delete p3;

    return 0;
}
