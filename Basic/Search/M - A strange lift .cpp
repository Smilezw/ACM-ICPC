//hdu 1548 M - A strange lift 
//Á½ÏòÍØÕ¹ 

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int w,v;
int a[200+5];
int vis[200+5];
int dir[2]={1,-1};
struct Node{
	int level,step;
};

int bfs(){
	queue <Node> q; 
	vis[w] = 1;
	Node s, t = {w,0};
	q.push(t);
	while(!q.empty()){
		s = q.front(); q.pop();
		if(s.level == v) return s.step;
		
		for(int i = 0; i < 2; i++){
			t.level = s.level + (dir[i] * a[s.level]); 
			t.step = s.step + 1;
			if(t.level > 0 && t.level <= n && vis[t.level] == 0){
				vis[t.level] = 1;
				q.push(t);
			}
		}
	}
	return -1;
}

int main(){
	while(cin >> n){
		memset(vis, 0 , sizeof(vis));
		cin >> w >> v;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int cnt = bfs();
		cout << cnt <<endl;
 	}
}

