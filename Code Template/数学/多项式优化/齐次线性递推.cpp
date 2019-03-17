#include<bits/stdc++.h>
#define gc getchar()
#define si isdigit(ch)
#define RI register
using namespace std;

const int N=4002,mod=1e9+7;
int ans,n,K,a[N],b[N],c[N],e[N],re[N];

char ch;
inline void rd(int &x) {
    ch=gc;x=0;int f=0;
    for(;!si;ch=gc) if(ch=='-') f=1;
    for(;si;ch=gc) x=x*10+(ch^48);
    if(f) x=mod-x;
}

inline int ad(int x,int y){x+=y;return x>=mod? x-mod:x;}
inline int dc(int x,int y){x-=y;return x<0? x+mod:x;}
inline int mul(int x,int y){return 1ll*x*y%mod;}

inline void Mul(int *f,int *g,int n) {
    RI int i,j;
    memset(re,0,sizeof(int)*(n+1));
    for(i=0;i<=K;++i)
     for(j=0;j<=K;++j)
      re[i+j]=ad(re[i+j],mul(f[i],g[j]));
    for(i=n;i>=K;--i){
        if(!re[i]) continue;
        for(j=0;j<K;++j)
         re[i-K+j]=ad(re[i-K+j],mul(re[i],a[K-j]));
        re[i]=0;
    }
    for(i=0;i<=K;++i) g[i]=re[i];
}

int main() {
    RI int i,j,M;
    rd(n);rd(K);M=K<<1;
    for(i=1;i<=K;++i) rd(a[i]); //系数
    for(i=1;i<=K;++i) rd(b[i]); //a[1]-a[n]
    if(n<K){printf("%d\n",b[n+1]);return 0;}
    e[0]=c[1]=1;
    for(;n;n>>=1,Mul(c,c,M))
     if(n&1) Mul(c,e,M);
    for(i=0;i<K;++i) ans=ad(ans,mul(e[i],b[i+1]));
    printf("%d\n",ans);
}
