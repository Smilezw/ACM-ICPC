//现有NN个数a1,a2,⋯,aN。
//对于每一个ak，求有多少个有序二元组(i,j)满足(ai×aj) mod P=ak
//其中P为一给定质数。

//点分治时用FFT优化

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6 + 5;
const double PI = acos(-1.0);

typedef complex<double> cpx;

ll qpow(ll n,ll m,ll p){
    ll ans=1;
    n%=p;
    for(;m;m>>=1,n=n*n%p)
        if(m&1)ans=ans*n%p;
    return ans;
}

int pri[MAX],tot;

ll getRoot(ll p) {//求质数p的最小原根
    tot=0;
    ll n=p-1,sq=sqrt(p+0.5);
    for(int i=2;i<=sq;i++)if(n%i==0) {
        pri[tot++]=i;
        while(n%i==0)n/=i;
    }
    if(n>1)pri[tot++]=n;
    for(int g=2;g<=p-1;g++) {//试探每一个g是否原根
        int flag=1;
        for(int i=0;i<tot;i++)if(qpow(g,(p-1)/pri[i],p)==1) {
            flag=0; break;
        }
        if(flag)return g;
    }
    return -1; //没有原根
}

int pos[MAX]; //DFT变换位置。结果一定是两者互换，不存在三者互换

void initpos(int n) {
    int k=log2(n+0.5)-1;
    for(int i=0;i<n;i++) //位置变换
        pos[i]=(pos[i>>1]>>1)|(i&1)<<k;
}

void FFT(cpx a[],int n,int tag) {//多项式项数n,请确保n是2的次幂
    initpos(n); //一定要预处理pos

    for(int i=0;i<n;i++)if(i<pos[i])
        swap(a[i],a[pos[i]]);
    for(int k=2;k<=n;k<<=1) {//枚举分治合并过程块长度
        int m=k>>1; //半个块的大小
        cpx wn(cos(tag*2*PI/k),sin(tag*2*PI/k)); //单位k次复根
        for(int i=0;i<=n;i+=k) //枚举分治块
        {
            cpx now(1,0); //单位复根的0次幂
            for(int j=0;j<m;j++) //分治块内的每一项
            {
                cpx temp=now*a[i+j+m];
                a[i+j+m]=a[i+j]-temp;
                a[i+j]=a[i+j]+temp;
                now=now*wn;  //旋转
            }
        }
    }
    if(tag==-1)
        for(int i=0;i<n;i++)a[i]=a[i]/cpx(n,0);
}

void solve(cpx a[],cpx b[],int n) //n项式相乘，FFT solving, ansult to a
{  //请确保n是2的次幂
    FFT(a,n,1); //DFT
    FFT(b,n,1);
    for(int i=0;i<n;i++)
        a[i]=a[i]*b[i]; //点值多项式相乘
    FFT(a,n,-1);//IDFT
}

cpx a[MAX];
int xp[MAX];
ll ans[MAX],arr[MAX];

int main() {
    int n,p;
    scanf("%d%d",&n,&p);
    int g=getRoot(p);
    for(int i=0,x=1;i<p-1;i++) {
        xp[x]=i;
        x=(ll)x*g%p;
    }
    int len=p+p-2;
    for(;(len&-len)!=len;len+=len&-len);
    ll t=0;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&arr[i]);
        if(arr[i]%p==0)t++;
        else a[xp[arr[i]%p]]+=cpx(1,0);
    }
    FFT(a,len,1);
    for(int i=0;i<len;i++)a[i]=a[i]*a[i];
    FFT(a,len,-1);
    for(int i=0,x=1;i<len;i++) {
        ans[x]+=ll(a[i].real()+0.5);
        x=(ll)x*g%p;
    }
    for(int i=1;i<=n;i++) {
        if(arr[i]>=p)puts("0");
        else if(arr[i]==0)printf("%lld\n",t*t+2*t*(n-t));
        else printf("%lld\n",ans[arr[i]]);
    }
    return 0;
}
