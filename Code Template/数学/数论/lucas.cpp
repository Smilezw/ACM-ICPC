 #include<bits/stdc++.h>
#define ui unsigned int
#define ll long long
#define db double
#define ld long double
#define ull unsigned long long
const int MAXP=100000+10;
ll fac[MAXP],inv[MAXP];
template<typename T> inline void read(T &x)
{
    T data=0,w=1;
    char ch=0;
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')data=((T)data<<3)+((T)data<<1)+(ch^'0'),ch=getchar();
    x=data*w;
}
template<typename T> inline void write(T x,char ch='\0')
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
    if(ch!='\0')putchar(ch);
}
template<typename T> inline void chkmin(T &x,T y){x=(y<x?y:x);}
template<typename T> inline void chkmax(T &x,T y){x=(y>x?y:x);}
template<typename T> inline T min(T x,T y){return x<y?x:y;}
template<typename T> inline T max(T x,T y){return x>y?x:y;}
inline ll qexp(ll a,ll b,int n)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%n;
        a=a*a%n;
        b>>=1;
    }
    return res;
}
inline void init(int p)
{
    fac[0]=1;
    for(register int i=1;i<p;++i)fac[i]=1ll*fac[i-1]*i%p;
    inv[p-1]=qexp(fac[p-1],p-2,p);
    for(register int i=p-2;i>=0;--i)inv[i]=1ll*inv[i+1]*(i+1)%p;
}
inline ll C(ll n,ll m,int p)
{
    if(n<m)return 0;
    if(n<p&&m<p)return fac[n]*inv[m]%p*inv[n-m]%p;
    else return C(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
int main()
{
    int T;
    read(T);
    while(T--)
    {
        int n,m,p;
        read(n);read(m);read(p);
        init(p);
        write(C(n+m,m,p),'\n');
    }
    return 0;
}
