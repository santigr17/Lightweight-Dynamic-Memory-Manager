#include "binaryfiles.h"

BinaryFiles::BinaryFiles()
{
    _infoManager = DataManager::getInstace();
    _sizesINfile = new lista_enlazada<int>();
}

vRef BinaryFiles::readFromFile(int pReadingData)
{
    _paginacionFile=fopen("/home/Documents/QT-Projects/GitHub/test.bin", "rb");
    if (!_paginacionFile)
        {
            printf("Unable to open file!");
            exit(EXIT_SUCCESS);
        }

    vRef* tmpVRef;
    int tmpSize = _infoManager->findDataInfo(pReadingData).getSize();
    char* tmpChar;

    fread(tmpChar, tmpSize, 1,_paginacionFile);

    while(fseek(_paginacionFile, tmpSize, SEEK_CUR)==0)
    {
        fread(&tmpChar, tmpSize, 1, _paginacionFile);// ver con que size moverse

        tmpVRef = (vRef*) tmpChar;
        if(tmpVRef->getId() == pReadingData)
        {
            remakeFile();
            break;
        }
    }
    fclose(_paginacionFile);
    cout << "tmpVREF" << tmpVRef << endl;

    return *tmpVRef;
    }


void BinaryFiles::writeToAFile(vRef pWrittingData)
{
    _paginacionFile=fopen("/home/Documents/QT-Projects/GitHub/test.bin","a+b");
    cout << "llego aqui" << endl;
    if (!_paginacionFile)
    {
        printf("Unable to open file!");
        exit(EXIT_SUCCESS);
    }
    int tmpID = pWrittingData.getId();
    int tmpSize = _infoManager->findDataInfo(tmpID).getSize();
    _sizesINfile->add_Dato_Atras(tmpSize);

    char* tmpVref = (char*)*pWrittingData;
    fwrite(tmpVref, tmpSize, 1,_paginacionFile);

    fclose(_paginacionFile);
}


void BinaryFiles::remakeFile()
{


}
