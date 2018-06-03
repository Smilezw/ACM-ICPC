// hdu  1584 蜘蛛牌 
// 搜索所有情况  回溯   
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

int a[10+5];
int vis[10+5];
int tot;

void dfs(int n,int now){
	if(now >= tot ) return;
	if(n==10)  {
	    tot=now;  
		return; 
	}
	for(int i=1; i<10; i++ ){
		if(!vis[i]){
			vis[i] = 1;
			for(int j=i+1; j<=10;j++){
				if(!vis[j]){
					dfs(n+1, now + abs(a[j]-a[i]) );
					break;
				}
			}
			vis[i]=0;
		}
	}
}

int main(){
    int t; 
    cin>>t;
    while(t--){
    	memset(vis,0,sizeof(vis));
    	for(int i=1;i<=10;i++){
    		int w;  cin>>w;  a[w]=i;
	    }
	    tot=1100;
	    dfs(1,0); 
	    cout<<tot<<endl;
    }
    return 0;
} 