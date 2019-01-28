#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 40;
typedef long long LL;

LL _pow[MAXN + 5];
LL ans, n, t;
LL gcd(LL a, LL b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void init(){
    _pow[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        _pow[i] = _pow[i-1] * t;
    }
}

int main(){
    while(cin >> t >> n){
        if(n == 0 && t == 0) break;
        if(n == 0) {
            cout << 0 << endl;
            continue;
        }
        init();
        LL a = 0;
        for(int i = 0; i < n; i++){
            a += _pow[gcd(i, n)];
        }
        LL b = 0;
        if(n % 2 == 1) b = n* _pow[(n+1) / 2];
        else b = n/2 * (_pow[n/2 + 1] + _pow[n/2]);
        ans = (a + b)/2/n;
        cout << ans << endl;
    }
	return 0;
}
