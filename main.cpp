#include "tubes.h"

int main()
{
    mll1 listInvestor;
    mll2 listSaham;
    Investor x;
    //y
    saham z;
    string kodeRdn;
    string kodeSaham;
    string keterangan;
    int jml = 0;
    int jmlkaryawan = 0;
    int n = 0;
    int i = 1;
    adrInvestor IV;
    //adrKaryawan K;
    adrSaham SH;
    adrRelasi R;
    createListInvestor(listInvestor);
    createListSaham(listSaham);
    x.kodeRdn = "1001";
    x.namaInvestor = "Naufal_Dzakwan";
    x.buyingPower = 200000;
    x.jmlaset = 0;
    IV = newElmInvestor(x);
    insertLastInvestor(listInvestor, IV);

    x.kodeRdn = "1002";
    x.namaInvestor = "Rudi_ Sinaga";
    x.buyingPower = 100000;
    x.jmlaset = 0;
    IV = newElmInvestor(x);
    insertLastInvestor(listInvestor, IV);

    x.kodeRdn = "1003";
    x.namaInvestor = "Ray_Samuel";
    x.buyingPower = 150000;
    x.jmlaset = 0;
    IV = newElmInvestor(x);
    insertLastInvestor(listInvestor, IV);

    x.kodeRdn = "1004";
    x.namaInvestor = "Doni_Sulaiman";
    x.buyingPower = 300000;
    x.jmlaset = 0;
    IV = newElmInvestor(x);
    insertLastInvestor(listInvestor, IV);


    z.kodeSaham = "UNTR";
    z.namaSaham = "United_Tractor";
    z.bidangUsaha = "Sewa_Alat_Berat";
    z.hargaSaham = 21000;
    SH = newElmSaham(z);
    insertLastSaham(listSaham, SH);

    z.kodeSaham = "ITMG";
    z.namaSaham = "Indah_Tambang_Raya_Megah";
    z.bidangUsaha = "Pertambangan_Batu_Bara";
    z.hargaSaham = 23000;
    SH = newElmSaham(z);
    insertLastSaham(listSaham, SH);

    z.kodeSaham = "TLKM";
    z.namaSaham = "Telkom_Indonesia_TBK";
    z.bidangUsaha = "Provider_Jaringan";
    z.hargaSaham = 2900;
    SH = newElmSaham(z);
    insertLastSaham(listSaham, SH);
    int pilihan = selectMenu();
    while (pilihan != 0){
        switch(pilihan){
        case 1:
            n = 0;
            i = 1;
            cout<<"berapa investor yang ingin ditambah ? ";
            cin >> n;
            while (i <= n){
                cout <<"masukan kode RDN : ";
                cin >> x.kodeRdn;
                cout <<"masukan nama investor: ";
                cin >> x.namaInvestor;
                cout <<"masukan buying power :  ";
                cin >> x.buyingPower;
                x.jmlaset = 0;
                IV = newElmInvestor(x);
                insertLastInvestor(listInvestor, IV);
                i++;
            }
            cout<<endl;
            break;
        case 2:
            showDataInvestor(listInvestor);
            cout<<endl;
            break;
        case 3:
             deleteInvestorAndRelasi(listInvestor);
             cout<<endl;
             break;
        case 4:
            cout <<"masukan kode RDN investor yang ingin dicari : ";
            cin >> kodeRdn;
            IV = searchInvestor(listInvestor, kodeRdn);
            if (IV != NULL){
                cout <<"DATA DITEMUKAN"<<endl;
                cout <<"Kode RDN :"<<info(IV).kodeRdn<<endl;
                cout <<"Nama investor :"<<info(IV).namaInvestor<<endl;
                cout <<"buying power:" <<info(IV).buyingPower<<endl;
                cout <<"jumlah aset saham : "<<info(IV).jmlaset<<endl;
            }else{
                cout<<"MAAF TIDAK ADA INVESTOR DENGAN KODE RDN TERSEBUT"<<endl;
            }
            cout <<endl;
            break;
        case 5:
            cout <<"masukan kode saham yang ingin dicari: ";
            cin>>kodeSaham;
            SH = searchSaham(listSaham, kodeSaham);
            if (SH != NULL){
                cout <<"DATA DITEMUKAN"<<endl;
                cout <<"Kode Saham :"<<info(SH).kodeSaham<<endl;
                cout <<"Nama Perusahaan:"<<info(SH).namaSaham<<endl;
                cout <<"Bidang Usaha :"<<info(SH).bidangUsaha<<endl;
                cout <<"Harga Saham :"<<info(SH).hargaSaham<<endl;
            }else{
                cout<<"MAAF TIDAK ADA SAHAM DENGAN KODE TERSEBUT"<<endl;
            }
            cout<<endl;
            break;
        case 6:
            cout <<"ada berapa saham yang ingin di tambah ? ";
            n = 0;
            i = 1;
            cin>> n;
             while (i <= n){
                cout <<"masukan kode saham : ";
                cin >> z.kodeSaham;
                cout <<"masukan nama perusahaan :  ";
                cin >> z.namaSaham;
                cout <<"masukan bidang usaha : ";
                cin >> z.bidangUsaha;
                cout <<"masukan harga saham : ";
                cin >> z.hargaSaham;
                SH = newElmSaham(z);
                insertLastSaham(listSaham, SH);
                i++;
             }
             cout<<"DATA SAHAM SUKSES DITAMBAHKAN"<<endl;
             break;
        case 7:
            cout <<"masukan kode RDN investor yang ingin membeli saham : ";
            cin >> kodeRdn;
            IV = searchInvestor(listInvestor, kodeRdn);
            cout <<"masukan kode saham yang ingin dibeli: ";
            cin>>kodeSaham;
            SH = searchSaham(listSaham, kodeSaham);
            asignRelasiToSaham(listInvestor, IV, SH);
            cout<<"SAHAM BERHASIL DIBELI DAN DIHUBUNGKAN DENGAN INVESTOR"<<endl;
            break;
        case 8:
            showInvestordanSaham(listInvestor);
            break;
        case 9:
            cariChildbyParent(listInvestor, listSaham);
            break;
        case 10:
            deleteRelasibyparent(listInvestor, listSaham);
            break;
        case 11:
            cout <<"Investor mana yang ingin dihitung jumlah aset sahamnya ?"<<endl;
            cout <<"masukan kode RDN investor : ";
            cin >> kodeRdn;
            IV = searchInvestor(listInvestor, kodeRdn);
            jml = hitungjmlSahambyParent(listInvestor, IV);
            cout <<"TOTAL ASET SAHAM/CHILD YANG DIMILIKI OLEH Mr/Mrs "<<info(IV).namaInvestor<<" adalah : "<<jml<<" ASET"<<endl;
            break;
        case 12:
            showDataSaham(listSaham);
            break;
        }
        pilihan = selectMenu();
    }
    /*



    cout <<"ada berapa investor yang ingin ditambah? ";
    cin>> n;
    while (i <= n){
        cout <<"masukan kode RDN : ";
        cin >> x.kodeRdn;
        cout <<"masukan nama investor: ";
        cin >> x.namaInvestor;
        cout <<"masukan buying power :  ";
        cin >> x.buyingPower;
        x.jmlaset = 0;
        IV = newElmInvestor(x);
        insertLastInvestor(listInvestor, IV);
        cout <<"masukan jumlah karyawan perusahaan : ";
        cin >> x.jmlKaryawan;
        k = 1;
        while(k <= x.jmlKaryawan){
                cout <<"masukan data karyawan ke "<<k<<endl;
                cout <<"nama karyawan :";
                cin >> y.namaKaryawan;
                cout <<"jabatan :";
                cin >> y.jabatan;
                cout <<"gaji:";
                cin >>y.gaji;
                PR = searchPerusahaan(listPerusahaan, x.namaPerusahaan);
                K = newElmKaryawan(y);
                insertNewKaryawan(listPerusahaan, PR, K);
                k++;
        }

        i++;
    }
    cout <<"ada berapa saham yang ingin di tambah ? ";
    n = 0;
    i = 1;
    cin>> n;
     while (i <= n){
        cout <<"masukan kode saham : ";
        cin >> z.kodeSaham;
        cout <<"masukan nama perusahaan :  ";
        cin >> z.namaSaham;
        cout <<"masukan bidang usaha : ";
        cin >> z.bidangUsaha;
        cout <<"masukan harga saham : ";
        cin >> z.hargaSaham;

        SH = newElmSaham(z);
        insertLastSaham(listSaham, SH);
        i++;
     }

    showDataInvestor(listInvestor);
    cout<<endl;
    showDataSaham(listSaham);

    //ALGORITMA UNTUK ASIGN DATA PARENT L1 KE L2//

    cout <<"masukan kode RDN investor yang ingin membeli saham : ";
    cin >> kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    cout <<"masukan kode saham yang ingin dibeli: ";
    cin>>kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    asignRelasiToSaham(listInvestor, IV, SH);


    cout <<"masukan kode RDN investor yang ingin membeli saham : ";
    cin >> kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    cout <<"masukan kode saham yang ingin dibeli: ";
    cin>>kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    asignRelasiToSaham(listInvestor, IV, SH);

    cout <<"masukan kode RDN investor yang ingin membeli saham : ";
    cin >> kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    cout <<"masukan kode saham yang ingin dibeli: ";
    cin>>kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    asignRelasiToSaham(listInvestor, IV, SH);
    showInvestordanSaham(listInvestor);

    //function untuk solved nomor 3
    deleteInvestorAndRelasi(listInvestor);
    showInvestordanSaham(listInvestor);

    //algoritma untuk solve nomor 11
    cout <<"Investor mana yang ingin dihitung jumlah aset sahamnya ?"<<endl;
    cout <<"masukan kode RDN investor : ";
    cin >> kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    int jml = hitungjmlSahambyParent(listInvestor, IV);
    cout <<"TOTAL ASET SAHAM/CHILD YANG DIMILIKI OLEH Mr/Mrs "<<info(IV).namaInvestor<<" adalah : "<<jml<<" ASET"<<endl;

    //function untuk solve nomor 9
    cariChildbyParent(listInvestor, listSaham);

    deleteRelasibyparent(listInvestor, listSaham);
    cout <<"kondisi setelah investor tertentu dihapus relasi sahamnya"<<endl;
    showInvestordanSaham(listInvestor);

    //ALGORITMA DELETE RELASI, FIRST, AFTER, LAST
    cout <<"masukan kodeRDN investor yang relasinya ingin dihapus :";
    cin >>kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    cout <<"masukan kodeSaham pada investor yang ingin dihapus :";
    cin >>kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    adrRelasi p = nextRelasi(IV);
    bool status =false;

    while (p != NULL && !status){
        if (nextSaham(next(p)) == SH){
            status = true;
        }else{
            p = next(p);
        }
    }
    deleteAfterRelasi(listInvestor, IV, p, R);
    //deleteLastRelasi(listInvestor, IV, R);
    //cout <<"kondisi setelah dihapus relasi terakhir"<<endl;
    showInvestordanSaham(listInvestor);


    cout <<"masukan kode RDN investor yang ingin membeli saham : ";
    cin >> kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    cout <<"masukan kode saham yang ingin dibeli: ";
    cin>>kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    asignRelasiToSaham(listInvestor, IV, SH);


    cout <<"masukan kode RDN investor yang ingin membeli saham : ";
    cin >> kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    cout <<"masukan kode saham yang ingin dibeli: ";
    cin>>kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    asignRelasiToSaham(listInvestor, IV, SH);


    cout <<"masukan kode RDN investor yang ingin membeli saham : ";
    cin >> kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    cout <<"masukan kode saham yang ingin dibeli: ";
    cin>>kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    asignRelasiToSaham(listInvestor, IV, SH);

    showInvestordanSaham(listInvestor);

    //INI ADALAH SOURCE CODE MAIN UNTUK SEARCHING//


    cout <<"masukan kode RDN investor : ";
    cin >> kodeRdn;
    IV = searchInvestor(listInvestor, kodeRdn);
    if (IV != NULL){
        cout <<"DATA DITEMUKAN"<<endl;
        cout <<"Kode RDN :"<<info(IV).kodeRdn<<endl;
        cout <<"Nama investor :"<<info(IV).namaInvestor<<endl;
        cout <<"buying power:" <<info(IV).buyingPower<<endl;
        cout <<"jumlah aset saham : "<<info(IV).jmlaset<<endl;
    }else{
        cout<<"MAAF TIDAK ADA INVESTOR DENGAN KODE RDN TERSEBUT"<<endl;
    }
    cout <<endl;

    cout <<"masukan kode saham : ";
    cin>>kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    if (SH != NULL){
        cout <<"DATA DITEMUKAN"<<endl;
        cout <<"Kode Saham :"<<info(SH).kodeSaham<<endl;
        cout <<"Nama Perusahaan:"<<info(SH).namaSaham<<endl;
        cout <<"Bidang Usaha :"<<info(SH).bidangUsaha<<endl;
        cout <<"Harga Saham :"<<info(SH).hargaSaham<<endl;
    }else{
        cout<<"MAAF TIDAK ADA SAHAM DENGAN KODE TERSEBUT"<<endl;
    }

    //ALGORITMA DELETE FIRST, LAST, DAN AFTER SAHAM//

    cout <<"ingin menghapus saham apa ?";
    cin >> kodeSaham;
    SH = searchSaham(listSaham, kodeSaham);
    adrSaham p = first(listSaham);
    while (next(p) != SH){
        p = next(p);
    }
    deleteAfterSaham(listSaham, p, SH);
    cout<<"kondisi setelah delete After"<<endl;
    showDataSaham(listSaham);

    deletefirstSaham(listSaham, SH);
    cout <<"data Saham setelah delete first"<<endl;
    showDataSaham(listSaham);

    deleteLastSaham(listSaham, SH);
    cout <<"data Saham setelah delete last"<<endl;
    showDataSaham(listSaham);
    */
    cout <<"TERIMAKASIH TELAH MENGGUNAKAN SYSTEM KAMI"<<endl;
    cout<<"ANDA TELAH KELUAR DARI SYSTEM"<<endl;
    return 0;
}
