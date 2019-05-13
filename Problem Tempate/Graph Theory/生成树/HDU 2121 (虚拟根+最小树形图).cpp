//创建虚拟根  权值为总和加一方便判断
//注意点的编号建新图时会变化

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 20005;
const int M = N*N;
const ll inf = 1e18;
struct Edge{
    ll u, v, w, pos;
}edge[N];

ll pre[N], f[N], vis[N], l[N];  //父，记录环 ，缩点，最小入边
int r;

ll Directed_MST(int root, int n, int m) {
    ll ret = 0;
    ll u, v, cnt;
    while(1) {
        for(int i = 1; i <= n; i++) f[i] = vis[i] = 0, l[i] = inf;
        for(int i = 1; i <= m; i++) {
            u = edge[i].u;
            v = edge[i].v;
            if(l[v] > edge[i].w) {
                pre[v] = u, l[v] = edge[i].w;
                if(u == root) r = edge[i].pos;
            }
        }
        for(int i = 1; i <= n; i++)  //子图入边
            if(l[i] == inf && i != root) return -1;
        l[root] = cnt = 0;
        for(int i = 1; i <= n; i++) {
            ret += l[i];
            if(vis[i]) continue;  //缩点
            for(v = i; !vis[v] && v != root; vis[v] = i, v = pre[v]);
            if(v != root && vis[v] == i) {  //第i个点形成环
                f[v] = ++cnt;
                for(u = pre[v]; u != v; u = pre[u]) f[u] = cnt;
            }
        }
        if(!cnt) break;  //无环
        for(int i = 1; i <= n; i++) if(!f[i]) f[i] = ++cnt;
        n = cnt, cnt = 0, root = f[root];
        for(int i = 1; i <= m; i++) {
            u = edge[i].u, v = edge[i].v;
            if(f[u] != f[v]) {  //外面指向环的边
                edge[++cnt].u = f[u];
                edge[cnt].v = f[v];
                edge[cnt].w = edge[i].w - l[v];   //最后一条边减去即可
                edge[cnt].pos = edge[i].pos;
            }
        }
        m = cnt;  //新图
    }
    return ret;
}
int n, m;

int main() {
    while(cin >> n >> m) {
        ll sum = 0;
        for(int i = 1; i <= m; i++) {
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
            edge[i].u++;
            edge[i].v++;
            sum += edge[i].w;
            edge[i].pos = 0;
        }
        sum++;
        ll root = n + 1;
        for(int i = 1; i <= n; i++) {
            edge[++m].u = root;
            edge[m].v = i;
            edge[m].w = sum;
            edge[m].pos = i;
        }
        ll ans = Directed_MST(root, n+1, m);
        if(ans == -1 || ans >= 2*sum) cout << "impossible" << endl << endl;
        else {
            cout << ans - sum << " " << r-1 << endl << endl;
        }
    }

     return 0;
}
