#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int mauso, tuso;
    cout << "Nhap tu so: ";
    cin >> tuso;
    cout << "Nhap mau so: ";
    cin >> mauso;
    int a = tuso / __gcd(tuso, mauso);
    int b = mauso / __gcd(tuso, mauso);

    if (b < 0){
        a = -a;
        b = -b;
    }

    cout << "Phan so toi gian: " << a << "/" << b << endl;
}