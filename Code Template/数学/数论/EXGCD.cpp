#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void extend_gcd(ll a, ll b, ll &x, ll &y, ll &d) {
    if (!b) {d = a, x = 1, y = 0;}
    else {
        extend_gcd(b, a % b, y, x, d);
        y -= a / b * x;
    }
}


ll mod_reverse(ll a, ll n) {
    ll x, y, d;
    extend_gcd(a, n, x, y, d);
    if (d == 1) return (x % n + n) % n;
    else return -1;
}


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

ll modular_liner_equation(ll a, ll b, ll n) {
    ll x, y, x0, d;
    extend_gcd(a, n, x, y, d);
    if (b % d)
        return -1;
    x0 = (x * (b / d)) % n;
    //for(int i=1;i<d;i++)
        //cout<<(x0+i*(n/d))%n<<endl;
    ll ans = x0, s = n / d;
    ans = (ans % s + s) % s;
    return ans;
}
