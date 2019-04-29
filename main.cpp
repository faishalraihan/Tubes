#include <iostream>
#include "Mahasiswa.h"
#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

List_parent Mhs;
List_child Mtkl;
List_relasi Rls;
address_parent P;
address_child C;
address_relasi R;


int main()
{
    createListParent(Mhs);
    createListChild(Mtkl);
//    createListrelasi(Rls);

    insertParent(Mhs);
    insertParent(Mhs);

    insertChild(Mtkl);
    insertChild(Mtkl);;

    printParent(Mhs);
    cout<<endl;
    printChild(Mtkl);
    cout<<endl;



    connect(Mhs,Mtkl,1,3);
    connect(Mhs,Mtkl,1,4);
//    connect(Mhs,Dsn,2,4);
    cout<<checkConnection(Mhs,Mtkl,1,3)<<endl;
    cout<<checkConnection(Mhs,Mtkl,1,4)<<endl;

}
