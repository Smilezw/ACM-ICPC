//poj 1088滑雪 
//分析路径经过的后效性 从大到小走

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
int n, m;
int mpt[MAXN][MAXN];
int dp[MAXN][MAXN];
int dir[4][2] = {1,0, -1,0, 0, -1, 0, 1};
struct Node{
	int x, y, t;
}edge[MAXN * MAXN];

bool cmp(Node &a, Node &b){
	return a.t > b.t;
}

int check(int x, int y){
	if(x >= 0 && y >= 0 && x < n && y < m){
		return 1;
	}
	return 0;
}

void dfs(int x, int y){
	for(int i = 0; i < 4; i ++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(check(tx, ty)){
			if(mpt[tx][ty] > mpt[x][y]){
				dp[x][y] = max(dp[x][y], dp[tx][ty] + 1);
				//cout << "zz" << x << " " << y << " " << tx << " " << ty << " "<<dp[tx][ty] << endl;
			}
		}
	}
}

int main(){
	while(cin >> n >> m){
		memset(edge, 0,sizeof(edge));
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j ++){
				cin >> mpt[i][j];
				dp[i][j] = 1;
				edge[cnt].t = mpt[i][j];
				edge[cnt].x = i;
				edge[cnt].y = j;
				cnt++;
			}
		}
		sort(edge , edge + cnt, cmp);
		for(int i = 0; i < cnt; i++){
				int x = edge[i].x;
				int y = edge[i].y;
				dfs(x, y);
		}
		int ans = -1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ans = max(ans , dp[i][j]);
			}
		}
		cout << ans <<endl;
	}
	return 0;
}

/*5 1
1 5 2 3 6
2
*/