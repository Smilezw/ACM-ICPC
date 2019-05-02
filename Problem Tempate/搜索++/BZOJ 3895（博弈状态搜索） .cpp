#include <bits/stdc++.h>
using namespace std;

int dp[55][50005];

int sg(int i, int j) {  //1个的堆  其他的堆石子总数+堆数+1
    if(~dp[i][j]) return dp[i][j];
    if(j == 1) return dp[i][j] = sg(i+1, 0);
    dp[i][j] = 0;
    if(i && !sg(i-1, j))  //a中取一个能到失败点
        dp[i][j] = 1;
    else if(j && !sg(i, j-1))   //b中取一个
        dp[i][j] = 1;
    else if(i && j && !sg(i-1, j+1)) //a合并到b
        dp[i][j] = 1;
    else if(i > 1 && ( (j == 0 && !sg(i-2, j+2) )  || (j && !sg(i-2, j+3)) ) )  //俩个a合并
        dp[i][j] = 1;
    return dp[i][j];
}

int main() {
    int T;
    cin >> T;
    memset(dp, -1, sizeof(dp));
    while(T--) {
        int n;
        scanf("%d", &n);
        int a = 0, b = 0;
        for(int i = 0 ; i < n; i++) {
            int v;
            scanf("%d", &v);
            if(v == 1) a++;
            else b = b + v + 1;
        }
        if(b) b--;
        int ans = sg(a, b);
        if(ans) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
