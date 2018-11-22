//欧拉函数优化公约数之和（可莫比乌斯函数优化）
//化简公式时枚举因子
#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
typedef long long ll;

const ll  mod = 1e9 + 7;
const int MAXN = 1111111;
const ll inv2 = 500000004;
unordered_map <ll , ll > m;

int euler[MAXN];
int sum[MAXN];

void euler_phi2() {
    for (int i = 0; i < MAXN; i++) euler[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (euler[i] == i) {
            for (int j = i; j < MAXN; j += i) euler[j] = euler[j] / i * (i - 1);
        }
    }
    for(int i = 1; i < MAXN; i++) {
        euler[i] = euler[i] + euler[i-1];
        if(euler[i] > mod) euler[i] -= mod;
    }
}

ll S(ll n){
    if(n < MAXN) return euler[n];
    if(m[n]) return m[n];
    ll ret = (n%mod)*((n+1)%mod)%mod*inv2%mod;
    ll next;
    for(ll i = 2; i <= n; i = next + 1){
        next = n/(n/i);
        ret = ret - ( (next - i + 1) % mod * S(n/i)%mod )%mod;
        ret = (ret + mod)%mod;
    }
    return m[n] = ret;
}

ll solve(ll n){
    ll ret = 0;
    ll next;
    for(ll i = 1; i <= n; i = next +1){
        next = n/(n/i);
        ret = ret + (((next + i)%mod) * ((next -i + 1)%mod) %mod * inv2%mod) * ((2 * S(n/i) - 1) % mod) % mod;
        ret = ret%mod;
    }
    return ret;
}

int main(){
    euler_phi2();
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", solve(n) );
    return 0;
}
