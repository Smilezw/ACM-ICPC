//hdu 1728 逃离迷宫
//  搜吧  注意逻辑  转弯数组剪枝 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

char mpt[100+5][100+5];
int vis[100+5][100+5];
int inf = 0x3f;
int ex,ey,dx,dy;
int m,n,mt;
int flag;
int dir[4][2]={1,0, -1,0, 0,1, 0,-1};

void dfs(int x,int y,int turn){
    if(x==ex && y==ey && vis[x][y]<=mt) { flag=1; return ;}
    if(flag)  return;
    if( vis[x][y] > mt ) return;
  
    for(int i = 0; i < 4; i++){
        int xx = x+dir[i][0];
        int yy = y+dir[i][1]; 
        if(xx>0 && yy>0 && xx<=m && yy<=n  && mpt[xx][yy]!='*'){
            if(vis[xx][yy] < vis[x][y]) continue;  //已走 且转弯数大 
            if(turn != -1 && turn != i && vis[xx][yy] < vis[x][y]+1) continue;
             
            if(i != turn && turn != -1) vis[xx][yy] = vis[x][y]+1;
            else vis[xx][yy] = vis[x][y];
            //cout<<xx<<"  " << yy<<"  " << vis[xx][yy] << endl;
            mpt[xx][yy]='*'; dfs(xx,yy,i); mpt[xx][yy]='.';
            if(flag) return; 
        }
    }
}

int main(){
    int t; 
    cin>>t;
    while(t--){
        flag=0;
        cin >> m >> n ;
        memset(vis,inf,sizeof(vis) );
        for(int i = 1; i <= m; i++){
            getchar();
            for(int j = 1; j<=n;  j++){
                scanf("%c",&mpt[i][j]);
            }
        }
        scanf("%d%d%d%d%d",&mt, &dy, &dx, &ey, &ex); 
        vis[dx][dy]=0;
        dfs(dx,dy,-1);
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
} 