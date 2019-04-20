//容斥计数
//20190419

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6;
ll f[N];
int main() {
    ll l, r, k;
    while(cin >> l >> r >> k) {
        ll cnt = 0;
        ll kk = 2*k;
        for(ll i = 2; i*i <= kk; i++) {
            if(kk % i == 0) {
                f[cnt++] = i;
                while(kk % i == 0) {
                    kk = kk/i;
                }
            }
        }
        if(kk > 1) f[cnt++] = kk;
        ll ans = 0;
        for(ll j = 0; j < (1 << cnt); j++) {
            ll t = 1;
            ll now = 0;
            ll play = 0;
            for(ll kkk = 0; kkk < cnt; kkk++) {
                if((1 << kkk) & j) {
                    play++;
                    t = t*f[kkk];
                }
            }
            now = max(0LL, r/t - (l+2*k-1)/t  );
            if(play%2 == 1) ans = ans - now;
            else ans = ans + now;
        }
        cout << ans << endl;
    }
    return 0;
 }
