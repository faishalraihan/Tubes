#include "list_relasi.h"

void createListrelasi(List_relasi &L)
{
    firstRelation(L) = NULL;
}
address_relasi allocationRelation(address_child C)
{
    address_relasi R = new elmlist_relasi;
    child(R) = C;
    nextRelation(R) = NULL;
    return R;
}

void insertRelation(List_relasi &L, address_relasi R)
{
        if(firstRelation(L) != NULL)
        {
        nextRelation(R) = firstRelation(L);
        firstRelation(L) = R;
        }else
        {
            firstRelation(L) = R;
        }
}

void deleteFirstRelation(List_relasi &L, address_relasi &R)
{
    R = firstRelation(L);
    firstRelation(L) = nextRelation(R);
    nextRelation(R) = NULL;
}

void deleteAfterRelation(address_relasi Prec, address_relasi &R)
{
    if (Prec!=NULL && nextRelation(Prec)!=NULL)
    {
        R = nextRelation(Prec);
        nextRelation(Prec) = nextRelation(R);
        nextRelation(R) = NULL;
    }
}
