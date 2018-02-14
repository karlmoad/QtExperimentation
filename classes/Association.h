//
// Created by Moad, Karl on 2/14/18.
//

#ifndef QTEXPERIMENTATION_ASSOCIATION_H
#define QTEXPERIMENTATION_ASSOCIATION_H

#include <QString>
#include <QSharedPointer>
#include <QJsonObject>
#include "classes/KeyedObject.h"

enum class AssociationType{
    Person2Car = 0,
    Person2House,
    House2Person,
    House2Car,
    Car2House,
    Car2Person,
    UNKNOWN
};


template <class A, class B>
class Association: public KeyedObject{
private:
    A m_From;
    B m_to;
    AssociationType m_Type = AssociationType::UNKNOWN;

public:
    Association():KeyedObject(){}

    Association(const Association &toCopy):KeyedObject(toCopy) {
        this->m_Type = toCopy.m_Type;
        this->m_From = toCopy.m_From;
        this->m_to = toCopy.m_to;
    }

    ~Association(){
        //qDebug() << "Association: " << this->getKey() << "deleted";
    }

    A getAssociationOrigin() const {
        return this->m_From;
    }

    B getAssocationTarget() const{
        return this->m_to;
    }

    AssociationType getType() const{
        return this->m_Type;
    }


    class Builder{
    private:
        Association<A,B> *instance;
    public:
        Builder(){
            this->instance = new Association<A,B>();
        }

        Builder* setAssociationOrigin(A &origin){
            this->instance->m_From = origin;
            return this;
        }

        Builder* setAssociationTarget(B &target){
            this->instance->m_to = target;
            return this;
        }

        Builder* setType(AssociationType type){
            this->instance->m_Type = type;
            return this;
        }

        Association<A,B>* build(){
            return this->instance;
        }
    };
};

#endif //QTEXPERIMENTATION_ASSOCIATION_H
