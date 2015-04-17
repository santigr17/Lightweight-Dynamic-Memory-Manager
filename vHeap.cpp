/*
 * vHeap.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: David Monestel
 */

#include "vHeap.h"

bool vHeap::instanceFlag = false; // Variable static para hacer la clase singleton
vHeap* vHeap::memoryManager = NULL; // Inicializar el vHeap static
docXML* vHeap::XML;



/**
 * @brief vHeap::vMalloc
 * @param pSize El tamaño que el usuario quiere para utilizar de la memoria
 * @param pType El tipo de dato que el usuario almacenara
 * @return un vRef que apuntara al pedazo de memoria que el usuario solicito
 */
vRef* vHeap::vMalloc(size_t pSize, string pType)
{
    if(_Size+pSize > begin_Size+_heapTOTALsize && _Size+pSize > begin_Size+500)
    {
       cout << "No hay suficiente espacio en el vheap"<< endl;
       exit(1);
    }

    if (_Size+pSize > begin_Size + _heapTOTALsize)
    {
        if (XML->getvDebug())
        {
            out.open("out.txt");
            std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
            std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
            cout << "No hay espacio en el vHeap, Se hace el Acomodo de memoria" << endl;

            std::cout.rdbuf(coutbuf);
        }

        freeSpace();
    }

    _vRefID++;

     vRef* memoryReference = new vRef();
     memoryReference->setObjectID(_vRefID);

    *memoryReference = _Size;
    _vRefList->add_Dato_Atras(*memoryReference);


    //memoryReference = _Size[_offSet]; // Se le asigna el pedazo de memoria al vRef;

   if(pType=="int")
   {
       _dataManager->insertNewObject(Int,_vRefID,_offSet);
       if (XML->getvDebug())
       {
           out.open("out.txt");
           std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
           std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

           cout << "dato el vRef creado es un int: " << memoryReference->getObjectData() <<endl;

           std::cout.rdbuf(coutbuf);


       }

   }
   if(pType=="string")
   {
       _dataManager->insertNewObject(String,_vRefID,_offSet);
       if (XML->getvDebug())
       {
           out.open("out.txt");
           std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
           std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

           cout << "dato el vRef creado es un string: " << memoryReference->getObjectData() <<endl;

           std::cout.rdbuf(coutbuf);


       }

   }
   if(pType=="char")
   {
       _dataManager->insertNewObject(Char,_vRefID,_offSet);
       if (XML->getvDebug())
       {
           out.open("out.txt");
           std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
           std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

           cout << "dato el vRef creado es un char: " << memoryReference->getObjectData() <<endl;

           std::cout.rdbuf(coutbuf);
       }

   }
   if(pType=="array")
   {
       _dataManager->insertNewObject(Array,_vRefID,_offSet);
       if (XML->getvDebug())
       {
           out.open("out.txt");
           std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
           std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
           cout << "dato el vRef creado es un array: " << memoryReference->getObjectData() <<endl;
           std::cout.rdbuf(coutbuf);
       }
   }


   _offSet += pSize;
   _Size += pSize;
   if (XML->getvDebug())
   {

       out.open("out.txt");
       std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
       std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
       cout << "offset del vRef:" << _offSet <<endl;
       cout << "size del vRef: " << _Size <<endl;
       std::cout.rdbuf(coutbuf);

   }


   return memoryReference;
}

void vHeap::needThis()
{

}




/**
 * @brief vHeap::freeSpace
 * Manda los archivos que no esten en uso a paginar.
 */
void vHeap::freeSpace()
{
    lista_enlazada<DataInfo>* MetaDatoList = _dataManager->getMetaDatosList();

    Nodo<DataInfo>* tmp = MetaDatoList->getHead();
    for(int i= 0; i< MetaDatoList->length(); i++)
    {
        cout << "metodo freespace" << endl;
        if (!tmp->getData().isFlaginUse())
        {
            makePagination((findVRef(tmp->getData().getID())));

            _offSet= _offSet-(tmp->getData().getSize()); // verificar si se le resta o no al offset o al size
            if(XML->getvDebug())
            {
                out.open("out.txt");
                std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
                std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

                cout << " -----------------MetodoFreeSpace---------------------------" << endl;
                cout<< "tmp ID Mandado a disk: " << tmp->getData().getID()<< endl;
                cout << "ID del vRef a liberar: " << tmp->getData().getID() << endl;
                cout << "offset actual: " << _offSet << endl;
                cout << "size actual: " << _Size << endl;

                std::cout.rdbuf(coutbuf);

            }
            vFree(findVRef(tmp->getData().getID()));
        }

        tmp = tmp->getNext();
    }
    reArrangeData();
}

/**
 * @brief vHeap::reArrangeData
 * Se desfragmenta el vheap
 */
void vHeap::reArrangeData() // VERIFICAR ESTO CUANDO ESTE VOBJECT BIEN
{
    for(int i =0; i<sizeof(_Size); i++)
    {

        if(_Size[i].getObjectData()==0)
        {

            for(int j = i+1; j<_heapTOTALsize; j++)
            {

                if(_Size[j].getObjectData()!=0)
                {

                    _Size[i] = _Size[j];
                    _dataManager->findDataInfo(_Size[j].getObjectID()).
                    setOffset(_dataManager->findDataInfo(_Size[i].getObjectID()).getOffset());
                    if(XML->getvDebug())
                    {
                        out.open("out.txt");
                        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
                        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

                        cout << "offset actual: " << _dataManager->findDataInfo(_Size[j].getObjectID()).getOffset() << endl;

                        std::cout.rdbuf(coutbuf);
                    }
                    _Size[j] = 0;
                    _offSet--;
                    break;
                }
            }
        }
    }
}




