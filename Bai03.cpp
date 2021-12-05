// Xay dung kieu du lieu bieu dien cac moc su kien voi moi moc su kien gom 3 thong tin:
//  + thoi_diem (mot moc ngay/thang/nam/gio/phut trong nam 2021 va 2020)
//  + ten su kien
//  + do quan trong (4 muc: khong quan trong, co chut quan trong, kha quan trong, rat quan trong)
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct thoi_diem {
    int ngay;  
    int thang; 
    int nam;  
    int gio;   
    int phut;   
};

struct su_kien {
    thoi_diem thoidiem;
    string ten;
    int doquantrong;
};
// Khai báo biến và mảng
su_kien sk[MAX];
// khai bao mang tinh thoi gian
int thoigian[100];
// Khai bao prototype ham
void nhapthoidiem(int& i); // Nhap mot thoi diem
void nhapSuKien(int& sosukien); // Nhap su kien
void thaySuKien(int i); // sua su kien sk[i]
void xuatSuKien(int i); // in ra su kien sk[i]
void xuatQuanTrong(int doquantrong); // chuyen doquantrong {0,1,2,3} -> {k quan trong,hoi quan trong , kha quan trong,rat quan trong}, dung switch
void SuKienDoQuangTrongCao(int sosukien); // cac su kien kha quan trong va rat quan trong
void SuKienBuoiSang(int sosukien);  // cac su kien dien ra vao buoi sang 4h-11h
void suaMucDoQuanTrong(int i); // Sua lai muc do quan trong cua 1 su kien
void xuatSuKienRatQuanTrong(int sosukien); // Xac dinh mot su kien rat quan trong khi biet thoi diem
void SapXepSuKien(su_kien sk[], int sosukien, int s[]); // Sap xep lai su kien
void xoaSuKien(su_kien sk[], int& sosukien, int p); // Xoa 1 su kien
void xoaSuKienKhongQuanTrong(su_kien sk[], int &sosukien); // Xoa su kien khong quan trong
int SoNgayTrongThang(int month); // Tim so ngay trong moi thang
bool LaNgayHopLe(int ngay, int thang, int nam); // Kiem tra ngay nhap vao co hop le khong
void TinhThoiGian(su_kien sk[],int sosukien, int s[]) ; // Tinh thoi gian (phut)
int timThoiDiem(int sosukien); // Tim thoi diem da nhap





int main() {
    int i, sosukien;
    // Nhap vao su kien
    nhapSuKien(sosukien);
    // Liet ke cac su kien co do quan trong cao
    cout << "Liet ke cac su kien co do quan trong cao: " << endl;
    SuKienDoQuangTrongCao(sosukien);
    // Liet ke cac su kien dien ra vao buoi sang
    cout << "Liet ke cac su kien dien ra vao buoi sang: " << endl;
    SuKienBuoiSang(sosukien);
    // Chon mot thoi diem va sua muc do quan trong cua thoi diem do
    cout << "Chon thoi diem muon sua muc do quan trong(0 ung voi thoi diem dau tien): ";
    cin >> i;
    suaMucDoQuanTrong(i);
    // Liet ke cac su kien rat quan trong sau thoi diem da nhap
    cout << "Moi nhap thoi diem de xuat su kien rat quan trong sau thoi diem do: " << endl;
    xuatSuKienRatQuanTrong(sosukien);
    // Sap xep lai cac su kien theo thu tu thoi gian
    TinhThoiGian(sk,sosukien,thoigian);
    SapXepSuKien(sk,sosukien,thoigian);
    cout<<"\nDanh sach su kien sau khi da sap xep la: \n";
    for (int i=0; i<sosukien; i++)
         {
        xuatSuKien(i);
        cout<<endl;
        }
    // Xoa nhung su kien khong quan trong
    xoaSuKienKhongQuanTrong(sk,sosukien);
    cout<<"\nDanh sach su kien sau khi xoa su kien khong quan trong: \n";
    for (int i=0; i<sosukien; i++)
         {
        xuatSuKien(i);
        cout<<endl;
        }
    system("pause");
    return 0;
}

// Ham nhap su kien
void nhapSuKien(int& sosukien) {
    cout << "Nhap so su kien can nhap: ";
    cin >> sosukien;
    for (int i = 0; i < sosukien; i++) {
        cout << "Nhap su kien thu " << i+1<< endl;
        thaySuKien(i); // nhập sk[i]
    }
}
void thaySuKien(int i) {
    cout << "Nhap thoi diem (ngay/thang/nam/gio/phut): "<<endl;
    nhapthoidiem(i);
    cout << "Nhap ten su kien (vd: sinh_nhat): ";
    cin>> sk[i].ten;
    do {
        cout << "Nhap muc do quan trong(0/1/2/3): ";
        cin >> sk[i].doquantrong;
    } while (sk[i].doquantrong < 0 || sk[i].doquantrong>3);
}
// Ham xuat ra nhung su kien
void xuatSuKien(int i) {
    cout << " Ten su kien: " << sk[i].ten << endl;
    cout << " Thoi diem dien ra su kien: " << sk[i].thoidiem.ngay << " / " << sk[i].thoidiem.thang << " / " << sk[i].thoidiem.nam << ". Luc: " << sk[i].thoidiem.gio << " gio " << sk[i].thoidiem.phut<< " phut" << endl;
    cout << " Muc do quan trong: ";
    xuatQuanTrong(sk[i].doquantrong);
    cout << endl;
}
// Ham xuat ra muc do quan trong ung voi tung so da nhap
void xuatQuanTrong(int doquantrong) {
    switch (doquantrong)
    {
    case 0: {
        cout << "Khong quan trong" << endl;
        break;
    }
    case 1: {
        cout << "Hoi quan trong" << endl;
        break;
    }
    case 2: {
        cout << "Kha quan trong" << endl;
        break;
    }
    case 3: {
        cout << "Rat quan trong" << endl;
        break;
    }
    }
}
// Ham liet ke nhung su kien co do quan trong cao
void SuKienDoQuangTrongCao(int sosukien) {
    for (int i = 0; i < sosukien; i++) {
        if (sk[i].doquantrong == 2 || sk[i].doquantrong == 3) {
            xuatSuKien(i);
        }
    }
}
// Ham liet ke nhung su kien dien ra vao buoi sang
void SuKienBuoiSang(int sosukien) {
    for (int i = 0; i < sosukien; i++) {
        if (sk[i].thoidiem.gio >= 4 && sk[i].thoidiem.gio < 11) {
            xuatSuKien(i);
        }
    }
}

