//LOJ 6053
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long
const int N = 1e6+5;
const int mod = 1e9+7;
int Sqr,zhi[N],pri[N],sp[N],tot,m,id1[N],id2[N],g[N],h[N];
ll n,w[N];
void Sieve(int n){
    zhi[1]=1;
    for (int i=2;i<=n;++i){
        if (!zhi[i]) pri[++tot]=i,sp[tot]=(sp[tot-1]+i)%mod;
        for (int j=1;i*pri[j]<=n;++j){
            zhi[i*pri[j]]=1;
            if (i%pri[j]==0) break;
        }
    }
}
int S(ll x,int y){
    if (x<=1||pri[y]>x) return 0;
    int k=(x<=Sqr)?id1[x]:id2[n/x];
    int res=(1ll*g[k]-h[k]-sp[y-1]+y-1)%mod;res=(res+mod)%mod;
    if (y==1) res+=2;
    for (int i=y;i<=tot&&1ll*pri[i]*pri[i]<=x;++i){
        ll p1=pri[i],p2=1ll*pri[i]*pri[i];
        for (int e=1;p2<=x;++e,p1=p2,p2*=pri[i])
            (res+=(1ll*S(x/p1,i+1)*(pri[i]^e)%mod+(pri[i]^(e+1)))%mod)%=mod;
    }
    return res;
}
int main(){
    scanf("%lld",&n);
    Sqr=sqrt(n);Sieve(Sqr);
    for (ll i=1,j;i<=n;i=j+1){
        j=n/(n/i);w[++m]=n/i;
        if (w[m]<=Sqr) id1[w[m]]=m;
        else id2[n/w[m]]=m;
        h[m]=(w[m]-1)%mod;
        g[m]=((w[m]+2)%mod)*((w[m]-1)%mod)%mod;
        if (g[m]&1) g[m]+=mod;g[m]/=2;
    }
    for (int j=1;j<=tot;++j)
        for (int i=1;i<=m&&1ll*pri[j]*pri[j]<=w[i];++i){
            int k=(w[i]/pri[j]<=Sqr)?id1[w[i]/pri[j]]:id2[n/(w[i]/pri[j])];
            g[i]=(g[i]-1ll*pri[j]*(g[k]-sp[j-1])%mod)%mod;g[i]=(g[i]+mod)%mod;
            h[i]=(h[i]-h[k]+j-1)%mod;h[i]=(h[i]+mod)%mod;
        }

    printf("%d\n",S(n,1)+1);
    return 0;
}
