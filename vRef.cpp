/*
 * vRef.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: santii
 */

#include "vRef.h"


vRef::vRef(int id) {
    this->heap->getInstace();
    this->ID=id;
}

vRef::~vRef() {
	// TODO Auto-generated destructor stub
}


//Sobrecarga del operador "*"
void* vRef:: operator *(void* a){
    //return &a;

}

//Sobrecarga del operador "="
void* vRef::operator =(void *pData){
    if(pData == (vRef*) pData){
             vRef pData=(vRef) pData;
             pData.setId(this->getId());
             return this;
         }
         else if(pData == (vObject*) pData){
             if(pData == (vInt*) pData & sizeof(pData) == sizeof(int)){
                 heap->vMalloc(sizeof(pData),"int");
                 return this;
             }
             else if(pData==(vString*) pData & sizeof(pData)==sizeof(string)){
                heap->vMalloc(sizeof(pData),"string");
             }
             else if(pData==(vChar*) pData & sizeof(pData)==sizeof(char)){
                 heap->vMalloc(sizeof(pData),"char");
             }
             else if(pData==(vArray*) pData & sizeof(pData)==sizeof(int[])){
                 heap->vMalloc(sizeof(pData),"array");
             }
             else if(pData==(vLong*) pData & sizeof(pData)==sizeof(long)){
                 heap->vMalloc(sizeof(pData),"long");
             }
             else if(pData==(vFloat*) pData & sizeof(pData)==sizeof(float)){
                 heap->vMalloc(sizeof(pData),"float");
             }
             else{
                 heap->vMalloc(sizeof(pData),"vObeject");
             }

         }
         else if(pData==(int*) pData){

         }

    }

//Sobrecarga del operador "=="

 bool* vRef:: operator ==(void* pCompare){
     if (this==b.id){
         return true
     }
     else{
         return false
     }

 }
//Sobrecarga del operador "++"
void* vRef:: operator ++(void a){

}
//Sobrecarga del operador "--"
void* vRef:: operator --(){

}
*/
//Sets & Gets
void vRef::setId(int id){
    this->ID->id;
}
int vRef::getId(){
    return this->ID;
}
