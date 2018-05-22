// 初始化的小技巧  	light oj 1007 - Mathematically Hard

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000000 + 5;
unsigned long long pri[MAXN];

void init(){
    memset(pri, 0, sizeof(pri));
    pri[1] = 1;
    for(int i = 2; i < MAXN; i++)
		if(!pri[i])
        for(int j = i; j < MAXN; j = j + i){
            if(!pri[j]) pri[j] = j;
            pri[j] = pri[j]/i*(i-1);
        }
    for(int i = 0; i < MAXN; i++)
       pri[i] = pri[i-1] + (pri[i] *pri[i]);
}

int main (){
    init();
    int T; cin >> T;
    int  t = 0;
    while (T--){
       unsigned l, r;
       scanf("%d%d", &l, &r);
       printf("Case %d: %llu\n", ++t, pri[r] - pri[l-1]);
    }
    return 0;
	//system("pause");
}