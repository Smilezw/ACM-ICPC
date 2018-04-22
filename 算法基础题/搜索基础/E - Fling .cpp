//好吧这个模拟有点烦  注意命名 

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Print{
	int xt , yt , pt;
};
char mpt[20][20];
int num, n =7, m = 8;
Print e[30];
char point[] = "ULRD";
int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int check(int x, int y){
	if( x < 0 || x >= n || y < 0|| y >= m) return 0;
	return 1; 
}

int dfs(int c){
	if( c == num -1 ) return 1;
	int fx[10], fy[10];
	int tx, ty;
	
/*		cout << endl;
  for(int a=0;a<7;a++){
  for(int b=0;b<m;b++){
    	  printf("%c",mpt[a][b]);
       }
       cout << endl;
       }
     		cout << endl;
*/    		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mpt[i][j] == 'O'){
				for(int p = 0; p < 4; p++){
					tx = i ; ty = j;
					int sum_b = 0 ;
					if(mpt[tx + dir[p][0]][ty + dir[p][1]] == 'O' && check(tx + dir[p][0],ty + dir[p][1]))
					    continue;
		            while( check(tx , ty) ){
			            if(mpt[tx][ty] == 'O'){
            				fx[sum_b] = tx;  fy[sum_b] = ty;  sum_b++; 
            			}
            			tx += dir[p][0]; ty += dir[p][1]; 
		            }
            		if( sum_b > 1 ){
		            	for(int k = 1; k <sum_b; k++){
		            		mpt[fx[k-1]][fy[k-1]] = 'X';
		            		mpt[fx[k]-dir[p][0]][fy[k]-dir[p][1]] = 'O';
		                }
		                mpt[fx[sum_b-1]][fy[sum_b - 1]] = 'X';
		                if( dfs(c+1) )  {e[c].xt = i; e[c].yt = j; e[c].pt = p;  return 1; }
		            }
		            int ti = i, tj = j;
                    while(check(ti,tj)){
                         mpt[ti][tj]='X';
                         ti+=dir[p][0];
                         tj+=dir[p][1];
                    }
            		for(int dk = 0; dk < sum_b; dk++)    // return
		            	mpt[fx[dk]][fy[dk]] = 'O';
	           }
			}
		}
	}
	return 0;
}


int main(){
    int i,j,p=0;
    while( cin >> mpt[0] ){
        for( i = 1; i < n; i++)
          cin >> mpt[i];
        num = 0;
        for( i = 0; i < n; i++)
            for( j = 0; j < m; j++)
                if(mpt[i][j] == 'O')  
			       num++;
        memset (e, 0,sizeof(e));
        dfs( 0);
        if(p) cout <<endl;
        cout << "CASE #" << ++p << ":" << endl;
        for(int i = 0; i < num -1; i++){
        	cout << e[i].xt << " " << e[i].yt << " " << point[e[i].pt] << endl;
        }
    }
    return 0;
}