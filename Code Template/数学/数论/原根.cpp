ll getRoot(ll p) {
    tot=0;
    ll n=p-1,sq=sqrt(p+0.5);
    for(int i=2;i<=sq;i++)if(n%i==0) {
        pri[tot++]=i;
        while(n%i==0)n/=i;
    }
    if(n>1)pri[tot++]=n;
    for(int g=2;g<=p-1;g++) {
        int flag=1;
        for(int i=0;i<tot;i++)if(qpow(g,(p-1)/pri[i],p)==1) {
            flag=0; break;
        }
        if(flag)return g;
    }
    return -1; 
}
