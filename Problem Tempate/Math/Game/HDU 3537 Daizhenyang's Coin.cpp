//翻硬币 （1-3）枚，且最右边的为正
//子问题为只有一枚硬币的为正的nim和
//求解一枚硬币的子问题得到SG函数表
//观察答案
//注意去重
//SG函数表
/*
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int SG[MAXN];
int vis[1000];

void init(){
    SG[0] = 1;
    for(int i = 1; i < 100; i++){
        memset(vis, 0, sizeof(vis));
        vis[0] = 1;
        for(int j = 0; j < i; j++) vis[SG[j]] = 1;
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                vis[SG[j]^SG[k]] = 1;
            }
        }
        for(int j = 0; ; j++) if(vis[j] == 0) {
            SG[i] = j; break;
        }
    }

    for(int i = 0; i < 20; i++)
        cout << i << " " << SG[i] << endl ;
}

int main(){
    init();
    return 0;
}
*/

//所以当2x为odious(奇数个二进制1)时，sg值是2x，当2x是evil时，sg值是2x+1.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map <ll , int> m;

ll f(ll x){
    int ok = 0;
    int y = x*2;
    while(y){
        if(y &1) ok++;
        y = y >> 1;
    }
    if(ok & 1) return (2*x);
    return (2*x+1);
}


int main(){
    int n;
    while(cin >> n){
        m.clear();
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            if(m[x] == 0) ans ^= f(x);
            m[x] = 1;
        }
        if(ans == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
