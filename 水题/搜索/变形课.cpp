#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int mpt[30][30];
int flag;
int vis[30];

void dfs(int pos){
    if(flag) return ;
    if(pos == m - 'a'){
        flag = 1; return;
    }
    for(int i = 0; i < 26; i++){
        if(mpt[pos][i] && vis[i] == 0){
            vis[i] = 1;
            dfs(i);
            vis[i] = 0;
        }
    }
}

int main(){
    char p[500];
    while(scnaf("%s", p) != EOF){
        n = 0; flag = 0;
        memset(mpt, 0, sizeof(mpt));
        memset(vis, 0, sizeof(vis));
        while(p[0] != '0'){
            int len = strlen(p);
            int u = p[0] - 'a';
            int v = p[len-1] - 'a';
            if(len == 1) mpt[u][u] = 1;
            else mpt[u][v] = 1;
            scanf("%s", p);
        }
        dfs(1);
        if(flag) printf("Yes.\n");
        else printf("No.\n");
    }
    return 0;

}
