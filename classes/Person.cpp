//
// Created by Moad, Karl on 2/13/18.
//

#include "Person.h"

Person::Person():KeyedObject(){};

Person::~Person(){};

Person::Person(const Person &toCopy) : KeyedObject(toCopy) {
    this->m_Name = QString(toCopy.m_Name);
    this->m_Sex = toCopy.m_Sex;
    this->m_height_inches = toCopy.m_height_inches;
}

Person::Person(const QJsonObject &json) : KeyedObject() {
    if(json.contains("name") && json.contains("key") && json.contains("height") && json.contains("gender")){
        this->setKey(json["key"].toString(""));
        this->m_Name = json["name"].toString("");
        this->m_height_inches = json["height"].toInt(0);
        this->m_Sex = (Gender)json["gender"].toInt(0);  //female
    }
}

QString Person::getName() const {
    return this->m_Name;
}

int Person::getHeightInInches() const {
    return this->m_height_inches;
}

double Person::getHeightinCentimeters() const {
    return (double)(this->m_height_inches * 2.54);
}

Gender Person::getGender() const {
    return this->m_Sex;
}

QJsonObject Person::toJSON() const {
    QJsonObject json;

    json.insert("key", this->getKey());
    json.insert("name", this->m_Name);
    json.insert("height", this->m_height_inches);
    json.insert("gender", (int)this->m_Sex);

    return json;
}

Person::Builder::Builder() {
    this->_instance = new Person();
}

Person::Builder::Builder(const Person &person)
{
    this->_instance = new Person(person);
}

Person::Builder::Builder(const QJsonObject &json)
{
    this->_instance = new Person(json);
}

Person::Builder &Person::Builder::setName(QString name) {
    this->_instance->m_Name = name;
    return *this;
}

Person::Builder &Person::Builder::setHeightInInches(int inches) {
    this->_instance->m_height_inches = inches;
    return *this;
}

Person::Builder &Person::Builder::setGender(Gender gender) {
    this->_instance->m_Sex = gender;
    return *this;
}

Person *Person::Builder::build() {
    return this->_instance;
}






