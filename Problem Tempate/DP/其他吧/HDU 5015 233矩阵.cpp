//hdu 5015

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int mod = 10000007;
const int MAXN = 15;
LL res[MAXN][MAXN];
int N;

void Matmul(LL X[MAXN][MAXN],LL Y[MAXN][MAXN])
{
    LL t[MAXN][MAXN] = {0};
    for(int i = 0; i < N;i++)
        for(int k = 0; k < N;k++)
            if(X[i][k])
                for(int j = 0;j < N;j++)
                    t[i][j] = (( t[i][j] + X[i][k] * Y[k][j] % mod) + mod) % mod;
    for(int i = 0; i < N; i++)
        for(int j = 0;j < N; j++)
            X[i][j] = t[i][j];
}

void Matrix(LL X[MAXN][MAXN],LL n)
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

int main()
{
    LL n;
    LL m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        LL a[MAXN];
        LL A[MAXN][MAXN];
        memset(A,0,sizeof(A));
        N = n+2;
        for(int i = 1;i <= n;i++)
            scanf("%lld",&a[i]);
        a[0]=23; a[n+1]=3;
        for(int i = 0;i < N;i++){
            if(i!=N-1) A[i][0] = 10;
            for(int j = 1; j <= i; j++){
                if(i != N-1) A[i][j]=1;
            }
            A[i][N-1]=1;
        }
        Matrix(A,m);
        LL ans = 0;
        for(int j = 0;j < N;j++){
            ans = ( ans + a[j]*res[N-2][j] % mod) % mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
