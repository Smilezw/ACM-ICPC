int dfn[N], low[N], csize[N], sta[N], color[N];
bool vis[N];
int dfs_num, col_num, top;

void Tarjan(int x) {
	dfn[x] = ++dfs_num ;
	low[x] = dfs_num ;
	vis[x] = 1 ;//是否在栈中
	sta[++top] = x;
	for(int i = head[x] ; i != -1; i = edge[i].next){
		int temp = edge[i].to ;
		if (!dfn[temp]){
			Tarjan(temp);
			low[x] = min(low[x], low[temp]);
		}
		else if (vis[temp]) low[x] = min(low[x] , dfn[temp]) ;
	}
	int now = 0;
	if (dfn[x]==low[x]) {//构成强连通分量
		++col_num;//染色
		while(now != x) {//清空
			now = sta[top];
			top--;
			csize[col_num]++;
			color[now] = col_num;
			vis[now] = 0;
		}
	}
}
