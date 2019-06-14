#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, shu[20], dp[20][2];  //表示长度为i的数的总数

int dfs(int len, bool if4, bool shangxian)
{
    if (len == 0)
        return 1;
    if (!shangxian && dp[len][if4])   //为什么要返回呢？可以画图理解当我们搜到3XXX时，程序运行到1XXX时就已经把3XXX之后的搜索完了，记忆化也是这个用意.
        return dp[len][if4];
    int cnt = 0, maxx = (shangxian ? shu[len] : 9);
    for (int i = 0; i <= maxx; i++)
    {
        if (if4 && i == 9)
            continue;
        cnt += dfs(len - 1, i == 4, shangxian && i == maxx);  //只有之前有限制现在的达到了上限才能构成限制
    }
    return shangxian ? cnt : dp[len][if4] = cnt; //如果有限制，那么就不能记忆化，否则记忆的是个错误的数.
}

int solve(int x)
{
    memset(shu, 0, sizeof(shu));
    int k = 0;
    while (x)
    {
        shu[++k] = x % 10;  //保存a,b的数
        x /= 10;
    }
    return dfs(k, false, true);
}

int main()
{
    scanf("%d%d", &a, &b);
    printf("%d\n", solve(b) - solve(a - 1));

    //while (1);
    return 0;
}
