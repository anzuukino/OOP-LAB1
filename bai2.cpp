#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Simplifies the given fraction represented by two integers `a` (numerator) and `b` (denominator).
 * It reduces the fraction to its simplest form by dividing both `a` and `b` by their greatest common divisor (GCD).
 * Additionally, if the denominator is negative, the function ensures the negative sign is moved to the numerator.
 *
 * @param a Reference to the numerator of the fraction.
 * @param b Reference to the denominator of the fraction.
 */

void rutGon(int &a, int &b){
    int x = __gcd(a, b);
    a = a / x;
    b = b / x;
    if (b < 0){
        a = -a;
        b = -b;
    }
}

/**
 * Main function to compare two fractions.
 * The program prompts the user to input the numerators and denominators of two fractions.
 * It ensures that the denominators are non-zero before proceeding.
 * The fractions are then simplified using the `rutGon` function.
 * Finally, the simplified fraction with the greater value is printed to the console.
 *
 * @return 0 on successful execution.
 */

int main(){
    int mauso1, tuso1;
    cout << "Nhap tu so cua phan so 1: ";
    cin >> tuso1;
    do {
        cout << "Nhap mau so cua phan so 1: ";
        cin >> mauso1;
        if (mauso1 == 0){
            cout << "Mau so phai khac 0. Vui long nhap lai.\n";
        }
    }while(mauso1 == 0);
    rutGon(tuso1, mauso1);
    int mauso2, tuso2;
    cout << "Nhap tu so cua phan so 2: ";
    cin >> tuso2;
    do {
        cout << "Nhap mau so cua phan so 2: ";
        cin >> mauso2;
        if (mauso2 == 0){
            cout << "Mau so phai khac 0. Vui long nhap lai.\n";
        }
    }while(mauso2 == 0);
    rutGon(tuso2, mauso2);
    if (tuso1 * mauso2 > tuso2 * mauso1){
        cout << tuso1 << "/" << mauso1 << endl;
    } else {
        cout << tuso2 << "/" << mauso2 << endl;
    }
}