#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=998244353;   //模数
const ll g=3;             //原根

ll fp(ll a,ll k) {
    ll res=1LL;
    while(k>0) {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}

void change(ll y[],int len) {
    for(int i=1,j=len/2;i<len-1;i++) {
        if(i<j)swap(y[i],y[j]);
        int k=len/2;
        while(j>=k) {
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}

void ntt(ll y[],int len,int on) {
    change(y,len);
    for(int h=2;h<=len;h<<=1) {
        ll wn=fp(g,(Mod-1)/h);
        if(on==-1)wn=fp(wn,Mod-2);
        for(int j=0;j<len;j+=h) {
            ll w=1LL;
            for(int k=j;k<j+h/2;k++) {
                ll u=y[k];
                ll t=w*y[k+h/2]%Mod;
                y[k]=(u+t)%Mod;
                y[k+h/2]=(u-t+Mod)%Mod;
                w=w*wn%Mod;
            }
        }
    }
    if(on==-1) {
        ll t=fp(len,Mod-2);
        for(int i=0;i<len;i++)
            y[i]=y[i]*t%Mod;
    }
}

ll x1[200005],x2[200005];
