#include <iostream>
#include <algorithm>

/**
 * This program performs basic arithmetic operations (addition, subtraction, multiplication, division)
 * on two fractions entered by the user and outputs the results in their simplest form.
 *
 * Functions:
 *  - `rutGon(int &a, int &b)`: Reduces the fraction a/b to its simplest form by dividing both
 *    the numerator and denominator by their greatest common divisor (GCD).
 *  - `cong(int a1, int b1, int a2, int b2)`: Adds two fractions a1/b1 and a2/b2, reduces the result,
 *    and prints the simplified fraction.
 *  - `tru(int a1, int b1, int a2, int b2)`: Subtracts fraction a2/b2 from a1/b1, reduces the result,
 *    and prints the simplified fraction.
 *  - `chia(int a1, int b1, int a2, int b2)`: Divides fraction a1/b1 by a2/b2, reduces the result,
 *    and prints the simplified fraction.
 *  - `nhan(int a1, int b1, int a2, int b2)`: Multiplies two fractions a1/b1 and a2/b2, reduces the result,
 *    and prints the simplified fraction.
 *
 * Input:
 *  - Numerator and denominator for two fractions entered by the user.
 *
 * Output:
 *  - The result of the addition, subtraction, multiplication, and division of the two fractions, 
 *    each in its simplest form.
 *
 * @return 0 on successful execution.
 */

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