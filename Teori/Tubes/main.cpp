#include <iostream>
#include "listVoucher.h"
#include "queueCostumer.h"
#include "stackHistory.h"
#include "tabelLaporan.h"
#include "externalUtils.h"
#include <string>
#include <cstdlib>

using namespace std;

void tambahVoucher(linkList *D){
    string kode, provider ,
    nominal, harga, stock;

    char fix;
    cout << endl <<"== tambahVoucher ==" << endl;
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

    if (isEmptyList(*(D))){
        cout << endl << "Voucher Pulsa Kosong..." << endl;
        cout << "Tekan Apa saja untuk Keluar...";
        cin.ignore();
        cin.get();
        return;
    };

    while(1){
        cout << endl;
        cetaklinkList(*(D));
        cout << "== antrianCostumer ==" << endl;
        cout << "Nama : ";
        getline(cin, nama);
        cout << "No Hp : ";
        getline(cin, noHP);
        cout << "Kode Pulsa : ";
        getline(cin, kodePulsa);
        cout << "Jumlah : ";
        getline(cin, jumlah);

        if (!cariKodePulsa(*(D), kodePulsa)){
            cout << "Kode Pulsa Tidak dapat ditemukan!" << endl;
            cout << "Tekan Apa saja untuk Keluar...";
            cin.ignore();
            cin.get();
            return;
        };

        if (!(isDigit(noHP, false) && isDigit(jumlah, true))){
            cout << "Gagal Memasukkan!" << endl;
            cout << "Tekan Apa saja untuk Keluar...";
            cin.ignore();
            cin.get();
            return;
        };

        enqueue(C, nama, noHP, kodePulsa, getTanggal() ,stoi(jumlah));
        saveQueueCos(*(C));

        cout << "Lagi? (y/n) : ";
        cin >> fix;
        cin.ignore();

        if (!(fix == 'y' || fix == 'Y')){
            return;
        };
    }
};

void dequeueCos(Costumer *C, linkList *D, History *H, tabelLaporan *T){

    string nama, noHp, kodePulsa;
    int minStock = 0;  char fix;
    int actualSell = 0, actualHarga = 0;

    string idTransaksi, tanggal;
    cout << endl;
    cetakCostumer(*(C));
    while(1){

        if (isEmptyList(*(D))){
            cout << "Voucher Pulsa Kosong..." << endl;
            cout << "Tekan Apa saja untuk Keluar...";
            cin.ignore();
            cin.get();
            return;
        };

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

        dequeue(C, &nama, &noHp, &kodePulsa, &minStock);
        kurangiStock(D, kodePulsa, minStock, &actualSell, &actualHarga);

        idTransaksi = generateID();
        tanggal = getTanggal();

        cout << endl;
        if (actualSell == 0){

            cout << "== Struk Belanja ==" << endl;
            cout << "Status Pembayaran : Gagal" << endl;
            cout << "id Transaksi : " << idTransaksi << endl;
            cout << "nama Pembeli : " << nama << endl;
            cout << "kode Pulsa : " << kodePulsa << endl;
            cout << "Tanggal : " << tanggal << endl;
            cout << "Jumlah : " << minStock << endl;
            cout << "total Harga : " << minStock * actualHarga << endl << endl;

            pushHistory(H, idTransaksi, nama, noHp, kodePulsa, tanggal, minStock, minStock * actualHarga, "Gagal");
            saveFileHistory(*(H));
            saveFileList(*(D));
            saveQueueCos(*(C));

        } else {

            cout << "== Struk Belanja ==" << endl;
            cout << "Status Pembayaran : Berhasil" << endl;
            cout << "id Transaksi : " << idTransaksi << endl;
            cout << "nama Pembeli : " << nama << endl;
            cout << "kode Pulsa : " << kodePulsa << endl;
            cout << "Tanggal : " << tanggal << endl;
            cout << "Jumlah : " << actualSell << endl;
            cout << "total Harga : " << actualSell * actualHarga << endl << endl;

            pushHistory(H, idTransaksi, nama, noHp, kodePulsa, tanggal, actualSell, actualSell * actualHarga, "Berhasil");
            pushTabel(T, tanggal, kodePulsa, actualSell, actualSell * actualHarga);
            saveFileHistory(*(H));
            saveFileList(*(D));
            saveFileTabel(*(T));
            saveQueueCos(*(C));

        };

        cetakCostumer(*(C));

    }
};

