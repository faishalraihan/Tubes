#include "Mahasiswa.h"

//**Insert Procedure
void insertParent(List_parent &L)
{
    int ID;
    string namaMhs;
    cout<<"ID Mahasiswa: ";
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
void insertChild(List_child &L)
{
    int ID;
    string namaDsn;
    cout<<"ID Mata Kuliah: ";
    cin>>ID;
    cout<<"Mata Kuliah: ";
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
//-------------------------------------------------------//

//*Print Procedure

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
void printAll(List_parent P,List_child C)
{
    address_parent Q = firstParent(P);
    address_relasi R;
    while(Q != NULL)
    {
        cout<<namaParent(Q)<<" - ";
        R= firstRelation(childlist(Q));
        if(R != NULL)
        {
            while(R != NULL)
            {
                cout<<namaChild(child(R))<<endl;
                R = nextRelation(R);
            }
        }else{
            cout<<"Tidak ada Data";
        }
        Q = nextParent(Q);
    }
    cout<<endl;
}

void printChildOfParent(List_parent P, List_child C, int idPrnt)
{

}
//-----------------------------------------------------//

//**Connection Procedure/Function
void connect(List_parent &P, List_child C, int idPrnt, int idChld)
{
    address_parent Prnt = SearchIdParent(P,idPrnt);
    address_child Chld = SearchIdChild(C,idChld);
    if(Prnt != NULL && Chld != NULL)
    {
        address_relasi R = allocationRelation(Chld);
        insertRelation(childlist(Prnt),R);
    }else
    {
        cout<<"Data tidak bisa dihubungkan"<<endl;
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
void disconnect(List_parent &P, List_child C, int idPrnt,int idChld)
{
    address_parent Prnt = SearchIdParent(P,idPrnt);
    address_child Chld = SearchIdChild(C,idChld);
    if(Prnt != NULL && Chld != NULL)
    {
        address_relasi R = firstRelation(childlist(Prnt));
        if(child(R) == Chld)
        {
            deleteFirstRelation(childlist(Prnt), R);
            deallocateRelation(R);
        }else
        {
            address_relasi Q = R;
            while(Q != NULL && Chld == child(nextRelation(Q)))
            {
                Q = nextRelation(Q);
            }
            deleteAfterRelation(childlist(Prnt),Q,R);
            deallocateRelation(R);
        }
    }
}

