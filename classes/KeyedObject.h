//
// Created by Moad, Karl on 2/13/18.
//

#ifndef QTEXPERIMENTATION_KEYEDOBJECT_H
#define QTEXPERIMENTATION_KEYEDOBJECT_H

#include <QString>
#include "classes/Utilities.h"

class KeyedObject {
public:
    KeyedObject()=default;
    KeyedObject(KeyedObject const &toCopy){
        this->m_key = toCopy.m_key;
    }
    virtual ~KeyedObject()=default;

    QString getKey() const{
        return this->m_key;
    }

    bool isDirty(){
        return m_dirty;
    }

    bool isEditable(){
        return m_editable;
    }

protected:
    void setKey(QString keyVal) {
        if(!keyVal.isNull() && !keyVal.isEmpty()) {
            this->m_key = keyVal;
        }
    }

    void setDirty(bool state){
        m_dirty = state;
    }

    void setEditable(bool editable){
        m_editable = editable;
    }

private:
    QString m_key = Utilities::generateNewKey();
    bool m_dirty = false;
    bool m_editable = true;
};

#endif //QTEXPERIMENTATION_KEYEDOBJECT_H
