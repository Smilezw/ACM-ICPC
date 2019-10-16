#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 7;
char num[maxn],num2[maxn],another[maxn],sub[maxn];
char ans[51][maxn];
char one[2] = "1";
bool judge(char *s){//判断当前数字是否为回文数字
   int lens = strlen(s);
   for(int i = 0;i<lens/2;i++){
        if(s[i]!=s[lens - i - 1]){
            return false;
        }
   }
   return true;
}
void Decrease(char *s1,char *s2){//大数减法，s1 - s2并把结果赋值给s1去掉前导0
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = len1-1;
    int j = len2-1;
    int flag = 0;
    while(i>=0&&j>=0){
        if(s1[i] - '0'>=flag){
            s1[i] = s1[i] - flag;
            flag = 0;
        }
        else{
            s1[i] = s1[i]  + 10 - flag;
            flag = 1;
        }
        if(s1[i]>=s2[j]){s1[i] = s1[i] -s2[j] + '0';}
        else{
            s1[i] = s1[i] + 10 - s2[j] + '0';
            flag = 1;
        }
        i--;
        j--;
    }
    while(flag&&i>=0){
        if(s1[i] - '0'>=flag){
            s1[i] = s1[i] - flag;
            flag = 0;
        }
        else{
            s1[i] = s1[i]  + 10 - flag;
            flag = 1;
        }
        i--;
    }
    //cout<<s1<<endl;
    int l = 0;
    bool flagd = false;
    memset(another,0,sizeof(another));
    for(int k = 0;k<len1;k++){//去掉前导0
        if(s1[k]=='0'&&!flagd)continue;
        else if(s1[k]!='0'&&!flagd){
            flagd = true;
            another[l++] = s1[k];
        }
        else if(flagd){
            another[l++] = s1[k];
        }
    }
    if(!l){another[l] = '0';l++;}//减法完为0
    another[l] = '\0';
    strcpy(s1,another);//复制
}
void palindromic(char *s1,char *s2){//取s1的回文串s2
    int len1 = strlen(s1);
    if(len1==2&&s1[0]=='1'&&s1[1]=='0'){//特判
        s2[0] = '9';
        s2[1] = '\0';
        return;
    }
    int len2 = (len1&1)?len1/2 + 1:len1/2;
    for(int i = 0;i<len2;i++){//取前一半
        s2[i]  = s1[i];
    }
    s2[len2] = '\0';
    Decrease(s2,one);//减1
    if(s2[0]=='0'){//判断1
        s2[0] = '1';
    }
    for(int i = len1-1,j = 0;j<i;i--,j++){
        s2[i] = s2[j];//对称
    }
    s2[len1] = '\0';
}
int main()
{
    int T;
    scanf("%d",&T);
    int t = 0;
    while(T--){
        scanf("%s",num);
        t++;
        int le = 0;
        while(num[0]!='0'&&le<=50){
            le++;
            //cout<<"num:"<<num<<endl;
            if(judge(num)){//当前为回文，直接结束
                strcpy(ans[le++],num);
                break;
            }
            memset(sub,0,sizeof(sub));
            palindromic(num,sub);//取回文数字sub
            //cout<<"sub:"<<sub<<endl;
            strcpy(ans[le++],sub);//保存结果sub
            Decrease(num,sub);//num - sub
        }
        printf("Case #%d:\n%d\n",t,le);
        for(int i = 0;i<le;i++){
            printf("%s\n",ans[i]);
        }
    }
    return 0;
}
