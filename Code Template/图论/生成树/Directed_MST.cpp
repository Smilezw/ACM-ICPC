#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;
const int M = N*N;
const int inf = 1 << 30;
struct Edge{
    int u, v, w;
}edge[M];

int pre[N], f[N], vis[N], l[N];  //父，记录环 ，缩点，最小入边

int Directed_MST(int root, int n, int m) {
    int ret = 0;
    int u, v, cnt;
    while(1) {
        for(int i = 1; i <= n; i++) f[i] = vis[i] = 0, l[i] = inf;
        for(int i = 1; i <= m; i++) {
            u = edge[i].u;
            v = edge[i].v;
            if(l[v] > edge[i].w) pre[v] = u, l[v] = edge[i].w;
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
            }
        }
        m = cnt;  //新图
    }
    return ret;
}
