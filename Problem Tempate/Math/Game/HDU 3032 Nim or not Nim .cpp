/*
题意，n堆石子，其中可以取任意一堆的任意个或者把一堆分作两堆
SG打表观察得到结果
*/

//打表代码
/*
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int SG[MAXN];

int g(int x){
    if(SG[x] != -1) return SG[x];
    int s[1010];
    memset(s ,0, sizeof(s));
    for(int i = x-1; i >= 0 ;i--){
        s[g(i)] = 1;
    }
    for(int i = 1; i <= x/2; i++){
        int t = 0;
        t = t^g(i)^g(x-i);   //两个游戏
        s[t] = 1;
    }
    for(int i = 0;; i++)
        if(!s[i]) {
            return SG[x] = i;
        }
}

int main(){
    memset(SG, -1, sizeof(SG));
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int y = g(i);
        ans ^= y;
        cout << "f: " << i << " " << SG[i] << endl;
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x%4==0) x = x-1;
            else if(x %4 == 3) x = x + 1;
            ans ^= x;
        }
        if(ans) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }

    return 0;
}
