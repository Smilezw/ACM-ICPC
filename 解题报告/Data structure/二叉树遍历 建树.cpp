#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
int mid[10+5];
int post[10+5]; 
int lch[10+5];
int rch[10+5];

void dfs(){
	queue <int> q;
	q.push(post[n-1]);
	while(!q.empty()){
		int root = q.front(); q.pop();
		cout << root << " ";
		if(lch[root]) q.push(lch[root]);
		if(rch[root]) q.push(rch[root]);
	}

}

int build(int L1, int R1, int L2, int R2){
	if( L1 > R1 ) return 0;
	int root = post[R2];
	int len = L1;
	while( mid[len]!= root ) len++;
	int x = len -L1;
	lch[root] = build(L1, len-1, L2, L2+x-1);
	rch[root] = build(len+1, R1, L2+x, R2-1);
	return root;
}

int main(){
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> post[i];
		}
		for(int i = 0; i < n; i++){
			cin >> mid[i];
		}
		build(0, n-1, 0, n-1);
		dfs();
		cout <<endl;
	}

	return 0;
}
