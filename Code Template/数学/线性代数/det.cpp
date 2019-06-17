#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[205][205],p;
int n;
ll Gauss(){
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	      a[i][j]=(a[i][j]%p+p)%p;
	ll ans=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
		      while(a[j][i]){
    			ll t=a[i][i]/a[j][i];
    			for(int k=i;k<=n;k++)
			         (a[i][k]-=a[j][k]*t)%=p;
    			for(int k=i;k<=n;k++)
			         swap(a[i][k],a[j][k]);
    			ans=-ans;
		      }
		if(!a[i][i]) return 0;
		ans=ans*a[i][i]%p;
	}
	return (ans+p)%p;
}
int main(){
	while(~scanf("%d%lld",&n,&p)){
		for(int i=1;i<=n;i++)
		      for(int j=1;j<=n;j++)
		            scanf("%lld",&a[i][j]);
		printf("%lld\n",Gauss());
	}
	return 0;
}
