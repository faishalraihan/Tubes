#include "list_relasi.h"

void createListrelasi(List_relasi &L)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    firstRelation(L) = NULL;
}
address_relasi allocationRelation(address_child C)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    address_relasi R = new elmlist_relasi;
    child(R) = C;
    nextRelation(R) = NULL;
    return R;
}
void deallocateRelation(address_relasi R)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    delete R;
}

void insertRelation(List_relasi &L, address_relasi R)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
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
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    R = firstRelation(L);
    firstRelation(L) = nextRelation(R);
    nextRelation(R) = NULL;
}

void deleteAfterRelation(List_relasi &L,address_relasi Prec, address_relasi &R)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    if (Prec!=NULL && nextRelation(Prec)!=NULL)
    {
        R = nextRelation(Prec);
        nextRelation(Prec) = nextRelation(R);
        nextRelation(R) = NULL;
    }
}
