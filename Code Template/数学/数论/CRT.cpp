#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

void extend_gcd(ll a, ll b, ll &x, ll &y, ll &d) {
    if (!b) {d = a, x = 1, y = 0;}
    else {
        extend_gcd(b, a % b, y, x, d);
        y -= a / b * x;
    }
}
//中国剩余定理 a[]存放余数 w[]存放两两互质的数
//sum{ai*ti*mi} ti*Mi % mi = 1
ll CRT(ll a[], ll w[], ll len) {
    ll d, x, y, m;
    ll ret = 0;
    ll n = 1;
    for (int i = 0; i < len; i++)
        n *= w[i];
    for (int i = 0; i < len; i++) {
        m = n / w[i];   //Mi
        extend_gcd(w[i], m, x, y, d);   // w[i] 与 m 互素
        ret = (ret + y * m * a[i]) % n;   //y*m = ti*Mi
    }
    return (n + ret % n) % n;
}

//对于不互质情况  解n个方程的方程组  以 a，r形式给出
ll _CRT(int n, ll a[], ll r[]) {
    ll x, y, d;
    ll a1 = a[0], r1 = r[0];
    for(int i = 1; i < n; i++) {
        extend_gcd(a1, a[i], x, y, d);
        if((r[i] - r1) % d)
            return -1;
        x = (r[i]-r1)/d*x;   //特解
        y = a[i]/d;
        x = (x%y + y) % y;  //通解
        r1 = x*a1 + r1 ;    //回代
        a1 = (a1*a[i])/d ;    //lcm
    }
    extend_gcd(1, a1, x, y, d);   //合并方程
    if(r1 % d) return -1;
    else {
        x = r1/d*x ;
        y = a1 / d ;
        x = ( x%y+y )%y ;
        return x;
    }
}
