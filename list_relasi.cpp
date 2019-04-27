#include "list_relasi.h"

void createListrelasi(List_relasi &L) {
    firstRelation(L) = NULL;
}

//void insertFirst(List_relasi &L, address_relasi P) {
//    next(P) = first(L);
//    first(L) = P;
//}
//void insertAfter(address_relasi &Prec, address_relasi P) {
//    next(P) = next(Prec);
//    next(Prec) = P;
//}
