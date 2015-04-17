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
#include "fstream"
#include <unistd.h>
#include "vThread.h"


class DataManager {
public:
	~DataManager();
	static DataManager* getInstace();
    void insertNewObject(int pType, int pID, int pOffset);
    void deleteData(int pID);
    lista_enlazada<DataInfo> *getMetaDatosList();
    DataInfo findDataInfo(int pID);
    static void *dumpFrecuency();
    void setDumpPath(string pDumpPath);
    void setdumpFrecuency(int pFrecuency){dFrecuency = pFrecuency;}

private:
    static int dFrecuency;
	DataManager();
    static lista_enlazada<DataInfo>* listaMetaDatos;
	static bool instanceFlag;
	static DataManager * dataManager;
    static int dumpCounter;
    static string _dumpPath;

    static void* threadDumpFrec(void*);

};

#endif /* DATAMANAGER_H_ */