// Ham doi thoi gian ra phut
void TinhThoiGian(su_kien sk[],int sosukien, int thoigian[]) 
{

    for (int i=0; i<sosukien; i++)
    {
        thoigian[i]= (sk[i].thoidiem.nam*12*43200 + sk[i].thoidiem.thang*43200 + sk[i].thoidiem.ngay*1440 + sk[i].thoidiem.gio*60 + sk[i].thoidiem.phut);
    }
}
// Ham sap xep su kien theo thu tu thoi gian
void SapXepSuKien(su_kien sk[], int sosukien, int thoigian[]) 
{
    for (int i=0; i<sosukien-1; i++)
        for (int j=1+i; j<sosukien; j++)
        {
            if (thoigian[i]>thoigian[j])
            {
                su_kien temp = sk[i];
                sk[i]= sk[j];
                sk[j]= temp;
            }
        }
}
// Ham huy su kien, p la vi tri can huy
void xoaSuKien(su_kien sk[], int& sosukien, int p) 
{
    for (int i=p; i<sosukien; i++)
        sk[i]=sk[i+1];
    sosukien--;             
    // So su kien giam xuong 1, vi ta da xoa di 1 su kien
}
// Ham xoa nhung su kien khong quan trong ra khoi mang
void xoaSuKienKhongQuanTrong(su_kien sk[], int &sosukien)
{
    for (int i=0; i<sosukien; i++)
    {
        if (sk[i].doquantrong == 0)
        {
            xoaSuKien(sk, sosukien, i);
        }
    }
}
// Ham sua lai muc do quan trong cua 1 su kien
void suaMucDoQuanTrong(int i) {
    cout << "Chon muc do quan trong muon sua: ";
    cin >> sk[i].doquantrong;
}
// Ham tra ve vi tri cua thoi diem da nhap
int timThoiDiem(int sosukien) {
    int temp;
    nhapthoidiem(temp);
    thoigian[temp] = (sk[temp].thoidiem.nam*12*43200 + sk[temp].thoidiem.thang*43200 + sk[temp].thoidiem.ngay*1440 + sk[temp].thoidiem.gio*60 + sk[temp].thoidiem.phut);
    for (int i = 0; i < sosukien; i++) {
        thoigian[i]= (sk[i].thoidiem.nam*12*43200 + sk[i].thoidiem.thang*43200 + sk[i].thoidiem.ngay*1440 + sk[i].thoidiem.gio*60 + sk[i].thoidiem.phut);
        if (thoigian[temp] == thoigian[i])
        {
            return i;
            break;
        }
        
    }
}
// Ham xuat ra nhung su kien rat quan trong sau thoi diem vua nhap
void xuatSuKienRatQuanTrong(int sosukien) {
    int counter;
    counter = timThoiDiem(sosukien);
    cout << "Cac su kien rat quan trong sau su kien da nhap la: " << endl;
    for (int j = counter + 1; j < sosukien; j++) {
        if (sk[j].doquantrong == 3)
            xuatSuKien(j);
    }
}
// Ham nhap vao thoi diem
void nhapthoidiem(int& i) {
    do {
        cout << "Nhap ngay: ";
        cin >> sk[i].thoidiem.ngay;
        cout << "Nhap thang: ";
        cin >> sk[i].thoidiem.thang;
        cout << "Nhap nam: ";
        cin >> sk[i].thoidiem.nam;
    }  while (LaNgayHopLe(sk[i].thoidiem.ngay, sk[i].thoidiem.thang, sk[i].thoidiem.nam) == false);
    do {
        cout << "Nhap gio: ";
        cin >> sk[i].thoidiem.gio;
    } while (sk[i].thoidiem.gio < 0 || sk[i].thoidiem.gio>23);
    do {
        cout << "Nhap phut: ";
        cin >> sk[i].thoidiem.phut;
    } while (sk[i].thoidiem.phut < 0 || sk[i].thoidiem.phut>59);
}
// Ham tim so ngay toi da cua moi thang
int SoNgayTrongThang(int month) {
    switch (month) {
        // Thang 2 cua nam 2021/2022 co 28 ngay
        case 2:
            return 28;
        // Cac thang 4, 6, 9, 11 co 30 ngay
        case 4: case 6: case 9: case 11: 
            return 30;
        // Cac thang 1, 3, 5, 7, 8, 10, 12 co 31 ngay
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:   
            return 31;
    }
}
// Ham kiem tra xem du lieu nhap vao co hop le hay khong
bool LaNgayHopLe(int ngay, int thang, int nam) {    
    if (0 < ngay && ngay <= SoNgayTrongThang(thang)) {
        if ((nam == 2021 || nam == 2022) && (0 < thang && thang <= 12)) 
            return true;
        else
            return false;
    }
    else 
        return false;
}

