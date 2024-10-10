#include <iostream>
#include <algorithm>

using namespace std;

void rutGon(int &a, int &b){
    int x = __gcd(a, b);
    a = a / x;
    b = b / x;
}

void cong(int a1, int b1, int a2, int b2){
    int a = a1 * b2 + a2 * b1;
    int b = b1 * b2;
    rutGon(a, b);
    cout << a << "/" << b << endl;
}

void tru(int a1, int b1, int a2, int b2){
    int a = a1 * b2 - a2 * b1;
    int b = b1 * b2;
    rutGon(a, b);
    cout << a << "/" << b << endl;
}

void chia(int a1, int b1, int a2, int b2){
    int a = a1 * b2;
    int b = b1 * a2;
    rutGon(a, b);
    cout << a << "/" << b << endl;
}

void nhan(int a1, int b1, int a2, int b2){
    int a = a1 * a2;
    int b = b1 * b2;
    rutGon(a, b);
    cout << a << "/" << b << endl;
}



int main(){
    int mauso1, tuso1;
    cout << "Nhap tu so cua phan so 1: ";
    cin >> tuso1;
    cout << "Nhap mau so cua phan so 1: ";
    cin >> mauso1;
    int mauso2, tuso2;
    cout << "Nhap tu so cua phan so 2: ";
    cin >> tuso2;
    cout << "Nhap mau so cua phan so 2: ";
    cin >> mauso2;
    cong(tuso1, mauso1, tuso2, mauso2);
    tru(tuso1, mauso1, tuso2, mauso2);
    nhan(tuso1, mauso1, tuso2, mauso2);
    chia(tuso1, mauso1, tuso2, mauso2);
}