/**
 * @brief vHeap::vFree
 * @param needToFree: ID del objeto a liberar
 */
void vHeap::vFree(vRef needToFree)
{
    cout << "vFree empieza" << endl;

    int deleteOffset = _dataManager->findDataInfo(needToFree.getObjectID()).getOffset();
    cout << " tatatata" << endl;

    for(int i=0; i< _dataManager->findDataInfo(needToFree.getObjectID()).getSize();i++)
    {
        _Size[deleteOffset+i] = 0;

    }
    _offSet = _offSet-(_dataManager->findDataInfo(needToFree.getObjectID()).getSize());


    if (XML->getvDebug())
    {
        out.open("out.txt");
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
        cout << "vFree empieza" << endl;
        cout << "offset del dato a eliminar: " << deleteOffset << endl;
        cout << "offset despues de vFree: " <<  _offSet << endl;

        std::cout.rdbuf(coutbuf);
    }

    reArrangeData();
}

/**
 * @brief vHeap::makePagination
 * @param pDato: El vRef que se mandara a paginacion
 */
void vHeap::makePagination(vRef pDato)
{
    cout<< "paginando..." << endl;
    if(_Overweight- sizeof(pDato)<= 0)
    {
        cout << "not Free Space available" << endl;
        exit(1);
    }
    _Overweight = _Overweight+ sizeof(pDato);
    if (XML->getvDebug())
    {
        out.open("out.txt");
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
        cout<< "paginando..." << endl;

        cout << "ID del vRef que será paginado: " << pDato.getObjectID() << endl;

        std::cout.rdbuf(coutbuf);
    }
    _binFILE->writeToAFile(pDato);
    this->vFree(pDato);
    reArrangeData();  
}

/**
 * @brief vHeap::readFromPagination
 * @param pID: El Id del vRef que se usara.
 * @return el vRef solicitado
 */
vRef vHeap::readFromPagination(int pID)
{
    cout << "metodo read from pagination" << endl;
    vRef tmpVRef = _binFILE->readFromFile(pID);// sobrecargar igual del vref para que apunte a lo que se le iguala
    if (XML->getvDebug())
    {
        out.open("out.txt");
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
        cout << "metodo read from pagination" << endl;

        cout << "ID del vRef que será leido: " << tmpVRef.getObjectID() << endl;

        std::cout.rdbuf(coutbuf);
    }
    return tmpVRef;
}


vRef vHeap::findVRef(int pID)
{

        Nodo<vRef>* tmp = _vRefList->getHead();

        for(int i=0;i<_vRefList->length();i++)
        {
            if (tmp->getData().getObjectID() == pID)
            {
                break;
            }
            tmp = tmp->getNext();
        }
        return tmp->getData();
}



lista_enlazada<vRef>* vHeap::getvRefList(){return this->_vRefList;}




/**
 * @brief vHeap::vHeap
 * @param pSize El tamaño de la memoria virtualvoid
 * @param pOverWeight El tamaño del archivo que se utilizara para la paginacion
 */

vHeap::vHeap(int pSize, int pOverWeight)
{
    if(XML->getvDebug())
    {
        out.open("out.txt");
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
        cout << "tamaño del vHeap: " << XML->getSize() << endl;
        cout << "tamaño del overWeight: " << XML->getOverweight() << endl;
        cout << "dump Frecuency: " << XML->getDumpFrecuency() << endl;
        std::cout.rdbuf(coutbuf);
    }





    _vRefList = new lista_enlazada<vRef>();


    _heapTOTALsize = pSize;
    _Overweight = (pOverWeight*pesoOverweight);
    _binFILE = new BinaryFiles(); //le debe de entrar el overweight para la paginacion;
    _Size  = ( vObject* ) malloc(_heapTOTALsize);
    //_vRefList = new vRefList();


   //Se inicializa el GC
    /*  _GarbageCollector = new vGarbageCollector(XML*);   */

    if (_Size == 0)
	{
		printf("ERROR: Out of memory\n");
	}


    for(int i= 0; i<_heapTOTALsize/32;i++)
        _Size[i] = 0;

    begin_Size = _Size;
    _dataManager->setdumpFrecuency(XML->getDumpFrecuency());
    _dataManager->setDumpPath(XML->getDumpPath());
    cout << XML->getDumpPath() << endl;
    _dataManager = DataManager::getInstace();

}

/**
 * @brief vHeap::~vHeap
 * Al terminar vuelve a habilitar la instancia de la clase
 */
vHeap::~vHeap() { free(memoryManager); instanceFlag = false; }

vHeap* vHeap::getInstace()
{
	if(! instanceFlag)
	    {
            XML = new docXML();
            cout<< "size xml: " << XML->getSize()<< endl;
            cout<< "size vObject: " << sizeof(vObject)<< endl;
            memoryManager = new vHeap(XML->getSize(),XML->getOverweight());// 400 = Size ARREGLARLO!.
	        instanceFlag = true;
	        return memoryManager;
	    }
    else
    {
        return memoryManager;
    }
}

int vHeap::getOffset(){return this->_offSet;}
int vHeap::getTotalSize(){return this->_heapTOTALsize;}
