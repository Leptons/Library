struct UF {
	vector<int> par, rank, sz;
	
	void init(int n){
		par = rank = vector<int>(n, 0);
		sz = vector<int>(n, 1);
		for(int i = 0; i < n; i++){
			par[i] = i;
		}
	}
	
	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	int size(int x){
		return sz[find(x)];
	}
	
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]){
			par[x] = y;
			sz[y] += sz[x];
		}else{
			par[y] = par[x];
			if(rank[x] == rank[y]) rank[y]++;
			sz[x] += sz[y];
		}
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
};

