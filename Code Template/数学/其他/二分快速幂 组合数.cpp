#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;

ll mod_pow(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % mod; //如果二进制最低位