//Codeforces Gym 100548F Color（容斥加组合数）

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAXN=1e6+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
ll n, m, k;
inline ll mod_pow(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % mod; //如果二进制最低位为1、则乘上x^(2^i)
        x = x * x % mod;  // 将x平方
        y >>= 1;
    }
    return res % mod;
}

ll inv[MAXN];
inline void init_inv(){
    for(int i = 1; i <= MAXN; i++)
        inv[i] = mod_pow(i, mod - 2);
}

ll cal[MAXN];   //m中取i个
inline void init(ll m){   //c(i, m)
    cal[0] = 1;
    for(int i = 1; i <= k; i++){   //c53 c52  ????   (m-i+1)/i  这个可还行。。。
         cal[i] = ((cal[i - 1] * (m - i + 1) % mod) * inv[i] % mod) % mod;
    }
}

int main(){
    ios::sync_with_stdio(false);
    init_inv();
    int t, cas = 0;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        init(m);
        ll demo = cal[k];
        init(k);
        ll ans = 0;
        int play = 1;
        for(int i = k; i >= 1; i--){    //  ++++++ (-1)^2*c(k, i)*i*(i-1)^(n-1)
            ans = (ans % mod + (play * i * mod_pow(i - 1, n - 1)) % mod * cal[i] % mod + mod) % mod;
            play = -play;
        }
        ans = (demo%mod*ans%mod) % mod;
        cout << "Case #" << ++cas << ": " << ans << endl;
    }
}
