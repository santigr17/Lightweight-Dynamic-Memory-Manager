#ifndef VOBJECT_H
#define VOBJECT_H

/*#include "vHeap.h"
#include "DataManager.h"*/

class vObject
{
private:
    int _ID;
    int data_type;
    bool _usageFlag;
    void* _Data;
    int data2;
    //vHeap* _heap;
    //DataManager* _dataManager;


public:
    vObject();
    void setObjectUsageFlag(bool);
    bool getObjectUsageFlag();
    void setObjectData(void*);
    void *getObjectData();
    void setObjectID(int);
    int getObjectID();
    void operator =(int);
    void setObjectType(int);
    int getObjectType();

    /*vHeap* getHeap();
    DataManager* getDataManager();*/
};

#endif // VOBJECT_H
