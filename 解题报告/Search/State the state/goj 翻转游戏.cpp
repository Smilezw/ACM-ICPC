//×´Ì¬Ñ¹Ëõ goj ·­×ªÓÎÏ·

#include<stdio.h>
#include<iostream>
using namespace std;

char mpt[20][20];
int a[20][20];
int n;
int INF = 1 << 30;

void turn(int x , int y){
	a[x][y] = 1 - a[x][y];
}

int dfs(int x){
	int i, j, k;
	int ss = 1 << n;
	int ansn = INF;
	for(k = 0; k < ss; k++){
		
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(mpt[i][j] == 'w') a[i][j] = 0;
				else a[i][j] = 1;
			}
		}
		int sum = 0;
		for(i = 0; i < n; i ++){
			if(k & (1 << i)){
				turn(0,i);
				if(i > 0) turn(0, i-1);
				if(i < n-1) turn(0, i+1);
				if(n > 1) turn(1, i);
				sum ++;
			}
		}
		for(i = 1; i < n; i++){
			for(j = 0; j < n; j++){
				if(a[i-1][j] != x){
					turn(i, j);
					turn(i-1, j);
					if(j > 0) turn(i, j-1);
					if(j < n-1) turn(i, j+1);
					if(i < n-1) turn(i+1, j);
					sum++;
				}
			}
		}
		for(i = 0; i < n ;i ++){
			if(a[n-1][i] != x) break;
		}
		if(i == n) {
			if(ansn > sum) ansn = sum;
		}
	}
	return ansn;
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%s", mpt[i]);
	}
	int ans = min(dfs(0),  dfs(1));
	if(ans == INF) 
		cout << "Impossible" <<endl;
	else
		cout << ans << endl;
	return 0;
}