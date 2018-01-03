ll data[2*N], datb[2*N], seg_n;
void init(int n){
	seg_n = 1;
	while(seg_n<n) seg_n<<=1;
	rep(i, 2*seg_n-1) data[i] = 0;
	rep(i, 2*seg_n-1) datb[i] = 0;
}

// v[a]+=x; v[a+1]+=x;...; v[b]+=x;
void add(int a, int b, ll x, int k, int l, int r){
	if(r <= a || b <= l) return;
	if(a <= l && r <= b){
		data[k] += x;
	} else {
		datb[k] += (min(b, r) - max(a, l))*x;
		add(a, b, x, k*2+1, l, (l+r)/2);
		add(a, b, x, k*2+2, (l+r)/2, r);
	}
}

// sum(v[a], v[a+1],..., v[b])
// to use: sum(a, b, 0, 0, seg_n);
ll sum(int a, int b, int k, int l, int r){
	if(r <= a || b <= l) return 0;
	if(a <= l && r <= b) return data[k]*(r-l) + datb[k];
	ll res = (min(b, r) - max(a, l))*data[k];
	res += sum(a, b, k*2+1, l, (l+r)/2) + sum(a, b, k*2+2, (l+r)/2, r);
	return res;
}

/*
struct segtree{
	vector<ll> data, datb;
	int seg_n;
	void init(int n){
		seg_n = 1;
		while(seg_n<n) seg_n<<=1;
		data = datb = vector<ll>(seg_n, 0LL);
		rep(i, 2*seg_n-1) data[i] = 0;
		rep(i, 2*seg_n-1) datb[i] = 0;
	}

	// v[a]+=x; v[a+1]+=x;...; v[b-1]+=x;
	void add(int a, int b, ll x, int k, int l, int r){
		if(r <= a || b <= l) return;
		if(a <= l && r <= b){
			data[k] += x;:
		} else {
			datb[k] += (min(b, r) - max(a, l))*x;
			add(a, b, x, k*2+1, l, (l+r)/2);
			add(a, b, x, k*2+2, (l+r)/2, r);
		}
	}

	// sum(v[a], v[a+1],..., v[b-1])
	// to use: sum(a, b, 0, 0, seg_n);
	ll sum(int a, int b, int k, int l, int r){
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return data[k]*(r-l) + datb[k];
		ll res = (min(b, r) - max(a, l))*data[k];
		res += sum(a, b, k*2+1, l, (l+r)/2) + sum(a, b, k*2+2, (l+r)/2, r);
		return res;
	}
};
*/
