//好吧 2018.4.12 最难一题了
// 加入优先队列搜索  拓展若n次全是等待 时间为2n  但可能拓展n+(n-i)次到达
// 使得时间为2n-i  优先级为时间  

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char mpt[20+5][20+5];
int vis[20+5][20+5];
int n, m, ex, ey, dx, dy;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct Node{
	int x ,y , step;
	friend bool operator < (Node temp, Node temp1) {
		return temp1.step < temp.step;
	}
};

int turn(int x, int y){
	if(mpt[x][y] == '*' || x < 0 || y < 0 || x >= n || y >= m || vis[x][y] )
	    return 0;
    return 1;
}

int bfs(){
    priority_queue  <Node> q;
	Node s = {dx, dy , 0}, t;
	q.push(s);
	vis[dx][dy] == 0;
	while( !q.empty() ){
		s = q.top(); q.pop();
	//cout << s.x << "  " << s.y << "  " << s.step << endl;
		if(s.x == ex && s.y == ey) return s.step;
		for(int i = 0; i < 4; i++){
			t.x = s.x + dir[i][0];
			t.y = s.y + dir[i][1];
			t.step = s.step + 1;
			if( turn( t.x , t.y) ){ 
			    Node rt; 
				rt.x = t.x + dir[i][0]; 
				rt.y = t.y + dir[i][1];
				rt.step = t.step;
				if( mpt[t.x][t.y] == '|' && turn(rt.x, rt.y) ){ 
				    if(i % 2 == 0 && s.step%2 == 0 || i%2==1 && s.step%2==1){
    					vis[rt.x][rt.y]=1; 
						q.push(rt); 
    				}    
                    else {
                    	vis[rt.x][rt.y]=1;
						rt.step++;
						q.push(rt); 
                    }     
				}
				else if(mpt[t.x][t.y] == '-' && turn(rt.x, rt.y)){
					if(i%2 == 0 && s.step%2 == 1 || i%2 == 1 && s.step%2==0) {
						vis[rt.x][rt.y]=1; 
						q.push(rt); 
					}    
                    else {
                    	vis[rt.x][rt.y]=1;
						rt.step++;
						q.push(rt); 
                    }   
				}
				else if(mpt[t.x][t.y] == '.' || mpt[t.x][t.y] == 'T'){
				    vis[t.x][t.y] =  1;
				    q.push(t);
				}
			}
		}
	}
	return -1;
} 

int main() {
	while(cin >> n >> m){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> mpt[i][j];
				if( mpt[i][j] == 'S') { dx = i; dy = j; }
				if( mpt[i][j] == 'T') { ex = i; ey = j; }
			}
		}
		int cnt;
		memset(vis, 0, sizeof(vis));
		cnt=bfs();
		cout << cnt << endl;
	} 
	return 0;
}