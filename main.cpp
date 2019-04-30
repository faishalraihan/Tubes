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

void mainmenu();

int main()
{
    createListParent(Mhs);
    createListChild(Mtkl);
    mainmenu();
//    createListrelasi(Rls);
}
    void mainmenu()
{
    createListParent(Mhs);
    createListChild(Mtkl);
    int x;
    do {
    cout<<"===================================================================="<<endl;
    cout<<               "SELAMAT DATANG DI PROGRAM MAHASISWA"<<endl;
    cout<<"===================================================================="<<endl;
    cout<<"    SILAHKAN PILIH BEBERAPA OPSI DIBAWAH INI LALU TEKAN (ENTER)"<<endl;
    cout<<"TEKAN 1 UNTUK MEMASUKKAN INFO MAHASISWA " <<endl;
    cout<<"TEKAN 2 UNTUK MEMASUKKAN INFO MATA KULIAH " <<endl;
    cout<<"TEKAN 3 UNTUK MELIHAT MAHASISWA " <<endl;
    cout<<"TEKAN 4 UNTUK MELIHAT MATA KULIAH " <<endl;
    cout<<"TEKAN 5 UNTUK MENAMBAH MATA KULIAH YANG DIAMBIL MAHASISWA "<<endl;
    cout<<"TEKAN 6 UNTUK MELIHAT MATA KULIAH APA YANG DIAMBIL SEORANG MAHASISWA "<<endl;
    cout<<"TEKAN 7 UNTUK MELIHAT HUBUNGAN SELURUH MAHASIWA DENGAN MATKUL YANG DIAMBIL"<<endl;
    cout<<"TEKAN 8 UNTUK MENDELETE MAHASISWA " <<endl;
    cout<<"TEKAN 9 UNTUK MENDELETE MATAKULIAH " <<endl;
    cout<<"TEKAN 10 UNTUK MENGHITUNG BERAPA MATKUL YANG DIAMBIL SEORANG MAHASISWA "<<endl;
    cout<<"TEKAN 11 UNTUK MELIHAT SATU MATKUL DIAMBIL OLEH BERAPA MAHASISWA "<<endl;
    cout << "PILIH ANGKA DAN TEKAN ENTER"<<endl;
    cin >> x;
    switch (x)
    {
    case 1 :
        insertParent(Mhs);
        break;
    case 2 :
        insertChild(Mtkl);
        break;
    case 3 :
        printParent(Mhs);
        break;
    case 4 :
        printChild(Mtkl);
        break;
    case 5 :
        int id;
        int matkul;
        cout<<"Masukkan ID mahasiswa yg mengambil matkul : ";
        cin>>id;
        cout<<"Matkul yang diambil : ";
        cin>>matkul;
        connect(Mhs,Mtkl,id,matkul);
        break;
    case 6 :
        int idmhs;
        cout<<"Masukkan id mahasiwa yang ingin dilihat matkulnya : ";
        cin>>idmhs;
        printChildOfParent(Mhs,Mtkl,idmhs);
        break;
    case 7 :
        printAll(Mhs,Mtkl);
        break;
    case 8 :
        deleteParent(Mhs);
        break;
    case 9 :
        deleteChild(Mhs,Mtkl);
        break;
    case 10 :
        jumlahmatkul(Mhs,Mtkl);
        break;
    case 11 :
        jmlmatkuldiambil(Mhs,Mtkl);
        break;
    case 0 :
        break;
        }

}while (true);

}

