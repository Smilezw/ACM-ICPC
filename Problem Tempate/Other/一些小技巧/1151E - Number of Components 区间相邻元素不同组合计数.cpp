#include<cstdio>
long long ans,n,i,x,ls;
int main(){
	for(scanf("%I64d",&n),i=1;i<=n;i++)scanf("%I64d",&x),ans+=x>ls?(x-ls)*(n-x+1):(ls-x)*x,ls=x;
	printf("%I64d",ans);
}
