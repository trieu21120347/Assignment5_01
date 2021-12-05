// Chuong trinh tinh tong 1 day phan so, sap xep lai day theo thu tu tang & xuat ket qua
#include<iostream>

using namespace std;
#define MAX 1000

struct DayPhanSo
{
    int tu;
    int mau;
};
DayPhanSo ps[MAX];
int SoPhanTu;
// Khai bao prototype ham:
void nhapPhanSo();// Prototype ham nhap cac phan so
void xuatPhanSo();// Prototype ham xuat cac phan so da nhap
DayPhanSo tongPhanSo();// Prototype ham tinh tong cac phan so da nhap
void xuatTong(); // Prototype ham xuat tong cac phan so da nhap
void sapxepPhanSo();// Prototype ham sap xep phan so
int timUCLN(int, int);// Prototype ham tim UCLN
int abs(int);// Prototype ham tri tuyet doi
void rutgon(int& tu, int& mau);// Prototype ham rut gon
void swap(int& a, int& b); //Prototype ham hoan vi 2 so


int main() {
    nhapPhanSo();
    cout << "Day phan so vua nhap la: ";
    xuatPhanSo();
    cout << endl;
    xuatTong();
    sapxepPhanSo();
    cout << "Day phan so sau khi da sap xep la: ";
    xuatPhanSo();
    cout << endl;
    system("pause");
    return 0;
}
// Ham nhap day phan so tu ban phim
void nhapPhanSo() {
    do {
    cout << "Nhap so phan so cua day: ";
    cin >> SoPhanTu;
    } while (SoPhanTu <= 0 || SoPhanTu > MAX);
    for (int i = 0; i < SoPhanTu; i++) {
        cout << "Nhap phan so " << i + 1 << " (ps[" << i << "]):" << endl;
        cout << "Nhap vao tu: "; cin >> ps[i].tu;
        cout << "Nhap vao mau(!= 0): "; cin >> ps[i].mau;
        while (ps[i].mau == 0) {
            cout << "Vui long nhap lai mau: ";
            cin >> ps[i].mau; 
        }
        cout << endl;
        }
    }
// Ham xuat ra day phan so
void xuatPhanSo() {
    for (int i = 0; i < SoPhanTu; i++) {
        cout << ps[i].tu << "/" << ps[i].mau << "  ";
    }
}
// Ham tinh tong day phan so
DayPhanSo tongPhanSo() {
    DayPhanSo tong = ps[0];
    for (int i = 1; i < SoPhanTu; i++) {
        tong.tu = tong.tu * ps[i].mau + tong.mau * ps[i].tu;
        tong.mau = tong.mau * ps[i]. mau;
        rutgon(tong.tu, tong.mau);
    }
    rutgon(tong.tu, tong.mau);
    return tong;
}
// Ham xuat tong day phan so 
void xuatTong() {
    DayPhanSo tongps = tongPhanSo();
    cout << "Tong cua day phan so vua nhap la: ";
    cout << tongps.tu << "/" << tongps.mau << endl;
}
// Ham sap xep day phan so
void sapxepPhanSo() {
    for (int i = 0; i < SoPhanTu; i++) {
        for (int j = i + 1; j < SoPhanTu; j++) {
            float A = (float)ps[i].tu / (float)ps[i].mau;
            float B = (float)ps[j].tu / (float)ps[j].mau;
            if (A > B) {
                swap(ps[i].tu, ps[j].tu);
                swap(ps[i].mau, ps[j].mau);
            }

        }
    }
}
// Ham tinh gia tri tuyet doi
int abs(int a) {
    if (a < 0)
        return -a;
    return a;
}
// Ham tim uoc chung lon nhat
int timUCLN(int tu, int mau) {
    abs(tu);
    abs(mau);
    if (mau == 0)
        return tu;
    if (mau == tu)
        return tu;
    return timUCLN(mau, tu % mau);
}
// Ham toi gian phan so
void rutgon(int& tu, int& mau) {
    int UCLN = timUCLN(tu, mau);
    tu /= UCLN;
    mau /= UCLN;
}
// Ham hoan vi 2 phan tu
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
