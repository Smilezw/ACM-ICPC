typedef long long ll;

ll n, m;
//n范围内 %m = k 的数字个数
ll count(ll k){
	return n/m+(n%m>=k);
}
