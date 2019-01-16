//带堆优  n*logm

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;

struct Node {
    int d, pos;
    bool operator < (const Node & rhs) const {
        return d > rhs.d;
    }
};

struct Edge {
    int u, v, w;
};

int n, m;

int dis[MAXN];
int vis[MAXN];

vector <Edge > edge[MAXN];

priority_queue <Node > q;

void Dijstra(int ss) {
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[ss] = 0;
    q.push(Node{0,ss});
    while(!q.empty() ) {
        Node t = q.top();
        q.pop();
        int s = t.pos;
        if(vis[s]) continue;
        vis[s] = 1;
        int len = edge[s].size();
        for(int i = 0; i < len; i++) {
            Edge &e = edge[s][i];
            if(dis[e.v] > dis[s] + e.w) {
                dis[e.v] = dis[s] + e.w;
                q.push(Node {dis[e.v], e.v});
            }
        }
    }
}
