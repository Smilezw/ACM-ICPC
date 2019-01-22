#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;

//二分快速幂
ll mod_pow(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % mod; //如果二进制最低位为1、则乘上x^(2^i)
        x = x * x % mod;  // 将x平方
        y >>= 1;
    }
    return res%mod;
}

ll inv[MAXN];
ll f[MAXN];

void init(){
    f[0] = inv[0] = 1;
    for(int i = 1; i < MAXN; i++){
        f[i] = 1ll*f[i-1] * i %mod;
        inv[i] = mod_pow(f[i], mod - 2);
    }
}

ll cal(ll n, ll i){
    //cout << n << " " << i << " " << f[n]*inv[i]%mod*inv[n-i]%mod  << endl;
    return f[n]*inv[i]%mod*inv[n-i]%mod;
}
