ll inv[N], fact[N], ifact[N], be[N];
 
ll comb(ll a, ll b){
	return fact[a+b]*ifact[a]%mod*ifact[b]%mod;
}
 
ll comb_nk(ll n, ll k){
	return comb(n-k, k);
}
 
ll pow_mod(ll a, ll r, ll m){
	ll x = 1;
	while(r){
		if(r&1) (x*=a)%=m;
		(a*=a)%=m;
		r>>=1;
	}
	return x;
}
 
void init_fact(ll n = N){
    inv[1] = 1;
    for(int i = 2; i < n; i++) inv[i] = inv[mod%i] * (mod - mod/i) % mod;
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < n; i++){
		fact[i] = (fact[i-1]*i)%mod;
		ifact[i]=(ifact[i-1]*inv[i])%mod;
	}
}
 
void init_bell(ll n = N){
	mset(be, 0);
	be[0] = 1;
	rep(i, n-1) rep(j, i+1) (be[i+1]+=fact[i]*ifact[i-j]%mod*ifact[j]%mod*be[j])%=mod;
}
 
void init_all(ll n = N){
	init_fact(n);
	init_bell(n);
}

// calculate [(10^a-1)/9) / ((10^g-1)/g) mod m
ll calc111(ll a, ll g, ll m){
	ll x = 0, y = 1, z = 1, w = 10;
	a /= g;
	while(g){
		if(g&1)(z*=w)%=m;
		(w*=w)%=m;
		g /= 2;
	}
	while(a){
		if(a&1){
			x = (x*z+y)%m;
		}
		y = (y*z+y)%m;
		z = (z*z)%m;
		a /= 2;
	}
	return x;
}
