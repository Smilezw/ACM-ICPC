//问题描述定义：
//定义sigma(n)为n的正因数的数量，求f(n,k)=sum_{i=1}^n (sigma(i^k))
#include<stdio.h>
#include<math.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const int N=200005;

int T,S,pr[N],pc;
ll n,num[N],m,K;
ull g[N];
bool fl[N];
// 给定一个数字X求出其为第几个可以得到有效的g的数字
inline int ID(ll x){return x<=S?x:m-n/x+1;}

ull f(ll n,int i){
    if(n<1||pr[i]>n)return 0;
    ull ret=g[ID(n)]-(i-1)*(K+1);
    while((ll)pr[i]*pr[i]<=n){
        int p=pr[i];
        ull e=K+1,t=n/p;
        while(t>=p)ret+=f(t,i+1)*e+e+K,t/=p,e+=K;
        // ret= sum{sigma(p^es)([n>1]+f(n/p^es,p)+g[n]-g[num[i-1]]}
        // 因为对于函数g(n,m)当n<=m^2,g(n,m)为0
        // 且根据sigma函数的性质，对于质数p，有sigma(p^es)=es*k+1
        // 所以 ret+=(es*k+1)*f(n/p^es,p)+((es+1)k+1)(1<=es&& n/p^es>p)即当前项的sigma(p^e)*f(n/p^e,p)加上下一项的sigma(p^e)
        // 这样的做法避免了e<1也就不必进行特判
        i++;
    }
    return ret;
}
//g[i]即小于i的所有质数的sigma函数求和
//根绝前面的推导，只有当i可以通过[n/m]得到时，其才有用
ull solve(ll n){
    int i,p,x;ull y;
    S=sqrt(n);
    while((ll)S*S<=n)S++;
    while((ll)S*S>n)S--;
    while(m)num[m--]=0;
    for(i=1;i<=S;i++)num[++m]=i;
    for(i=S;i>=1;i--)if(n/i>S)num[++m]=n/i;
    for(i=1;i<=m;i++)g[i]=num[i]-1;
    //此处g[i]为小于等于第i个满足可以通过[n/m]得到的数的素因子的数量
    //故先减去“1”因为1一定不为素因子且无法被后续操作筛去
    x=1;y=0;
    for(p=2;p<=S;p++)if(g[p]!=g[p-1]){
        while(num[x]<(ll)p*p)x++;
        //令g'(i,j)为埃氏筛法筛出前j个素数后，1到j之间剩余数的数量
        //则有g'(i,j)=g'(0,j)-sum_{k=0,k<i}(g'(k,[j/p[k+1]])-g'(k,p[k]))
        //其中p[0]=1,p[i](i>0)为第i个质数
        //则g(j)即为g'(i,j)使得有p[i]<j&&p[i+1]>j
        //其中g'(k,p[k])即为k+1
        //由于以上的递推式仅仅作用到num[x]>=p^2为止，故仅仅将更新到x
        //由于每次都要减去尚未去除当前素数的g以充当g'因此从大往小更新
        for(i=m;i>=x;i--)g[i]-=g[ID(num[i]/p)]-y;
        y++;
    }
    for(i=1;i<=m;i++)g[i]*=K+1;
    return f(n,1)+1;
}

int main(){
    int i,j;
    //素数筛
    for(i=2;i<N;i++)if(!fl[i]){
        pr[++pc]=i;
        for(j=i+i;j<N;j+=i)fl[j]=1;
    }
    for(scanf("%d",&T);T--;){
        scanf("%lld%lld",&n,&K);
        printf("%llu\n",solve(n));
    }
    return 0;
}
