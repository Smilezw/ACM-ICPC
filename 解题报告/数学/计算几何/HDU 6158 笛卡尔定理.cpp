//   计蒜客 Finding the Radius for an Inserted Circle
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/

int main(){
    int k, t;
    double r,ans,k1,k2,k3,k4,k5;
    int n;
    while(cin >> t && t != -1){
        cin >> r;
        while(t--){
            cin >> k;
            k1 = 1.0/r, k2 = 1.0/r, k3= 1.0/r;
            rep(i, 0, k){
                double b = -2*(k1+k2+k3);
                double c = 2*(k1*k1+k2*k2+k3*k3)-(k1+k2+k3)*(k1+k2+k3);
                double data = b*b - 4*c;
                double x = (-b + sqrt(data))/2;
                ans = 1/x;
                k3 = x;
            }
            ans = floor(ans);
            cout << k << " " << ans << endl;
        }
    }
    return 0;
}

//hdu 6158
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-15;
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/

int main(){
    int t; cin >> t;
    while(t--){
        int n;
        double ans, r1, r2, k1, k2, k3, k4, k5, r;
        cin >> r1 >> r2;
        cin >> n;
        if(r1 < r2) swap(r1, r2);
        k1 = -1.0/r1, k2 = 1.0/r2, k3 = 1.0/(r1 - r2);
        ans = (r1 - r2)*(r1 - r2);
        n--;
        k4 = k1+k2+k3;
        rep(i, 0, n){
            if((1.0/k4)*(1.0/k4) < eps) break;
            ans += (1.0/k4)*(1.0/k4);
            if(i+1 < n) ans += (1.0/k4)*(1.0/k4), i++;
            k5 = 2*(k1 + k2 + k4) - k3;
            k3 = k4, k4 = k5;
        }
        printf("%.5lf\n", ans*PI);
    }
    return 0;
}
