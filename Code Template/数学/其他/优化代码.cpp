#pragma GCC optimize(3,"Ofast","inline")
inline int ad(int x,int y){x+=y;return x>=mod? x-mod:x;}
inline int dc(int x,int y){x-=y;return x<0? x+mod:x;}
inline int mul(int x,int y){return 1ll*x*y%mod;}

//加速
template <class T>
inline void scan_d(T &ret) {
	char c; ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}

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
