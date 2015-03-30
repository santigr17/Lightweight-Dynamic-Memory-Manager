#include "binaryfiles.h"

BinaryFiles::BinaryFiles()
{
    _infoManager = DataManager::getInstace();
}

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

    fread(tmpVRef, tmpSize, 1,_paginacionFile);

    fclose(_paginacionFile);

    return *tmpVRef;



}

void BinaryFiles::writeToAFile(vRef pWrittingData)
{
    _paginacionFile=fopen("test.bin","wb");
    if (!_paginacionFile)
    {
        printf("Unable to open file!");
        exit(EXIT_SUCCESS);
    }
    int tmpID = pWrittingData.getId();
    int tmpSize = _infoManager->findDataInfo(tmpID).getSize();

    fwrite(&pWrittingData, tmpSize, 1,_paginacionFile);

    fclose(_paginacionFile);

}
