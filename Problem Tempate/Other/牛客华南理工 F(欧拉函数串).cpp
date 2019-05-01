//素数分布  在1e9内较密集

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 0x3f3f3f3f;
const int N = 305;
int n = 300;
ll a[N];

ll getphi(ll a){
    ll tmp = a;
    for(ll j=2;j*j<=a;j++){
        if(a%j==0) {
            tmp=tmp/j*(j-1);
            while(a%j==0) a/=j;
        }
    }if(a>1) tmp=tmp/a*(a-1);
    return tmp;
}

int check(int pos, ll val) {
    ll v = val + 1;
    for(ll i = 0; i < n ; i++) {
        ll t = v + i - pos;
        if(getphi(t) != a[i]) return 0;
    }
    return 1;
}

int main(){
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = inf;
    for(int i = 0; i < n; i++) {
        ll l = a[i];
        int pos = i;
        if(l+300-i > 1e9) continue;
        if(i == 0 && a[i] == 1) {
            if(check(0, 0)) {
                ans = 1;
                break;
            }
        }
        if(check(pos, l)) {
            ans = min(ans, l+1-i);
        }
    }
    if(ans == inf) cout << "yang12138 laji" << endl;
    else cout << ans << endl;
    return 0;
}
