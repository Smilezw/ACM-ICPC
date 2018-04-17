//好吧  方向数组了解一波
//深搜树  回溯  
//  hdu 1241 Oil Deposits  

#include<iostream>  
#include<cstring>
using namespace std;

const int MAXN=100+10;

char mp[MAXN][MAXN]={"\0"};
int sp[MAXN][MAXN]; 
int sum;
int n,m;

int turn(int xx, int yy){
	if(xx < n && yy < m && xx >= 0 && yy >= 0 && mp[xx][yy]!='*' && !sp[xx][yy]){
		return 1;
	}
	  
    return 0;
}
void bfs(int x,int y){
	sp[x][y]=sum;
	if( turn(x+1,y) ) bfs(x+1,y);
	
	if( turn(x,y+1) ) bfs(x,y+1);
	
	if( turn(x-1,y) ) bfs(x-1,y);
	
	if( turn(x,y-1) ) bfs(x,y-1);
	
	if( turn(x+1,y+1) ) bfs(x+1,y+1);
	
	if( turn(x+1,y-1) ) bfs(x+1,y-1);
	
	if( turn(x-1,y+1) ) bfs(x-1,y+1);
	
	if( turn(x-1,y-1) ) bfs(x-1,y-1);
	
}

int main() {
	while(cin >> n >> m &&n&&m){
		sum=0;
		memset(sp,0,sizeof(sp));
		for(int i=0 ;i < n; i++)
		  cin>>mp[i];
 
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		if(mp[i][j] != '*' && !sp[i][j]){
		            sum++; bfs(i,j); 	
		        }
	        }
        }
        cout<<sum<<endl;
	} 
} 