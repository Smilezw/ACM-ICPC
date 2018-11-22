//欧拉函数及莫比乌斯函数前n项和
//注意代码的整洁度  无序map加速
#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
typedef long long ll;
const int MAXN = 1111111;
#define RG register
const int mod = 1e9 + 7;
ll euler[MAXN];
ll mu[MAXN];

unordered_map <ll, ll > m1;
unordered_map <ll, ll > m2;
bool check[MAXN];
ll prime[MAXN];

ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}

void init(){
    for (ll i = 0; i < MAXN; i++) euler[i] = i;
    for (ll i = 2; i < MAXN; i++) {
        if (euler[i] == i) {
            for (ll j = i; j < MAXN; j += i) euler[j] = euler[j] / i * (i - 1);
        }
    }
    for(ll i = 1; i < MAXN; i++) euler[i] += euler[i-1];

    memset(check,false,sizeof(check));
    mu[1] = 1;
     ll tot = 0;
    for(ll i = 2; i <= MAXN; i++){
        if( !check[i] ){
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(ll j = 0; j < tot; j++){
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                break;
            }
            else{
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for(int i = 1; i < MAXN; i++){
        mu[i] += mu[i-1];
    }
}

struct Node {
    ll a, b;
}ans;

inline Node sum( ll n){
    if (n < MAXN) return (Node){euler[n],mu[n]};
    if (m1[n]) return (Node){m1[n], m2[n]};
    ll ans1 = (n*(n+1)) >> 1, ans2 = 1, next;
    for( ll i = 2; i <= n; i = next + 1){
        next = n/(n/i); Node t = sum(n/i);
        ans1 -= (next - i + 1)*t.a;
        ans2 -= (next - i + 1)*t.b;
    }
    m1[n] = ans1, m2[n] = ans2;
    return (Node){ans1, ans2};
}

int main(){
    init();
    int T;
    scanf("%d", &T);
    while(T--){
        ll n;
        n = gi();
        ans = sum(n);
        printf("%lld %lld\n", ans.a, ans.b);
    }
    return 0;
}
