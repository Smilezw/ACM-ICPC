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
const int maxn = 50;
const int mod = 1e9 + 7;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat& A, mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k]) // 对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}
mat Pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1) B = mul(B, A);
    return B;
}
