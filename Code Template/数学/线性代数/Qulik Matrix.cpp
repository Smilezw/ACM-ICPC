#include <bits/stdc++.h>
using namespace std;

const int MM = 55;

struct Matrix {
    int mat[MM][MM];
};

Matrix multiply(Matrix a,Matrix b,int M) {
    Matrix c;
    memset(c.mat,0,sizeof(c.mat));
    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++) {
            if(a.mat[i][j]==0)continue;
            for(int k=0;k<M;k++) {
                if(b.mat[j][k]==0)continue;
                c.mat[i][k]=(c.mat[i][k]+a.mat[i][j]*b.mat[j][k])%M;
            }
        }
    }
    return c;
}

Matrix quickmod(Matrix a,int n,int M) {
    Matrix res;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++)
            res.mat[i][j]=(i==j);
    }
    while(n) {
        if(n&1) res=multiply(res,a,M);
        n>>=1;
        a=multiply(a,a,M);
    }
    return res;
}
