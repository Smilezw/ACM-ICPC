//poj 1190 ×´Ì¬ËÑË÷ 
//Ð¡¼ôÖ¦

#include <iostream>
using namespace std;
typedef long long ll;

ll v, m;
ll ans;

void dfs(ll nowv, ll nows, ll d, ll nowh, ll nowr){
	if(nowv < 0 || d < 0) return;
	if(nows > ans && ans) return;
	if(nowv == 0 && d == 0) {
		if(ans)
			ans = min(ans, nows);
		else
			ans = nows;
		return;
	}
	if(d*(nowh-1)*(nowr-1)*(nowr-1) < nowv && m != d)
		return ;
	for(ll r = nowr - 1; r >= d; r--){
		for(ll h = nowh - 1; h >= d; h--){ 
			ll nV = r *r *h; 
			ll nS = 2 * r * h; 
			if(nV > v ) continue; 
			if(d == m) nS = nS + r*r; 
			if(nows + 2*nowv/r >= ans && ans) continue;
			dfs(nowv - nV, nows + nS, d-1, h, r);  
		}
	}
    
}

int main(){
	while(cin >> v >> m){
		if(m == 0) {
			cout << 0 <<endl;
			continue;
		}
		ans = 0;
		dfs(v, 0, m ,1000,100);
		cout << ans << endl;
	}
	return 0;
}
