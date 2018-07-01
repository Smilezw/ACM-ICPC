//贪心思维  代码实现技术。。。。999d 
#include <bits/stdc++.h>
#define lson x << 1
#define rson (x << 1) + 1
#define ld long double
#define pb push_back
#define PI 3.14159265
using namespace std;
typedef long long ll;
const int MAXN = 202020;
int n, m, step;
int vis[MAXN];
int a[MAXN];
set <int> s;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		s.insert(i);
	}
	int goal = n/m;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		int md = a[i] % m;
		set<int>::iterator it = s.lower_bound(md);
		if(it == s.end()) it = s.begin();
		step = *it - md;
		if(md > *it) step = step + m;
		if(++vis[*it] == goal) s.erase(it);
		ans += step;
		a[i] += step;
	}
	cout << ans <<endl;
	for(int i = 1; i <= n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
	