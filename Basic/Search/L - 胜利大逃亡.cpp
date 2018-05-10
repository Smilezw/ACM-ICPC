#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int mpt[50+5][50+5][50+5];
int a,b,c,T;
int dir[6][3]={1,0,0, -1,0,0, 0,1,0, 0,-1,0, 0,0,1, 0,0,-1};

struct Node{
	int x,y,z,turn;
};  

int bfs( ){
	queue <Node> q;
	Node s1={1,1,1,0},s2;
	mpt[1][1][1]=1;
	q.push(s1);
	while(!q.empty()){
		s2=q.front();  q.pop();
		for(int i = 0; i < 6; i++){
            s1.x = s2.x + dir[i][0];
		    s1.y = s2.y + dir[i][1];
		    s1.z = s2.z + dir[i][2];
		    s1.turn = s2.turn + 1;
	    	if(s1.x == a && s1.y == b && s1.z == c && s2.turn <= T){
			     return s1.turn;
		    } 
		    if(s1.x>0&&s1.x<=a&&s1.y>0&&s1.y<=b&&s1.z>0&&s1.z<=c&&!mpt[s1.x][s1.y][s1.z])
		    {
    			mpt[s1.x][s1.y][s1.z] = 1;
			    q.push(s1);
    		}	
	    }
	}
	return -1;
} 

int main(){

	int G ; scanf( "%d", &G );
	while(G--){
		scanf("%d%d%d%d",&a,&b,&c,&T);
		memset(mpt,-1,sizeof(mpt));
		for(int i = 1; i <= a ; i++){
			for(int j = 1; j <= b; j++){
				for(int k = 1; k <= c; k++){
					scanf( "%d", &mpt[i][j][k] ); 
				}
			}
		}
		mpt[0][0][0]=0;
		if(a+b+c-3>T||mpt[a][b][c]==1)  
        {  
            printf("-1\n");  
            continue;  
        }  
        if(a==b==c==1)  
        {  
            printf("0\n");  
            continue;  
        }  
		cout<<bfs()<<endl;
	}
	return 0;
} 