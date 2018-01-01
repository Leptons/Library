ll dat[2*N], seg_n;
void init(int n){
	seg_n = 1;
	while(seg_n<n) seg_n<<=1;
	rep(i, 2*seg_n-1) dat[i] = INF;
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
// to use: query(a, b, 0, 0, seg_n);
ll rmq(int a, int b, int k, int l, int r){
	if(r <= a || b <= l) return INF;
	if(a <= l && r <= b) return dat[k];
	return min(rmq(a, b, k*2+1, l, (l+r)/2), rmq(a, b, k*2+2, (l+r)/2, r));
}
