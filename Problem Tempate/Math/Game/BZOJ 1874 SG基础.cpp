#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int n,a[maxn],sg[maxn],ans,Tim,vis[maxn],b[maxn],m;

void init()
{
    for (int i = 1; i <= 1000; i++)
    {
        Tim++;
        for (int j = 1; j <= m; j++)
        {
            if (i - b[j] >= 0)
                vis[sg[i - b[j]]] = Tim;
        }
        for (int j = 0; j <= 10; j++)
            if (vis[j] != Tim)
            {
                sg[i] = j;
                break;
            }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i = 1; i <= m; i++)
        scanf("%d",&b[i]);
    init();
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            ans = sg[a[i]];
        else
            ans ^= sg[a[i]];
    }
    if (ans == 0)
        puts("NO");
    else
    {
        puts("YES");
        for (int i = 1; i <= n; i++)
        {
            bool flag = false;
            for (int j = 1; j <= m; j++)
            {
                if (a[i] >= b[j] && (ans ^ sg[a[i]] ^ sg[a[i] - b[j]]) == 0)
                {
                    printf("%d %d\n",i,b[j]);
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
    }

    return 0;
}
