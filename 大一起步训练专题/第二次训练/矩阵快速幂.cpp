#include<iostream>
#include<cstring>
using namespace std;

struct M{
	int A[10+5][10+5];
};
const int mod=9973;
M m1,m2;
int n,k;

void input(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        cin>>m1.A[i][j];
	        m2.A[i][j]=m1.A[i][j];
	    }
	}
}
M mul(M s1,M s2){
     M c;
    for(int i=1; i<=n; i++)   //枚举第一个矩阵的行
        for(int j=1; j<=n; j++)  //枚举第二个矩阵的列
        {
            c.A[i][j]=0;
            for(int k=1; k<=n; k++)  
                c.A[i][j]=(c.A[i][j]+s1.A[i][k]*s2.A[k][j]%mod)%mod;
            c.A[i][j]%=mod;
        }
    return c;
}

M solve(M a,M b,int x){
	while(x){
        if(x&1) b=mul(b,a);
        x>>=1;
        a=mul(a,a);
    }
    return b;
}

int main(){
	int N; cin>>N;
	while(N--){
		input();
		M c;
		c=solve(m1,m2,k-1);
		int ans=0;
		for(int i=1;i<=n;i++){
			  ans=(ans+c.A[i][i])%mod;
		}
		cout<<ans<<endl;
	}
} 