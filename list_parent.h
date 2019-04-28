#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "list_relasi.h"

#define firstParent(L) L.firstParent
#define lastParent(L) L.lastParent
#define idParent(P) P-> idParent
#define nextParent(P) P->nextParent
#define prevParent(P) P->prevParent
#define childlist(P) P->childlist
#define namaParent(P) P->namaParent

using namespace std;

typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    int idParent;
    string namaParent;
    List_relasi childlist;
    address_parent nextParent;
    address_parent prevParent;
};

struct List_parent {
    address_parent firstParent;
    address_parent lastParent;
};

void createListParent(List_parent &L);
void insertFirstParent(List_parent &L, address_parent P);
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_parent &L, address_parent P);
void deleteFirstParent(List_parent &L, address_parent &P);
void deleteLastParent(List_parent &L, address_parent &P);
void deleteAfterParent(List_parent &L, address_parent Prec, address_parent &P);
address_parent SearchIdParent(List_parent L,int idParent);
address_parent allocationParent(int idParent, string namaParent);
void deallocateParent(address_parent &P);



#endif // LIST_PARENT_H_INCLUDED
