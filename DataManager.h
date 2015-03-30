/*
 * DataManager.h
 *
 *  Created on: Mar 18, 2015
 *      Author: david
 */

#ifndef DATAMANAGER_H_
#define DATAMANAGER_H_

#include "DataInfo.h"
#include "lista_enlazada.h"
#include "nodo.h"


class DataManager {
public:
	~DataManager();
	static DataManager* getInstace();
    void insertNewObject(int pType, int pID, int pOffset);
    void deleteData(int pID);
    lista_enlazada<DataInfo> *getMetaDatosList();
    DataInfo findDataInfo(int pID);

private:
	DataManager();
    lista_enlazada<DataInfo>* listaMetaDatos;
	static bool instanceFlag;
	static DataManager * dataManager;

};

#endif /* DATAMANAGER_H_ */
