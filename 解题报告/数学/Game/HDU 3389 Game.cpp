//每个盒子中有一定量的卡片。每次取编号为B和编号为A的盒子， 要求满足
//B < A && (A+B)%2=1 && (A+B)%3=0，把A中的任意数量的卡片转移给B，谁不能再转移了谁输。

/*
1. 分成一个二分图
如果可以从A拿卡片到B，连一条从A到B的边。把所有box编号x满足（(x%3==0&&x%2==1) || x%3==1)这个条件的放左边，其他放右边，不难发现
a) 只有从左边到右边的边或从右到左的边。
b) 所有不能拿卡片出去的box都在左边。
2. 证明左边的box并不影响结果。假设当前从右边的局势来看属于输家的人为了
摆脱这种局面，从左边的某盒子A拿了n张卡片到B，因为B肯定有出去的边，对手
会从B再取走那n张卡片到左边，局面没有变化
3. 于是这就相当于所有右边的box在nim游戏。
*/
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int T;
    int n;
    int a;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a);
            if((i%3==0 && i%2==0) || i%3 == 2)
                sum ^= a;
        }
        if(sum)printf("Case %d: Alice\n",iCase);
        else printf("Case %d: Bob\n",iCase);
    }
    return 0;
}
