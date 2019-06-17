#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define For(i,a,b) for(i=(a);i<=(b);++i)
#define Forward(i,a,b) for(i=(a);i>=(b);--i)
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
using namespace std;
template<typename T>inline void read(T &x){
    T s=0,f=1;char k=getchar();
    while(!isdigit(k)&&k^'-')k=getchar();
    if(!isdigit(k)){f=-1;k=getchar();}
    while(isdigit(k)){s=s*10+(k^48);k=getchar();}
    x=s*f;
}
void file(void){
    freopen("polynomial.in","r",stdin);
    freopen("polynomial.out","w",stdout);
}
const int MAXN=1<<22;

typedef long long ll;

namespace polynomial
{
    static int mod=998244353,gen=3,g[21],rev[MAXN],Len;

    inline int ad(int a,int b){return (a+=b)>=mod?a-mod:a;}

    inline int power(int a,int b)
    {
        static int sum;
        for(sum=1;b;b>>=1,a=(ll)a*a%mod)if(b&1)
            sum=(ll)sum*a%mod;
        return sum;
    }

    inline void predone()
    {
        static int i,j;
        for(i=1,j=2;i<=20;++i,j<<=1)g[i]=power(gen,(mod-1)/j);
    }

    inline void calrev(int Len)  
    {
        static int Logl;Logl=(int)floor(log(Len)/log(2)+0.3)-1;
        Rep(i,1,Len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<Logl);
    }

    inline void NTT(int X[],int typ)
    {
        Rep(i,1,Len-1)if(i<rev[i])swap(X[i],X[rev[i]]);
        static int i,j,k,kk,w,t,wn,r;
        for(k=2,kk=1,r=1;k<=Len;k<<=1,kk<<=1,++r)
        {
            wn=g[r];
            for(i=0;i<Len;i+=k)for(j=0,w=1;j<kk;++j,w=(ll)w*wn%mod)
            {
                t=(ll)w*X[i+j+kk]%mod;
                X[i+j+kk]=ad(X[i+j],mod-t);
                X[i+j]=ad(X[i+j],t);
            }
        }
        if(typ==-1)
        {
            reverse(X+1,X+Len);
            static int invn;invn=power(Len,mod-2);
            Rep(i,0,Len-1)X[i]=(ll)X[i]*invn%mod;
        }
    }

    static int x[MAXN],y[MAXN];
    inline void mul(int a[],int b[])
    {
        memset(x,0,sizeof x);memset(y,0,sizeof y);
        Rep(i,0,(Len>>1)-1)x[i]=a[i],y[i]=b[i];
        NTT(x,1);NTT(y,1);
        Rep(i,0,Len-1)x[i]=(ll)x[i]*y[i]%mod;
        NTT(x,-1);
        Rep(i,0,Len-1)a[i]=x[i];
    }

    static int c[2][MAXN];

    inline void Inv(int a[],int n)  //求逆
    {
        static int t;t=0;
        memset(c,0,sizeof c);
        c[0][0]=power(a[0],mod-2);
        Len=2;
        while(Len<=(n<<1))
        {
            Len<<=1;calrev(Len);t^=1;
            memset(c[t],0,sizeof c[t]);
            Rep(i,0,Len)c[t][i]=ad(c[t^1][i],c[t^1][i]);
            mul(c[t^1],c[t^1]);mul(c[t^1],a);
            Rep(i,0,Len)c[t][i]=ad(c[t][i],mod-c[t^1][i]);
        }
        Rep(i,0,Len-1)a[i]=c[t][i];
    }

    static int sq[2][MAXN];

    inline void Sqrt(int *a,int n)   //根
    {
        static int t,z;t=0;
        memset(sq,0,sizeof sq);
        sq[0][0]=sqrt(a[0]);
        Len=z=2;
        while(z<=(n<<1))
        {
            z<<=1;t^=1;
            memset(sq[t],0,sizeof sq[t]);
            Rep(i,0,z)sq[t][i]=sq[t^1][i],sq[t^1][i]=ad(sq[t^1][i],sq[t^1][i]);
            calrev(Len=z);
            mul(sq[t],sq[t]);
            Rep(i,0,z)sq[t][i]=ad(sq[t][i],a[i]);
            Inv(sq[t^1],z>>1);
            calrev(Len=z);
            mul(sq[t],sq[t^1]);
        }
        Rep(i,0,n)a[i]=sq[t][i];
    }

    static int X[MAXN],Y[MAXN];

    inline void Div(int *a,int n,int *b,int m)  //除法
    {
        memcpy(X,a,sizeof X);memcpy(Y,b,sizeof Y);
        reverse(b,b+m+1);reverse(X,X+n+1);
        Rep(i,n-m+1,n)X[i]=0;
        Inv(b,n-m+1);
        while(Len<=(n<<2))Len<<=1;
        calrev(Len);
        mul(X,b);reverse(X,X+n-m+1);
        Rep(i,n-m+1,n)X[i]=0;
        mul(Y,X);
        Rep(i,0,m-1)b[i]=ad(a[i],mod-Y[i]);
        memcpy(a,X,sizeof X);
    }

    inline void Direv(int *a,int n)  //求导
    {Rep(i,1,n)a[i-1]=(ll)a[i]*i%mod;a[n]=0;}

    inline void Inter(int *a,int n)  //积分
    {Repe(i,n,1)a[i]=(ll)a[i-1]*power(i,mod-2)%mod;a[0]=0;}

    inline void Ln(int *a,int n)   //ln
    {
        memcpy(X,a,sizeof X);
        Inv(X,n);Direv(a,n);
        while(Len<=(n<<2))Len<<=1;
        calrev(Len);
        mul(a,X);
        Inter(a,n);
        Rep(i,n+1,Len)a[i]=0;
    }

    static int T[MAXN],K[MAXN];

    inline void Exp(int *a,int n)  //e次
    {
        static int t,z;t=0;
        memset(K,0,sizeof K);K[0]=1;
        Len=z=2;
        while(z<=(n<<1))
        {
            z<<=1;t^=1;
            Rep(i,0,(z>>1)-1)T[i]=K[i];
            Ln(T,(z>>1)-1);
            Rep(i,0,(z>>1)-1)T[i]=ad(a[i]+(i==0),mod-T[i]);
            calrev(Len=z);
            mul(K,T);
            Rep(i,z,z<<1)K[i]=T[i]=0;
        }
        Rep(i,0,n)a[i]=K[i];
    }
}
using namespace polynomial;

static int n,F[MAXN];

int main(){
    predone();  //初始化
    read(n);
    Rep(i,0,n-1)read(F[i]);
    Len=2;
    while(Len<=n<<1)Len<<=1;
    Ln(F,n);
    Rep(i,0,n-1)printf("%d ",F[i]);
    return 0;
}
