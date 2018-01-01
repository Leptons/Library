ll inv[N], fact[N], ifact[N], be[N];
 
ll comb(ll a, ll b){
	return fact[a+b]*ifact[a]%mod*ifact[b]%mod;
}
 
ll comb_nk(ll n, ll k){
	return comb(n-k, k);
}
 
ll lcm(ll a, ll b){
    return a/__gcd(a, b)*b;
}
 
ll extgcd(ll x, ll y, ll &u, ll &v){
	ll d = x;
	if(y != 0){
		d = extgcd(y, x%y, v, u);
		v -= (x/y)*u;
	} else {
		u = 1;
		v = 0;
	}
	return d;
}

int128 extgcd128(int128 x, int128 y, int128 &u, int128 &v){
	int128 d = x;
	if(y != 0){
		d = extgcd128(y, x%y, v, u);
		v -= (x/y)*u;
	} else {
		u = 1;
		v = 0;
	}
	return d;
}

void chrm_coprime(ll &a, ll &m, ll b, ll n){
	ll u, v;
	extgcd(m, n, u, v);
	a = a*n*v+b*m*u;
	m = m*n;
	a %= m;
	if(a<0) a += m;
}

void chrm128(int128 &a, int128 &m, int128 b, int128 n){
	a = a%m+m; b = b%n+n;
	int128 a2 = a, m2 = m;
	int128 u, v;
	int128 g = extgcd128(m, n, u, v);
	if(a%g!=b%g) cerr<<"NG"<<endl;
	u *= (b-a)/g; v *= (b-a)/g;
	a = m*u+a;
	m *= n/g;
	a %= m;
	if(a<0) a += m;
	return;
}

void chrm(ll &a, ll &m, ll b, ll n){
	int128 a2 = a, m2 = m, b2 = b, n2 = n;
	chrm128(a2, m2, b2, n2);
	a = a2; m = m2; b = b2; n = n2;
}
 
ll lambda(ll m){
    ll res = 1;
    if(m%8==0) m /= 2;
    for(ll i = 2; i*i <= m; i++){
        if(!(m%i)){
            ll r = i-1;
            m /= i;
            while(!(m%i)){
                m /= i;
                r *= i;
            }
            res = lcm(res, r);
        }
    }
    if(m>1) res = lcm(res, m-1);
    return res;
}
 
ll tot(ll m){
	ll res = 1;
	for(ll i = 2; i*i <= m; i++){
		if(!(m%i)){
			res *= i-1;
			m /= i;
			while(!m%i){
				m /= i;
				res *= i;
			}
		}
	}
	if(m>1) res *= m-1;
	return res;
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
