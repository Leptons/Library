struct rmq {
	int seg_n;
	vector<ll> dat;
	void init(int n, ll initial_value = INF){
		seg_n = 1;
		while(seg_n<n) seg_n<<=1;
		dat = vector<ll>(seg_n*2-1, initial_value);
	}

	// v[k] <- a
	void update(int k, ll a){
		k += seg_n - 1;
		dat[k] = a;
		while(k>0){
			k = (k-1)/2;
			dat[k] = min(dat[k*2+1], dat[k*2+2]);
		}
	}

	// min(v[a], v[a+1],..., v[b-1])
	// to use: query(a, b);
	ll rmin(int a, int b, int k, int l, int r){
		if(r <= a || b <= l) return INF;
		if(a <= l && r <= b) return dat[k];
		return min(rmin(a, b, k*2+1, l, (l+r)/2), rmin(a, b, k*2+2, (l+r)/2, r));
	}

	ll rmin(int a, int b){
		return rmin(a, b, 0, 0, seg_n);
	}
};
