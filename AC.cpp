#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int a[N], n, L, R;

int main() {
    while(cin >> n) {
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        int ans = n;
        R = n;
        for(L = n/2; L > 0; L--){
            if(a[L]*2 <= a[R]) {
                ans--;
                R--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
