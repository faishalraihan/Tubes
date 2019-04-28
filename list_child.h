#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define namaChild(A) A->namaChild
#define idChild(A) A->idChild
#define nextChild(P) P->nextChild
#define prevChild(P) P->prevChild
#define firstChild(L) L.firstChild
#define lastChild(L) L.lastChild

using namespace std;

typedef struct elmlist_child *address_child;

struct elmlist_child{
    string namaChild;
    int idChild;
    address_child nextChild;
    address_child prevChild;
};

struct List_child{
    address_child firstChild;
    address_child lastChild;
};

void createListChild(List_child &L);
void insertFirstChild(List_child &L, address_child P);
void insertLastChild(List_child &L, address_child P);
void insertAfterChild(address_child Prec, address_child P);
void deleteFirstChild(List_child &L, address_child &P);
void deleteLastChild(List_child &L, address_child &P);
void deleteAfterChild(List_child &L, address_child Prec, address_child &P);
address_child allocationChild(int idChild, string namaChild);
void deallocateChild(address_child &P);
address_child SearchIdChild(List_child L, int idChild);



#endif // LIST_CHILD_H_INCLUDED
