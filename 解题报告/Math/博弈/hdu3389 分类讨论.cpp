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
