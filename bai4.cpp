#include <iostream>
#include <algorithm>
#include <math.h>
#include  <cmath> 

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