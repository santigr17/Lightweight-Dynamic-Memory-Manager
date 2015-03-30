/*
 * DataInfo.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: david
 */

#include "DataInfo.h"

DataInfo::DataInfo()
{

}

void DataInfo::initInfo(int pType,int pID,int pOffset)
{
    this->setOffset(pOffset);
    this->setID(pID);

    if (pType == Int)
    {
        this->setType("int");
        this->setSize(sizeof(int));
    }

    if (pType == String)
    {
        this->setType("string");
        this->setSize(sizeof(string));
    }
    if (pType == Char)
    {
        this->setType("char");
        this->setSize(sizeof(char));
    }
    if (pType == Array)
    {
        this->setType("array");
        this->setSize(sizeof(int));
    }

}
void DataInfo::setID(int pID){this->_ID = pID;}
int DataInfo::getID(){return this->_ID;}

void DataInfo::setType(string type){this->_Type = type;}
string DataInfo::getType(){return this->_Type;}

void DataInfo::setSize(int size){this->_Size = size;}
int DataInfo::getSize(){return this->_Size;}

void DataInfo::setReferenceCounter(int referenceCounter){ this->_ReferenceCounter = referenceCounter;}
int DataInfo::getReferenceCounter(){return this->_ReferenceCounter;}

void DataInfo::setOffset(int offset){this->_Offset = offset;}
int DataInfo::getOffset(){return this->getOffset();}

bool DataInfo::isFlaginUse()
{
    if(this->_UsageFlag =false)return false;
    else return true;
}

void DataInfo::setUsageFlag(bool usageFlag){ this->_UsageFlag = usageFlag;}
