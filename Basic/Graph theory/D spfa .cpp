//最短路  spfa
// d  hdu 3790 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 100000 + 5;  //点
const int INF = 1 << 30;
int n, m;
int vis[MAXN];
int dis[MAXN];
int pis[MAXN];

struct Node{
	int u, v, d, w;
};

vector <Node> edge[100000 + 5];

void spfa(int pos){
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++){
		pis[i] = INF; dis[i] = INF;
	}
	queue <int> q;
	pis[pos] = 0; dis[pos] = 0;
	q.push(pos); 
	vis[pos] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = 0;
		for(int i = 0; i < edge[u].size(); i++){
			int v = edge[u][i].v, w = edge[u][i].w, d = edge[u][i].d;
			if(dis[v] > dis[u] + d ){
				dis[v] = dis[u] + d;
				pis[v] = pis[u] + w;
				if(vis[v] == 0){
					q.push(v);
					vis[v] = 1;
				}
			}
			else if(dis[v] == dis[u] + d ){
				if(pis[v] > pis[u] + w){
					dis[v] = dis[u] + d;
					pis[v] = pis[u] + w;
					if(vis[v] == 0){
						q.push(v);
						vis[v] = 1;
					}
				}
			}
		}
	}
}

int main(){
	while(scanf("%d%d", &n, &m) && n ){
		while(m --){
			int u, v, w, d;
			scanf("%d%d%d%d", &u, &v, &d, &w);
			Node temp_1 = {u, v, d, w}, temp_2 = {v, u, d, w};  
			edge[u].push_back(temp_1); 
			edge[v].push_back(temp_2);
		}
		int x, y;
		scanf("%d%d", &x, &y);
		spfa(x);
		printf("%d %d\n", dis[y], pis[y]);
		for(int i = 1; i <= n; i++)
			edge[i].clear();           //清空下
	}
	return 0;
}