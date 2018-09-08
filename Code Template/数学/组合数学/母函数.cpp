//hdu  1171  母函数模板
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;

const int MAXN = 250000 + 5;
int ans[MAXN], temp[MAXN];
int val[50 + 5];
int cnt[50 + 5];
int n;

int main(){
    while(cin >> n && n > 0){
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> val[i] >> cnt[i];
            sum += val[i]*cnt[i];
        }
        memset(ans, 0, sizeof(ans));
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i <= val[0] * cnt[0]; i = i + val[0]){
             ans[i]=1;
        }
        for(int i = 1; i < n; i++){   //多项式乘法
            for(int j = 0; j <= sum; j++){
                for(int k = 0; k*val[i] + j <= sum && k <= cnt[i]; k++){
                    temp[k*val[i] + j] += ans[j];
                }
            }
            for(int j = 0; j <= sum; j++){
                ans[j] = temp[j];
                temp[j] = 0;
            }
        }
        for(int i = sum/2; i >= 0; i--){
            if(ans[i] != 0){
                printf("%d %d\n", sum - i, i);
                break;
            }
        }
    }
    return 0;
}
