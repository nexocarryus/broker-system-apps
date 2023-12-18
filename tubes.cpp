#include "tubes.h"
adrInvestor searchInvestor(mll1 listInvestor, string kodeRdn){
    adrInvestor IV = first(listInvestor);
    while (IV != NULL){
        if (info(IV).kodeRdn == kodeRdn){
            return IV;
        }
        IV = next(IV);
    }
    return NULL;
}
adrSaham searchSaham(mll2 listSaham, string kodeSaham){
    adrSaham SH = first(listSaham);
    while (SH != NULL){
        if (info(SH).kodeSaham == kodeSaham){
            return SH;
        }
        SH = next(SH);
    }
    return NULL;

}
void createListInvestor(mll1 &listInvestor){
     first(listInvestor) = NULL;
}
void createListSaham(mll2 &listSaham){
    first(listSaham) = NULL;
}
adrSaham newElmSaham(saham infosaham){
    adrSaham SH = new elmSaham;
    info(SH) = infosaham;
    next(SH) = NULL;
    return SH;

}
adrInvestor newElmInvestor(Investor infoInvestor){
    adrInvestor IV = new elmInvestor;
    info(IV) = infoInvestor;
    next(IV) = NULL;
    nextRelasi(IV) = NULL;
    return IV;
}
adrRelasi newElmRelasi(){
    adrRelasi R = new elmRelasi;
    next(R) = NULL;
    nextSaham(R) = NULL;

    return R;
}
void insertLastInvestor(mll1 &listInvestor, adrInvestor IV){
    adrInvestor p;
    if (first(listInvestor) == NULL){
        first(listInvestor) = IV;
    }else{
        p = first(listInvestor);
        while (next(p) != NULL){
            p = next(p);
        }
        next(p) = IV;
    }
}
void insertLastSaham(mll2&listSaham, adrSaham SH){
      adrSaham p;
    if (first(listSaham) == NULL){
        first(listSaham) = SH;
    }else{
        p = first(listSaham);
        while (next(p) != NULL){
            p = next(p);
        }
        next(p) = SH;
    }
}
void insertNewRelasi(mll1 &listInvestor, adrInvestor IV, adrRelasi R){
    adrRelasi p;
    if (nextRelasi(IV) == NULL){
        nextRelasi(IV) = R;
    }else{
        p = nextRelasi(IV);
        while (next(p) != NULL){
            p = next(p);
        }
        next(p) = R;
    }
}
void deleteFirstRelasi(mll1 &listInvestor, adrInvestor IV, adrRelasi R){
    if (nextRelasi(IV) == NULL){
        cout <<"Investor"<<info(IV).namaInvestor<<" tidak memiliki Aset saham "<<endl;
    }else if(next(nextRelasi(IV)) == NULL){
        R = nextRelasi(IV);
        nextRelasi(IV) = NULL;
        nextSaham(R) = NULL;
    }else{
        R = nextRelasi(IV);
        nextRelasi(IV) = next(R);
        next(R) = NULL;
        nextSaham(R) = NULL;
    }
}

