#include "Mahasiswa.h"

void insertParent(List_parent &L)
{
    int ID;
    string namaMhs;
    cout<<"ID: ";
    cin>>ID;
    cout<<"Nama Mahasiswa: ";
    cin>>namaMhs;

    address_parent P = allocationParent(ID,namaMhs);
    if(SearchIdParent(L,ID) == NULL)
    {
        if(firstParent(L) == NULL || idParent(P) < idParent(firstParent(L)))
        {
            insertFirstParent(L,P);
        }else if(idParent(P) > idParent(lastParent(L)))
        {
            insertLastParent(L,P);
        }else
        {
            address_parent Q = firstParent(L);
            while(idParent(nextParent(Q)) < idParent(P))
            {
                Q = nextParent(Q);
            }
            insertAfterParent(L,Q,P);
        }
    }else
    {
        deallocateParent(P);
    }
}

void printParent(List_parent L)
{
    if(firstParent(L) != NULL)
    {
        address_parent P = firstParent(L);
        while(P != NULL)
        {
            cout<<namaParent(P)<<" - ";
            P = nextParent(P);
        }
    }else
    {
       cout<<"Tidak ada data "<<endl;
    }
}
void insertChild(List_child &L)
{
    int ID;
    string namaDsn;
    cout<<"ID: ";
    cin>>ID;
    cout<<"Nama Dosen: ";
    cin>>namaDsn;

    address_child C = allocationChild(ID,namaDsn);
    if(SearchIdChild(L,ID) == NULL)
    {
        if(firstChild(L) == NULL || idChild(C) < idChild(firstChild(L)))
        {
            insertFirstChild(L,C);
        }else if(idChild(C) > idChild(lastChild(L)))
        {
            insertLastChild(L,C);
        }else
        {
            address_child Q = firstChild(L);
            while(idChild(nextChild(Q)) < idChild(C))
            {
                Q = nextChild(Q);
            }
            insertAfterChild(L,Q,C);
        }
    }else
    {
        deallocateChild(C);
    }
}
void printChild(List_child L)
{
    if(firstChild(L) != NULL)
    {
        address_child C = firstChild(L);
        while(C != NULL)
        {
            cout<<namaChild(C)<<" - ";
            C = nextChild(C);
        }
    }else
    {
       cout<<"Tidak ada data "<<endl;
    }
}
void connect(List_parent &P, List_child C, int idPrnt, int idChld)
{
    address_parent Prnt = SearchIdParent(P,idPrnt);
    address_child Chld = SearchIdChild(C,idChld);
    if(Prnt != NULL && Chld != NULL)
    {
        address_relasi R = allocationRelation(Chld);
        insertRelation(childlist(Prnt),R);
    }
}

bool checkConnection(List_parent P, List_child C,int idPrnt, int idChld)
{
    address_parent Prnt = SearchIdParent(P,idPrnt);
    address_child Chld = SearchIdChild(C,idChld);
    if(Prnt != NULL && Chld != NULL)
    {
        address_relasi R = firstRelation(childlist(Prnt));
        while(R != NULL)
        {
            if(Chld == child(R))
            {

                return true;
            }
        R = nextRelation(R);
        }
    }
    return false;
}
