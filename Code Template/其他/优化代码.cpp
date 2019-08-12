#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

inline int ad(int x,int y){x+=y;return x>=mod? x-mod:x;}
inline int dc(int x,int y){x-=y;return x<0? x+mod:x;}
inline int mul(int x,int y){return 1ll*x*y%mod;}

//加速

inline void out(int x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}

inline ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}

//快速幂
inline int _power(int a,int b)
{
    static int sum;
    for(sum=1;b;b>>=1,a=(ll)a*a%mod)if(b&1)
        sum=(ll)sum*a%mod;
    return sum;
}

//快速乘
(x*y-(ll)(((long double)x*y)/mod)*mod)%mod
