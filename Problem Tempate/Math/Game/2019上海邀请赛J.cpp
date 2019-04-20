#include <bits/stdc++.h>
using namespace std;
/*
int SG[10000];

int get(int x) {
    if(SG[x] != -1) return SG[x];
    int vis[10000];
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i < x; i++) {
        if(x % i == 0) {
            int t = get(x-i);
            vis[t] = 1;
        }
    }
    for(int i = 0;; i++) {
        if(!vis[i]) return SG[x] = i;
    }
}

int main (){
    memset(SG, -1, sizeof(SG));
    for(int i = 0; i <= 1000; i++) {
        cout << i << "  " << get(i) << endl;
    }
    return 0;
}
*/


typedef long long ll;
const int N = 1e5 + 5 ;
ll a[N];

inline ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        x = gi();
        int t = 0;
        int xx = x;
        while(xx % 2 == 0) {
            xx = xx/2;
            t++;
        }
        //cout << x << " " << t << endl;
        ans = ans^t;
    }

    if(ans == 0) cout << "Lose" << endl;
    else cout << "Win" << endl;

    return 0;
}
