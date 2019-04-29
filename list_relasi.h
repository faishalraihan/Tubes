#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "list_child.h"

using namespace std;

#define nextRelation(R) R->nextRelation
#define firstRelation(L) L.firstRelation
#define child(R) R->child


typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi nextRelation;
    address_child child;

};

struct List_relasi
{
    address_relasi firstRelation;
};

void createListrelasi(List_relasi &L);
void insertRelation(List_relasi &L, address_relasi R);
void deleteFirstRelation(List_relasi &L, address_relasi &R);
void deleteLastRelation(List_relasi &L, address_relasi &R);
void deleteAfterRelation(List_relasi &L,address_relasi Prec, address_relasi &R);
address_relasi allocationRelation(address_child C);
void deallocateRelation(address_relasi R);

#endif // LIST_RELASI_H_INCLUDED
