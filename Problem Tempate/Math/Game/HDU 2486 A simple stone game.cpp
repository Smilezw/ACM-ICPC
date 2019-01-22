//k倍动态减去游戏
/*
我们需要构造一个数列使得每个整数可以由数列中若干个数相加并且这些数倍数差距大于k，
我们用a来存这些数，用b来表示前i-1个能构成的最大的数，那么a[i+1]=b[i]+1；然后再构造b[i+1]，
由于b[i+1]要用到a[i+1]，并且不相邻，因此要找到a[j]*k<a[i]，b[i+1]=a[i+1]+b[j]。
查询时只需要不断减去最大的a[i]直到0，最后剩下的就是第一次取的值。
*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i = a; i < n; i++)
#define mem(a,b) memset((a),(b),sizeof(a))
#define pb push_back
typedef long long ll;

const int MAXN = 2e6 + 5;
const int mod = 1e9 + 7;

int a[MAXN], b[MAXN];

int main(){
    int T;
    cin >> T;
    int cas = 1;
    while(T--){
        int n, k;
        cin >> n >> k;

        printf("Case %d: ",cas++);
        if(n <= k + 1)  {
            printf("lose\n");
            continue;
        }
        int i = 0, j = 0;
        a[0] = b[0] = 1;
        while(a[i] < n){
            i++;
            a[i] = b[i-1] + 1;
            while(a[j+1]*k < a[i]) j++;
            if(a[j]*k < a[i]) b[i] = b[j] + a[i];
            else b[i] = a[i];
        }
        if(a[i]==n)printf("lose\n");
        else
        {
            int ans = 0;
            while(n)
            {
                if(n>=a[i])
                {
                    n -= a[i];
                    ans = a[i];
                }
                i--;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
