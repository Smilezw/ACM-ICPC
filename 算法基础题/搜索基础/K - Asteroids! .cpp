// hdu 1240 K - Asteroids! 题意 三维迷宫 起点到终点最短路
 #include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int n;
char mpt[20+5][20+5][20+5];
int vis[20+5][20+5][20+5];
int sx,sy,sz,ex,ey,ez;
int dir[6][3]={1,0,0, -1,0,0, 0,1,0, 0,-1,0, 0,0,1, 0,0,-1};

struct Node{
	int x,y,z,step;
} ;
int can(int x,int y,int z){
	if(x>=0&&x<n&&y>=0&&y<n&&z>=0&&z<n&&!vis[x][y][z]) return 1;
	return 0;
}
int bfs( ){
	queue <Node> q;
	Node s1={sx,sy,sz,0},s2;
	vis[sx][sy][sz]=1;
	q.push(s1);
	while(!q.empty()){
		s2=q.front();  q.pop();
		if(s2.x == ex && s2.y == ey && s2.z == ez){
			     return  s2.step;
       } 
		for(int i = 0; i < 6; i++){
            s1.x = s2.x + dir[i][0];
		    s1.y = s2.y + dir[i][1];
		    s1.z = s2.z + dir[i][2];
            if(can(s1.x,s1.y,s1.z) && mpt[s1.x][s1.y][s1.z]!='X')
		    {
		    	s1.step = s2.step+1;
		    //	cout<< s1.x << "  " << s1.y << "  " << s1.z <<"  "<< s1.step <<endl;
    			vis[s1.x][s1.y][s1.z] = 1;
			    q.push(s1);
    		}	
	    }
	}
	return -1;
} 

int main(){
	char *p[100];
	while(scanf("%s%d",p,&n)!=EOF){
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n ; i++)
			for(int j = 0; j < n; j++)
					scanf( "%s", mpt[i][j]);
	    scanf("%d%d%d%d%d%d",&sx,&sy,&sz,&ex,&ey,&ez);
		scanf("%s",p);
		
		mpt[ex][ey][ez]=mpt[sx][sy][sz]='O';
		
		int ans =bfs(); 
		
		if(ans >= 0)
		   printf("%d %d\n",n,ans);
		else  
           printf("NO ROUTE\n"); 
	}
	return 0;
} 