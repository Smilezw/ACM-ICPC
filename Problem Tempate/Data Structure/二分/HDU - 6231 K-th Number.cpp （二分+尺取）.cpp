#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug cerr << "*" << endl;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define pre(i, a, b) for(int i = a; i >= b; i--)
#define met(a, b) memset(a, b, sizeof(a))
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
ll T, n, k, m, a[maxn], b[maxn];

bool check(ll mid) {
    ll l = 1, r = 0, num = 0;
    ll ans = 0;
    while(r <= n) {
        if(num < k) {
            if(a[r + 1] >= mid) num++;
            r++;
        } else {
            if(num == k) ans += (n - r + 1);
            if(a[l] >= mid) num--;
            l++;
            if(ans >= m) return true;
        }
    }
    return false;
}

int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld%lld%lld", &n, &k, &m);
        rep(i, 1, n) {
            scanf("%lld", &a[i]);
        }
        memcpy(b, a, sizeof(a));
        ll l = 1, r = n, ans;
        sort(b + 1, b + 1 + n);
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(check(b[mid])) {
                ans = b[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
