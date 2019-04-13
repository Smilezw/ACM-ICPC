#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)

struct LB{
    ll b[33];
    void clear(){
        rep(i,0,31) b[i]=0;
    }
    void insert(int x){
        rrep(i,31,0) if(x>>i&1){
            if(b[i]) x^=b[i];
            else{
                b[i]=x;
                //rrep(j,i-1,0) if(b[j]&&(b[i]>>j&1)) b[i]^=b[j];
                //rep(j,i+1,30) if(b[j]>>i&1) b[j]^=b[i];
                break;
            }
        }
    }
    ll rnk1(){
        ll res=0;
        rrep(i,31,0) res=max(res,res^b[i]);
        return res;
    }
};