void editStock(linkList *D){
    if(isEmptyList(*(D))){
        return;
    };

    cout << endl;
    cetaklinkList(*(D));
    
    string kodePulsa, stock;
    cout << "== editStock Voucher ==" << endl;
    cout << "Masukan KodePulsa : ";

    getline(cin, kodePulsa);
    voucherPulsa *Temp =  cariVoucher(D, kodePulsa);

    if (Temp == nullptr){
        cout << endl <<"Kode Pulsa Tidak ditemukan!" << endl;
        cout << "Tekan Apa saja untuk Keluar..";
        cin.ignore();
        cin.get();
        return;
    };

    cout << "Masukan Stock : ";
    getline(cin, stock);

    if(!isDigit(stock, true)){
        cout << endl << "Gagal Menambahkan!" << endl;
        cout << "Tekan Apa saja untuk Keluar..";
        cin.ignore();
        cin.get();
        return;
    };
    
    Temp->stock = stoi(stock);
    cout << endl << "Berhasil Mengedit Stock!.." << endl;
    saveFileList(*(D));

    cout << "Tekan Apa saja untuk Keluar..";
    cin.ignore();
    cin.get();

};

int main (){
    History H = createHistory(); loadHistory(&H);
    linkList D = createList(); loadStoack(&D);
    Costumer C = createQueue(); loadQueue(&C);
    tabelLaporan T = createTabel(); loadTabel(&T);

    int caseMain = 0;
    string input;
    do {
        system("clear");
        cout << string(3, '=') << " Program Konter " << string(3, '=') << endl;
        cout << "1. Tambah Voucher" << endl;
        cout << "2. Lihat Voucher" << endl;
        cout << "3. Edit Voucher" << endl;
        cout << "4. Tambah Antrian" << endl;
        cout << "5. Proses Antrian" << endl;
        cout << "6. Lihat Antrian" << endl;
        cout << "7. Lihat History" << endl;
        cout << "8. Lihat Laporan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> input;
        cin.ignore();

        if (!isDigit(input, false)){
            caseMain = 999;
        } else {
            caseMain = stoi(input);
        };

        switch (caseMain) {
            case 1:
                tambahVoucher(&D);
                break;

            case 2:
                cout << endl;
                
                if (isEmptyList(D)){
                    cout << "Voucher Kosong!. " << endl;
                    cout << "Tekan Apa saja untuk Keluar...";
                    cin.ignore();
                    cin.get();
                    break;
                };

                cetaklinkList(D);

                cout << "Tekan Apa saja untuk Keluar...";
                cin.ignore();
                cin.get();
                break;
            
            case 3:
                editStock(&D);
                break;
            
            case 4:
                enqueueCos(&C, &D);
                break;

            case 5:
                dequeueCos(&C, &D, &H, &T);
                break;

            case 6:
                cout << endl;

                if(isEmptyQueue(C)){
                    cout << "Tidak Ada Antrian!. " << endl;
                    cout << "Tekan Apa saja untuk Keluar...";
                    cin.ignore();
                    cin.get();
                    break;
                };

                cetakCostumer(C);

                cout << "Tekan Apa saja untuk Keluar...";
                cin.ignore();
                cin.get();
                break;

            case 7:
                cout << endl;

                if(isEmptyHistory(H)){
                    cout << "Tidak Ada History!. " << endl;
                    cout << "Tekan Apa saja untuk Keluar...";
                    cin.ignore();
                    cin.get();
                    break;
                };

                cetakHistory(H);

                cout << "Tekan Apa saja untuk Keluar...";
                cin.ignore();
                cin.get();
                break;

            case 8:
                cout << endl;

                if (isEmptyTabel(T)){
                    cout << "Tidak Ada Laporan!. " << endl;
                    cout << "Tekan Apa saja untuk Keluar...";
                    cin.ignore();
                    cin.get();
                    break;
                };

                cetakTabel(T);

                cout << "Tekan Apa saja untuk Keluar...";
                cin.ignore();
                cin.get();
                break;

            case 0:
                cout << "Keluar program..." << endl ;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                cout << "Tekan Apa saja untuk Keluar...";
                cin.ignore();
                cin.get();
        };
    } while (caseMain != 0);
};
