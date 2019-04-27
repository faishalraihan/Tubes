#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

#define nextRelation(R) R->next
#define firstRelation(L) L.firstRelation
#define child(R) R->child
#define parent(R) R->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_child child;
    address_parent parent;
    address_relasi nextRelation;
};

struct List_relasi
{
    address_relasi firstRelation;
};

void createListrelasi(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);

#endif // LIST_RELASI_H_INCLUDED
