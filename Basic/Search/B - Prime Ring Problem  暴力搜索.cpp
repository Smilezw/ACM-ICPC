//素数环 递归 
//回溯标记还原
//hdu 1016  
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,t=0;
int A[20+5];
int f[20+5];
int isp(int p){
	int i;
	for(int i=p-1;i>=2;i--){
		if(p%i==0) return 0;
	}
	return 1;
}

void dfs(int now){
	if( now==n+1 && isp(f[now-1]+1) ){
		for(int i=1;i<=n;i++){
			if(i!=1) printf(" ");
			printf("%d",f[i]);
		}
		cout<<endl;
	}
	
	else {
		for(int i=2;i<=n;i++){
			if( isp(f[now-1]+i) && !A[i]){
				f[now]=i;
				A[i] = 1;
				dfs(now+1);
				A[i] = 0;
			}
		}
	}
}
int main(){
	for(int i=0;i<=20;i++)
		A[i]=i;
	f[1]=1;
	while(cin>>n){
		t++;  memset(A,0,sizeof(A));
		printf("Case %d:\n",t);
		dfs(2);
		cout<<endl;
	}
} 