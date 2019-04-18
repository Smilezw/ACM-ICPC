#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007
int add(int x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
int mul(int x,int y)
{
    ll z=1ll*x*y;
    return z-z/mod*mod;
}
#define maxn 700005
int p[maxn],f[maxn],np=0,m=350000,s0[maxn],s1[maxn];  //p素数  f标记
void get_prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        s0[i]=s0[i-1];
        s1[i]=s1[i-1];
        if(!f[i])p[++np]=i,s0[i]++,s1[i]=add(s1[i],i);
        for(int j=1;j<=np&&i*p[j]<=n;j++)
        {
            f[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
    np--;
}
ll val[maxn],n;
int nn,cnt;
void init()
{
    nn=1;
    while((ll)nn*nn<n)nn++;
    cnt=0;
    for(ll i=1;i<=n;i=n/(n/i)+1)val[++cnt]=n/i;
}
int ID(ll x)
{
    if(x>=nn)return n/x;
    return cnt-x+1;
}
int g0[maxn],g1[maxn];
void Get_g(ll n)
{
    for(int i=1;i<=cnt;i++)  //val分块数
    {
        g0[i]=(val[i]-1)%mod;  //1到j-1的前缀贡献sum{f}
        g1[i]=mul((val[i]-1)%mod,(val[i]+2)%mod); //g数组
        if(g1[i]&1)g1[i]+=mod;
        g1[i]/=2;
    }
    for(int j=1;j<=np;j++)  //枚举素数
        for(int i=1;i<=cnt&&(ll)p[j]*p[j]<=val[i];i++)
        {
            int k=ID(val[i]/p[j]);
            g0[i]=add(g0[i],mod-add(g0[k],mod-(j-1)));
            g1[i]=add(g1[i],mod-mul(p[j],add(g1[k],mod-s1[p[j-1]])));
        }
    return ;
}
int S(ll i,int j)
{
    if(i<=1||p[j]>i)return 0;
    int k=ID(i);
    int ans=add(add(g1[k],mod-g0[k]),mod-add(s1[p[j-1]],mod-(j-1)));
    if(j==1)ans=add(ans,2);
    for(int k=j;k<=np&&(ll)p[k]*p[k]<=i;k++)
    {
        ll p1=p[k],p2=(ll)p[k]*p[k];
        for(int e=1;p2<=i;p1=p2,p2*=p[k],e++)
            ans=add(ans,add(mul(p[k]^e,S(i/p1,k+1)),p[k]^(e+1)));
    }
    return ans;
}
int main()
{
    get_prime(m);
    while(~scanf("%lld",&n))
    {
        init();
        Get_g(n);
        printf("%d\n",add(S(n,1),1));
    }
    return 0;
}
