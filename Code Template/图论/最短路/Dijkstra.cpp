#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int n, m;

struct Node {
    int d, pos;
    bool operator < (const Node & rhs) const {
        return d > rhs.d;
    }
};

struct Edge {
    int to, w;
    int next;
}edge[M];

int head[N], tot;

void init(int n) {
    for(int i = 0; i <= n; i++) head[i] = -1;
    tot = 0;
}

void add(int u, int v, int w) {
    edge[tot].to = v; edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int dis[N];
int vis[N];

priority_queue <Node > q;

void Dijstra(int s) {
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[s] = 0;
    q.push(Node{0,s});
    while(!q.empty() ) {
        Node t = q.top();
        q.pop();
        int u = t.pos;
        if(vis[u]) continue;
        vis[u] = 1;
        int len = edge[u].size();
        for(int i = head[u]; i != -1; i = edge[i].next) {
            Edge v = edge[i].to;
            if(dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                q.push(Node {dis[v], v});
            }
        }
    }
}

int main() {

    return 0;
}
