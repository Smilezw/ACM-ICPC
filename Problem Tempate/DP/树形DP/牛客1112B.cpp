#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
const ll mod = 1e9 + 7;

struct Edge { ll to, w; ll next;} edge[N];

ll n, m, tot, head[N], a[N], b[N], du[N], dp[N], vis[N];

void init() {
    for(int i = 0; i <= n; i++) head[i] = -1;
    tot = 0;
}

void add(int u, int v) {
    edge[tot].to = v; edge[tot].next = head[u], head[u] = tot++;
}

void dfs(int u) {
	if(vis[u]) return;
	dp[u] = b[u], vis[u] = 1;
	for(int i = head[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		dfs(v);
		dp[u] = (dp[v] + dp[u])%mod;
	}
}

int main() {
    while(scanf("%d%d", &n, &m)!=EOF) {
        init();
		for(int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
			vis[i] = dp[i] = du[i] = 0;
		}
		for(int i = 1; i <= m; i++) {
			int u, v;
			cin >> u >> v;
			add(u, v);
			du[v]++;
		}
		for(int i = 1; i <= n; i++) {
			if(du[i] == 0) dfs(i);
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			ans = (ans+(a[i]*(dp[i]-b[i])%mod))%mod;
		    ans = (ans % mod + mod) % mod;
		}
		cout << ans << endl;
    }
    return 0;
}
