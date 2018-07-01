// poj 4020 分析一波时间复杂度吧  熟练的水题刷题速度 场外一遍过 但改错改很久 
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 100000 + 5;
int dx, dy, ex, ey;
int dir[2] = {1, -1};
struct Node {
	int x, y, time;
};
int n, m;
vector <int> edge[MAXN];
queue <Node> q;

int check(int x, int y){
	if(x < n && y < m && x >=0 && y >= 0)
		return 1;
	else return 0;
}

int bfs(int x, int y){
	if(x == ex && y == ey) return 0;
	while(!q.empty())
		q.pop();
	Node u = {x, y, 0}, v;
	q.push(u);
	while(!q.empty()){
		u = q.front(); q.pop();
		int turn = edge[u.x][u.y];
		if(u.x == ex && u.y == ey) return u.time;
		if( ( (turn == 0 || turn == 3) && u.time %2 == 0) || ( (turn == 1 || turn == 4) && u.time % 2 == 1) ){    //i+-1
			for(int i = 0; i < 2; i++){
				v.x = dir[i] + u.x;
				v.y = u.y;
				if(check(v.x, v.y) ){
					if(edge[v.x][v.y] == 3 || edge[v.x][v.y] == 4 || edge[v.x][v.y] == 2) continue;
					v.time = u.time + 1; 
					if(edge[v.x][v.y] == 0) edge[v.x][v.y] = 3;
					else if(edge[v.x][v.y] == 1) edge[v.x][v.y] = 4;
					//cout << "zz1  " << v.x << " " << v.y << " " << edge[v.x][v.y] << endl;
					q.push(v);
				}
			}
		}
		else if( ( (turn == 1 || turn == 4) && u.time %2 == 0) || ( (turn == 0 || turn == 3) && u.time % 2 == 1) ){
			for(int i = 0; i < 2; i++){
				v.x = u.x; 
				v.y = u.y + dir[i];
				if(check(v.x, v.y)){
					if(edge[v.x][v.y] == 3 || edge[v.x][v.y] == 4 || edge[v.x][v.y] == 2) continue;
					v.time = u.time + 1; 
					if(edge[v.x][v.y] == 0) edge[v.x][v.y] = 3;
					else if(edge[v.x][v.y] == 1) edge[v.x][v.y] = 4;
					//cout << "zz2  " << v.x << " " << v.y << " " << edge[v.x][v.y] << endl;
					q.push(v);
				}
			}
		}
		edge[u.x][u.y] = 2;
	}
	return -1;
}

int main(){
	int r; cin >> r;
	while(r--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n ; i++){
			edge[i].clear();
			for(int j = 0; j < m ; j++){
				int d;
				scanf("%d", &d);
				edge[i].push_back(d);
			}
		}
		scanf("%d%d%d%d", &dx, &dy, &ex, &ey);
		ex = ex - 1; ey = ey - 1;
		int cnt = bfs(dx - 1, dy - 1);
		printf("%d\n", cnt);
	}
	//system("pause");
	return 0;
}