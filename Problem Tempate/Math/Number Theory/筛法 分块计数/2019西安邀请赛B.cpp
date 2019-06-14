//https://nanti.jisuanke.com/t/39269

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e6 + 5;
int mod, n, m, k;

inline int ad(int x,int y){x+=y;return x>=mod? x-mod:x;}
inline int dc(int x,int y){x-=y;return x<0? x+mod:x;}
inline int mul(int x,int y){return 1ll*x*y%mod;}

ll pow_mod(ll a, ll b, ll m) {
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % m;
        a = a * a % m;
        b = b >> 1;
    }
    return ans;
}

int Abs(int x) {
    if(x < 0) return x+mod;
    return x;
}

unordered_map <int, int > T1, T2;

int phi[N], pri[N], cnt = 0;
int d[N];
bool vis[N];

void init() {
    phi[1] = d[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
            d[i] = 2;
        }
        for(int j = 0; j < cnt && pri[j]*i < N; j++) {
            vis[pri[j]*i] = 1;
            if(i % pri[j]) {
                d[i*pri[j]] = d[i]*2;
                phi[pri[j]*i] = phi[pri[j]]*phi[i];
            }
            else {
                phi[i*pri[j]] = phi[i]*pri[j];
                int sum = 1, x = i;
                while(x%pri[j] == 0) x/=pri[j], sum++;
                d[i*pri[j]] = d[i]/sum*(sum+1);
                break;
            }
        }
    }
    for(int i = 1; i < N; i++) {
        //cout << phi[i] << " " << d[i] << endl;
        phi[i] = ad(phi[i], phi[i-1]);
        d[i] = mul(d[i], i);
        d[i] = ad(d[i], d[i-1]);

    }
}

int calc(int l, int r) {
    return 1ll*(l+r)*(r-l+1)/2%mod;
}

int cald(int x) {
    if(x < N) return d[x];
    if(T2[x]) return T2[x];
    int res = 0, next;
    for(int i = 1; i <= x; i = next+1) {
        next = x/(x/i);
        res = ad(res, 1ll*calc(i, next)*calc(1, x/i) %mod);
    }
    res = Abs(res);
    return T2[x] = res;
}

int ouler(int x) {
    if(x < N) return phi[x];
    if(T1[x]) return T1[x];
    int res = calc(1, x), next;
    int ans = 0;
    for(int i = 2; i <= x; i = next+1) {
        next = x/(x/i);
        ans = ad(ans, 1ll*(next-i+1)*ouler(x/i)%mod );
    }
    res = ad(res, -ans);
    res = Abs(res);
    return T1[x] = res;
}

int sum(int x) {
    int res = 0;
    int next;
    for(int i = 1; i <= x; i = next+1) {
        next = x/(x/i);
        int a = 2*ouler(x/i)-1;
        int b = ad(cald(next), -cald(i-1));
        b = Abs(b);
        res = ad(res, 1ll*a*b%mod);
    }
    res = Abs(res);
    return res;
}

int main(){
    cin >> n >> m >> k;
    mod = k-1;
    init();
    int ans = sum(n);
    ans = pow_mod(m, ans, k);
    cout << ans << endl;
    return 0;
}
