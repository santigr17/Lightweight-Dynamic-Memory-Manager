#ifndef BINARYFILES_H
#define BINARYFILES_H

#include<stdio.h>
#include "vRef.h"
#include "DataManager.h"

class BinaryFiles
{
private:
    int _counter;
    FILE* _paginacionFile;
    DataManager* _infoManager;


public:
    BinaryFiles();
    void writeToAFile(vRef pWrittingData);
    vRef readFromFile(int pReadingData);
};

#endif // BINARYFILES_H
