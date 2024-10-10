#include <bits/stdc++.h>
using namespace std;

void RutGon(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp; 
}

int main() {
    int a, b;
    cout << "Nhap tu so va mau so cua phan so: ";
    cin >> a >> b;
    RutGon(&a, &b);
    cout << "Phan so rut gon la: " << a << '/' << b;
    return 0;
}