void deleteLastRelasi(mll1 &lisInvestor, adrInvestor IV, adrRelasi R){
    adrRelasi p;

    if (nextRelasi(IV) == NULL){
        cout <<"Investor"<<info(IV).namaInvestor<<" tidak memiliki Aset saham "<<endl;
    }else if(next(nextRelasi(IV)) == NULL){
        R = nextRelasi(IV);
        nextRelasi(IV) = NULL;
        nextSaham(R) = NULL;
    }else{
       p = nextRelasi(IV);
       R = next(nextRelasi(IV));
       while (next(next(p))!= NULL){
            p = next(p);
            R = next(R);
       }
       next(p) = NULL;
       nextSaham(R) = NULL;
    }
}
void deleteAfterRelasi(mll1 &listInvestor, adrInvestor IV, adrRelasi previous, adrRelasi R){
    if (nextRelasi(IV) == NULL){
        cout <<"Investor"<<info(IV).namaInvestor<<" tidak memiliki Aset saham "<<endl;
    }else if(next(nextRelasi(IV)) == NULL){
        R = nextRelasi(IV);
        nextRelasi(IV) = NULL;
        nextSaham(R) = NULL;
    }else{
        R = next(previous);
        next(previous) = next(R);
        next(R) = NULL;
        nextSaham(R) = NULL;
    }

}
adrRelasi searchRelasi(adrInvestor IV, adrSaham SH){
    adrRelasi R = nextRelasi(IV);
    while (R != NULL){
        if (nextSaham(R) == SH){
            return R;
        }
        R = next(R);
    }
    return NULL;
}
void deleteRelasibyparent(mll1 &listInvestor, mll2 listSaham){
    string kodeRdn, kodeSaham;
    adrInvestor IV;
    adrSaham SH;
    adrRelasi R;

    cout <<"investor mana yang kepemilikan sahamnya ingin dihapus ?"<<endl;
    cout <<"masukan kode RDN investor : ";
    cin>>kodeRdn;

    IV = searchInvestor(listInvestor, kodeRdn);
    if (IV != NULL){
        cout <<"Saham mana yang kepemilikannya ingin dihapus ? "<<endl;
        cout <<"masukan kode Saham yang dituju : ";
        cin >> kodeSaham;
        SH = searchSaham(listSaham, kodeSaham);
        if (SH != NULL){
                R = searchRelasi(IV, SH);
                if (R != NULL){
                    if (R == nextRelasi(IV)){
                        deleteFirstRelasi(listInvestor, IV, R);
                    }else if(next(R) == NULL){
                        deleteLastRelasi(listInvestor, IV, R);
                    }else{
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
                    }
                }else{
                    cout<<"MAAF INVESTOR YANG DITUJU TIDAK MEMILIKI SAHAM DENGAN KODE TERSEBUT"<<endl;
                }

        }else{
            cout<<"MAAF SAHAM DENGAN KODE TERSEBUT TIDAK ADA DI BURSA"<<endl;
        }
    }else{
        cout<<"MAAF INVESTOR DENGAN KODE RDN TERSEBUT TIDAK DITEMUKAN"<<endl;
    }


}
void showDataInvestor(mll1 listInvestor){
    cout <<"=======DATA INVESTOR STOCKBIT======="<<endl;
    adrInvestor p;
    p = first(listInvestor);
    while(p != NULL){
        cout <<"Kode RDN :"<<info(p).kodeRdn<<endl;
        cout <<"Nama investor :"<<info(p).namaInvestor<<endl;
        cout <<"buying power:" <<info(p).buyingPower<<endl;
        cout <<"jumlah aset saham : "<<info(p).jmlaset<<endl;
        cout <<endl;
        p = next(p);
    }
}
void showDataSaham(mll2 listSaham){
    cout <<"=======DATA SAHAM BURSA EFEK INDONESIA======="<<endl;
    adrSaham p;
    p = first(listSaham);
    while(p != NULL){
        cout <<"Kode Saham :"<<info(p).kodeSaham<<endl;
        cout <<"Nama Perusahaan:"<<info(p).namaSaham<<endl;
        cout <<"Bidang Usaha :"<<info(p).bidangUsaha<<endl;
        cout <<"Harga Saham :"<<info(p).hargaSaham<<endl;
        cout <<endl;
        p = next(p);
    }
}
void asignRelasiToSaham(mll1 &listInvestor, adrInvestor IV, adrSaham SH){
    adrRelasi R;
    R = newElmRelasi();
    insertNewRelasi(listInvestor, IV, R);
    nextSaham(R) = SH;
    info(IV).jmlaset = info(IV).jmlaset + 1;
    info(IV).buyingPower = info(IV).buyingPower-info(SH).hargaSaham;

}
void showInvestordanSaham(mll1 listInvestor){
    adrInvestor p;
    adrRelasi q;
    adrSaham SH;
    p = first(listInvestor);
    while(p != NULL){
        cout <<"Kode RDN :"<<info(p).kodeRdn<<endl;
        cout <<"Nama investor :"<<info(p).namaInvestor<<endl;
        cout <<"buying power:" <<info(p).buyingPower<<endl;
        cout <<"jumlah aset saham : "<<info(p).jmlaset<<endl;
        cout <<endl;
        if (nextRelasi(p) != NULL){
            cout <<"ASET SAHAM YANG DIMILIKI : "<<endl;
            q = nextRelasi(p);
            while(q != NULL){
                SH = nextSaham(q);
                cout <<"Kode Saham :"<<info(SH).kodeSaham<<endl;
                cout <<"Nama Perusahaan:"<<info(SH).namaSaham<<endl;
                cout <<"Bidang Usaha :"<<info(SH).bidangUsaha<<endl;
                cout <<"Harga Saham :"<<info(SH).hargaSaham<<endl;
                cout <<endl;
                q = next(q);
            }
        }
        cout <<"======================="<<endl;
        p = next(p);
    }
}

