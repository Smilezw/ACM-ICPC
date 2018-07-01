//反向搜索  G - Choose the best route  // hdu 2680 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 100000 + 5;  //点
const int INF = 1 << 30;
int n, m, p;
int vis[MAXN];
int dis[MAXN];

struct Node{
	int u, v, w;
};

vector <Node> edge[100000 + 5];

void spfa(int pos){
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++){
		dis[i] = INF;
	}
	queue <int> q;
	dis[pos] = 0;
	q.push(pos); 
	vis[pos] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = 0;
		for(int i = 0; i < edge[u].size(); i++){
			int v = edge[u][i].v, w = edge[u][i].w;
			if(dis[v] > dis[u] + w ){
				dis[v] = dis[u] + w;
				//printf("zz %d %d %d\n", u, v, w);
				if(vis[v] == 0){
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}

int main(){
	while(scanf("%d%d%d", &n, &m, &p) != EOF){
		while(m --){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			Node temp = {v, u, w};  
			edge[v].push_back(temp); 
		}
		int v, x, y;
		spfa(p);
		scanf("%d", &v);
		int ans = INF;
		/*for(int i = 0; i <= n; i++)
			cout << dis[i] << " ";
		cout <<endl;*/
		while(v--){
			scanf("%d", &x);
			//cout << "pp " << dis[p] <<endl;
			if(ans > dis[x])  ans = dis[x];
		}
		if(ans == INF) 
			printf("-1\n");
		else
			printf("%d\n", ans);
		for(int i = 1; i <= n; i++)
			edge[i].clear();           //清空下
	}
	return 0;
}