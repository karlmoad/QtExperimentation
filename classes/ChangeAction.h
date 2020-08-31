//
// Created by Karl Moad on 8/30/20.
//

#ifndef QTEXPERIMENTATION_CHANGEACTION_H
#define QTEXPERIMENTATION_CHANGEACTION_H



enum class ChangeType{UNKNOWN=0, CREATE, UPDATE, DELETE};

template<typename T>
class ChangeAction
{
public:
    ChangeAction();
    ChangeAction(ChangeType type, T value);
    virtual ~ChangeAction();

    ChangeType type() const;
    void setType(ChangeType type);

    T value() const;
    void setValue(T value);

private:
    ChangeType _type;
    T _value;
};

template<typename T>
ChangeAction<T>::ChangeAction():_type(ChangeType::UNKNOWN), _value(nullptr)
{}

template<typename T>
ChangeAction<T>::ChangeAction(ChangeType type, T value): _type(type), _value(value)
{}

template<typename T>
ChangeAction<T>::~ChangeAction()
{}

template<typename T>
ChangeType ChangeAction<T>::type() const
{
    return _type;
}

template<typename T>
void ChangeAction<T>::setType(ChangeType type)
{
    _type = type;
}

template<typename T>
T ChangeAction<T>::value() const
{
    return _value;
}

template<typename T>
void ChangeAction<T>::setValue(T value)
{
    _value=value;
}


#endif //QTEXPERIMENTATION_CHANGEACTION_H
