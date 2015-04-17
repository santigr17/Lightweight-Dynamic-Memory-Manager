#include "binaryfiles.h"
/*!
 * \brief BinaryFiles::BinaryFiles
 */
BinaryFiles::BinaryFiles()
{
    _infoManager = DataManager::getInstace();
    _sizesINfile = new lista_enlazada<int>();
}
/**
 * @brief BinaryFiles::readFromFile
 * @param pReadingData
 * @return
 */
vRef BinaryFiles::readFromFile(int pReadingData)
{
    _paginacionFile=fopen("test.bin", "rb");
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
        if(tmpVRef->getObjectID() == pReadingData)
        {
            remakeFile();
            break;
        }
    }
    fclose(_paginacionFile);
    cout << "tmpVREF" << tmpVRef << endl;

    return *tmpVRef;
    }

/**
 * @brief BinaryFiles::writeToAFile
 * @param pWrittingData
 */
void BinaryFiles::writeToAFile(vRef pWrittingData)
{

    _paginacionFile=fopen("test.bin","a+b");
    if (!_paginacionFile)
    {
        printf("Unable to open file!");
        exit(EXIT_SUCCESS);
    }
    int tmpID = pWrittingData.getObjectID();
    int tmpSize = _infoManager->findDataInfo(tmpID).getSize();
    _sizesINfile->add_Dato_Atras(tmpSize);



    char* tmpVref = (char*)&(pWrittingData);


    fwrite(tmpVref, tmpSize, 1,_paginacionFile);

    fclose(_paginacionFile);
}


void BinaryFiles::remakeFile()
{


}
