//模数不是质数
PI {n+2, 2*n}/PI {n, 2}

#include<bits/stdc++.h>
using namespace std;
#define maxn 3000005

int n,p,ans=1,tot;
int f[maxn],prime[maxn],pos[maxn];
bool isprime[maxn];

int read(){
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

void change(int x,int val){
    for (;x!=1;) f[prime[pos[x]]]+=val,x/=prime[pos[x]];
}

int power(int a,int k,int p){
    int x=1;
    for (;k;k>>=1,a=1ll*a*a%p) if (k&1) x=1ll*x*a%p;
    return x;
}

int main(){
    n=read(),p=read();memset(isprime,1,sizeof(isprime));
    for (int i=2;i<=2*n;i++){
        if (isprime[i]) prime[++tot]=i,pos[i]=tot;
        for (int j=1;i*prime[j]<=2*n&&j<=tot;j++){
            isprime[i*prime[j]]=0,pos[i*prime[j]]=j;
            if (i%prime[j]==0) break;
        }
    }
    for (int i=2*n;i>n+1;i--) change(i,1);  //
    for (int i=1;i<=n;i++) change(i,-1);
    for (int i=1;i<=tot;i++) if (f[prime[i]]) ans=1ll*ans*power(prime[i],f[prime[i]],p)%p;
    printf("%d\n",ans);
    return 0;
}
