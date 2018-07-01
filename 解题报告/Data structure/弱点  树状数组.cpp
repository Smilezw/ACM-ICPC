//树状数组  计数器 

#include <iostream>
#include <cstring>
using namespace std;

int tree[2][1000005];
int n;
int a[1000005];

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void add(int f , int x, int val){
	for(int i = x; i <= 1000000; i += i & (-i) )
		tree[f][i] += val; 
}

long long query(int f, int x){
	long long sum = 0;
	for(int i = x; i; i -= i & (-i)){
		sum += tree[f][i];
	}
	return sum;
}

int main(){
	while (cin >> n){
		for (int i = 1; i <= n; i++)
			a[i] = read();
		for(int i = 1; i <= n ;i++)
			add(0, a[i], 1);
		long long int ans = 0;
		for(int i = 1;i <= n; i++){
			add(0,a[i],-1);  //去除对i后的影响 
			ans+=(query(1,1000001)-query(1,a[i]))* query(0,a[i]-1);
			add(1,a[i],1);   //增加对i后的影响 
		}
     cout << ans <<endl;
	}
	return 0;
}