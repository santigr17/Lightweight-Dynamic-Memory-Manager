#include "vint.h"

vInt::vInt(int pdata){
    vdata = pdata;
}

vInt::~vInt()
{
    //delete;
}

int vInt::getVData()
{
    return vdata;
}

void vInt::setVData(int pdata)
{
    vdata = pdata;
}

vInt vInt::operator =(int a)
{
    vInt *vint = new vInt(a);
    return *vint;
}

vInt operator +(vInt &a, vInt &b)
{
    int value = a.getVData() + b.getVData();
    vInt *vint_result = new vInt(value);
    return *vint_result;
}
