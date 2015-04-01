#ifndef VOBJECT_H
#define VOBJECT_H

/**
 * 25-03-2015
 *
 * @autor: jairo-m-m
 *
 * esta es clase vobject
 */
template <class Object_Type>
class vObject
{

public:
    vObject(Object_Type);
    vObject<Object_Type> operator= (Object_Type&);
    void setObejctDataType(int);
    Object_Type getObjectData();


private:
    Object_Type data_object;
    int data_type;
};

template <class Object_Type>
vObject<Object_Type>::vObject(Object_Type pdata)
{
    data_object = pdata;
}

template <class Object_Type>
vObject<Object_Type> vObject<Object_Type>::operator =(Object_Type &pdata)
{
    vObject<Object_Type>* vobj = new vObject(pdata);
    //this->data_object = pdata;
    return *vobj;
}

template <class Object_Type>
void vObject<Object_Type>::setObejctDataType(int ptype)
{
    data_type = ptype;
}

template <class Object_Type>
Object_Type vObject<Object_Type>::getObjectData()
{
    return data_object;
}


#endif // VOBJECT_H

