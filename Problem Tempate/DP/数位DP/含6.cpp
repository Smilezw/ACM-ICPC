//¾ÍÁ½ÖÖ×´Ì¬

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[20];
int cnt;
ll dp[20][2];

ll dfs(int pos, bool s6, int j, int limit) {
    if(pos == 0) return s6;
    if(!limit && dp[pos][s6] != -1 ) return dp[pos][s6];
    int up = limit ? num[pos] : 9;
    ll tmp = 0;
    for(int i = 0; i <= up; i++) {
        tmp = tmp + dfs(pos-1, i == 6 || s6, i, i == up && limit);
    }
    if(!limit) dp[pos][s6] = tmp;
    return tmp;
}

ll cal(ll x) {
    cnt = 0;
    while(x) {
        num[++cnt] = x%10;
        x = x /10;
    }
    return dfs(cnt, 0, 0, 1);
}

int main() {
	ll l, r;
    memset(dp, -1, sizeof(dp));
    while(cin >> l >> r) {
        cout << cal(r) - cal(l-1) << endl;
    }
	return 0;
}
