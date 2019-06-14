/*windy定义了一种windy数。不含前导零且相邻两个数字之差至少为2的正整数被称为windy数。
windy想知道，在A和B之间，包括A和B，总共有多少个windy数？

    假设我们需要求0至x（用数组表示）的区间的windy数的个数，
    1. x有t位，我们先求出t-1位的windy的个数，因为这些windy数绝对比x小，不会超过这个区间，
    2. 然后求出长度为t,最高位小于x[0]的windy数的个数，同样不会超过这个区间.
    最后统计长度为t，最高位为x[0]的windy数的个数，怎么统计呢？
    3. 枚举i从0到x[1]-1,加上长度为t-1的最高位为i的数，不会超过这个区间，
     然后同样的，再求最高位为x[1]的windy数的个数，
     类似于递归过程.如果abs(x[0] - x[1]) < 2,
     则最高位为x[0],次高位为x[1]的windy数再不存在了，
     直接退出，到最后一位时，如果还存在windy数，windy数的个数+1即可.
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long t, a, b;

long long f[15][11],shu[15];

void init()
{
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 10; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

long long solve(long long x)
{
    memset(shu, 0, sizeof(shu));
    if (x == 0)
        return 0;
    long long k = 0,ans = 0;
    while (x)
    {
        shu[++k] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= k - 1; i++)
        for (int j = 1; j <= 9; j++)
            ans += f[i][j];             //小于k位的
    for (int i = 1; i < shu[k]; i++)
        ans += f[k][i];                 //k位 比第k位小的
    for (int i = k - 1; i >= 1; i--)    //k位  第k位是shu[k] 的
    {
        for (int j = 0; j <= shu[i] - 1; j++)
            if (abs(j - shu[i + 1]) >= 2)
                ans += f[i][j];
        if (abs(shu[i + 1] - shu[i]) < 2)
            break;
        if (i == 1)
            ans += 1;
    }
    return ans;
}

int main()
{
    scanf("%lld%lld", &a, &b);
    init();
    printf("%lld", solve(b) - solve(a - 1));
    return 0;
}
