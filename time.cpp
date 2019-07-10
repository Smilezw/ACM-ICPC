@@ -0,0 +1,106 @@
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;

//nlongm
struct DIJSTRA{

    int tot;  //
    struct Node {
        int d, pos;
    }sta[N];

    void push(Node b) {
    	sta[++tot] = b;
    	for(int i = tot,j = i >> 1; j; i = j,j = i >> 1) {
    		if(sta[j].d > sta[i].d) swap(sta[j], sta[i]);    //
    	}
    }

    void pop() {
    	sta[1] = sta[tot--];//
    	for(int i = 1, j = i << 1; j <= tot; i = j,j = i << 1) {   //
    		if(j+1 <= tot && sta[j+1].d < sta[j].d) j++;
    		if(sta[i].d < sta[j].d) break;
    		else swap(sta[i],sta[j]);

    	}
    }

    int n, m;

    struct Edge {  //
        int u, v, w;
        int next;
    }edge[N];

    int head[N], cal;   //

    void init() {
        for(int i = 0; i <= n; i++) head[i] = -1;
        cal = 0;
    }

    void add(int u, int v, int w) {
        edge[cal].u = u, edge[cal].v = v, edge[cal].w = w;
        edge[cal].next = head[u], head[u] = cal++;
    }

    //
    int dis[MAXN];
    int vis[MAXN];

    void Dijstra(int s) {
        tot = 0;   //
        for(int i = 0; i <= n; i++) {
            dis[i] = INF;
            vis[i] = 0;
        }
        dis[s] = 0;
        push((Node){0,s});
        while(tot) {
            Node t = sta[1];
            pop();
            int u = t.pos;
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = head[u]; i != -1; i = edge[i].next) {  //
                int v = edge[i].v;
                int w = edge[i].w;
                if(dis[v] > dis[u] + w) {   //
                    dis[v] = dis[u] + w;
                    push((Node){dis[v], v});
                }
            }
        }
    }

    void creat() {
        cin >> n >> m;
        init();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;   //
            add(u, v, w);
            add(v, u, w);
        }
    }

    void output() {
        for(int i = 1; i <= n; i++) {
            printf("S to %d dis is : %d\n", i, dis[i]);
        }
    }

}text;

int main() {
    text.creat();
    text.Dijstra(1);
    text.output();
    return 0;
}
