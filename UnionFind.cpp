struct UF {
	int par[N],rank[N];
	
	void init(int n){
		for(int i = 0; i < n; i++){
			par[i] = i;
			rank[i] = 0;
		}
	}
	
	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}
	
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = par[x];
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
};
