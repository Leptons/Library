template <class T> ll mergecount(vector<T> &a){
	ll cnt = 0;
	int n = a.size();
	if(n<=1) return 0;
	vector<T> b(a.begin(), a.begin()+n/2);
	vector<T> c(a.begin()+n/2, a.end());
	cnt += mergecount(b);
	cnt += mergecount(c);
	for(int i = 0, j = 0, k = 0; i < n; i++){
		if(k==c.size()) a[i] = b[j++];
		else if(j==b.size()) a[i] = c[k++];
		else if(b[j] <= c[k]) a[i] = b[j++];
		else { a[i] = c[k++]; cnt+=b.size()-j; }
	}
	return cnt;
}
