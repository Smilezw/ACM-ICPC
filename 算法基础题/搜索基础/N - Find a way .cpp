//hdu 2612 没有好的思路了 走两遍把 
//没用翻译。。 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n , m;
char mpt[200+5][200+5];
int vis[2][200+5][200+5];
int flag[200+5][200+5];
int dx, dy, ex, ey;
int step_min;
int dir[4][2]={1, 0, 0, 1, -1, 0, 0, -1};

struct Node{
	int x, y;
};

int turn (int x ,int y ){
	if( flag[x][y] || x < 0 || y < 0 || x >= n || y >= m || mpt[x][y] == '#')
	    return 0;
    return 1;
}

void bfs(int xx, int yy, int c){
	queue <Node> q;
	Node s={xx, yy}, t;
	q.push(s);
	flag[xx][yy] = 1;
	while ( !q.empty() ){
		s = q.front(); q.pop();
		for(int i = 0 ; i < 4; i++){
		    t.x = s.x + dir[i][0];
		    t.y = s.y + dir[i][1];
			if(turn (t.x , t.y )){
				vis[c][t.x][t.y] = vis[c][s.x][s.y] + 1;
				flag[t.x][t.y] = 1;
				q.push(t);
			} 
		}
	}
}

int main(){
	while(cin >> n >> m){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> mpt[i][j];
				if(mpt[i][j] == 'M') {dx = i; dy = j;}
				if(mpt[i][j] == 'Y') {ex = i; ey = j;}
			}
		}
	    step_min = 1 << 30;
	    memset(vis, 0, sizeof(vis));
	    
	    memset(flag, 0, sizeof(flag));
	    bfs(dx, dy, 0);
	    memset(flag, 0, sizeof(flag));
	    bfs(ex, ey, 1);
	    
	    for(int i = 0 ; i < n; i++){
    		for(int j = 0; j < m; j++){
    			if(mpt[i][j] == '@' && vis[0][i][j] > 0 && vis[1][i][j] > 0)
		    	step_min = min(step_min , vis[0][i][j] + vis[1][i][j]);
		    }
    	}
	    cout << step_min*11 << endl;
	}
	return 0;
}