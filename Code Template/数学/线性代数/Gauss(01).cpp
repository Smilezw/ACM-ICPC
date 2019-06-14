#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for(int i = a; i < n; i++)
const int MAXN = 35;

int a[MAXN][MAXN];//Ôö¹ã¾ØÕó
int free_x[MAXN];
int free_num;
int n;
int equ,var;

int Gauss(){
    int max_r, col, k;
    equ = n, var = n;
    free_num = 0;
    for(k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for(int i = k+1; i < equ; i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col]) ) max_r = i;
        }
        if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
        }
        for(int i = k+1; i < equ; i++)
        {
            if(a[i][col] != 0)
            {
                for(int j = col; j < var + 1; j++){
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    for(int i = k; i < equ; i++){
        if(a[i][col]) return -1;
    }
    if(k < var) return var - k;
    return 0;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(a, 0, sizeof(a));
        cin >> n;
        rep(i, 0, n)  cin >> a[i][n];
        rep(i, 0, n) {
            int x;
            cin >> x;
            a[i][n] ^= x;
        }
        int s, e;
        rep(i, 0, n) a[i][i] = 1;
        while(cin >> s >> e && s+e) a[e-1][s-1] = 1;
        int ans = Gauss();
        if(ans == -1) printf("Oh,it's impossible~!!\n");
        else  printf("%lld\n", 1 << ans);
    }
    return 0;
}
