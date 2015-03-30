/*
 * DataInfo.h
 *
 *  Created on: Mar 18, 2015
 *      Author: david
 */

#ifndef DATAINFO_H_
#define DATAINFO_H_

#include <string.h>
#include <iostream>
using namespace std;

#define Int 0
#define String 1
#define Char 2
#define Array 3



class DataInfo {
public:
    DataInfo();

    void initInfo(int pType, int pID, int pOffset);

    bool isFlaginUse();

	void setUsageFlag(bool usageFlag);

	int getOffset();

	void setOffset(int offset);

	int getReferenceCounter();

	void setReferenceCounter(int referenceCounter);

	int getSize() ;

	void setSize(int size);

    string getType() ;

    void setType(string type);

    int getID();

    void setID(int pID);

private:
    int _Size;
    int _Offset;
    string _Type;
    int _ID;
    int _ReferenceCounter;
    bool _UsageFlag;





};

#endif /* DATAINFO_H_ */
