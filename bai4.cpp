#include <iostream>
#include <algorithm>
#include <math.h>
#include  <cmath> 

/**
 * This program calculates the sine of an angle (in radians) using a Taylor series expansion.
 * It also compares the result with the standard library `sin()` function for accuracy.
 *
 * Functions:
 *  - `fra(long long n)`: Computes the factorial of a given number `n`.
 *  - `Sinx(double x)`: Calculates the sine of angle `x` using the Taylor series expansion.
 *    The series is computed until the current term is smaller than a predefined precision (0.00001).
 *    The angle `x` is reduced modulo `2 * pi` to keep the angle within one full revolution.
 *
 * Input:
 *  - The angle `x` in radians entered by the user.
 *
 * Output:
 *  - The sine of `x` calculated using the Taylor series.
 *  - The sine of `x` calculated using the `sin()` function from the standard library.
 *
 * @return 0 on successful execution.
 */


using namespace std;


long long fra(long long n){
    long long res = 1;
    for (int i = 2;i <= n ; i++){
        res = res * i;
    }
    return res;
}

double Sinx(double x){
    double ans = 0;
    double precision = 0.00001;
    x = fmod(x,2*M_PI);
    double check = x;
    long long i = 0;
    while (check > precision){
        
        if (i%2==0) ans += check;
        else ans -= check;
        i++;
        check = pow(x,2*i + 1)/fra(2*i+1);
    }
    return ans;
}

int main(){
    double x;
    cout << "Nhap x: ";
    cin >> x;
    cout << Sinx(x) << endl;
    cout << sin(x) << endl;
    return 0;
}