
#ifndef VREF_H_
#define VREF_H_

#include "vobject.h"
using namespace std;

class vRef {
private:
	int _ID;
	bool _usageFlag;
public:
	vRef();
	virtual ~vRef();
	void setId(int pId);
	int getId();
	vRef* getReference();
	vObject* operator* ();
    void operator= (vObject*);
    void operator= (vRef*);
    void operator= (int*);
    bool operator== (vRef*);
    void operator++ ();
    void operator-- ();

};

#endif /* VREF_H_ */
