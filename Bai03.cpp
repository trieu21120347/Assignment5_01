// Xay dung kieu du lieu bieu dien cac moc su kien voi moi moc su kien gom 3 thong tin:
//  + thoi_diem (mot moc ngay/thang/nam/gio/phut trong nam 2021 va 2020)
//  + ten su kien
//  + do quan trong (4 muc: khong quan trong, co chut quan trong, kha quan trong, rat quan trong)
#include <iostream>
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
    char ten;
    int doquantrong;
};
// Khai bao prototype ham
void nhapthoidiem(int i);
void nhapSuKien(int& sosukien);
void thaySuKien(int i); // sua su kien sk[i]
void xuatSuKien(int i); // in ra su kien sk[i]
void xuatQuanTrong(int doquantrong); // chuyen doquantrong {0,1,2,3} -> {k quan trong,hoi quan trong , kha quan trong,rat quan trong}, dung switch
void lietkeSK1(int a); // cac su kien kha quan trong va rat quan trong
void lietkeSK2(int b);  // cac su kien dien ra vao buoi sang 4h-11h
void suaMucDoQuanTrong(int i);
void sk_ratquantrong(int i, int sosukien); // Xac dinh mot su kien rat quan trong khi biet thoi diem
void SapXepSuKien(su_kien sk[], int sosukien, int s[]) ;
void XoaSuKien(su_kien sk[], int& sosukien, int p) ;
void XoaSuKienKhongQuanTrong(su_kien sk[], int &sosukien);
int SoNgayTrongThang(int month);
bool LaNgayHopLe(int ngay, int thang, int nam);
void TinhThoiGian(su_kien sk[],int sosukien, int s[]) ;


// Khai báo biến và mảng
su_kien sk[MAX];
// int sosukien;
int s[100];

int main() {
    
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
    cout << "Nhap ten su kien: ";
    cin >> sk[i].ten;
    do {
        cout << "Nhap muc do quan trong(0/1/2/3): ";
        cin >> sk[i].doquantrong;
    } while (sk[i].doquantrong < 0 || sk[i].doquantrong>3);
}
void xuatSuKien(int i) {
    cout << " Ten su kien: " << sk[i].ten << endl;
    cout << " Thoi diem dien ra su kien: Ngay" << sk[i].thoidiem.ngay<<" Thang " << sk[i].thoidiem.thang << " Nam " << sk[i].thoidiem.nam << ". Luc " << sk[i].thoidiem.gio << " gio " << sk[i].thoidiem.phut<< " phut" << endl;
    cout << " Muc do quan trong: ";
    xuatQuanTrong(sk[i].doquantrong);
}
void xuatQuanTrong(int doquantrong) {
    switch (doquantrong)
    {
    case 0: {
        cout << "Khong quan trong";
        break;
    }
    case 1: {
        cout << "Hoi quan trong";
        break;
    }
    case 2: {
        cout << "Kha quan trong";
        break;
    }
    case 3: {
        cout << "Rat quan trong";
        break;
    }
    }
}
void lietkeSK1(int a) {
    cout << "Liet ke cac su kien co do quan trong cao" << endl;
    for (int i = 0; i < a; i++) {
        if (sk[i].doquantrong == 3 || sk[i].doquantrong == 4) {
            xuatSuKien(i);
        }
    }
}
void lietkeSK2(int b) {
    cout << "Liet ke cac su kien dien ra vao buoi sang" << endl;
    for (int i = 0; i < b; i++) {
        if (sk[i].thoidiem.gio >= 4 && sk[i].thoidiem.gio < 11) {
            xuatSuKien(i);
        }
    }
}

// Ham doi thoi gian ra phut
void TinhThoiGian(su_kien sk[],int sosukien, int s[]) 
{

    for (int i=0; i<sosukien; i++)
    {
        s[i]= (sk[i].thoidiem.nam*12*43200 + sk[i].thoidiem.thang*43200 + sk[i].thoidiem.ngay*1440 + sk[i].thoidiem.gio*60 + sk[i].thoidiem.phut);
    }
}
// Ham sap xep su kien theo thu tu thoi gian
void SapXepSuKien(su_kien sk[], int sosukien, int s[]) 
{
    for (int i=0; i<sosukien-1; i++)
        for (int j=1+i; j<sosukien; j++)
        {
            if (s[i]>s[j])
            {
                su_kien temp = sk[i];
                sk[i]= sk[j];
                sk[j]= temp;
            }
        }
}
// Ham huy su kien, p la vi tri can huy
void XoaSuKien(su_kien sk[], int& sosukien, int p) 
{
    for (int i=p; i<sosukien; i++)
        sk[i]=sk[i+1];
    sosukien--;             
    // So su kien giam xuong 1, vi ta da xoa di 1 su kien
}
void XoaSuKienKhongQuanTrong(su_kien sk[], int &sosukien)
{
    for (int i=0; i<sosukien; i++)
    {
        if (sk[i].doquantrong == 0)
        {
            XoaSuKien(sk, sosukien, i);
        }
    }
}

void sk_ratquantrong(int i, int sosukien) {
    nhapthoidiem(i);
    for (int j = i + 1; j < sosukien; j++) {
        if (sk[j].doquantrong == 3)
            xuatSuKien(i);
    }
}
void nhapthoidiem(int i) {
    do {
        cin >> sk[i].thoidiem.ngay;
        cin >> sk[i].thoidiem.thang;
        cin >> sk[i].thoidiem.nam;
    }  while (LaNgayHopLe(sk[i].thoidiem.ngay, sk[i].thoidiem.thang, sk[i].thoidiem.nam) == false);
    do {
        cin >> sk[i].thoidiem.gio;
        cin >> sk[i].thoidiem.phut;
    } while (sk[i].thoidiem.gio < 0 || sk[i].thoidiem.gio>23);
    do {
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
        if (nam > 0 && (0 < thang && thang <= 12)) 
            return true;
        else
            return false;
    }
    else 
        return false;
}

void suaMucDoQuanTrong(int i) {
    cout << "Chon thoi diem muon sua muc do quan trong: ";
    cin >> i;
    cout << "Chon muc do quan trong muon sua: ";
    cin >> sk[i].doquantrong;
}