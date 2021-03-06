//
// Created by Moad, Karl on 2/13/18.
//

#include <iostream>
#include "classes/Person.h"
#include "classes/Car.h"
#include "classes/House.h"
#include "classes/Association.h"
#include "classes/Utilities.h"
#include "classes/KeyedObject.h"
#include "classes/EventSource.h"
#include "classes/EventReceiver.h"
#include "classes/Reactor.h"
#include "classes/Product.h"
#include <QSharedPointer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>
#include <QList>
#include <bitset>
#include "classes/Formatter.h"
#include "classes/ChangeAction.h"


template<typename int_t = uint64_t>
size_t encodeVarint(int_t value, uint8_t* output) {
    size_t outputSize = 0;
    //While more than 7 bits of data are left, occupy the last output byte
    // and set the next byte flag
    while (value > 127) {
        //|128: Set the next byte flag
        output[outputSize] = ((uint8_t)(value & 127)) | 128;
        //Remove the seven bits we just wrote
        value >>= 7;
        outputSize++;
    }
    output[outputSize++] = ((uint8_t)value) & 127;
    return outputSize;
}
/**
 * Decodes an unsigned variable-length integer using the MSB algorithm.
 * @param value A variable-length encoded integer of arbitrary size.
 * @param inputSize How many bytes are
 */
template<typename int_t = uint64_t>
int_t decodeVarint(uint8_t* input, size_t inputSize) {
    int_t ret = 0;
    for (size_t i = 0; i < inputSize; i++) {
        ret |= (input[i] & 127) << (7 * i);
        //If the next-byte flag is set
        if(!(input[i] & 128)) {
            break;
        }
    }
    return ret;
}