void deletefirstSaham(mll2 &listSaham, adrSaham SH){
    SH = first(listSaham);
    if (first(listSaham) == NULL){
        cout <<"TIDAK ADA DATA SAHAM DALAM SISTEM"<<endl;
    }else if(next(SH) == NULL){
        first(listSaham) = NULL;
    }else{
        first(listSaham) = next(SH);
        next(SH) = NULL;
    }
}
void deleteLastSaham(mll2 &listSaham, adrSaham SH){
    adrSaham p = first(listSaham);
    SH = next(first(listSaham));
    cout <<info(p).kodeSaham<<endl;
    cout<<info(SH).kodeSaham<<endl;


    if (first(listSaham) == NULL){
        cout <<"TIDAK ADA DATA SAHAM DALAM SISTEM"<<endl;
    }else if(next(p) == NULL){
        first(listSaham) = NULL;
    }else{
        while (next(next(p)) != NULL){
            p = next(p);
            SH = next(SH);
        }
        next(p) = NULL;
    }
}
void deleteAfterSaham(mll2 &listSaham, adrSaham previous, adrSaham SH){
     if (first(listSaham) == NULL){
        cout <<"TIDAK ADA DATA SAHAM DALAM SISTEM"<<endl;
    }else if(next(SH) == NULL){
        first(listSaham) = NULL;
    }else{
        SH = next(previous);
        next(previous) = next(SH);
        next(SH) = NULL;
    }
}

void cariChildbyParent(mll1 lisInvestor, mll2 listSaham){
    string kodeRdn, kodeSaham;
    adrInvestor IV;
    adrSaham SH;
    adrRelasi R;

    cout <<"Investor mana yang ingin dicari kepemilikan sahamnya ? "<<endl;
    cout <<"masukan kode RDN investor : ";
    cin >> kodeRdn;
    IV = searchInvestor(lisInvestor, kodeRdn);
    if (IV != NULL){
        cout <<"DATA INVESTOR DITEMUKAN"<<endl;
        cout <<"saham apa yang ingin dicari dari aset Mr/Mrs"<<info(IV).namaInvestor<<" ?"<<endl;
        cout <<"masukan kode saham : ";
        cin >> kodeSaham;
        SH = searchSaham(listSaham, kodeSaham);
        if (SH != NULL){
            R = searchRelasi(IV, SH);
            if (R != NULL){
                adrSaham p = nextSaham(R);
                cout <<"DATA DITEMUKAN, Mr/MRs Naufal memiliki aset saham "<<info(p).kodeSaham<<endl;
                cout <<"Berikut data lengkapnya"<<endl;
                cout <<"Kode Saham :"<<info(p).kodeSaham<<endl;
                cout <<"Nama Perusahaan:"<<info(p).namaSaham<<endl;
                cout <<"Bidang Usaha :"<<info(p).bidangUsaha<<endl;
                cout <<"Harga Saham :"<<info(p).hargaSaham<<endl;
                cout <<endl;
            }else{
                cout<<"Mr/Mrs "<<info(IV).namaInvestor<<"tidak memiliki aset dengan kode saham tersebut"<<endl;
            }
        }else{
            cout <<"TIDAK ADA SAHAM DENGAN KODE TERSEBUT DI BURSA"<<endl;
        }

    }else{
        cout <<"MAAF TIDAK ADA INVESTOR DENGAN KODE RDN TERSEBUT"<<endl;
    }

}

