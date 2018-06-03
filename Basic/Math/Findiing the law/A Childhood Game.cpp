// light oj 1688 

#include <bits/stdc++.h>
using namespace std;
#define lson x << 1
#define rson (x << 1) + 1
typedef long long ll;
const int MAXN = 1e5+5;  
const int INF = 0x3f3f3f3f;  
ll n, m;
ll cnt;

int main()  
{  
    int T; scanf("%d", &T);
	int t = 0;
	string s[2] = {"Alice", "Bob"};
	while(T--){
		char ss[10];
		scanf("%lld%s", &n, ss);
		if(ss[0] == 'A'){
			if(n % 3 == 1)
				cout <<"Case " << ++t <<": " << s[1] << endl;
			else 
				cout <<"Case " << ++t <<": " << s[0] << endl;
		}
		if(ss[0] == 'B'){
			if(n % 3 == 0)
				cout <<"Case " << ++t <<": " << s[0] << endl;
			else
				cout <<"Case " << ++t <<": " << s[1] << endl;
		}
		
	}
	//system("pause");
	return 0;
}  