ll eular(ll n) {
    ll ans = n;
    for(ll i = 2;i*i <= n;i++){
        if(n % i == 0){
            ans -= ans/i;
            while(n % i == 0)
              n /= i;
          }
      }
    if(n > 1)ans -= ans/n;
    return ans;
}

const int MAXN = 1e7 + 5;
const int N = 1e6 + 5;

int p[N], o[MAXN];
int cnt = 0;
ll ans, sum[MAXN];
bool vis[MAXN];
int n;
void init() {
    o[1]=1;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) {p[cnt++] = i; o[i] = i-1; }
        for(int j = 0; j < cnt; j++) {
            int x = p[j];
            if(i*x > n) break;
            vis[i*x] = 1;
            if(i % x == 0) {o[i*x] = o[i]*x; break;}
            else o[i*x] = o[i]*o[x];
        }
    }
}
