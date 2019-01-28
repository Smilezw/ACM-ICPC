//对于二维的容斥关系  直接求不好求，考虑减去行上的不幸运数 (3^n-3)^n  (类比三进制下长度为n的数)
//显然多减去了行上相同的部分  那么考虑加上去，使用容斥关系
//对于i行相同      1. 这i行 为一种颜色3种选择,再对列    3*c(n,i)  *  (3^(n-i) - 1)^n （每一列到所有列）
//对于i行各不相同  2. 这i行各不相同3^i-1种选择，再对列 (3^i-3)*c(n,i) * (3^(n-i))^n
//总数3^(n^2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int MAXN = 1e6 + 5;

inline ll quickpow(ll a, ll b) {
    ll ret = 1;
    ll n = a;

    while (b) {
        if (b & 1) ret = ret * n % mod; //如果二进制最低位为1、则乘上x^(2^i)
        n = n * n % mod;  // 将x平方
        b = b >> 1;
    }
    return ret % mod;
}

ll inv[MAXN];
ll f[MAXN];

void init(){
    f[0] = inv[0] = 1;
    for(int i = 1; i < MAXN; i++){
        f[i] = 1ll*f[i-1] * i %mod;
        inv[i] = quickpow(f[i], mod - 2);
    }
}

ll cal(ll n, ll i){
    //cout << n << " " << i << " " << f[n]*inv[i]%mod*inv[n-i]%mod  << endl;
    return f[n]*inv[i]%mod*inv[n-i]%mod;
}

ll n;
int main(){
    init();
    cin >> n;
    ll ans = quickpow(3ll, n*n) - quickpow( quickpow(3ll, n) - 3, n); //每一列至少一种颜色的方法
    for(ll i = 1; i <= n; i++){    //枚举1个颜色行的数量
        ll now = 3*quickpow( (quickpow(3, (n-i)) - 1), n) %mod;  //整行颜色相同的行的颜色都一样
        now += (quickpow(3,i) - 3)*quickpow(3, (n-i)*n); //整行颜色相同的行颜色不一样
        now %= mod;
        now *= cal(n, i);
        now %= mod;
        if(i&1)
            ans = (ans + now)%mod;
        else
            ans = (ans - now + mod)%mod;
    }
    cout << ans << endl;
    return 0;
}
