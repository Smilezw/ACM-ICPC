#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, p, a[3000010];

int main() {
	cin >> n >> p;
	for(int i = 2; i <= n; i++) a[i] = -1ll*(p/i)*a[p%i]%p;
	for(int i = 1; i <= n; i++) {
		if(a[i] < 0) a[i] += p;
		cout << a[i] << endl;
	}
	return 0;
}
