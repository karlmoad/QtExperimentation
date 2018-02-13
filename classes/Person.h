//
// Created by Moad, Karl on 2/13/18.
//

#ifndef QTEXPERIMENTATION_PERSON_H
#define QTEXPERIMENTATION_PERSON_H

#include <QJsonObject>
#include <QString>
#include "classes/KeyedObject.h"
#include "classes/Gender.h"

class Person : public KeyedObject {
private: //Member variables
    QString m_Name;
    int m_height_inches=0;
    Gender m_Sex = Gender::FEMALE;  //All humans begin as female

    explicit Person(const QJsonObject &json);

public:   //constructors
    Person();
    ~Person();
    Person(const Person &toCopy);

public: //Member functions

    QString getName() const;
    int getHeightInInches() const;
    double getHeightinCentimeters() const;
    Gender getGender() const;
    QJsonObject toJSON() const;

    class Builder{
    private:
        Person *instance;

    public:
        Builder();
        explicit Builder(const Person &person);
        explicit Builder(const QJsonObject &json);
        Builder* setName(QString name);
        Builder* setHeightInInches(int inches);
        Builder* setGender(Gender gender);
        Person* build();
    };
};


#endif //QTEXPERIMENTATION_PERSON_H
