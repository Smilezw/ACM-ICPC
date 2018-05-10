//C - Stacks of Flapjacks
//uva 120
//翻到最前面  然后往后翻 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100 + 5] ;
int n = 0;

void overturn(int x){
    printf("%d ", n-x);
    for(int i = 0; i <= x/2; i++)  {
        swap(a[i], a[x -i]);
    }
}

int main(){
    char no;
    while(scanf("%d", &a[n++]) != EOF){
        no = getchar();
        while(no != '\n'){
            scanf("%d", &a[n++]);
            no = getchar();
        }
        for(int i = 0; i < n; i++)  {
            if(i == n - 1)
                printf("%d\n", a[i]);
            else
                printf("%d ", a[i]);
        }
        int len = n ;
        while(len){
            int maxn = 0, pos;
            for(int j = 0; j < len; j++){
                if(a[j] > maxn){
                    maxn = a[j];
                    pos = j;
                }
            }
            if(pos != len-1){
                if(pos != 0)
                    overturn(pos); //反到前面  往后翻 
                overturn(len-1);
            }
            len--;
        }
        printf("0\n");
        n = 0;
    }
    return 0;
}
