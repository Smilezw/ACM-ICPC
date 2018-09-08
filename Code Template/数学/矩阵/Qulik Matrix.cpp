#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000009;
ll ans, n;
//二分快速幂
ll mod_pow(ll x, ll y, ll mod) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % mod; //如果二进制最低位为1、则乘上x^(2^i)
        x = x * x % mod;  // 将x平方
        y >>= 1;
    }
    return res%mod;
}
//矩阵快速幂
//队res进行操作
const int mod = 10000007;
const int MAXN = 15;
ll res[MAXN][MAXN];
int N;

void Matmul(ll X[MAXN][MAXN], ll Y[MAXN][MAXN], ll mod)
{
    ll t[MAXN][MAXN] = {0};
    for(int i = 0; i < N;i++)
        for(int k = 0; k < N;k++)
            if(X[i][k])
                for(int j = 0;j < N;j++)
                    t[i][j] = (( t[i][j] + X[i][k] * Y[k][j] % mod) + mod) % mod;
    for(int i = 0; i < N; i++)
        for(int j = 0;j < N; j++)
            X[i][j] = t[i][j];
}

void Matrix(ll X[MAXN][MAXN], ll n)
{
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            res[i][j] = (i==j);
        }
    }
    //对角线为1
    while(n){
        if(n&1) Matmul(res,X);
        Matmul(X,X);
        n>>=1;
    }
}
