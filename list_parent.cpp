#include "list_parent.h"

void createListParent(List_parent &L)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    firstParent(L) = NULL;
    lastParent(L) = NULL;
}

address_parent allocationParent(int idParent, string namaParent)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
     address_parent P = new elmlist_parent;
     idParent(P) = idParent;
     namaParent(P) = namaParent;
     createListrelasi(childlist(P));
     nextParent(P) = NULL;
     prevParent(P) = NULL;
     return P;
}
void deallocateParent(address_parent &P)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    delete P;
}

void insertFirstParent(List_parent &L, address_parent P)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    if(firstParent(L) == NULL && lastParent(L) == NULL)
    {
        firstParent(L) = P;
        lastParent(L) = P;
    }else
    {
        nextParent(P) = firstParent(L);
        prevParent(firstParent(L)) = P;
        firstParent(L) = P;
    }
}

void insertLastParent(List_parent &L, address_parent P)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    if(firstParent(L) == NULL && lastParent(L) == NULL)
    {
        insertFirstParent(L,P);
    }else
    {
        prevParent(P) = lastParent(L);
        nextParent(lastParent(L)) = P;
        lastParent(L) = P;
    }
}
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    if(firstParent(L) != NULL)
    {
        nextParent(P) = nextParent(Prec);
        prevParent(P) = Prec;
        nextParent(Prec) = P;
        prevParent(nextParent(P)) = P;
    }
}
void deleteFirstParent(List_parent &L,address_parent &P)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    if(firstParent(L) != NULL && lastParent(L) != NULL)
    {
      P = firstParent(L);
      if(firstParent(L) != lastParent(L))
      {
          firstParent(L) = nextParent(firstParent(L));
          prevParent(firstParent(L)) = NULL;
          nextParent(P) = NULL;
      }else if(firstParent(L) == lastParent(L))
      {
          deallocateParent(P);
      }
    }
}
void deleteLastParent(List_parent &L, address_parent &P)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    if(firstParent(L) != NULL && lastParent(L) != NULL)
    {
        P = lastParent(L);
        if(firstParent(L) != lastParent(L))
        {
            lastParent(L) = prevParent(P);
            nextParent(prevParent(P)) = NULL;
            prevParent(P) = NULL;
        }else
        {
            deallocateParent(P);
        }
    }
}

void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    P = nextParent(Prec);
    nextParent(Prec) = nextParent(P);
    prevParent(nextParent(P)) = Prec;
    prevParent(P) = NULL;
    nextParent(P) = NULL;
}
address_parent SearchIdParent(List_parent L, int idPrnt)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    address_parent P = firstParent(L);
    while(P != NULL && idParent(P) != idPrnt)
    {
        P = nextParent(P);
    }
    return P;
}


