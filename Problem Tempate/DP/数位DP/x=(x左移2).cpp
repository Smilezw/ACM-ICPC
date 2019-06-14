#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[70][2][2];
int a[70],cnt;
ll dfs(int pos,int la,int lla,bool limit)
{
    if(pos==0) return 1;
    if(dp[pos][la][lla]!=-1&&!limit) return dp[pos][la][lla];
    int up=limit?a[pos]:1;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {
        if(i&&lla) continue;
        ans+=dfs(pos-1,i,la,i==up&&limit);   //看当前和下两位即可
    }
    if(!limit) dp[pos][la][lla]=ans;
    return ans;
}
ll calc(ll x)
{
    cnt=0;
    while(x)
        a[++cnt]=(x&1),x>>=1;
    return dfs(cnt,0,0,true);
}
int main()
{
    memset(dp,-1,sizeof dp);
    int T;
    ll l,r;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",calc(r)-calc(l-1));
    }
    return 0;
}
