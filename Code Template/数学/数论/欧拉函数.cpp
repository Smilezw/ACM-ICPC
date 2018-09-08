/*欧拉函数
欧拉函数的值等于不超过m并且和m互素的数的个数
如果x和m互素 x^(elur(m)) = 1(mod m)
求欧拉函数值  复杂度O(sqrt(n))*/
ll eular(ll n) {
    ll ans = n;
    for(int i = 2;i*i <= n;i++){
        if(n % i == 0){
            ans -= ans/i;
            while(n % i == 0)
              n /= i;
          }
      }
    if(n > 1)ans -= ans/n;
    return ans;
}

//O(MAXN)时间筛出欧拉函数值的表
int euler[MAXN];
void euler_phi2() {
    for (int i = 0; i < MAXN; i++) euler[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (euler[i] == i) {
            for (int j = i; j < MAXN; j += i) euler[j] = euler[j] / i * (i - 1);
        }
    }
}
