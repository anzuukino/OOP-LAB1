#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int mauso1, tuso1;
    cout << "Nhap tu so cua phan so 1: ";
    cin >> tuso1;
    cout << "Nhap mau so cua phan so 1: ";
    cin >> mauso1;
    int a1, b1;
    a1 = tuso1 / __gcd(tuso1, mauso1);
    b1 = mauso1 / __gcd(tuso1, mauso1);
    int mauso2, tuso2;
    cout << "Nhap tu so cua phan so 2: ";
    cin >> tuso2;
    cout << "Nhap mau so cua phan so 2: ";
    cin >> mauso2;
    int a2, b2;
    a2 = tuso2 / __gcd(tuso2, mauso2);
    b2 = mauso2 / __gcd(tuso2, mauso2);
    if (a1 * b2 < a2 * b1){
        cout << a2 <<"/" << b2 << endl;
    } else {
        cout << a1 <<"/" << b1 << endl;
    }
}