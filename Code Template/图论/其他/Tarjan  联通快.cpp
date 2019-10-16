int dfn[N], low[N], csize[N], sta[N], color[N];
bool vis[N];
int dfs_num, col_num, top;

void ta_init() {
    dfs_num = col_num = top = 0;
    for(int i = 0; i <= n; i++) {
        vis[i] = false;
        color[i] = in[i] = dfn[i] = low[i] = 0;
    }

}

void Tarjan(int x) {
	dfn[x] = ++dfs_num ;
	low[x] = dfs_num ;
	vis[x] = 1 ;
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
	if (dfn[x]==low[x]) {
		++col_num;
		while(now != x) {
			now = sta[top];
			top--;
			csize[col_num]++;
			color[now] = col_num;
			vis[now] = 0;
		}
	}
}
