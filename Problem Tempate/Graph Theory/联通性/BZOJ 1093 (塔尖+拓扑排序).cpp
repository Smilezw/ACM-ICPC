#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

inline void out(int x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}

inline ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}

const int M = 1e6 + 5;
const int N = 1e5 + 5;

struct Edge{
	int next, to, w;
}edge[M];

int head[N];
int tot;

void init(int n) {
	for(int i = 0; i <= n; i++) head[i] = -1;
	tot = 0;
}

void add(int u, int v) {
	edge[tot].to = v,
	edge[tot].next = head[u],
	head[u] = tot++;
}

int dfn[N], low[N], csize[N], sta[N], color[N];
bool vis[N];
int dfs_num, col_num, top;

void Tarjan(int x) {
	dfn[x] = ++dfs_num ;
	low[x] = dfs_num ;
	vis[x] = 1 ;//是否在栈中
	sta[++top] = x;
	for(int i = head[x] ; i != -1; i = edge[i].next){
		int temp = edge[i].to ;
		if (!dfn[temp]){
			Tarjan(temp);
			low[x] = min(low[x], low[temp]);
		}
		else if (vis[temp]) low[x] = min(low[x] , dfn[temp]) ;
	}
	int now = 0;
	if (dfn[x]==low[x]) {//构成强连通分量
		++col_num;//染色
		while(now != x) {//清空
			now = sta[top];
			top--;
			csize[col_num]++;
			color[now] = col_num;
			vis[now] = 0;
		}
	}
}

struct Edge2{
	int next, to, w;
}redge[M];

int rhead[N], rtot, d[N];  //考虑入度

void rinit(int n) {
	for(int i = 0; i <= n; i++) rhead[i] = -1;
	rtot = 0;
}

void radd(int u, int v) {
	d[v]++;
	redge[rtot].to = v,
	redge[rtot].next = rhead[u],
	rhead[u] = rtot++;
}

void rebuild(int n) {
	rinit(n);
	for(int i = 1; i <= n; i++) {
		for(int j = head[i]; j != -1; j = edge[j].next) {
			if(color[i] != color[edge[j].to]) radd(color[i], color[edge[j].to]);
		}
	}
}

int g[N], f[N], q[N], fa[N], x;

void dp(int n) {
	//cout << "col " << col_num << endl;
	int head = 0, tail = 0;
	for(int i = 1; i <= col_num; i++) {
		if(!d[i]) q[tail++] = i;
		f[i] = csize[i]; g[i] = 1;
	}
	while(head!=tail) {
		int u = q[head]; head++;
		for(int i = rhead[u]; i != -1; i = redge[i].next) {
			int v = redge[i].to;
			d[v]--;
			if(!d[v]) q[tail++] = v;
			if(fa[v] == u) continue;
			if(f[u] + csize[v] > f[v]) {
				f[v] = f[u] + csize[v];
				g[v] = g[u];
			}
			else if(f[u] + csize[v] == f[v])
				g[v] = (g[v] + g[u])%x;
			fa[v] = u;
		}
	}

}

int main() {
	int n, m;
	n = gi(), m = gi(), x = gi();
	init(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		u = gi(), v = gi();
		add(u, v);
	}
	for(int i = 1; i <= n; i++)
		if(!dfn[i]) Tarjan(i);
	rebuild(n);
	dp(n);
	int ans = 0, mx = 0;
	for(int i = 1; i <= n; i++) {
		if(f[i] > mx) {mx = f[i], ans = g[i];}
		else if(f[i] == mx) ans = (ans + g[i]) %x;
	}
	printf("%d\n%d\n", mx, ans);
	return 0;
}
