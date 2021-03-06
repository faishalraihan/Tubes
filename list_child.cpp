#include "list_child.h"

void createListChild(List_child &L) {
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    firstChild(L) = NULL;
    lastChild(L) = NULL;
}

address_child allocationChild(int idChild,string namaChild)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    address_child P = new elmlist_child;
    idChild(P) = idChild;
    namaChild(P) = namaChild;
    nextChild(P) = NULL;
    prevChild(P) = NULL;
    return P;
}
void deallocateChild(address_child &P)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    delete P;
}

void insertFirstChild(List_child &L, address_child P)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
     if(firstChild(L) == NULL && lastChild(L) == NULL)
    {
        firstChild(L) = P;
        lastChild(L) = P;
    }else
    {
        nextChild(P) = firstChild(L);
        prevChild(firstChild(L)) = P;
        firstChild(L) = P;
    }
}
void insertLastChild(List_child &L, address_child P)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    if(firstChild(L) == NULL && lastChild(L) == NULL)
    {
        insertFirstChild(L,P);
    }else
    {
        prevChild(P) = lastChild(L);
        nextChild(lastChild(L)) = P;
        lastChild(L) = P;
    }
}

void insertAfterChild(List_child &L, address_child Prec, address_child P)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    prevChild(nextChild(Prec)) = P;
    nextChild(P) = nextChild(Prec);
    prevChild(P) = Prec;
    nextChild(Prec) = P;
}

void deleteFirstChild(List_child &L, address_child &P)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    if(firstChild(L) != NULL && lastChild(L) != NULL)
    {
      P = firstChild(L);
      if(firstChild(L) != lastChild(L))
      {
          firstChild(L) = nextChild(firstChild(L));
          prevChild(firstChild(L)) = NULL;
          nextChild(P) = NULL;
      }else if(firstChild(L) == lastChild(L))
      {
          deallocateChild(P);
      }
    }
}

void deleteLastChild(List_child &L, address_child &P)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    if(firstChild(L) != NULL && lastChild(L) != NULL)
    {
        P = lastChild(L);
        if(firstChild(L) != lastChild(L))
        {
            lastChild(L) = prevChild(P);
            nextChild(prevChild(P)) = NULL;
            prevChild(P) = NULL;
        }else
        {
            deallocateChild(P);
        }
    }
}

void deleteAfterChild(List_child &L, address_child Prec, address_child &P)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    P = nextChild(Prec);
    nextChild(Prec) = nextChild(P);
    prevChild(nextChild(P)) = Prec;
    prevChild(P) = NULL;
    nextChild(P) = NULL;
}

address_child SearchIdChild(List_child L, int idChld)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    address_child P = firstChild(L);
    while(P != NULL && idChild(P) != idChld)
    {
        P = nextChild(P);
    }
    return P;
}
