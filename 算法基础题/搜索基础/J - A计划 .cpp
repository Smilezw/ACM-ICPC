//hdu 2102 A计划  
//深搜传送门 

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char mpt[2][10+5][10+5];
int vis[2][10+5][10+5];
int inf = 0x3f;
int n, m, T;
int flag;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int turn (int x , int y ,int c){
	if( x >= n || y >= m || mpt[c][x][y] == '*' || x < 0 || y < 0)
	    return 0;
    return 1;
}

void dfs (int x, int y, int c, int t){
 // cout << x << " " << y << " " << c << " " << t << " " << mpt[c][x][y]<<"  "<<vis[c][x][y]<<endl;
	if(flag) return ;
	if(t > T) return ;
	if( mpt[c][x][y] == 'P' && t <= T){
		flag = 1; 
		cout << "YES" <<endl;  
		return ;
	}
	for(int i = 0; i < 4; i++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if( turn (tx , ty , c) ){
			if(mpt[c][tx][ty] == '#' && (mpt[1-c][tx][ty] == '.' || mpt[1-c][tx][ty] == 'P')){
				if(vis[c][x][y] < vis[1-c][tx][ty] ){
					vis[1-c][tx][ty] = vis[c][x][y];
					dfs(tx , ty , 1-c , t + 1) ;
				}
			}
			else if( mpt[c][tx][ty] != '#' && vis[c][tx][ty] > vis[c][x][y]){
				vis[c][tx][ty] = vis[c][x][y] + 1 ;
				dfs(tx, ty, c, t+1);
			}
		}
	}
}

int main(){
	int repeat; cin >> repeat;
	while(repeat--){
		cin >> n >> m >> T;
		memset ( vis, inf , sizeof(vis) );
		flag = 0;
		for(int i = 0; i < n; i++)
  		  scanf ("%s" , mpt[0][i]);
        for(int i = 0; i < n; i++)
            scanf ("%s" , mpt[1][i]);
        vis[0][0][0] = 0;
        dfs(0 ,0, 0, 0);
        if(flag == 0) cout << "NO" <<endl;
	}
	return 0;
}