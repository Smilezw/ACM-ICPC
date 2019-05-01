//考虑n（最大的数）的位置对答案的影响
//n在i位置，就把1到i-1， i+1到n分成两个不连通部分（前i都会连在n上）
//所以dp[i]=sigma_(j=1~i)( C(i-1,j-1)*(j-1)!*j^2   *   dp[i-j])
//化简  右边为卷积  用cdq求左边对右边的影响  NTT优化

#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
typedef long long LL;
const int MX=444444;
const int P=998244353;
int n;
LL F[MX],invF[MX];
LL quick_power(LL a, LL x, LL mod)
{
    LL ans = 1;
    a %= mod;
    while(x)
    {
        if(x & 1)ans = ans * a % mod;
        x >>= 1;
        a = a * a % mod;
    }
    return ans;
}
void init()
{
    F[0] = 1;
    for(int i = 1; i < MX; i++)  F[i] = ((LL)F[i - 1] * i) % P;
    invF[MX - 1] = quick_power(F[MX - 1],P - 2,P);
    for(int i = MX - 2; i >= 0; i--)  invF[i] = (LL)invF[i + 1] * (i + 1) % P;
}
const int G = 3;
const int NUM = 20;
LL  wn[NUM];
LL  va[MX],vb[MX];
void GetWn()
{
    for(int i = 0; i < NUM; i++)
    {
        int t = 1 << i;
        wn[i] = quick_power(G, (P - 1) / t, P);
    }
}
void Rader(LL F[], int len)
{
    int j = len >> 1;
    for(int i = 1; i < len - 1; i++)
    {
        if(i < j) swap(F[i], F[j]);
        int k = len >> 1;
        while(j >= k)j -= k,k >>= 1;
        if(j < k) j += k;
    }
}
void NTT(LL F[], int len, int t)
{
    Rader(F, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1)
    {
        id++;
        for(int j = 0; j < len; j += h)
        {
            LL E = 1;
            for(int k = j; k < j + h / 2; k++)
            {
                LL u = F[k];
                LL v = E * F[k + h / 2] % P;
                F[k] = (u + v) % P;
                F[k + h / 2] = (u - v + P) % P;
                E = E * wn[id] % P;
            }
        }
    }
    if(t == -1)
    {
        for(int i = 1; i < len / 2; i++)swap(F[i], F[len - i]);
        LL inv = quick_power(len, P - 2, P);
        for(int i = 0; i < len; i++)F[i] = F[i] * inv % P;
    }
}
void Conv(LL a[], LL b[], int len)
{
    NTT(a, len, 1);
    NTT(b, len, 1);
    for(int i = 0; i < len; i++)a[i] = a[i] * b[i] % P;
    NTT(a, len, -1);
}
int dp[MX];
void cdq(int l,int r)  //看做左区间对右区间的影响 由NTT加速
{                       //这个卷积有点玄学。。。
    if(l==r)
    {
        dp[l]=(LL)F[l-1]*(dp[l]+(LL)l*l%P)%P;
        return ;
    }
    int mid=(l+r)>>1;
    cdq(l,mid);
    int len=1;
    while(len<mid-2*l+r-1)len<<=1;
    for(int i=l; i<=mid; i++)va[i-l]=(LL)dp[i]*invF[i]%P;
    for(int i=mid-l+1; i<len; i++)va[i]=0;
    for(int i=1; i<=r-l; i++)vb[i-1]=(LL)i*i%P;
    for(int i=r-l; i<len; i++)vb[i]=0;
    Conv(va,vb,len);
    for(int i=mid+1; i<=r; i++)dp[i]=(dp[i]+va[i-l-1])%P;
    cdq(mid+1,r);
}
void pre()
{
    for(int i=1; i<=100000; i++)dp[i]=0;
    cdq(1,100000);
}
int main()
{
    GetWn();
    init();
    pre();
    while(cin>>n)cout<<dp[n]<<endl;
    return 0;
}
