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
    QSharedPointer<A> m_From;
    QSharedPointer<B> m_to;
    AssociationType m_Type = AssociationType::UNKNOWN;

public:
    Association():KeyedObject(){}

    Association(const Association &toCopy):KeyedObject(toCopy) {
        this->m_Type = toCopy.m_Type;
        this->m_From = toCopy.m_From;
        this->m_to = toCopy.m_to;
    }

    ~Association(){}

    QSharedPointer<A> getAssociationOrigin() const {
        return this->m_From;
    }

    QSharedPointer<B> getAssocationTarget() const{
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

        Builder* setAssociationOrigin(A *origin){
            this->instance->m_From = QSharedPointer<A>(origin);
            return this;
        }

        Builder* setAssociationTarget(B *target){
            this->instance->m_to = QSharedPointer<B>(target);
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


class AssociationFactory {
public:

    template<typename X, typename Y, typename A, typename B>
    static Association<X, Y> *CreateAndCast(A *origin, B *target, AssociationType type) {

        X *x = static_cast<X*>(origin);
        Y *y = static_cast<Y*>(target);

        return typename Association<X, Y>::Builder().setType(type)->setAssociationOrigin(x)->setAssociationTarget(
                y)->build();
    }

    template<typename X, typename Y, typename A, typename B>
    static void OriginTarget_Cast(QSharedPointer<X> &x, QSharedPointer<Y> &y, QSharedPointer<Association<A,B>> &association){
        x = association->getAssociationOrigin().template staticCast<X>();
        y = association->getAssocationTarget().template staticCast<Y>();
        return;
    };
};


#endif //QTEXPERIMENTATION_ASSOCIATION_H
