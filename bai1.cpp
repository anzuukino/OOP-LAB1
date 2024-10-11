#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Main function to reduce a fraction to its simplest form.
 * The program repeatedly prompts the user to input the numerator and denominator of a fraction.
 * It ensures that the denominator is non-zero before proceeding.
 * Using the greatest common divisor (GCD), the fraction is reduced by dividing both the numerator
 * and the denominator by their GCD.
 * If the reduced denominator is negative, the signs of both numerator and denominator are adjusted
 * to keep the denominator positive.
 * Finally, the simplified fraction is printed in the form "a/b".
 *
 * @return 0 on successful execution.
 */


int main(){
    int mauso, tuso;
    do {
        cout << "Nhap tu so: ";
        cin >> tuso;
        cout << "Nhap mau so: ";
        cin >> mauso;
        if (mauso == 0){
            cout << "Mau so phai khac 0. Vui long nhap lai.\n";
        }
    }while(mauso == 0); 
    
    int a = tuso / __gcd(tuso, mauso);
    int b = mauso / __gcd(tuso, mauso);

    if (b < 0){
        a = -a;
        b = -b;
    }

    cout << "Phan so toi gian: " << a << "/" << b << endl;
}