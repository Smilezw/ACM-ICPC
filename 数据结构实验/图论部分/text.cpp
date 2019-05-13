#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int M = 400;

struct Edge{
    int u, v, w;
}edge[M];

int cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    //freopen("input.txt","r", stdin);
    //freopen("C:\\Users\\ASUS\\Desktop\\in.txt","w", stdout) ;

    ///*  ¿ËÂ³Ë¹¿¨¶û
    int n, m;
    srand(time(NULL));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u = rand()%n, v = rand()%n, w = rand()%n;
        if(u == v) u = (v+m)%n + 1;
        edge[i] = (Edge){u, v, w};
        edge[i+m] = (Edge){v, u, w};
    }
    sort(edge, edge+m, cmp);
    for(int i = 0; i < m;i++) {
        printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].w);
    }
    //*/

    /*

    */
    return 0;
}
