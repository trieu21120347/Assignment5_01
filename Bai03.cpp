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
void lietkeSK1(su_kien sk[],int sosukien); // cac su kien kha quan trong va rat quan trong
void lietkeSK2(su_kien sk[],int sosukien);  // cac su kien dien ra vao buoi sang 4h-11h
// Khai báo biến và mảng
su_kien sk[MAX];
int sosukien;

int main() {
    nhapSuKien(sosukien);
}

// Ham nhap su kien
void nhapSuKien(int& sosukien){
    cout<< "Nhap so su kien can nhap: ";
    cin >> sosukien;
    for (int i=1;i<sosukien;i++){
        cout << "Nhap su kien thu " << i;
        thaySuKien(i); // nhập dữ liệu sk[i]
    }
}

void lietkeSK1(su_kien sk[], int n){
    for (int i = 0; i < n; i++) {
        if (sk[i].doquantrong == 3 || sk[i].doquantrong == 4) {
            xuatSuKien(i);
        }
    }
}
// Ham liet ke 2
void lietkeSK2(su_kien sk[], int n) {
    for (int i = 0; i < n; i++) {
        if (sk[i].thoidiem.gio >= 4 && sk[i].thoidiem.gio < 11) {
            xuatSuKien(i);
        }
    }
}
// cop vo roi nhan commit change o duoi la dc
