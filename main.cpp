#include <iostream>
#include "Mahasiswa.h"
#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

List_parent Mhs;
List_child Dsn;
List_relasi Rls;
address_parent P;
address_child C;
address_relasi R;
int IDMhs;
int IDDsn;

int main()
{
    createListParent(Mhs);
    createListChild(Dsn);
//    createListrelasi(Rls);

    insertParent(Mhs);
//    insertParent(Mhs);

    insertChild(Dsn);
//    insertChild(Dsn);

    printParent(Mhs);
    cout<<endl;
    printChild(Dsn);
    cout<<endl;



    connect(Mhs,Dsn,1,3);
//    connect(Mhs,Dsn,2,4);
    cout<<checkConnection(Mhs,Dsn,1,3)<<endl;

}