int hitungjmlSahambyParent(mll1 listInvestor, adrInvestor IV){
    int total = 0;
    adrRelasi R = nextRelasi(IV);
    while (R != NULL){
        total = total + 1;
        R = next(R);
    }
    return total;

}


void deleteFirstInvestor(mll1 &listInvestor, adrInvestor IV){
    if (first(listInvestor) == NULL){
        cout <<"TIDAK ADA DATA INVESTOR"<<endl;
    }else if(next(first(listInvestor)) == NULL){
        IV = first(listInvestor);
        first(listInvestor) = NULL;
    }else{
        IV = first(listInvestor);
        first(listInvestor) = next(IV);
        next(IV) = NULL;
    }
}
void deleteLastInvestor(mll1 &listInvestor, adrInvestor IV){
    adrInvestor p;
    if (first(listInvestor) == NULL){
        cout <<"TIDAK ADA DATA INVESTOR"<<endl;
    }else if(next(first(listInvestor)) == NULL){
        IV = first(listInvestor);
        first(listInvestor) = NULL;
    }else{
        p = first(listInvestor);
        IV = next(first(listInvestor));
        while(next(next(p)) != NULL){
            p = next(p);
            IV = next(IV);
        }
        next(p) = NULL;
    }
}
void deleteAfterInvestor(mll1 &listInvestor, adrInvestor previous, adrInvestor IV){
     if (first(listInvestor) == NULL){
        cout <<"TIDAK ADA DATA INVESTOR"<<endl;
    }else if(next(first(listInvestor)) == NULL){
        IV = first(listInvestor);
        first(listInvestor) = NULL;
    }else{
        IV = next(previous);
        next(previous) = next(IV);
        next(IV) = NULL;
    }
}
void deleteInvestorAndRelasi(mll1 &lisInvestor){
    string kodeRdn;
    adrInvestor IV, previous;
    adrRelasi R;

    cout<<"INVESTOR MANA YANG INGIN DIHAPUS ?"<<endl;
    cout<<"Masukan kode RDN investor : ";
    cin >> kodeRdn;
    IV = searchInvestor(lisInvestor, kodeRdn);
    while(nextRelasi(IV) != NULL){
        deleteFirstRelasi(lisInvestor, IV, R);
    }
    if (IV == first(lisInvestor)){
        deleteFirstInvestor(lisInvestor, IV);
    }else if(next(IV) == NULL){
        deleteLastInvestor(lisInvestor, IV);
    }else{
        previous = first(lisInvestor);
        while(next(previous) != IV){
            previous = next(previous);
        }
        deleteAfterInvestor(lisInvestor, previous, IV);
    }
    cout<<"DATA INVESTOR BERHASIL DIHAPUS BESERTA DENGAN RELASINYA"<<endl;
}
int selectMenu(){
    int input = 0;
    cout<<"=================WELCOME TO BROKER SYSTEM==============="<<endl;
    cout<<endl;
    cout<<"1.menambahkan data investor"<<endl;
    cout<<"2.Tampilkan semua data investor"<<endl;
    cout<<"3.Hapus investor tertentu beserta aset sahamnya"<<endl;
    cout<<"4.Cari data investor"<<endl;
    cout<<"5.cari data saham"<<endl;
    cout<<"6.menambahkan data saham"<<endl;
    cout<<"7.menghubungkan data investor ke data saham"<<endl;
    cout<<"8.tampilkan semua investor beserta aset sahamnya"<<endl;
    cout<<"9.cari aset saham pada investor"<<endl;
    cout<<"10.menghapus kepemilikan saham tertentu pada investor tertentu"<<endl;
    cout<<"11.hitung jumlah aset saham pada investor tertentu"<<endl;
    cout<<"12.Tampilkan data saham"<<endl;
    cout<<"0.Exit System"<<endl;
    cout<<endl;
    cout<<"Pilih menu : ";
    cin >> input;
    return input;
}

