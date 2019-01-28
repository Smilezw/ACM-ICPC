#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
//返回d = gcd(a, b);和对应于等式ax+by = d中的x,y
void extend_gcd(ll a, ll b, ll &x, ll &y, ll &d) {
    if (!b) {d = a, x = 1, y = 0;}
    else {
        extend_gcd(b, a % b, y, x, d);
        y -= a / b * x;
    }
}

//ax = 1(mod n) 要求a与n互质  求逆元   逆元公式 (a/b)mod m = (a mod (m * b))/b
ll mod_reverse(ll a, ll n) {
    ll x, y, d;
    extend_gcd(a, n, x, y, d);
    if (d == 1) return (x % n + n) % n;
    else return -1;
}
//欧拉函数求逆元 a的 n的欧拉函数次减一
/*费马小定理 要求a与n互质  且n为素数
如果p是素数 x^p = x(mod p)
如果x无法被p整除、则x^(p - 1)= 1(mod p)
a^(-1) = a^(p - 2)(mod p) 可以通过快速幂求出逆元*/
const int mod = 1000000009;  // ax %mod = 1%mod;
ll quickpow(ll a, ll b) {
    if (b < 0) return 0;
    ll ret = 1;
    a %= mod;
    while(b) {
        if (b & 1) ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}

ll inv(ll a) {
    return quickpow(a, mod - 2);
}
//求解模线性方程ax=b(mod n)
ll modular_liner_equation(ll a, ll b, ll n) {
    ll x, y, x0, d;
    extend_gcd(a, n, x, y, d);
    if (b % d)//没有解
        return -1;
    x0 = (x * (b / d)) % n;//特解
    //for(int i=1;i<d;i++)
        //cout<<(x0+i*(n/d))%n<<endl;
    ll ans = x0, s = n / d;
    ans = (ans % s + s) % s;   //ans为最小整数解
    return ans;
}
