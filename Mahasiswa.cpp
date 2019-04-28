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
        cout<<"Done "<<endl;
    }else
    {
        cout<<"Nope "<<endl;
    }
}
void cobacoba(List_parent L)
{
    cout<<"mem";
}
