#include <iostream>
#include "Mahasiswa.h"
#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

List_parent Mhs;
List_child Dsn;
address_parent P;
address_child C;
address_relasi R;


int main()
{
    createListParent(Mhs);
    createListChild(Dsn);

    insertParent(Mhs);
    insertParent(Mhs);
    printParent(Mhs);
}
