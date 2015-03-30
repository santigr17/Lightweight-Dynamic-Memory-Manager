/*
 * DataManager.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: david
 */

#include "DataManager.h"

bool DataManager::instanceFlag = false;
DataManager* DataManager::dataManager = nullptr;

DataManager::DataManager() {
    listaMetaDatos = new lista_enlazada<DataInfo>();
}

void DataManager::insertNewObject(int pType,int pID, int pOffset)
{
    DataInfo* newDato = new DataInfo();
    newDato->initInfo(pType,pID,pOffset);
    listaMetaDatos->add_Dato_Atras(*newDato);
}

lista_enlazada<DataInfo>* DataManager::getMetaDatosList(){return this->listaMetaDatos;}

void DataManager::deleteData(int pID)
{
    DataInfo toDelete = findDataInfo(pID);
    //listaMetaDatos->eliminar_Dato(toDelete);


}

DataInfo DataManager::findDataInfo(int pID)
{
    Nodo<DataInfo>* tmp = listaMetaDatos->getHead();

    for(int i=0;i<listaMetaDatos->length();i++)
    {
        if (tmp->getData().getID() == pID)
        {
            break;
        }
        tmp = tmp->getNext();
    }
    return tmp->getData();

}







DataManager::~DataManager() {
	instanceFlag = false;
}

DataManager* DataManager::getInstace()
{
	if(! instanceFlag)
	    {
            dataManager = new DataManager();
	        instanceFlag = true;
	        return dataManager;
	    }
	    else
	    {
	        return dataManager;
	    }
}




