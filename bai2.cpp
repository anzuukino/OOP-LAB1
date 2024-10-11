#include <iostream>
#include <algorithm>

/**
 * Main function to compare two fractions and output the larger one in its simplest form.
 * 
 * The program prompts the user to input the numerators and denominators of two fractions.
 * It ensures that the denominators are non-zero by repeatedly asking the user for valid inputs.
 * 
 * Once both fractions are provided, the program simplifies each fraction by calculating the greatest 
 * common divisor (GCD) and dividing both the numerator and denominator by the GCD. If the denominator
 * is negative after simplification, the signs of both the numerator and denominator are adjusted to 
 * ensure the denominator is positive.
 * 
 * The two simplified fractions are then compared by cross-multiplying their numerators and denominators 
 * (to avoid floating-point precision issues). The larger fraction is printed in the form "a/b".
 * 
 * Input:
 *   - Numerator and denominator for two fractions, where the denominators must be non-zero.
 * 
 * Output:
 *   - The larger of the two fractions, simplified, in the form "a/b".
 *
 * @return 0 on successful execution.
 */


using namespace std;

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
    int a1, b1;
    a1 = tuso1 / __gcd(tuso1, mauso1);
    b1 = mauso1 / __gcd(tuso1, mauso1);
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
    int a2, b2;
    a2 = tuso2 / __gcd(tuso2, mauso2);
    b2 = mauso2 / __gcd(tuso2, mauso2);
    if (a1 * b2 < a2 * b1){
        cout << a2 <<"/" << b2 << endl;
    } else {
        cout << a1 <<"/" << b1 << endl;
    }
}