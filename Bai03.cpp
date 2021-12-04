// Xay dung kieu du lieu bieu dien cac moc su kien voi moi moc su kien gom 3 thong tin:
//  + thoi_diem (mot moc ngay/thang/nam/gio/phut trong nam 2021 va 2020)
//  + ten su kien
//  + do quan trong (4 muc: khong quan trong, co chut quan trong, kha quan trong, rat quan trong)
#include<iostream>
#define MAX 1000
using namespace std;

struct thoi_diem {
    int ngay; // 0< x <= 31 
    int thang; //0<x<=12
    int nam;  // 2021<=x<=2022
    int gio;   // 0<= x <= 23 
    int phut;   // 0<= x <= 59
};

struct su_kien {
    thoi_diem thoidiem;
    char ten;
    int doquantrong;
};
// Khai bao prototype ham
void nhapSuKien(int& sosukien);
void thaySuKien(int i); // sua su kien sk[i]
void xuatSuKien(int i); // in ra su kien sk[i]
void xuatQuanTrong(int doquantrong); // chuyen doquantrong {0,1,2,3} -> {k quan trong,hoi quan trong , kha quan trong,rat quan trong}, dung switch
void lietkeSK1(int a); // cac su kien kha quan trong va rat quan trong
void lietkeSK2(int b);  // cac su kien dien ra vao buoi sang 4h-11h

// Khai báo biến và mảng
su_kien sk[MAX];
int sosukien;

int main() {
    nhapSuKien(sosukien);
    cout << endl;
    lietkeSK1(sosukien);
    cout << endl;
    lietkeSK2(sosukien);
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
    do {
        cout << "Nhap ngay: ";
        cin >> sk[i].thoidiem.ngay;
    } while (sk[i].thoidiem.ngay < 0 || sk[i].thoidiem.ngay>31);
    do {
        cout << "Nhap thang: ";
        cin >> sk[i].thoidiem.thang;
    } while (sk[i].thoidiem.thang < 1 || sk[i].thoidiem.thang>12);
    do {
        cout << "Nhap nam (2021/2022): ";
        cin >> sk[i].thoidiem.nam;
    } while (sk[i].thoidiem.nam != 2021 && sk[i].thoidiem.nam != 2022);
    do {
        cout << "Nhap gio: ";
        cin >> sk[i].thoidiem.gio;
    } while (sk[i].thoidiem.gio < 0 || sk[i].thoidiem.gio>23);
    do {
        cout << "Nhap phut: ";
        cin >> sk[i].thoidiem.phut;
    } while (sk[i].thoidiem.phut < 0 || sk[i].thoidiem.phut>59);
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
// cop vo roi nhan commit change o duoi la dc
