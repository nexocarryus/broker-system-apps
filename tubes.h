#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define nextRelasi(P) P->nextRelasi
#define nextSaham(P) P->nextSaham
using namespace std;
struct Investor{
    string kodeRdn;
    string namaInvestor;
    int buyingPower;
    int jmlaset;
};
struct saham{
    string kodeSaham;
    string namaSaham;
    string bidangUsaha;
    int hargaSaham;
};

typedef struct elmInvestor*adrInvestor;
typedef struct elmRelasi*adrRelasi;
typedef struct elmSaham*adrSaham;
struct elmInvestor{
    Investor info;
    adrInvestor next;
    adrRelasi nextRelasi;
};
struct elmRelasi{
    adrRelasi next;
    adrSaham nextSaham;
};
struct elmSaham{
    saham info;
    adrSaham next;
};

struct mll1{
    adrInvestor first;
};
struct mll2{
    adrSaham first;
};

int selectMenu();
adrInvestor searchInvestor(mll1 listInvestor, string kodeRdn);
adrSaham searchSaham(mll2 listSaham, string kodeSaham);
adrRelasi searchRelasi(adrInvestor IV, adrSaham SH);
void cariChildbyParent(mll1 lisInvestor, mll2 listSaham);

void insertLastInvestor(mll1 &listInvestor, adrInvestor IV);
void insertLastSaham(mll2&listSaham, adrSaham SH);
void createListInvestor(mll1 &listInvestor);
void createListSaham(mll2 &listSaham);
adrSaham newElmSaham(saham infosaham);
adrInvestor newElmInvestor(Investor infoInvestor);
adrRelasi newElmRelasi();
void insertNewRelasi(mll1 &listInvestor, adrInvestor IV, adrRelasi R);

void deleteFirstInvestor(mll1 &listInvestor, adrInvestor IV);
void deleteLastInvestor(mll1 &listInvestor, adrInvestor IV);
void deleteAfterInvestor(mll1 &listInvestor, adrInvestor previous, adrInvestor IV);

void deleteFirstRelasi(mll1 &listInvestor, adrInvestor IV, adrRelasi R);
void deleteLastRelasi(mll1 &lisInvestor, adrInvestor IV, adrRelasi R);
void deleteAfterRelasi(mll1 &listInvestor, adrInvestor IV, adrRelasi previous, adrRelasi R);


void showDataInvestor(mll1 listInvestor);
void showInvestordanSaham(mll1 listInvestor);
void showDataSaham(mll2 listSaham);
void asignRelasiToSaham(mll1 &listInvestor, adrInvestor IV, adrSaham SH);

void deletefirstSaham(mll2 &listSaham, adrSaham SH);
void deleteLastSaham(mll2 &listSaham, adrSaham SH);
void deleteAfterSaham(mll2 &listSaham, adrSaham previous, adrSaham SH);
void deleteRelasibyparent(mll1 &listInvestor, mll2 listSaham);
void deleteInvestorAndRelasi(mll1 &lisInvestor);
int hitungjmlSahambyParent(mll1 listInvestor, adrInvestor IV);



#endif // TUBES_H_INCLUDED
