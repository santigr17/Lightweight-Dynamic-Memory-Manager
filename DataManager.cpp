/*
 * DataManager.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: david
 */

#include "DataManager.h"

bool DataManager::instanceFlag = false;
DataManager* DataManager::dataManager = nullptr;
int DataManager:: dFrecuency;
lista_enlazada<DataInfo>* DataManager::listaMetaDatos;

int DataManager:: dumpCounter;
string DataManager::_dumpPath;
/**
 * @brief DataManager::DataManager
 */
DataManager::DataManager() {
    listaMetaDatos = new lista_enlazada<DataInfo>();
    vThread* thread = new vThread((void*)DataManager::threadDumpFrec, nullptr);

}
/**
 * @brief DataManager::insertNewObject
 * @param pType
 * @param pID
 * @param pOffset
 */
void DataManager::insertNewObject(int pType, int pID, int pOffset)
{
    DataInfo* newDato = new DataInfo();
    newDato->initInfo(pType,pID,pOffset);
    listaMetaDatos->add_Dato_Atras(*newDato);
}

lista_enlazada<DataInfo>* DataManager::getMetaDatosList(){return this->listaMetaDatos;}
/**
 * @brief DataManager::deleteData
 * @param pID
 */
void DataManager::deleteData(int pID)
{
    DataInfo toDelete = findDataInfo(pID);
    //listaMetaDatos->eliminar_Dato(toDelete);


}
/**
 * @brief DataManager::findDataInfo
 * @param pID
 * @return
 */
DataInfo DataManager::findDataInfo(int pID)
{
    Nodo<DataInfo>* tmp = listaMetaDatos->getHead();

    for(int i=0;i<listaMetaDatos->length();i++)
    {
        cout << pID << endl;
        if (tmp->getData().getID() == pID)
        {            
            cout << tmp->getData().getID() << endl;
            break;
        }
        tmp = tmp->getNext();

    }


    return tmp->getData();
}
/**
 * @brief DataManager::threadDumpFrec
 * @return
 */
void* DataManager::threadDumpFrec(void*)
{
    dumpFrecuency();
    while(true)
    {

        usleep(1);
    }


}
/**
 * @brief DataManager::dumpFrecuency
 * @return
 */
void* DataManager::dumpFrecuency( )
{

    std::string dumpPath = _dumpPath + std::to_string (dumpCounter);
     pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;

         cout << "dumpFrecuency Empieza " <<endl;

    Nodo<DataInfo>* tmp = listaMetaDatos->getHead();
    std::ofstream dumpFrec(dumpPath);



    for(int i=0;i<listaMetaDatos->length();i++)
    {
        cout << "dump Frec Loop" << endl;
        pthread_mutex_lock(&mutex);
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(dumpFrec.rdbuf()); //redirect std::cout to out.txt!

        cout <<"vRef ID: "<< tmp->getData().getID()<< endl;
        cout <<"vRef Offset: "<< tmp->getData().getOffset() << endl;
        cout <<"vRef ReferenceCounter: "<< tmp->getData().getReferenceCounter() << endl;
        cout <<"vRef Size: "<< tmp->getData().getSize() << endl;
        cout <<"vRef Type: "<< tmp->getData().getType() << endl;
        cout <<"vRef Usage Flag: "<< tmp->getData().isFlaginUse() << endl;
        cout << "---------------------------------------------------------"<< endl;
        cout << " " << endl;
        std::cout.rdbuf(coutbuf);
        cout <<"vRef ID hecho: "<< tmp->getData().getID()<< endl;

        tmp = tmp->getNext();
        pthread_mutex_unlock(&mutex);
        usleep(1);
    }


    dumpCounter++;
    pthread_exit(NULL);
}

void DataManager::setDumpPath(string pDumpPath){ this->_dumpPath = pDumpPath;}







DataManager::~DataManager() {
	instanceFlag = false;
}
/**
 * @brief DataManager::getInstace
 * @return
 */
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




