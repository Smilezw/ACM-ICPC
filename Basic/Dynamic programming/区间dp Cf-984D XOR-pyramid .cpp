//Codeforces-984D - XOR-pyramid - ˼ά
//����dp  dp[i][j] = dp[i + 1][j] ^ dp[i][j - 1] ȡ���������

#include <bits/stdc++.h>
using namespace std;

int dp[5000 + 5][5000 + 5];
int ans[5000 + 5][5000 + 5];

int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> dp[i][i] ;
		ans[i][i] = dp[i][i];
	}
	for(int len = 2; len <= n; len++){
		for(int i = 1; i + len - 1 <= n; i++){
			int j = i + len - 1;
			dp[i][j] = dp[i+1][j] ^ dp[i][j-1];
			ans[i][j] = max(dp[i][j], max(ans[i+1][j], ans[i][j-1]));
		}
	}
	int p; cin >> p;
	while(p--){
		int l, r; 
		cin >> l >> r;
		cout << ans[l][r] << endl;
	}
	return 0;
}