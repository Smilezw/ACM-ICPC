ll pow_mod(ll a, ll b){//aµÄb´Î·½
    if(b == 0) return 1%MOD;
    ll ret = pow_mod(a, b/2);
    ret = ret * ret % MOD;
    if(b % 2 == 1) ret = ret * a % MOD;
    return ret;
}
