// light oj 	Basic Math 1010 

#include <bits/stdc++.h>
typedef long long ll;
const int MAXN=1e5+5;  
const int INF=0x3f3f3f3f;  
  
using namespace std;

int main()  
{  
    int T; scanf("%d", &T);
	int t = 0;
	int cnt;
	while(T--){
		ll m , n;
		scanf("%lld%lld", &m, &n);
		if(n > m) swap(m , n);
		
		if(n == 1)  cnt = m;
		else if(n == 2){
			cnt = (m / 4 * 4) + (min(n, m % 4) * 2);
		}
		else
			cnt = ((m * n) +1) / 2;
		printf("Case %d: %d\n", ++t, cnt);
	}
	//system("pause");
}  