#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 21;
//s1
/*
求p个人围成k个圈 (圈不能为空) 的方案数。注意这里的圈中的人的顺序不同也会视为圈不同。
f(p,k) = (p−1)f(p−1,k) + f(p−1,k−1)
*/
ll stirling[maxn][maxn];

void get_stirling() {
	stirling[0][0] = 0;
	stirling[1][1] = 1;
	for(ll i = 2; i < maxn; i++) {
		for(ll j = 1; j <= i; j++) {
			stirling[i][j] = stirling[i - 1][j - 1] + (i - 1) * stirling[i - 1][j];
		}
	}
}

//S2
/*
定义：求p个人，放入k个相同的房子 (房子不可以为空) 的方案数。
*把基数为p的集合划分为k个非空集的方法
f(p,k)=kf(p−1,k)+f(p−1,k−1)
*/

ll Stirling[maxn][maxn];

void get_Stirling() {
	Stirling[0][0] = 0;
	Stirling[1][1] = 1;
	for(ll i = 2; i < maxn; i++) {
		for(ll j = 1; j <= i; j++) {
			Stirling[i][j] = Stirling[i - 1][j - 1] + j * Stirling[i - 1][j];
		}
	}
}

/*
n个数可以划分成多少个集合
*/

ll Bell[maxn];

void get_Bell() {
	ll T[maxn];
	Bell[0] = 1;
	Bell[1] = 1;
	T[0] = 1;
	for(int i = 2; i < maxn; i++) {
	    T[i - 1] = Bell[i - 1];
	    for(int j = i - 2; j >= 0; j--)
	        T[j] = T[j] + T[j + 1];
	    Bell[i] = T[0];
	}
}
