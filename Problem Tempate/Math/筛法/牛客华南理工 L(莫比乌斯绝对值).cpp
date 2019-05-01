#include<cstdio>
#include<map>
using namespace std;
typedef long long LL;
const int N=1e7+50;
int T,mu[N],pri[N/10],tot;
bool vis[N];
LL n,k,Ans,f[N];
map<LL,LL>mp;
void pre(int u){
    mu[1]=1;
    for(int i=2;i<=u;i++){
        if(!vis[i])pri[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&i*pri[j]<=u;j++){
            vis[i*pri[j]]=1;
            mu[i*pri[j]]=mu[i]*mu[pri[j]];
            if(!(i%pri[j])){
                mu[i*pri[j]]=0;
                break;
            }
        }
    }
    for(int i=1;i<=u;i++)f[i]=f[i-1]+mu[i];
}
LL get(LL u){
    if(u<=N-50)return f[u];
    if(mp.find(u)!=mp.end())return mp[u];
    LL res=1;
    for(LL l=2,r;l<=u;l=r+1){
        r=u/(u/l);
        res-=(r-l+1)*get(u/l);
    }
    return mp[u]=res;
}
int main(){
    pre(N-50);
    for(scanf("%d",&T);T;T--){
        scanf("%lld%lld",&n,&k);
        if(k==0){printf("%lld\n",n);continue;}
        if(k&1){printf("%lld\n",get(n));continue;}
        for(LL i=1;i*i<=n;i++)Ans+=mu[i]*(n/i/i);
        printf("%lld\n",Ans);Ans=0;
    }
}
