// light oj 1078 - Integer Divisibility 同模定理

#include <bits/stdc++.h>
using namespace std;
#define lson x << 1
#define rson (x << 1) + 1
typedef long long ll;
const int MAXN = 1e5+5;  
const int INF = 0x3f3f3f3f;  
ll n, m;
ll cnt;

int main()  
{  
    int T; scanf("%d", &T);
	int t = 0;
	while(T--){
		scanf("%lld%lld", &n, &m);
		cnt = 1;
		ll k = m % n;
		while(k){
			cnt ++;
			k = (k * 10 + m) % n;
		}
		cout <<"Case " << ++t <<": " << cnt << endl;
	}
	//system("pause");
	return 0;
}  