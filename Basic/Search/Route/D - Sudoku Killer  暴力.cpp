// hdu 1426 输出输入方式和储存方式 

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int num;
int flag;
int mpt[82][82];
struct P{
	int x,y;
};
P p[82];
int ok(int k, int now){
	for(int i = 0; i < 9; i++)
		if( mpt[p[now].x][i]== k || mpt[i][p[now].y] == k ) return 0;
		
	int x,y;
    x=(p[now].x/3)*3;  
    y=(p[now].y/3)*3; 
    
    for(int i = x; i < x+3; i++) 
        for(int j = y; j < y+3; j++)   
            if(mpt[i][j] == k)   
                return false;  
                
    return true;   
}

void dfs(int n){
	if(flag) return ;
	if(n == num) { 
        flag =1;
        for(int i = 0; i < 9; i++){  
            for(int j = 0; j < 9; j++){ 
                cout<<mpt[i][j]; 
				if(j!=8) cout<<" ";  
            }  
            cout<<endl;  
        }     
    }  
    else {
    	for(int i=1; i<=9; i++){  
            if(ok(i,n)){  
                mpt[p[n].x][p[n].y]=i;  
                dfs(n+1);  
                mpt[p[n].x][p[n].y]=0;  
            }  
         } 
    }  
    return;
} 

int main(){  
    char s; int z=0; 
    while(cin >> s){  
        num = 0;  flag = 0;
        if(s == '?'){  
            p[num].x = 0; p[num].y = 0;  
            num++;  
            mpt[0][0] = 0;  
        }  
        else  mpt[0][0] = s-'0'; 
		   
        for(int i = 0; i < 9; i++){  
            for(int j = 0; j < 9; j++){  
                if(i == 0 && j == 0)  continue;  
                cin>>s;  
                if(s=='?'){  
                    p[num].x = i;  p[num].y = j;  
                    num++;  
                    mpt[i][j]=0; 
                }  
                else   mpt[i][j]=s-'0';   
            }  
        }
        if(z++) cout<<endl;
        dfs(0);
    }
	return 0;  
}