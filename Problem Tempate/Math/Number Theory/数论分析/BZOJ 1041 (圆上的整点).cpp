#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

int check(ll a, double b) {
    if(b == floor(b)) {
        ll bb = (ll)floor(b);
        if(a*a != bb*bb && gcd(a*a, bb*bb) == 1) return 1;
    }
    return 0;
}
ll R, ans;
int main() {
    while(cin >> R) {
        ans = 0;
        for(ll d = 1; d <= sqrt(2*R); d++) {
            if(2*R % d == 0) {
                for(ll a = 1; a <= sqrt(2*R/2/d); a++) {
                    double b = sqrt(2*R/d - a*a);
                    if(check(a, b)) ans++;
                }
                if(d != 2*R/d) {
                    for(ll a = 1; a <= sqrt(d/2); a++) {
                        double b = sqrt(d - a*a);
                        if(check(a, b)) ans++;
                    }
                }
            }
        }
        cout << ans*4 + 4 << endl;
    }
    return 0;
}
