//考虑打或不打的贡献  以及b操作的贡献  对每步走最大贡献即可

#include<bits/stdc++.h>
using namespace std;
#define cur (i%2)
#define las (cur^1)
long long dp[2][102][5600];
int n,T;
long long a[102],b[102],c[102];
long long ans;

int main(){
     scanf("%d",&T);
     while(T){
        T--;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[n%2][1][n]=a[n];
        ans = 0;

        for(int i=n-1;i>=1;i--){
            memset(dp[cur],0,sizeof(dp[cur]));
            for(int j=1;j<=n-i+1;j++){
                for(int k=n+(i+i+j-2)*(j-1)/2;k<=(n+n-j+1)*j/2;k++){
                //  dp[cur][j+1][k+i]=max(dp[cur][j+1][k+i],dp[las][j][k]+a[i]);
                    if(j>=2) dp[cur][j][k]=max(dp[cur][j][k],dp[las][j-1][k-i]+a[i]);   //打或不打
                    if(j!=n-i+1) dp[cur][j][k]=max(dp[cur][j][k],dp[las][j][k]+max(c[i]*j,b[i]*(k-i*j)));  //做b操作的贡献
                    if(i==1){
                        ans=max(ans,dp[cur][j][k]);
                    }
                }
            }

        }
        printf("%lld\n",ans);
     }
    return 0;
}
