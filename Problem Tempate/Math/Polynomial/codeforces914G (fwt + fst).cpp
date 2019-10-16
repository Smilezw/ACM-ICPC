#include<bits/stdc++.h>
#define mem(p) memset(&p,0,sizeof(p))
using namespace std;
typedef long long ll;
const ll M=1000000007;
int n,a,i;
ll s[200005],ans[200005],inv2,p[200005],fans,f[200005];
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ans;
}
void FWTand(ll *a,int op,int n)
{
	int i,j,k;
	for(i=2;i<=n;i<<=1)
		for(j=0;j<n;j+=i)
			for(k=j;k<j+(i>>1);k++)
			{
				if(op==1)a[k]=(a[(i>>1)+k]+a[k])%M;
				else a[k]=(a[k]-a[(i>>1)+k])%M;
			}
}
void FWTxor(ll *a,int op,int n)
{
	int i,j,k;
	for(i=2;i<=n;i<<=1)
		for(j=0;j<n;j+=i)
			for(k=j;k<j+(i>>1);k++)
			{
				ll n=a[k],m=a[(i>>1)+k];
				if(op==1)a[k]=(n+m)%M,a[k+(i>>1)]=(n-m)%M;
				else a[k]=(n+m)*inv2%M,a[k+(i>>1)]=(n-m)*inv2%M;
			}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		s[a]++;
		p[a]++;
	}
	inv2=qpow(2,M-2);
	for(i=0;i<(1<<17);i++)   //子集卷积  占位多项式法
		for(register int j=i;;j=(j-1)&i)
		{
			ans[i]+=s[j]*s[i^j];
			if(j==0)
				break;
		}
	for(i=0;i<(1<<17);i++)
		ans[i]%=M;
	FWTxor(s,1,1<<17);  //异或卷积 （自卷）
	for(i=0;i<(1<<17);i++)
		s[i]=s[i]*s[i]%M;
	FWTxor(s,-1,1<<17);
	f[1]=1;
	for(i=2;i<(1<<17);i++)
		f[i]=(f[i-1]+f[i-2])%M;
	for(i=0;i<(1<<17);i++)
	{
		s[i]=f[i]*s[i]%M;
		ans[i]=f[i]*ans[i]%M;
		p[i]=f[i]*p[i]%M;
	}
	FWTand(s,1,1<<17);       //三个and卷积
	FWTand(p,1,1<<17);
	FWTand(ans,1,1<<17);
	for(i=0;i<(1<<17);i++)
		ans[i]=ans[i]*p[i]%M*s[i]%M;
	FWTand(ans,-1,1<<17);
	for(i=1;i<(1<<17);i<<=1)    //统计二进制位的答案
		fans=(fans+ans[i])%M;
	cout<<(fans%M+M)%M;
}
