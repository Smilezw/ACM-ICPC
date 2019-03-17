#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e4 + 5;
ll a[N], b[N], c[N];
ll l, r, ans;
int n;

ll cal(ll m) {
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        ll k = min(m, b[i]);
        if(k >= a[i]) ret = ret + (k-a[i])/c[i] + 1;
    }
    return ret;
}

int main() {
    while(cin >> n) {
        l = 0, r = 1LL << 31;
        ans = -1;
        for(int i = 0; i < n; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(cal(mid) % 2 == 1) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if(ans == -1) cout << "DC Qiang is unhappy." << endl;
        else {
            cout << ans << " " << cal(ans) - cal(ans-1) << endl;
        }
    }
    return 0;
}
