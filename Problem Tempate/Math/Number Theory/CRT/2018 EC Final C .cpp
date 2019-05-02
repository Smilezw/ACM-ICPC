#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll up = 1e9;
const int N = 5e4 + 5;

int prime[N];
bool notprime[N];
void getprime()
{
    for (int i = 2; i < N; i++) {
        if(!notprime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < N; j++)
        {
            notprime[i * prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}

ll exgcd(ll a,ll b,ll &x, ll &y) {
    ll g = a;
    if(b==0) x=1,y=0; else g=exgcd(b,a%b,y,x),y-=x*(a/b);
    return g;
}

ll inv(ll a,ll m) {
    ll x, y;
    ll d = exgcd(a, m, x, y);
    return (d == 1) ? (x % m + m) % m : -1;
}

int ti[6], m[6] = {4, 9, 25, 49, 121, 169}, a[6];
int M;

void CRT() {
    M = 1;
    for(int i = 0; i < 6; i ++) M = M*m[i];
    for(int i = 0; i < 6; i++) {
        int Mi = M/m[i];
        ti[i] = 1LL*inv(Mi, m[i])*Mi%M;
    }
}

string s,t;

int check(int v, int r) {
    while(v < 200) {
        if(s[v] == '1') return 0;
        v += r;
    }
    return 1;
}

int mu(int x) {
    for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= x; i++) {
        if(x%(prime[i]*prime[i]) == 0) return 0;
        if(x%prime[i] == 0) x/=prime[i];
    }
    return 1;
}

int ok(int x) {
    for (int i = 0; i < 200; i++)
       if(mu(i+x) != s[i]-'0') return 0;
   return 1;
}

int ans = inf;

void dfs(int x) {
    if(x == 6) {
        int v = 0;
        for(int i = 0; i < 6; i++) v = (v + 1LL*ti[i]*a[i]%M)%M;
        if(v == 0) v = M;
        while(v+199 <= up && v < ans) {
            if(ok(v)) ans = v;
            v = v + M;
        }
        return;
    }
    for(int i = 0; i < m[x]; i++) {
        if(check(i, m[x])) {
            a[x] = ( m[x] - i );
            dfs(x+1);
        }
    }
}

int main(){
    getprime();
    CRT();
    for(int i = 0; i < 10; i++) {cin >> t, s = s + t;}
    int num = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '0') num++;
    if(num < 65 || num > 95)
        cout << -1 << endl;
    else {
        dfs(0);
        if(ans == inf)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
