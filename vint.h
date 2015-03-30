#ifndef VINT_H
#define VINT_H

class vInt
{
public:
    vInt(int);
    ~vInt();
    vInt operator=(int);
    friend vInt operator+(vInt&,vInt&);
    int getVData();
private:
    int vdata;
    void setVData(int);
};

#endif // VINT_H
