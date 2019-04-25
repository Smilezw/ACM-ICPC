#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
int _link[N][15], star[15], sta[15][N], used[15], have[15];

bool find(int x) {
    for (int i = 1; i <= m; i ++) {
        if(!_link[x][i] || used[i]) continue;//如果你不喜欢或者前面已经的人已经选过了
        used[i] = 1;
        if(have[i] < star[i]) {
            sta[i][++have[i]] = x;
            return 1;
        }

        else{
            for (int j = 1; j <= have[i]; j ++)  //匹配不到就找路
                if(find(sta[i][j])) {
                    sta[i][j] = x;
                    return 1;
                }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    while(scanf("%d %d", &n, &m) != EOF){
        memset(have, 0, sizeof(have));
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                scanf("%d", &_link[i][j]);
        for (int i = 1; i <= m; i ++)
            scanf("%d", &star[i]);
        int i;
        for (i = 1; i <= n; i ++) {
            memset(used, 0, sizeof(used));
            if(!find(i))
                break;
        }
        if(i > n) printf("YES\n");
        else printf("NO\n");


    }
    return 0;
}
