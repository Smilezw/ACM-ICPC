#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 5;

ll dp[N][5];
ll n, x, ans;

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        dp[i][0] = max(0LL, dp[i-1][0] + t);
        dp[i][1] = max(dp[i-1][1] + t*x, dp[i][0]);  //加或不加的最大值
        dp[i][2] = max(dp[i-1][2] + t, dp[i][1]);   //对前缀的最大值
        ans = max(dp[i][2], ans);
    }
    cout << ans << endl;
    return 0;
}
