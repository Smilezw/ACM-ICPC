#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, shu[20], dp[20][2];  //��ʾ����Ϊi����������

int dfs(int len, bool if4, bool shangxian)
{
    if (len == 0)
        return 1;
    if (!shangxian && dp[len][if4])   //ΪʲôҪ�����أ����Ի�ͼ��⵱�����ѵ�3XXXʱ���������е�1XXXʱ���Ѿ���3XXX֮����������ˣ����仯Ҳ���������.
        return dp[len][if4];
    int cnt = 0, maxx = (shangxian ? shu[len] : 9);
    for (int i = 0; i <= maxx; i++)
    {
        if (if4 && i == 9)
            continue;
        cnt += dfs(len - 1, i == 4, shangxian && i == maxx);  //ֻ��֮ǰ���������ڵĴﵽ�����޲��ܹ�������
    }
    return shangxian ? cnt : dp[len][if4] = cnt; //��������ƣ���ô�Ͳ��ܼ��仯�����������Ǹ��������.
}

int solve(int x)
{
    memset(shu, 0, sizeof(shu));
    int k = 0;
    while (x)
    {
        shu[++k] = x % 10;  //����a,b����
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
