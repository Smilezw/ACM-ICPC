#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef pair <ll, ll> pr;

//X = sqrt(X)
//(a + bx)(c + dx) = (ac + bdX) + (bc + ad)x
//(a - bx)(c - dx) = (ac + bdX) - (bc + ad)x

pr mul(pr a, pr b, ll mod, ll B){
    return mp( (a.fi*b.fi%mod + a.se*b.se%mod*B)%mod , (a.fi*b.se%mod + a.se*b.fi%mod)%mod );
}

pr solve(ll a, ll b, ll B, ll n, ll mod){
    pr ans = mp(a, b);
    pr x = mp(a, b);
    n--;
    while(n){
        if(n & 1) ans = mul(ans, x, mod, B);
        x = mul(x, x, mod, B);
        n = n >> 1;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        ll  A, B, N, p;
        scanf("%lld %lld %lld %lld", &A, &B, &N, &p);
        ll ans = solve(A, 1, B, N, p).se;
        ans = (ans + p)%p;
        for(int i = 2; i*i <= B; i++){
            if(B % (i*i) == 0 )  {
                while(B%(i*i) == 0){
                    B = B/i/i;
                    ans = ans*i%p;
                }
            }
        }
        printf("1 %lld %lld\n", ans, B);
    }
    return 0;
}
