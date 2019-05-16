//A第i回合， B第j回合  还需要多少步到第n回合
//当回合前一个人升级
//dp(i, j) =  pi*dp(i+1, j) + qi*dp(j, i) + 1
//dp(j, i) =  pj*dp(j+1, i) + qj*dp(i, j) + 1
//化简可得公式

#include<bits/stdc++.h>
using namespace std;
double dp[400][400],p[400];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=1 ; i<=n ; i++)
        {
            scanf("%lf",&p[i]);
        }
        for(int i=n ; i>=1 ; i--)
        {
            for(int j=n ; j>=1 ; j--)
            {
                dp[i][j]=(p[i]*dp[i+1][j]+(1-p[i])*p[j]*dp[j+1][i]+1-p[i]+1)/(1-(1-p[i])*(1-p[j]));
                dp[j][i]=(p[j]*dp[j+1][i]+(1-p[j])*p[i]*dp[i+1][j]+1-p[j]+1)/(1-(1-p[j])*(1-p[i]));

            }
        }
        printf("%.4f\n",dp[1][1]);
    }

}
