#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

const int N = 1e5 + 9;

vector<ll> v[N];

int m;

ll check(int x){
	int need = x - v[0].size();
	ll res = 0;
	vector < ll > f;
	for(int i = 1;i <= m ;i++)
	 for(int j = 0;j < v[i].size();j++){
	 	 if(v[i].size() - j >= x){
	 	 	res += v[i][j];
	 	 	--need;
		  }
		  else f.push_back(v[i][j]);
	 }
	 sort(f.begin(),f.end());

	 for(int k = 0;k < need;k++)
	 	res += f[k];
    return res;
}

int main(){
    int n,a;
	ll b;
	while(scanf("%d",&n) != EOF){
        for(int i = 0;i <= m;i++){
            v[i].clear();
        }
        m = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d %lld",&a,&b);
            m = max(m,a);       //找出最大的皇子
            v[a].push_back(b);  //每个皇子的支持者分别存放
        }
        for(int i = 1;i <= m;i++)
            sort(v[i].begin(),v[i].end());//对每个皇子的支持者的价值排序
        int l = 0,r = n;
        while(l + 1 < r){
            int ml = (l + r) >> 1;
            int mr = (ml + r) >> 1;
            if(check(ml) > check(mr))
                l = ml;
            else r = mr;
        }
        printf("%d\n",check(r));
	}
	return 0;
}
