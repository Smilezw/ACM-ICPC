#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

int n;

queue <int > q;
/*
void bfs() {
	int cnt = 0;
	q.push(1);
	while(!q.empty() ) {
		if(cnt >= n-1) break;
		int u = q.front();
		q.pop();
		for(int i = -2; i < 2; i++) {
			int v = u*4 + i;
			cout << u << " " << v << endl;
			cnt++;
			if(cnt >= n-1) break;
			q.push(v);
		}
	}
}
*/
int main() {
    freopen("C:\\Users\\ASUS\\Desktop\\4in.txt", "w", stdout);
	n = 40000;
	cout << n << endl;
	int cnt = 0;
	for(int i = 2; i <= n; i++) {
		cout << i << " " << i-1 <<endl;
		cnt++;
	}
	return 0;
}