int main() {


    QString obj = "{\"key\":\"{1e98c284-e313-4c9b-8067-05b261a2ac28}\", \"name\":\"John Doe\", \"height\":56, \"gender\":1, \"aka\":[\"Jack\",\"Tader\"], \"children\":[{ \"id\":1, \"name\":\"able\"},{\"id\":2, \"name\":\"kane\"}]}";
    QJsonDocument jdoc = QJsonDocument::fromJson(obj.toUtf8());

    QJsonObject json = jdoc.object();

    std::cout << "Is AKA Array: " << json["aka"].isArray() << std::endl;


    json["locked"] = false;
    std::cout << json["locked"].toBool() << std::endl;

    QString pathex = "Code.system.system_id.key";
    int idx = pathex.lastIndexOf('.');
    QString front = pathex.left(idx);
    QString back = pathex.right(pathex.size()-idx);
    std::cout << "Up to last . :" << front.toStdString() << std::endl;
    std::cout << "After last . :" << back.toStdString() << std::endl;


    QJsonArray akas = json["aka"].toArray();
    for(int i=0; i< akas.size(); i++){
            std::cout << "AKA : " << akas.at(i).toString().toStdString() << std::endl;
    }



    Person *p1 = Person::Builder(json).build();
    Person *p2 = Person::Builder(*p1).setName("Jane Does").setGender(Gender::FEMALE).build();
    Person *p3 = Person::Builder().setName("Jim Doe").setHeightInInches(60).setGender(Gender::MALE).build();

    ChangeAction<Person*> c1(ChangeType::CREATE, p1);
    ChangeAction<Person*> c2(ChangeType::CREATE, p2);
    ChangeAction<Person*> c3(ChangeType::CREATE, p3);

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


    std::cout << "change action 1:" << static_cast<Person*>(c1.value())->getKey().toStdString() << std::endl;
    std::cout << "change action 2:" << static_cast<Person*>(c2.value())->getKey().toStdString() << std::endl;
    std::cout << "change action 3:" << static_cast<Person*>(c3.value())->getKey().toStdString() << std::endl;

    delete p1;
    delete p2;
    delete p3;

//    QList<House*> homes;
//
//    homes.append(House::Builder().setColor("Blue")
//                                               ->setBathroomCount(2)
//                                               ->setFloorCount(1)
//                                               ->setGarageSize(1)->setLivingSpace(1800)
//                                               ->setRoomCount(10)->build());
//
//    homes.append(House::Builder().setColor("Red")
//                                               ->setBathroomCount(1)
//                                               ->setFloorCount(1)
//                                               ->setLivingSpace(1100)
//                                               ->setRoomCount(7)->build());
//
//    homes.append(House::Builder().setColor("Grey")
//                                               ->setBathroomCount(3)
//                                               ->setFloorCount(3)
//                                               ->setLivingSpace(3200)
//                                               ->setGarageSize(4)
//                                               ->setRoomCount(15)->build());
//
//
//    for(int i = 0; i < homes.size(); i++){
//        House *item = homes.at(i);
//        std::cout << "House: " << i
//                  << " Key: " << item->getKey().toStdString()
//                  << " Square Feet: " << item->getSquareFeetLivingSpace()
//                  << " Rooms: " << item->getNumberOfRooms()
//                  << " Bathrooms: " << item->getNumberOfBathrooms()
//                  << " Garage Spaces: " << item->getGarageSize()
//                  << " Number of floors: " << item->getNumberOfFloors() << std::endl;
//    }
//
//    QList<Car*> cars;
//    cars.append(Car::Builder().setVehicleIdentificationNumber("123456")
//                                            ->setCylinderCount(4)
//                                            ->setManualTransmission()
//                                            ->setDriveTrain(DriveTrain::TWO_WD)
//                                            ->setHorsePowerRating(102)
//                                            ->build());
//
//    cars.append(Car::Builder().setVehicleIdentificationNumber("JHFIJADOCNASOPDNC423E")
//                                            ->setCylinderCount(6)
//                                            ->setAutomatictransmission()
//                                            ->setDriveTrain(DriveTrain::TWO_WD)
//                                            ->setHorsePowerRating(189)
//                                            ->build());
//
//    cars.append(Car::Builder().setVehicleIdentificationNumber("NJNQI2NRJKNQ-340-2809284")
//                                            ->setCylinderCount(8)
//                                            ->setManualTransmission()
//                                            ->setDriveTrain(DriveTrain::FOUR_WD)
//                                            ->setHorsePowerRating(350)
//                                            ->build());
//
//    cars.append(Car::Builder().setVehicleIdentificationNumber("38483F0H3047H07402HHH")
//                                            ->setCylinderCount(10)
//                                            ->setManualTransmission()
//                                            ->setDriveTrain(DriveTrain::ALL_WD)
//                                            ->setHorsePowerRating(590)
//                                            ->build());
//
//    cars.append(Car::Builder().setVehicleIdentificationNumber("HHH5H5HH5HH0W90RU4U093QJ")
//                                            ->setCylinderCount(4)
//                                            ->setManualTransmission()
//                                            ->setDriveTrain(DriveTrain::ALL_WD)
//                                            ->setHorsePowerRating(210)
//                                            ->build());
//
//    cars.append(Car::Builder().setVehicleIdentificationNumber("5Y82Y82Y845Y809488948594")
//                                            ->setCylinderCount(6)
//                                            ->setManualTransmission()
//                                            ->setDriveTrain(DriveTrain::FOUR_WD)
//                                            ->setHorsePowerRating(250)
//                                            ->build());
//
//    cars.append(Car::Builder().setVehicleIdentificationNumber("ZZZZZZ")
//                                            ->setCylinderCount(4)
//                                            ->setManualTransmission()
//                                            ->setDriveTrain(DriveTrain::NO_WD)
//                                            ->setHorsePowerRating(90)
//                                            ->build());
//
//    cars.append(Car::Builder().setVehicleIdentificationNumber("987654321")
//                                            ->setCylinderCount(5)
//                                            ->setManualTransmission()
//                                            ->setDriveTrain(DriveTrain::TWO_WD)
//                                            ->setHorsePowerRating(120)
//                                            ->build());
//
//    for(int i = 0; i < cars.size(); i++){
//        Car* c = cars.at(i);
//        std::cout << "Car :" << i
//                  << " Key : " << c->getKey().toStdString()
//                  << " VIN :" << c->getVin().toStdString()
//                  << " Engine Cyl: " << c->getCylinderCount()
//                  << " HP: " << c->getHorsePowerRating()
//                  << " DT: " << (int)c->getDriveTrain()
//                  << std::endl;
//    }
//
//    Car *c = cars.at(0);
//    auto AP2C1 = QSharedPointer<Association<Person,Car>>(Association<Person, Car>::Builder().setType(AssociationType::Person2Car)->setAssociationOrigin(p1)->setAssociationTarget(c)->build());
//
//    std::cout << "Association 1: Person to Car " <<
//              " Key: " << AP2C1->getKey().toStdString() <<
//              " Person: Key: " << AP2C1->getAssociationOrigin()->getKey().toStdString() << " Name: " << AP2C1->getAssociationOrigin()->getName().toStdString() <<
//              " Car: Key:" << AP2C1->getAssocationTarget()->getKey().toStdString() << " VIN: " << AP2C1->getAssocationTarget()->getVin().toStdString() << std::endl;
//
//
//    //Cast a person and car to keyed object and store in an association
//
//    KeyedObject *koFrom = static_cast<KeyedObject*>(p3);
//    KeyedObject *koTo = static_cast<KeyedObject*>(c);
//
//    auto assoc2 = QSharedPointer<Association<KeyedObject,KeyedObject>>(Association<KeyedObject, KeyedObject>::Builder().setType(AssociationType::Person2Car)->setAssociationOrigin(koFrom)->setAssociationTarget(koTo)->build());
//
//    std::cout << "Test KeyedObject Association 2: Person to Car " <<
//              " Key: " << assoc2->getKey().toStdString() <<
//              " Person: Key: " << assoc2->getAssociationOrigin()->getKey().toStdString() <<
//              " Car: Key:" << assoc2->getAssocationTarget()->getKey().toStdString()  << std::endl;
//
//    //Test Factory method
//
//    auto assoc3 = QSharedPointer<Association<KeyedObject,KeyedObject>>(
//            AssociationFactory::CreateAndCast<KeyedObject,KeyedObject,Person,Car>(p2,c, AssociationType::Person2Car));
//
//
//    std::cout << "Test KeyedObject Association 3: Person to Car " <<
//              " Key: " << assoc3->getKey().toStdString() <<
//              " Person: Key: " << assoc3->getAssociationOrigin()->getKey().toStdString() <<
//              " Car: Key:" << assoc3->getAssocationTarget()->getKey().toStdString()  << std::endl;
//
//
//    QSharedPointer<Person> pr;
//    QSharedPointer<Car> cr;
//    AssociationFactory::OriginTarget_Cast<Person, Car, KeyedObject, KeyedObject>(pr,cr,assoc3);
//
//    std::cout << "Casted Association 3 Values back to orig types: Person to Car " <<
//              " Key: " << assoc3->getKey().toStdString() <<
//              " Person: Key: " << pr->getKey().toStdString() << " Name: " << pr->getName().toStdString() <<
//              " Car: Key:" << cr->getKey().toStdString() << " VIN: " << cr->getVin().toStdString() << std::endl;
//
//    //Now make a list to hold various associations i.e. Person -> Car, Car -> House, Person -> House ...etc. all inherit from KeyedObject
//    QList<QSharedPointer<Association<KeyedObject,KeyedObject>>> associations;
//    associations.append(assoc2);
//    associations.append(assoc3);
//
//    //Add more Associations or various relations
//
//    auto h1 = homes.at(0);
//    auto h2 = homes.at(1);
//    auto h3 = homes.at(2);
//
//    for(int i = 0; i < cars.size() ; i++){
//        int part = i % 3;
//        Car* item = cars.at(i);
//
//        switch(part){
//            case 1:
//                associations.append(QSharedPointer<Association<KeyedObject,KeyedObject>>(
//                        AssociationFactory::CreateAndCast< KeyedObject, KeyedObject , House, Car>(h1,item, AssociationType::House2Car)));
//                break;
//            case 2:
//                associations.append(QSharedPointer<Association<KeyedObject,KeyedObject>>(
//                        AssociationFactory::CreateAndCast< KeyedObject, KeyedObject , House, Car>(h2,item, AssociationType::House2Car)));
//                break;
//            default:
//                associations.append(QSharedPointer<Association<KeyedObject,KeyedObject>>(
//                        AssociationFactory::CreateAndCast< KeyedObject, KeyedObject , House, Car>(h3,item, AssociationType::House2Car)));
//                break;
//        }
//    }
//
//    for(int i = 0; i < associations.size(); i++){
//        std::cout << "Associations Object " << i <<
//                  " Type: " << (int)associations.at(i)->getType() <<
//                  " Key: " << associations.at(i)->getKey().toStdString() <<
//                  " From Key: " << associations.at(i)->getAssociationOrigin()->getKey().toStdString() <<
//                  " To Key:" << associations.at(i)->getAssocationTarget()->getKey().toStdString()  << std::endl;
//    }
//
//    //Now reverse the cast and return orig types of the association
//
//
//    EventSource source = EventSource();
//    EventReceiver r1;
//    EventReceiver r2;
//    EventReceiver r3;
//
//    r1.setMyName("John");
//    r2.setMyName("Jane");
//    r3.setMyName("Jimmy");
//
//    source.registerReceiver(&r1, &EventReceiver::printMe);
//    source.registerReceiver(&r2, &EventReceiver::printMe);
//    source.registerReceiver(&r3, &EventReceiver::printMe);
//
//    source.raise();
//
//
//    Reactor r(1);
//    std::cout << "A: " << r.getA() << " B: " << r.getB() << " X: " << r.getX() << std::endl;
//
//
//    std::cout <<" DYNAMIC INSTANTIATION" << std::endl;
//
//    Product *prod1 = Product::getObject("Apple");
//    Product *prod2 = Product::getObject("Banana");
//
//    if(prod1 != nullptr){
//        std::cout << "Product 1 is a: " << prod1->getName() << std::endl;
//    }
//
//    if(prod2 != nullptr){
//        std::cout << "Product 2 is a: " << prod2->getName() << std::endl;
//    }
//
//
//    QString date = "04/28/2006";
//
//    std::cout << "Month: " << date.section('/',0,0).toStdString() << std::endl;
//    std::cout << "Day: " << date.section('/',1,1).toStdString() << std::endl;
//    std::cout << "Year: " << date.section('/',2,2).toStdString() << std::endl;
//
//    QString pathTest = "John.Jacob.Jingleheimer.schmidt";
//
//    std::cout << "Test Start: " << pathTest.section('.',0,0).toStdString() << std::endl;
//    std::cout << "Test rest: " << pathTest.section('.',1).toStdString() << std::endl;

//    std::cout << "Bit packing example and demo" << std::endl;
//
//    uint32_t val;
//
//    std::cout << "Enter an integer value :";
//
//    std::cin >> val;
//
//    std::cout << std::endl;
//
//    std::cout << "Enter a long value :";
//
//    uint64_t  val2;
//    std::cin >> val2;
//
//    std::bitset<32> x(val);
//    std::bitset<64> x2(val2);
//
//    std::cout << "Input value1: " << val << " : " << x << std::endl;
//    std::cout << "Input value2: " << val2 << " : " << x2 << std::endl;
//
//    std::cout << "bit packed value 1 :" << std::endl;
//
//    uint8_t* buf1;
//    size_t outsize = encodeVarint<uint32_t>(val, buf1);
//    std::cout << "output size of packed value1 :" << outsize << std::endl;
//    std::cout << decodeVarint(buf1, outsize) << endl;
//
//    std::cout << "bit packed value 2 :" << std::endl;
//
//    uint8_t* buf2;
//    size_t outsize2 = encodeVarint<uint64_t>(val2, buf2);
//    std::cout << "output size of packed value2 :" << outsize2 << std::endl;
//    std::cout << decodeVarint(buf2, outsize2) << endl;



    std::cout << "\n\nSTARTING VARIADIC TEST-------------------------------" << std::endl;


    Formatter *formatter = new Formatter();

    formatter->add(QString("This"),QString("That"), QString("and"), QString("All"), QString("of It"));
    formatter->print();


    delete formatter;

    std::cout << "____END OF LINE____\n\n";


    return 0;
}
