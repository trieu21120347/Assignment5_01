#include <iostream>
using namespace std;
#define MAX 1000
struct DaGiac
{
	int socanh;//số cạnh
	float length[MAX]; // chiều dài từng cạnh
};
// prototype ham nhap da giac
void nhapDaGiac(DaGiac &a);
// prototype ham tinh chu vi da giac
float chuviDaGiac(DaGiac a);


int main()
{
	DaGiac a;
	nhapDaGiac(a);
	cout << "Chu vi da giac do la:" << chuviDaGiac(a) << endl;
	return 0;
}

// Ham nhap da giac
void nhapDaGiac(DaGiac &a)
{
    do {
	cout << "Nhap so canh cua da giac: ";
	cin >> a.socanh;
    } while (a.socanh < 3);
	for (int i = 0; i < a.socanh; i++)
	{
		do {
			cout << "Nhap canh thu " << i + 1 << ": ";
			cin >> a.length[i];
		} while (a.length[i] <= 0);
	}
}
// Ham tinh chu vi da giac
float chuviDaGiac(DaGiac a)
{
	float chuvi = 0;
	for (int i = 0; i < a.socanh ; i++)
	{
		chuvi += a.length[i];
	}
	return chuvi;
}