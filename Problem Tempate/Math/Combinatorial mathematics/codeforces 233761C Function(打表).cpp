//打表找规律
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000 + 5;
int a[5000][5000][2];

int main(){
    int n = 5;
    a[0][0][0] = 1;
    a[0][0][1] = n;
    cout << "f(" << a[0][0][0]  << ", " << a[0][0][1] << " )" << endl;
    for(int i = 1; i < n; i++){
        int t = pow(2, 1.0*i);
        for(int j = 0; j < t; j = j+2){
            a[i][j][0] = a[i-1][j/2][0] + 1;
            a[i][j][1] = a[i-1][j/2][1];
            a[i][j+1][0] = a[i-1][j/2][0];
            a[i][j+1][1] = a[i-1][j/2][1] - 1;
            cout << "f(" << a[i][j][0] << "," << a[i][j][1] << ") ";
            cout << "f(" << a[i][j+1][0]  << "," << a[i][j+1][1]<< ") ";
        }
        cout << endl;
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
const ll mod = 1e9 + 7;

ll pow_mod(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b&1) ret = ret * a %mod;
        a = a*a %mod;
        b = b >> 1;
    }
    return ret;
}

ll f[MAXN];
ll inv[MAXN];
void init(){
    f[0] = inv[0] = 1;
    for(int i = 1; i < MAXN; i++){
        f[i] = 1ll*f[i-1] * i %mod;
        inv[i] = pow_mod(f[i], mod-2);
    }
}

ll cal(ll n, ll i){
    return f[n]*inv[i]%mod*inv[n-i]%mod;
}

ll sum[MAXN];

int main(int argc, char const *argv[]) {
    init();
    int T;
    cin >> T;
    while(T--){
        ll n;
        scanf("%lld", &n);
        sum[0] = 0;
        for(int i = 1; i <= n; i++) {
            ll x;
            scanf("%lld", &x);
            sum[i] = sum[i-1] + x;
            sum[i] %= mod;
        }
        if(n == 1) {
            cout << sum[1] << endl;
            continue;
        }
        ll ans = 0;
        for(ll i = 1; i <= n; i++){
            ans = (ans + cal(n, i-1)*sum[i]%mod - cal(n, i)*sum[i-1]%mod + mod)%mod;
        }
        cout << ans << endl;
    }
    return 0;
}
