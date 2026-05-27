#include <iostream>
#include "listvoucher.h"
#include "queuecostumer.h"
#include "stackhistory.h"
#include <string>

using namespace std;

bool isDigit(string text, bool cekPanjang){
    if (text.empty()){
        return false;
    };

    if (cekPanjang && text.length() > 9){
        return false;
    };
    

    int counter;
    for (counter = 0; counter < text.length(); counter++){
        
        if (!(text[counter] >= '0' && text[counter] <= '9')){
            return false;
        };

    };
    return true;
};

void tambahVoucher(linkList *D){
    string kode, provider ,
    nominal, harga, stock;
    
    char fix;
    cout << "== tambahVoucher ==" << endl;
    while(1){
        
        cout << "Nama Provider : ";
        getline(cin, provider);
        cout << "Nama nominal pulsa : ";
        getline(cin, nominal);
        cout << "Nama harga Rp : ";
        getline(cin, harga);
        cout << "Nama stock : ";
        getline(cin, stock);
        cout << "Nama kode : ";
        getline(cin, kode);

        if (!(isDigit(nominal, true) && isDigit(harga, true) && isDigit(stock, true))){
            cout << "Gagal Memasukkan!" << endl;
            cout << "Tekan Apa saja untuk Keluar...";
            cin.ignore();
            cin.get();
            return;
        };

        addFirstList(D, provider, kode, stoi(nominal), stoi(harga), stoi(stock));
        saveFileList(*(D));

        cout << "Lagi? (y/n) : ";
        cin >> fix;
        cin.ignore();

        if (!(fix == 'y' || fix == 'Y')){
            return;
        };
    };
    
};

void enqueueCos(Costumer *C, linkList *D){
    string nama, noHP, kodePulsa, jumlah;
    char fix;

    while(1){
        cetaklinkList(*(D));
        cout << endl << "== antrianCostumer ==" << endl;
        cout << "Nama : ";
        getline(cin, nama);
        cout << "No Hp : ";
        getline(cin, noHP);
        cout << "Kode Pusa :";
        getline(cin, kodePulsa);
        cout << "Jumlah : ";
        getline(cin, jumlah);

        if (!(isDigit(noHP, false) && isDigit(jumlah, true))){
            cout << "Gagal Memasukkan!" << endl;
            cout << "Tekan Apa saja untuk Keluar...";
            cin.ignore();
            cin.get();
            return;
        };

        enqueue(C, nama, noHP, kodePulsa, stoi(jumlah));

        cout << "Lagi? (y/n) : ";
        cin >> fix;
        cin.ignore();

        if (!(fix == 'y' || fix == 'Y')){
            return;
        };
    }
};

void dequeueCos(Costumer *C, linkList *D){

    string nama, noHp, kodePulsa; 
    int minstock;  char fix;

    cetakCostumer(*(C));
    while(1){

        if (isEmptyQueue(*(C))){
            cout << "Queue Kosong..." << endl;
            cout << "Tekan Apa saja untuk Keluar...";
            cin.ignore();
            cin.get();
            return;    
        };
           
        cout << "Proses Antrian? (y/n) : " ;
        cin >> fix;
        cin.ignore();

        if (!(fix == 'y' || fix == 'Y')){
            return;
        };
        
        cout << "Isi Sekarang = " << endl;
        dequeue(C, &nama, &noHp, &kodePulsa, &minstock);
        editStock(D, kodePulsa, minstock);

        cetakCostumer(*(C));


    }
};


int main (){
    linkList D = createList();
    Costumer C = createQueue();
    History D = createHistory();
    loadStoack(&D);
    enqueueCos(&C, &D);
    dequeueCos(&C, &D);
    cetaklinkList(D);

};