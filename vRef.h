
#ifndef VREF_H_
#define VREF_H_

#include "vObject.h"
#include "DataManager.h"
#include "nodo.h"



using namespace std;


class vRef:  public vObject {
private:
    /*int _ID;
	bool _usageFlag;
    vHeap* _heap;*/
    DataManager* _dataManager;
    int getBehindOffset();



public:
    vRef();
	virtual ~vRef();

	vRef* getReference();
    vObject operator *();
    void operator= (vObject* pVObject);
    void operator= (int);
    void operator= (vRef* pVRef);

    bool operator== (vRef* pVRef);
    void operator++ ();
    void operator-- ();




};

#endif /* VREF_H_ */
