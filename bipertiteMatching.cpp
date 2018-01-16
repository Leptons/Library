bool go(vector<vector<int> > &g, int u, vector<int> &mt, vector<bool> &vs){
	int n = g.size();
	if(u<0) return true;
	for(int v = 0; v < n; v++){
		if(!g[u][v] || vs[v] || mt[v]!=-1) continue;
		vs[v] = true;
		mt[v] = u;
		return true;
	}
	for(int v = 0; v < n; v++){
		if(!g[u][v] || vs[v]) continue;
		vs[v] = true;
		if(go(g, mt[v], mt, vs)){
			mt[v] = u;
			return true;
		}
	}
	return false;
}

// g (subset of K_{n,n}) is adjacency matrix (g[left vertex][right vertex])
int bm(vector<vector<int> > &g){
	int n = g.size();
	vector<int> mt(n, -1);
	int res = 0;
	for(int i = 0; i < n; i++){
		vector<bool> vs(n);
		if(go(g, i, mt, vs)) res++;
	}
	return res;
}
