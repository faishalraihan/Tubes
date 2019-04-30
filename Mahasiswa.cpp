#include "Mahasiswa.h"

//**Insert Procedure
void insertParent(List_parent &L)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
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
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
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
   /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
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
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
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
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
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
            cout<<"Belum mengambil menu";
        }
        Q = nextParent(Q);
    }
    cout<<endl;
}

void printChildOfParent(List_parent P, List_child C, int idPrnt)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    address_parent Prnt = SearchIdParent(P,idPrnt);
    if (Prnt !=NULL )
    {
        cout<< "Mahasiswa dengan nama "<< namaParent(Prnt)<< " mengambil mata kuliah : ";
        address_relasi R = firstRelation(childlist(Prnt));
        if (R!=NULL)
        {
            while (R!=NULL)
            {
            cout<< namaChild(child(R)) << ", ";
            R=nextRelation(R);
            }
        }
        else
        {
            cout<< " Mahasiswa belum mengambil mata kuliah";
        }
    }
    else
    {
            cout<< " Mahasiswa tidak ditemukan ";
    }
}
//-----------------------------------------------------//

//**Connection Procedure/Function
void connect(List_parent &P, List_child C, int idPrnt, int idChld)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
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
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
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
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
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

void deleteParent(List_parent &P)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    int id;
    cout << "Masukkan ID mahasiswa yang ingin dihapus : ";
    cin>> id;
    address_parent Prnt = SearchIdParent(P, id);
    if (Prnt!=NULL)
    {
        address_relasi tmp, relasi = firstRelation(childlist(Prnt));
        while (relasi!=NULL)
        {
            tmp= relasi;
            relasi= nextRelation(relasi);
            deleteFirstRelation(childlist(Prnt),tmp);
            deallocateRelation(tmp);
        }
        if (Prnt == firstParent(P))
        {
            deleteFirstParent(P,Prnt);
        }
        else if (Prnt == lastParent(P))
        {
            deleteLastParent(P,Prnt);
        }
        else
        {
            address_parent prec = prevParent(Prnt);
            deleteAfterParent(P, prec, Prnt);
        }
        deallocateParent(Prnt);
        cout << "Mahasiswa berhasil dihapus "<<endl;
    }else
    {
        cout << "ID mahasiswa tidak ditemukan "<<endl;
    }
}

void deleteChild(List_parent &P, List_child &C)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    int id;
    cout << "Masukkan ID matakuliah yang ingin dihapus : ";
    cin>> id;
    address_child prec, Chld = SearchIdChild(C, id);
    if (Chld!=NULL)
    {
        address_parent Prnt = firstParent(P);
        while (Prnt!=NULL)
        {
            address_relasi tmp, relasi = firstRelation(childlist(Prnt));
            while (relasi !=NULL){
                if(child(relasi)==Chld)
                {
                    relasi = nextRelation(relasi);
                    deleteFirstRelation(childlist(Prnt),tmp);
                    deallocateRelation(tmp);
                }else if (nextRelation(relasi)!=NULL && child(nextRelation(relasi))==Chld)
                {
                    deleteAfterRelation(childlist(Prnt),relasi,tmp);
                    deallocateRelation(tmp);
                } else {
                    relasi=nextRelation(relasi);
                }
                Prnt = nextParent(Prnt);
            }
        }
            if (Chld == firstChild(C))
            {
                deleteFirstChild(C,Chld);
            }
            else if (Chld == lastChild(C))
            {
                deleteLastChild(C,Chld);
            }
            else
            {
                prec = prevChild(Chld);
                deleteAfterChild(C, prec, Chld);
            }
        deallocateChild(Chld);
        cout << "Matakuliah berhasil dihapus "<<endl;
    }else
    {
            cout << "Matakuliah tidak ditemukan";
    }
}

void jumlahmatkul(List_parent P, List_child C)
{
    /** NAMA: ADITYA RAMADHAN
        NIM : 1301184380
    */
    int jumlahmtkl=0;
    cout<< "Masukkan Id mahasiswa yang ingin diketahui mengambil berapa matkul : ";
    int idPrnt;
    cin >> idPrnt;
    address_parent Prnt = SearchIdParent(P,idPrnt);
    if (Prnt !=NULL )
    {
        address_relasi R = firstRelation(childlist(Prnt));
        if (R!=NULL)
        {
            while (R!=NULL)
            {
            jumlahmtkl=jumlahmtkl+1;
            R=nextRelation(R);
            }
            cout<< "Mahasiswa dengan nama "<< namaParent(Prnt)<< " mengambil mata kuliah sebanyak : " << jumlahmtkl<<endl;
        }
        else
        {
            cout<< " Mahasiswa belum mengambil mata kuliah";
        }
    }
    else
    {
            cout<< " Mahasiswa tidak ditemukan ";
    }
}

void jmlmatkuldiambil(List_parent P, List_child C)
{
    /** NAMA: FAISHAL RAIHAN
        NIM : 1301184163
    */
    int total = 0;
    cout<<"Masukan Id Matkul: ";
    int idChld;
    cin>>idChld;
    address_child Chld = SearchIdChild(C, idChld);
    address_parent Prnt = firstParent(P);
    if(Chld != NULL){
        while(Prnt != NULL)
        {
            address_relasi R = firstRelation(childlist(Prnt));
            while(R != NULL)
            {
                if(idChild(child(R)) == idChld)
                {

                    total++;
                    R = nextRelation(R);
                }else{

                    R = nextRelation(R);
                }
            }
        Prnt = nextParent(Prnt);
        }
    cout<<total<<endl;
    }

}


