//背包问题注意点  ：注意点的更新  覆盖掉可用结果 

#include<iostream>
#include<cstring>
using namespace std;

int w[1000];
int f[1000];

int main(){
	int s,n;
	while(cin>>s>>n){
	    memset(f,0,sizeof(f));
	    if(s==0)  {
    		cout<<"NO"<<endl; continue;
    	}
		int i,j;
	    for(i=1;i<=n;i++){
		   cin>>w[i];
	    }
	    f[0]=1;
	    
	    for(i=1;i<=n;i++){
		   for(j=s;j>w[i];j--){
  				if(f[j-w[i]==1])    
				f[j]=f[j-w[i]];
			  }
	    }
	    if(f[s]) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
} 