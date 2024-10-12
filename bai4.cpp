#include <iostream>
#include <algorithm>
#include <math.h>
#include  <cmath> 


using namespace std;

/**
 * Computes the factorial of a given number `n`.
 *
 * @param n The number for which the factorial is to be computed.
 * @return The factorial of `n`.
 */

long long fra(long long n){
    long long res = 1;
    for (int i = 2;i <= n ; i++){
        res = res * i;
    }
    return res;
}

/**
 * Computes the sine of a given angle `x` using the Maclaurin series expansion.
 *
 * @param x The angle in radians for which the sine is to be computed.
 * @return The sine of the given angle.
 */

double Sinx(double x){
    double res = 0;
    double precision = 0.00001;
    int flag = 0;
    if (x < 0) flag = 1;
    x = fabs(x);
    x = fmod(x,2*M_PI);
    double ans = x;
    long long i = 0;
    while (ans > precision){
        if (i%2==0) res += ans;
        else res -= ans;
        i++;
        ans = pow(x,2*i + 1)/fra(2*i+1);
    }
    return flag == 0 ? res : -res;
}

/**
 * Main function to compute the sine of a given angle.
 * The program prompts the user to input an angle in radians.
 * It then computes the sine of the angle using both the custom `Sinx` function
 * and the built-in `sin` function from the `cmath` library.
 * The results are printed to the console.
 *
 * @return 0 on successful execution.
 */

int main(){
    double x;
    cout << "Nhap x: ";
    cin >> x;
    cout << Sinx(x) << endl;
    return 0;
}