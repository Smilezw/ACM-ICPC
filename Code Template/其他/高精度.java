#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
const ll MAX = 1e12;

map <ll, ll> m;

void init() {
	ll now = 1;
	m[0] = 1;
	for(ll i = 1;; i++) {
		now = now*i;
		cout << now << " " << i << endl;
		m[i] = now;
		if(now > MAX) break;
	}
}

int main() {
	ll n, mod;
	cin >> n >> mod;
	init();
	ll now = 1;
	return 0;
}
