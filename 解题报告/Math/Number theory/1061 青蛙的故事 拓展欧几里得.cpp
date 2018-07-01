//百练 1061 拓展欧几里得  公式转化
//特殊情况处理 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y){
	if(!b){
		x = 1; y = 2;
		return a;
	}
	else{
		ll d = exgcd(b, a%b, y, x);
		y -= (a / b) * x;
		return d;
	}
}

int main (){
	ll a, b, m, n, l;
	while(cin >> a >> b >> m >> n >> l){
		ll len = b - a, turn = m-n;
		ll x , y;
		if(turn < 0){
			len = -len;
			turn = -turn;
		}
		ll c = exgcd(turn, l, x, y);
		if(len % c != 0){
			printf("Impossible\n");continue;
		}
		x = x * len / c;
		ll t = l / c;
		if(x >= 0) x = x % t;
		else x =  (x%t) +t;
		cout << x <<endl;
	}
	return 0;
}