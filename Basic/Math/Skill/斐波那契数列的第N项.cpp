//qulik mul matrix 51 nod 1242 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000009;
ll ans, n;

struct Matrix  
{  
    long long ma[2][2];  
};  

Matrix mul(Matrix A,Matrix B)  
{  
    Matrix C;  
    C.ma[0][0]=C.ma[0][1]=C.ma[1][0]=C.ma[1][1]=0;  
    for(int i=0;i<2;i++)  
    {  
        for(int j=0;j<2;j++)  
        {  
            for(int k=0;k<2;k++)  
            {  
                C.ma[i][j]=(C.ma[i][j] %mod + ( (A.ma[i][k]%mod) * (B.ma[k][j]%mod) )%mod )%mod;  
            }  
        }  
    }  
    return C;  
}  
Matrix pow_mod(Matrix A,long long n)  
{  
    Matrix B;
    B.ma[0][0]=B.ma[1][1]=1;  
    B.ma[0][1]=B.ma[1][0]=0;  
    while(n)  
    {  
        if(n&1) B=mul(B,A);  
        A=mul(A,A);  
        n>>=1;  
    }  
    return B;  
}
int main(){
	while(cin >> n){
		Matrix A;
        A.ma[0][0]=0;A.ma[0][1]=1;
        A.ma[1][0]=1;A.ma[1][1]=1;
        Matrix ans=pow_mod(A,n);  
        printf("%lld\n",ans.ma[0][1]);  
	}
	return 0;
}