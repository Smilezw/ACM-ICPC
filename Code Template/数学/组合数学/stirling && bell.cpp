#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 21;
//s1
/*
��p����Χ��k��Ȧ (Ȧ����Ϊ��) �ķ�������ע�������Ȧ�е��˵�˳��ͬҲ����ΪȦ��ͬ��
f(p, k) = kf(p-1, k) + f(p-1, k-1)
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
n�������Ի��ֳɶ��ٸ�����
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
