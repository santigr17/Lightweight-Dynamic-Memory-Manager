
#ifndef VREF_H_
#define VREF_H_

#include "vobject.h"
using namespace std;

class vRef {
private:
	int _ID;
	bool _usageFlag;
public:
	vRef(int);
	virtual ~vRef();
	int getId();
	vRef* getReference();
	vObject* operator* ();
    void operator= (void*);
    bool operator== (vRef*, vRef*);

};

#endif /* VREF_H_ */
