//哈希表 10倍左右的素数

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 1000 + 5;
const ll mod = 10007;

int n;
struct Node{
	ll x, y, ci;
	Node (){}
	Node (ll xx, ll yy) : x(xx), y(yy) {}
}p[MAXN];

vector <Node>  hs[mod + 5];

Node up_ver(ll x1, ll y1, ll x2, ll y2){  //点的坐标的两倍（避免精度丢失）
	return Node( (x1+y1+x2-y2), (-x1+y1+x2+y2));
}

Node down_ver(ll x1, ll y1, ll x2, ll y2){
	return Node( (x1-y1+x2+y2), (x1+y1-x2+y2));
}

int check(Node &temp){
	ll x = temp.x, y = temp.y;
	ll hs_num = x*x + y*y;      //函数部分
	//cout << "zz " << x << " " << y << endl;
	int len = hs[hs_num%mod].size();
	if(len){
		for(int i = 0; i < len; i++){
			Node ok = hs[hs_num%mod][i];
			if(ok.x*2 == x && ok.y*2 == y) {
				temp.ci = ok.ci;
				return 1;
			}
		}
	}
	return 0;
}


int main(){
	while(cin >> n && n){
		for(int i = 0; i <= mod; i++){
			hs[i].clear();
		}
		for(int i = 1; i <= n; i++){
			cin >> p[i].x >> p[i].y;
			p[i].ci = i;
			ll hs_num =  p[i].x * p[i].x * 4 + p[i].y * p[i].y * 4;   //函数部分
			hs[hs_num%mod].push_back(p[i]);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+ 1; j <= n; j++){
				Node pu = up_ver(p[i].x, p[i].y, p[j].x, p[j].y );
				Node pd = down_ver(p[i].x, p[i].y, p[j].x, p[j].y );
				if(check(pu) && check(pd)) {
					ans++;
				}
			}
		}
		printf("%d\n", ans/2);
	}
	return 0;
}