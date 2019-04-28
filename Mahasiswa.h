#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <iostream>
#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

void insertParent(List_parent &L);
void insertChild(List_child &L);
void printParent(List_parent L);
void printChild(List_child L);
void connect(List_parent &P,List_child C,int idPrnt,int idChld);
bool checkConnection(List_parent P, List_child C,int idPrnt, int idChld);
void disconnect (List_parent &P, List_child C, int idPrnt, int idChld);
void printAll (List_parent P, List_child C);
void printChildOfParent (List_parent P, List_child C, int idPrnt);
void deleteChild (List_parent &P, List_child &C);
void deleteParent (List_parent &P);


#endif // MAHASISWA_H_INCLUDED
