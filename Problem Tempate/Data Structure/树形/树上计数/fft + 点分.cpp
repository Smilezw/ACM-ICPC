
#include<cstdio>
#include<complex>
#include<iostream>
using namespace std;
typedef long long LL;
const int Mn=200005;
const double Pi=acos(-1);
struct Edge{int to,next;}w[Mn];
int n,cnt=0,h[Mn],vst[Mn],minn,tg,s[Mn],sz,prm[Mn];
LL sum[Mn],sp[Mn],sn[Mn];
complex<double>ft[Mn],fft1[Mn],fft2[Mn];
void FFT(complex<double>A[],int n,int ty){
	 int i,j,k,m;
	 complex<double>t0,t1;
	 for(i=0;i<n;i++){
	 	for(j=0,k=i,m=1;m<n;m<<=1,j=(j<<1)|(k&1),k>>=1);
	 	if(i<j)t0=A[i],A[i]=A[j],A[j]=t0;
	 }
	 ft[0]=1;
	 for(m=1;m<n;m<<=1){
	 	t0=complex<double>(cos(Pi/m),ty*sin(Pi/m));
	 	for(i=1;i<m;i++)ft[i]=ft[i-1]*t0;
	 	for(k=0;k<n;k+=(m<<1))
	 	  for(i=k;i<k+m;i++){
	 	  	t0=A[i];t1=A[i+m]*ft[i-k];
	 	  	A[i]=t0+t1;A[i+m]=t0-t1;
		  }
	 }
	 if(ty==1)return;
	 for(t0=1.0/n,i=0;i<n;i++)A[i]*=t0;
}
void AddEdge(int x,int y){w[++cnt]=(Edge){y,h[x]};h[x]=cnt;}
void init(){
	 int i,x,y;
	 scanf("%d",&n);
	 for(i=1;i<n;i++){
	 	scanf("%d%d",&x,&y);
	 	AddEdge(x,y);AddEdge(y,x);
	 }
}
void Size(int x,int fa){
	 int j,y;s[x]=1;
	 for(j=h[x];j;j=w[j].next){
	 	y=w[j].to;
	 	if(vst[y]||y==fa)continue;
	 	Size(y,x);
	 	s[x]+=s[y];
	 }
}
void Find(int x,int fa){
	 int j,y,mx=0;
	 for(j=h[x];j;j=w[j].next){
	 	y=w[j].to;
	 	if(vst[y]||y==fa)continue;
	 	Find(y,x);
	 	mx=max(mx,s[y]);
	 }
	 mx=max(mx,sz-s[x]);
	 if(mx<minn){minn=mx;tg=x;}
}
int FindCen(int x){
	minn=0x7fffffff/2;tg=-1;
	Size(x,0);
	sz=s[x];
	Find(x,0);
	return tg;
}
void DFS(int x,int fa,int dep){
	 int j,y;
	 sn[dep]++;
	 for(j=h[x];j;j=w[j].next){
	 	y=w[j].to;
	 	if(y==fa||vst[y])continue;
	 	DFS(y,x,dep+1);
	 }
}
void Clear(LL a[],int N){for(int i=0;i<N;i++)a[i]=0;}
void Calc(LL a[],int N,int ty){
     for(int i=0;i<N;i++)fft1[i]=a[i];
	 for(int i=0;i<N;i++)fft2[i]=a[i];
	 FFT(fft1,N,1);FFT(fft2,N,1);
	 for(int i=0;i<N;i++)fft1[i]*=fft2[i];
	 FFT(fft1,N,-1);
	 for(int i=0;i<N;i++)sum[i]+=ty*(LL)(fft1[i].real()+0.3);
}
void Add(LL a[],LL b[],int N){for(int i=0;i<N;i++)a[i]+=b[i];}
void solve(int x){
	 int j,y,N,i;
	 Size(x,0);
	 for(N=1;N<=s[x];N<<=1);
	 Clear(sp,N);sp[0]=1;
	 for(j=h[x];j;j=w[j].next){
	 	y=w[j].to;
	 	if(vst[y])continue;
	 	for(N=1;N<=2*s[y];N<<=1);
	 	Clear(sn,N);DFS(y,x,1);
	 	Calc(sn,N,-1);Add(sp,sn,N);
	 }
	 for(N=1;N<=s[x];N<<=1);
	 Calc(sp,N,1);sum[0]=0;
}
void DivOnT(int x){
	 int j,y,G;
	 G=FindCen(x);
	 solve(G);
	 vst[G]=1;
	 for(j=h[G];j;j=w[j].next){
	 	y=w[j].to;
	 	if(!vst[y])DivOnT(y);
	 }
}
void solve(){
	 int i,j;LL ans=0;
	 for(i=2;i<=n;i++)
	   if(!prm[i]){
	   	  ans+=sum[i];
	   	  for(j=2*i;j<=n;j+=i)prm[j]=1;
	   }
	 printf("%.6lf\n",ans/2/((double)n*(n-1)/2.0));
}
int main(){
    init();
    DivOnT(1);
    solve();
	return 0;
}
