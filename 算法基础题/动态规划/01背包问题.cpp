//背包思想剪枝+搜索
//贝克汉姆  goj   超时   
//数组递推成功 
 
#include<iostream>
#include<cstring>
using namespace std;
int n,V;
int dp[5000+5];
int v[5000+5],w[5000+5];   //v  w

void dfs(int i,int nv ){
	if(i > n) return;
	if(dp[nv+v[i+1]] < dp[nv]+w[i+1]&&(nv+v[i+1])<=V){
		dp[nv+v[i+1]] = dp[nv]+w[i+1];
		dfs(i + 1, nv + v[i+1]);
	}
		dfs(i + 1, nv);	
}

int main(){
	while(cin>>n>>V){
	    for(int i=1;i<=n;i++)
		   cin>>v[i]>>w[i];
	    dfs(0,0);
	    int k=0;
 	    for(int i=0;i<=V;i++)
    		k=max(dp[i],k);
   		cout<<k<<endl;
	}
	return 0;
} 
/* 
//从后向前拓展体积  递推公式判定
 
#include<iostream>
#include<cstring>
using namespace std;
int N,V;
int dp[50000+5];
int v[50000+5],w[50000+5];

int main(){
	while(cin>>N>>V){
        for(int i=1;i<=N;i++)
		   cin>>v[i]>>w[i];
	     memset(dp,0,sizeof(dp));
	   
	    for(int i=1;i<=N;i++){
    	   	for(int j=V;j>=0;j--){
   		    	if(dp[j]||j==0 && j+v[i]<=V )
                    dp[j+v[i]] = max(dp[j]+w[i],dp[j+v[i]]);
   		    }
   	    }
   	    int k=0;
 	   for(int i=1;i<=V;i++)
    		k=max(dp[i],k);
   		cout<<k<<endl;
	}
	return 0;
} 
*/ 