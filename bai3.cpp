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
}

/**
 * Adds two fractions represented by numerators (`a1`, `a2`) and denominators (`b1`, `b2`).
 * The function calculates the sum of the two fractions, simplifies the result using `rutGon()`,
 * and then prints the simplified fraction in the form "a/b".
 *
 * @param a1 Numerator of the first fraction.
 * @param b1 Denominator of the first fraction.
 * @param a2 Numerator of the second fraction.
 * @param b2 Denominator of the second fraction.
 */

void cong(int a1, int b1, int a2, int b2){
    int a = a1 * b2 + a2 * b1;
    int b = b1 * b2;
    rutGon(a, b);
    cout << a << "/" << b << endl;
}

/**
 * Subtracts two fractions represented by numerators (`a1`, `a2`) and denominators (`b1`, `b2`).
 * The function calculates the difference of the two fractions, simplifies the result using `rutGon()`,
 * and then prints the simplified fraction in the form "a/b".
 *
 * @param a1 Numerator of the first fraction.
 * @param b1 Denominator of the first fraction.
 * @param a2 Numerator of the second fraction.
 * @param b2 Denominator of the second fraction.
 */

void tru(int a1, int b1, int a2, int b2){
    int a = a1 * b2 - a2 * b1;
    int b = b1 * b2;
    rutGon(a, b);
    cout << a << "/" << b << endl;
}

/**
 * Multiplies two fractions represented by numerators (`a1`, `a2`) and denominators (`b1`, `b2`).
 * The function calculates the product of the two fractions, simplifies the result using `rutGon()`,
 * and then prints the simplified fraction in the form "a/b".
 *
 * @param a1 Numerator of the first fraction.
 * @param b1 Denominator of the first fraction.
 * @param a2 Numerator of the second fraction.
 * @param b2 Denominator of the second fraction.
 */

void chia(int a1, int b1, int a2, int b2){
    int a = a1 * b2;
    int b = b1 * a2;
    rutGon(a, b);
    cout << a << "/" << b << endl;
}

/**
 * Divides two fractions represented by numerators (`a1`, `a2`) and denominators (`b1`, `b2`).
 * The function calculates the quotient of the two fractions, simplifies the result using `rutGon()`,
 * and then prints the simplified fraction in the form "a/b".
 *
 * @param a1 Numerator of the first fraction.
 * @param b1 Denominator of the first fraction.
 * @param a2 Numerator of the second fraction.
 * @param b2 Denominator of the second fraction.
 */

void nhan(int a1, int b1, int a2, int b2){
    int a = a1 * a2;
    int b = b1 * b2;
    rutGon(a, b);
    cout << a << "/" << b << endl;
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