/*windy������һ��windy��������ǰ������������������֮������Ϊ2������������Ϊwindy����
windy��֪������A��B֮�䣬����A��B���ܹ��ж��ٸ�windy����

    ����������Ҫ��0��x���������ʾ���������windy���ĸ�����
    1. x��tλ�����������t-1λ��windy�ĸ�������Ϊ��Щwindy�����Ա�xС�����ᳬ��������䣬
    2. Ȼ���������Ϊt,���λС��x[0]��windy���ĸ�����ͬ�����ᳬ���������.
    ���ͳ�Ƴ���Ϊt�����λΪx[0]��windy���ĸ�������ôͳ���أ�
    3. ö��i��0��x[1]-1,���ϳ���Ϊt-1�����λΪi���������ᳬ��������䣬
     Ȼ��ͬ���ģ��������λΪx[1]��windy���ĸ�����
     �����ڵݹ����.���abs(x[0] - x[1]) < 2,
     �����λΪx[0],�θ�λΪx[1]��windy���ٲ������ˣ�
     ֱ���˳��������һλʱ�����������windy����windy���ĸ���+1����.
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
            ans += f[i][j];             //С��kλ��
    for (int i = 1; i < shu[k]; i++)
        ans += f[k][i];                 //kλ �ȵ�kλС��
    for (int i = k - 1; i >= 1; i--)    //kλ  ��kλ��shu[k] ��
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
