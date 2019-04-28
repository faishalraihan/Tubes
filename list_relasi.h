#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

#define nextRelation(R) R->nextRelation
#define firstRelation(L) L.firstRelation
#define child(R) R->child
#define parent(R) R->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi nextRelation;
    address_child child;
    address_parent parent;
};

struct List_relasi
{
    address_relasi firstRelation;
};

void createListrelasi(List_relasi &L);
void insertRelation(List_relasi &L, address_relasi R);
void deleteFirstRelation(List_relasi &L, address_relasi &R);
void deleteLastRelation(List_relasi &L, address_relasi &R);
void deleteAfterRelation(address_relasi Prec, address_relasi &R);
address_relasi allocationRelation(address_parent P , address_child C);

#endif // LIST_RELASI_H_INCLUDED
